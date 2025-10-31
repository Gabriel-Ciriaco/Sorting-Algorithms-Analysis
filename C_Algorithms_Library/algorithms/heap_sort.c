#include "sort_algorithms.h"


/*
    Heapify uma sub-arvore com raiz i,
    sendo i um índice do vetor.
*/
void heapify(int* vetor, int vetor_size, int i)
{
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    // Se o elemento da esquerda é o maior.
    if (left < vetor_size && vetor[left] > vetor[largest])
    {
        largest = left;
    }

    // Se o elemento da direita é o maior
    if (right < vetor_size && vetor[right] > vetor[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        troca(&vetor[i], &vetor[largest]);

        // Heapify recursivamente.
        heapify(vetor, vetor_size, largest);
    }
}

void heap_sort(int* vetor, int ini, int fim)
{
    // Cria o heap
    for (int i = (fim - ini) / 2; i >= 0; i--)
    {
        heapify(vetor, (fim - ini) + 1, i);
    }

    // Tira o elemento da heap 1 por 1
    for (int i = fim; i > 0; i--)
    {
        troca(&vetor[0], &vetor[i]);

        // Heapify o heap reduzido.
        heapify(vetor, i, 0);
    }
}
