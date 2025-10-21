#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "csv_manager/csv_manager.h"

typedef struct sequencia
{
    int tamanho;
    int * vetor;
} Sequencia;

Sequencia * ler_sequencia_numerica(char* nome_arquivo_entrada);

#endif // FILE_MANAGER_H
