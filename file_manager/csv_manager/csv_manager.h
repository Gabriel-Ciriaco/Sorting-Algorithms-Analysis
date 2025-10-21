#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H


void write_csv(const char* CSV_PATH,
               char* nome_algoritmo,
               int numero_entradas,
               double tempo,
               char* tipo_entrada);

#endif // CSV_MANAGER_H
