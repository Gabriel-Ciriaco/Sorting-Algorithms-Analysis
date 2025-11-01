#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include "../export.h"

typedef void (*sort_function)(int*, int, int);

DLL_EXPORT double run_sort_function(sort_function sort_algorithm,
                         int* vetor,
                         int ini,
                         int fim);

void troca(int* a, int* b);

void heapify(int* vetor, int i, int vetor_size);

DLL_EXPORT void merge_sort(int* vetor, int ini, int fim);

DLL_EXPORT void quick_sort(int* vetor, int ini, int fim);

DLL_EXPORT void central_quick_sort(int* vetor, int ini, int fim);

DLL_EXPORT void bubble_sort(int* vetor, int ini, int fim);

DLL_EXPORT void better_bubble_sort(int* vetor, int ini, int fim);

DLL_EXPORT void insertion_sort(int* vetor, int ini, int fim);

DLL_EXPORT void selection_sort(int* vetor, int ini, int fim);

DLL_EXPORT void heap_sort(int* vetor, int ini, int fim);

DLL_EXPORT void shell_sort(int* vetor, int ini, int fim);

#endif // SORT_ALGORITHMS_H
