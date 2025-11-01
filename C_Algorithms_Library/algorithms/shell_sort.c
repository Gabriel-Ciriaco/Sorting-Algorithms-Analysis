#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sort_algorithms.h"


void shell_sort(int *vetor, int ini, int fim)
{
    int pos;
    int i;
    int j;
    int span;
    int chave;

    int n = (fim - ini) + 1;

    /*
        Usaremos a sequência de Hibbard:
        1, 3, 7, 15, 31,..., 2^k - 1.

        Logo, o número de incrementos é log2(n+1)
    */
    int numGaps = (int) log2(n + 1);

    int* vetorGaps = (int*) malloc(sizeof(int) * numGaps);

    if (!vetorGaps)
    {
        perror("[SHELL-SORT]: There was an error allocating the gaps.");
        return;
    }

    for (int k = 0; k < numGaps; k++)
    {
        // Gera o incremento 2^k - 1 usando bitShift
        vetorGaps[k] = (1 << (numGaps - k)) - 1;
    }


    // Shell Sort em si
    for(pos = 0; pos < numGaps; pos++)
    {
        span = vetorGaps[pos];

        for(i = ini + span; i <= fim; i++)
        {
            chave = vetor[i];

            for(j = i - span; j >= ini && vetor[j] > chave; j -= span)
            {
                vetor[j + span] = vetor[j];
            }

            vetor[j + span] = chave;
        }
    }

    free(vetorGaps);
}
