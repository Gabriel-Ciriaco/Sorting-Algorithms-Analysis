#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h> // Required for sleep()

#include "file_manager/file_manager.h"

#include "algorithms/sort_algorithms.h"


void testar_algoritmo(sort_function sort_algorithm,
                      int numero_entradas,
                      int* entradas,
                      char* nome_algoritmo,
                      char* tipo_entrada)
{
    // Definindo o tamanho do vetor
    int tamanho = numero_entradas;

    double tempo = run_sort_function(sort_algorithm, entradas, 0, tamanho - 1);

    printf("Tempo demorado: %f", tempo);

    write_csv("relatorio/testes_ordenacao.csv", nome_algoritmo, tamanho, tempo, tipo_entrada);
}

int main()
{
    Sequencia * log_exp = ler_sequencia_numerica("./sequencia/sequencia_log_exp.bin");

    if (!log_exp)
    {
        printf("[MAIN]: Ocorreu um erro ao ler a sequência de testes.");

        return 1;
    }

    Sequencia * entrada_teste = ler_sequencia_numerica("entradas/entrada_rand1.bin");

    if (!entrada_teste) return 1;

    int * entradas = (int*) malloc(sizeof(int) * 100000);

    if (!entradas) return 1;

    for (int i = 0; i < 100000; i++)
    {
        entradas[i] = i;
    }

    for (int i = 0; i < log_exp->tamanho; i++)
    {
        printf("\nExecutando com o tamanho do vetor: %d \n", log_exp->vetor[i]);
        testar_algoritmo(bubble_sort, log_exp->vetor[i], entrada_teste->vetor, "BubbleSort", "Aleatória");
    }

    free(log_exp->vetor);
    free(log_exp);

    free(entrada_teste->vetor);
    free(entrada_teste);
    free(entradas);
    return 0;
}
