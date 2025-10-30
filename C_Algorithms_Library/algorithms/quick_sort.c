#include "sort_algorithms.h"

#define SIZE 5


int particionar(int* vetor, int ini, int fim)
{
    int pivo = vetor[ini];
    int i = ini;
    int j = fim;

    while (i < j)
    {
        while(vetor[i] <= pivo && i <= fim - 1)
        {
            i++;
        }

        while(vetor[j] > pivo && j >= ini + 1)
        {
            j--;
        }

        if (i < j)
        {
            troca(&vetor[i], &vetor[j]);
        }
    }

    troca(&vetor[ini], &vetor[j]);

    return j;
}

void quick_sort(int* vetor, int ini, int fim)
{
    if (ini < fim)
    {
        int pos = particionar(vetor, ini, fim);

        quick_sort(vetor, ini, pos - 1);
        quick_sort(vetor, pos + 1, fim);
    }
}
