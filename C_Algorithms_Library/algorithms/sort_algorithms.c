#include <time.h>

#include "sort_algorithms.h"


double run_sort_function(sort_function sort_algorithm,
                         int* vetor,
                         int ini,
                         int fim)
{
    if (!vetor || !sort_algorithm || ini < 0 || fim < ini) return -1.0;

    struct timespec start, finish;

    /*
        Medimos o tempo de wall-clock, ou seja,
        o tempo real que se passou do início ao fim da execução do algoritmo.

        CLOCK_MONOTONIC nos garante que o tempo nunca retroceda, mesmo que o
        relógio do sistema seja ajustado.
    */
    clock_gettime(CLOCK_MONOTONIC, &start);

    sort_algorithm(vetor, ini, fim);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    // Retorna o tempo com maior precisão.
    return (double) (finish.tv_sec - start.tv_sec) +
                    (finish.tv_nsec - start.tv_nsec) / 1e9;
}


void troca(int * a, int * b)
{
    if (a == b) return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
