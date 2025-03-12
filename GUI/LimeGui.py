import tkinter as tk
from tkinter import ttk
import pandas as pd

# Leer nuevamente el archivo y eliminar filas que contengan '***'
data_complete = pd.read_excel('/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/bydtatype2.xlsx')
api_descriptions = pd.read_excel('/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/LimeAPI_descruption.xlsx')

cleaned_data_complete = data_complete[~data_complete.apply(lambda row: row.astype(str).str.contains(r'\*\*\*').any(), axis=1)]

# Crear diccionario de descripciones desde LimeAPI_description.xlsx
desc_dict = api_descriptions.set_index('API Name')['API Description'].to_dict()

# Generar estructura con descripción integrada
structured_info = {}
for qt_label, group in cleaned_data_complete.groupby('QT Label'):
    structured_info[qt_label] = []
    for _, row in group.iterrows():
        api_name = row["API Name"]
        description = desc_dict.get(api_name, "Description not found.")
        structured_info[qt_label].append({
            "API Name": api_name,
            "Opcode": row["HEX OPCODE"],
            "Description": description
        })

class MainWindow(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("LIMEGUI - LMS7002M")

        # QT Label
        tk.Label(self, text="QT Label:").grid(row=0, column=0, sticky="w", padx=5, pady=5)
        self.cmb_qt_label = ttk.Combobox(self, values=list(structured_info.keys()), state="readonly")
        self.cmb_qt_label.grid(row=0, column=1, padx=5, pady=5)
        self.cmb_qt_label.bind("<<ComboboxSelected>>", self.update_api_names)

        # API Name
        tk.Label(self, text="API Name:").grid(row=1, column=0, sticky="w", padx=5, pady=5)
        self.cmb_api_name = ttk.Combobox(self, state="readonly")
        self.cmb_api_name.grid(row=1, column=1, padx=5, pady=5)
        self.cmb_api_name.bind("<<ComboboxSelected>>", self.show_opcode)

        # Opcode
        self.lbl_opcode = tk.Label(self, text="Opcode: ")
        self.lbl_opcode.grid(row=2, column=0, columnspan=2, sticky="w", padx=5, pady=5)

        # Descripción
        self.lbl_description = tk.Label(self, text="Descripción: ", anchor="w", justify="left", wraplength=400)
        self.lbl_description.grid(row=3, column=0, columnspan=2, sticky="w", padx=5, pady=5)

        # Iniciar valores
        self.cmb_qt_label.current(0)
        self.update_api_names(None)

    def update_api_names(self, event):
        qt_label = self.cmb_qt_label.get()
        api_list = [api['API Name'] for api in structured_info[qt_label]]
        self.cmb_api_name.config(values=api_list)
        self.cmb_api_name.current(0)
        self.show_opcode(None)

    def show_opcode(self, event):
        qt_label = self.cmb_qt_label.get()
        api_name = self.cmb_api_name.get()
        api_info = next((api for api in structured_info[qt_label] if api['API Name'] == api_name), None)
        if api_info:
            self.lbl_opcode.config(text=f"Opcode: 0x{api_info['Opcode']}")
            self.lbl_description.config(text=f"Description: {api_info['Description']}")

if __name__ == "__main__":
    app = MainWindow()
    app.mainloop()