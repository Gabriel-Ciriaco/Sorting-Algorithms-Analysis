#include "sort_algorithms.h"


void bubble_sort(int* vetor, int ini, int fim)
{
    if (!vetor || ini < 0 || fim < ini) return;

    for (int i = 0; i < fim; i++)
    {
        for (int j = 0; j < fim - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                troca(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}
