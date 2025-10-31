#include "sort_algorithms.h"


int central_particionar(int *vetor, int ini, int fim)
{
    int meio = (ini + fim) / 2;

    troca(&vetor[meio], &vetor[ini]);

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

void central_quick_sort(int *vetor, int ini, int fim)
{
    if (ini < fim)
    {
        int pos = central_particionar(vetor, ini, fim);

        central_quick_sort(vetor, ini, pos - 1);
        central_quick_sort(vetor, pos + 1, fim);
    }
}
