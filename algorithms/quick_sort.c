#include "sort_algorithms.h"

#define SIZE 5


int particionar(int vetor[], int ini, int fim)
{
    int pivo = vetor[ini];

    while (ini < fim)
    {
        while (ini < fim && vetor[ini] <= pivo)
        {
            ini++;
        }

        while (ini < fim && vetor[fim] > pivo)
        {
            fim--;
        }

        troca(&vetor[ini], &vetor[fim]);

    }

    return ini; // ini é a posição do primeiro elemento grande
}

void quick_sort(int vetor[], int ini, int fim)
{
    int pos = 0;

    if (ini < fim)
    {
        pos = particionar(vetor, ini, fim);

        quick_sort(vetor, ini, pos - 1);
        quick_sort(vetor, pos, fim);
    }
}
