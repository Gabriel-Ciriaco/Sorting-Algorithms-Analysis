#include <stdbool.h>

#include "sort_algorithms.h"


void better_bubble_sort(int* vetor, int ini, int fim)
{
    if (!vetor || ini < 0 || fim < ini) return;

    bool trocado = false;

    for (int i = 0; i < fim; i++)
    {
        trocado = false;

        for (int j = 0; j < fim - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                troca(&vetor[j], &vetor[j + 1]);
                trocado = true;
            }
        }

        // Se nenhum elemento foi trocado, então está ordenado.
        if(!trocado)
            break;
    }
}
