#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H


typedef void (*sort_function)(int*, int, int);

double run_sort_function(sort_function sort_algorithm,
                         int* vetor,
                         int ini,
                         int fim);

void troca(int* a, int* b);

void merge_sort(int vetor[], int ini, int fim);

void quick_sort(int vetor[], int ini, int fim);

void bubble_sort(int vetor[], int ini, int fim);


#endif // SORT_ALGORITHMS_H
