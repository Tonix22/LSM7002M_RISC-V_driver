import tkinter as tk
from tkinter import ttk
import pandas as pd

# Leer los archivos Excel
data_complete = pd.read_excel('/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/bydtatype2.xlsx')
api_descriptions = pd.read_excel('/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/LimeAPI_descruption.xlsx')

cleaned_data_complete = data_complete[~data_complete.apply(lambda row: row.astype(str).str.contains(r'\*\*\*').any(), axis=1)]

# Crear diccionario de descripciones
desc_dict = api_descriptions.set_index('API Name')['API Description'].to_dict()

# Generar estructura con parámetros y descripciones integradas
structured_info = {}
param_cols = ['P1_t', 'P2_t', 'P3_t', 'P4_t', 'P5_t']

for qt_label, group in cleaned_data_complete.groupby('QT Label'):
    structured_info[qt_label] = []
    for _, row in group.iterrows():
        api_name = row["API Name"]
        description = desc_dict.get(api_name, "Description not found.")
        params = {col: row[col] for col in param_cols if pd.notna(row[col]) and row[col] != 'None'}
        structured_info[qt_label].append({
            "API Name": api_name,
            "Opcode": row["HEX OPCODE"],
            "Description": description,
            "Parameters": params
        })

class MainWindow(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("LIMEGUI - LMS7002M")
        self.geometry("700x600")
        self.resizable(False, False)

        style = ttk.Style(self)
        style.theme_use('clam')

        style.configure('TLabel', font=('Arial', 12))
        style.configure('TButton', font=('Arial', 12, 'bold'), foreground='white', background='#0078D7')

        ttk.Label(self, text="QT Label:").pack(padx=10, pady=5, anchor="w")
        self.cmb_qt_label = ttk.Combobox(self, values=list(structured_info.keys()), state="readonly")
        self.cmb_qt_label.pack(fill='x', padx=10)
        self.cmb_qt_label.bind("<<ComboboxSelected>>", self.update_api_names)

        ttk.Label(self, text="API Name:").pack(padx=10, pady=5, anchor="w")
        self.cmb_api_name = ttk.Combobox(self, state="readonly")
        self.cmb_api_name.pack(fill='x', padx=10)
        self.cmb_api_name.bind("<<ComboboxSelected>>", self.show_details)

        self.lbl_opcode = ttk.Label(self, text="Opcode: ", foreground="blue")
        self.lbl_opcode.pack(padx=10, pady=5, anchor="w")

        self.lbl_description = ttk.Label(self, text="Descripción:", wraplength=560)
        self.lbl_description.pack(padx=10, pady=5, anchor="w")

        self.param_frame = ttk.Frame(self)
        self.param_frame.pack(padx=10, pady=10, fill='x', anchor="w")

        self.btn_send = ttk.Button(self, text="Enviar", command=self.send_data)
        self.btn_send.pack(pady=10)

        self.cmb_qt_label.current(0)
        self.update_api_names(None)

    def update_api_names(self, event):
        qt_label = self.cmb_qt_label.get()
        api_list = [api['API Name'] for api in structured_info[qt_label]]
        self.cmb_api_name.config(values=api_list)
        self.cmb_api_name.current(0)
        self.show_details(None)

    def show_details(self, event):
        for widget in self.param_frame.winfo_children():
            widget.destroy()

        qt_label = self.cmb_qt_label.get()
        api_name = self.cmb_api_name.get()
        api_info = next((api for api in structured_info[qt_label] if api['API Name'] == api_name), None)

        if api_info:
            self.lbl_opcode.config(text=f"Opcode: 0x{api_info['Opcode']}")
            self.lbl_description.config(text=f"Descripción: {api_info['Description']}")

            self.param_entries = {}
            for idx, (param, param_type) in enumerate(api_info.get('Parameters', {}).items()):
                ttk.Label(self.param_frame, text=f"{param} ({param_type}):").grid(row=idx, column=0, sticky="w", padx=5)
                if 'double' in param_type:
                    slider = ttk.Scale(self.param_frame, from_=0, to=1000, orient='horizontal')
                    slider.grid(row=idx, column=1, padx=5, pady=2, sticky='ew')

                    value_label = ttk.Label(self.param_frame, text="000.00")
                    slider.config(command=lambda val, l=slider, lbl=value_label: lbl.config(text=f"{float(val):.2f}".zfill(6)))
                    value_label.grid(row=idx, column=2, padx=10, pady=5, sticky='ew')

                    ttk.Label(self.param_frame, text="Escala:").grid(row=idx, column=3, padx=5)
                    unit = ttk.Combobox(self.param_frame, values=['', 'K', 'M', 'G'], width=4)
                    unit.grid(row=idx, column=4, padx=5)
                    unit.current(0)

                    self.param_entries[param] = (slider, unit)
                else:
                    entry = ttk.Entry(self.param_frame)
                    entry.grid(row=idx, column=1, padx=5, pady=2, sticky='ew')
                    self.param_entries[param] = entry

            self.param_frame.columnconfigure(1, weight=1)

    def send_data(self):
        qt_label = self.cmb_qt_label.get()
        api_name = self.cmb_api_name.get()
        api_info = next((api for api in structured_info[qt_label] if api['API Name'] == api_name), None)

        if api_info:
            params = {}
            for param, widget in self.param_entries.items():
                if isinstance(widget, tuple):
                    slider, unit = widget
                    val = slider.get()
                    scale = unit.get()
                    multiplier = {'': 1, 'K': 1e3, 'M': 1e6, 'G': 1e9}.get(unit.get(), 1)
                    params[param] = round(val * multiplier, 2)
                else:
                    params[param] = widget.get()

            print(f"Opcode: 0x{api_info['Opcode']}, Parameters: {params}")


if __name__ == "__main__":
    app = MainWindow()
    app.mainloop()