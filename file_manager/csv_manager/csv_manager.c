#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv_manager.h"


void write_csv(const char* CSV_PATH,
               char* nome_algoritmo,
               int numero_entradas,
               double tempo,
               char* tipo_entrada)
{
    if (!CSV_PATH || !nome_algoritmo || !tipo_entrada) return;

    FILE* arquivo_csv = fopen(CSV_PATH, "a+");

    if (!arquivo_csv)
    {
        perror("\n[WRITE-CSV]: Não foi possível abrir o arquivo especificado.\n");
        return;
    }

    fprintf(arquivo_csv, "\n%s,%d,%f,%s",
             nome_algoritmo,
             numero_entradas,
             tempo,
             tipo_entrada);

    fclose(arquivo_csv);
}
