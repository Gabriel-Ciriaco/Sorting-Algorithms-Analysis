#include <time.h>

#include "sort_algorithms.h"


double run_sort_function(sort_function sort_algorithm,
                         int* vetor,
                         int ini,
                         int fim)
{
    if (!vetor || !sort_algorithm || ini < 0 || fim < ini) return -1.0;

    clock_t start, finish;

    start = clock();

    sort_algorithm(vetor, ini, fim);

    finish = clock();

    return (double) (finish - start) / CLOCKS_PER_SEC;
}


void troca(int * a, int * b)
{
    if (a == b) return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
