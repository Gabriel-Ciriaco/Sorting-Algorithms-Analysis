#include "sort_algorithms.h"


void selection_sort(int * vetor, int ini, int fim)
{
    if (!vetor || ini < 0 || fim < ini) return;

    for (int i = ini; i <= fim; i++)
    {
        int min_element = i;

        for (int j = i + 1; j <= fim; j++)
        {
            if (vetor[j] < vetor[min_element])
            {
                min_element = j;
            }
        }

        troca(&vetor[i], &vetor[min_element]);
    }
}
