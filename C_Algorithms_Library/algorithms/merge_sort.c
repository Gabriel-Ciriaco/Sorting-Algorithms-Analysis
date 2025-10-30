#include "sort_algorithms.h"

#include <stdio.h>
#include <stdlib.h>

void intercalar(int* vetor, int ini, int meio, int fim)
{
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int tamanho = fim - ini + 1;
    int* aux = (int*) malloc(sizeof(int) * tamanho);

    if (!aux)
    {
        perror("\n[MERGE-SORT]: Não foi possível alocar espaço.\n");
        return;
    }

    while (i <= meio && j <= fim)
    {
        if (vetor[i] < vetor[j])
        {
            aux[k++] = vetor[i++];
        }
        else
        {
            aux[k++] = vetor[j++];
        }
    }

    // Copia o resto de cada subvetor
    while(i <= meio) aux[k++] = vetor[i++];
    while (j <= fim) aux[k++] = vetor[j++];

    // Copia do auxiliar para vetor
    for (i = ini, k = 0; i <= fim; i++, k++)
    {
        vetor[i] = aux[k];
    }

    free(aux);
}

void merge_sort(int* vetor, int ini, int fim)
{
    int meio;

    if (ini < fim)
    {
        meio = (ini + fim) / 2;
        merge_sort(vetor, ini, meio);
        merge_sort(vetor, meio + 1, fim);
        intercalar(vetor, ini, meio, fim);
    }
}
