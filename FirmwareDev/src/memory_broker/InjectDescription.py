#!/usr/bin/env python3

import re
import pandas as pd

# Ajusta la ruta de tu LimeAPI_descruption.xlsx
LIMEAPI_DESCRIPTION_XLSX = "/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/LimeAPI_descruption.xlsx"

# Ajusta la ruta al archivo C original refactored
INPUT_C_FILE  = "parser.c"
OUTPUT_C_FILE = "parser_with_desc.c"

def load_api_descriptions(xlsx_path):
    """
    Retorna un diccionario:
      { 'LMS7002M_create': '....', 'LMS7002M_destroy': '....', ... }
    con la documentación proveniente del Excel.
    """
    df = pd.read_excel(xlsx_path)
    api_dict = {}
    for _, row in df.iterrows():
        api_name = str(row["API Name"]).strip()
        api_desc = str(row["API Description"]).strip() if "API Description" in row else ""
        if api_name:
            api_dict[api_name] = api_desc
    return api_dict

def inject_descriptions_into_code(input_file, output_file, api_docs):
    """
    Lee un archivo C (ya refactored) línea por línea.
    Busca entradas de la forma: { &<API_NAME> }, y si <API_NAME>
    aparece en `api_docs`, inyecta un bloque de comentario Doxygen
    encima de esa línea, con saltos de línea y tabulaciones por cada línea
    de la descripción.

    :param input_file:   Ruta al archivo C de entrada.
    :param output_file:  Ruta donde se guardará el archivo C con descripciones inyectadas.
    :param api_docs:     Diccionario { API Name -> Descripción multilinea }.
    """
    with open(input_file, "r", encoding="utf-8") as fin:
        lines = fin.readlines()

    new_lines = []
    pattern = re.compile(r"\{\s*&([\w\d_]+)\s*\}")

    for line in lines:
        # Buscar entradas { &<API_NAME> }
        match = pattern.search(line)
        if match:
            api_name = match.group(1)
            desc = api_docs.get(api_name, "").strip()

            if desc:
                # Escapar '*/' si existiera
                desc = desc.replace("*/", "*\\/")

                # Separar la descripción en líneas
                desc_lines = desc.split('\n')

                # Formatear cada línea con tabulaciones
                desc_formatted = ""
                for dl in desc_lines:
                    desc_formatted += f" *\t{dl}\n"

                # Bloque Doxygen, se inserta antes de la línea original
                new_lines.append("/**\n")
                new_lines.append(f" * @brief {api_name}\n")
                new_lines.append(desc_formatted)
                new_lines.append(" */\n")

        # Agregar la línea original (con o sin bloque)
        new_lines.append(line)

    # Escribir el resultado
    with open(output_file, "w", encoding="utf-8") as fout:
        fout.writelines(new_lines)


def main():
    # 1) Cargar descripciones
    api_docs = load_api_descriptions(LIMEAPI_DESCRIPTION_XLSX)

    # 2) Inyectar descripciones en el .c refactored
    inject_descriptions_into_code(INPUT_C_FILE, OUTPUT_C_FILE, api_docs)

    print(f"Archivo '{OUTPUT_C_FILE}' generado con descripciones Doxygen inyectadas.")

if __name__ == "__main__":
    main()
