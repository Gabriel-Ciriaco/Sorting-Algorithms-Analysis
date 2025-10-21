#include "file_manager.h"

#include <stdio.h>
#include <stdlib.h>


Sequencia * ler_sequencia_numerica(char* nome_arquivo_entrada)
{
    FILE * arquivo_entrada = fopen(nome_arquivo_entrada, "rb");

    if (!arquivo_entrada)
    {
        printf("[LER-ENTRADA]: Não foi possível abrir o arquivo: %s", nome_arquivo_entrada);
        return NULL;
    }

    // Lendo o tamanho do vetor (primeiro valor no arquivo)
    int tamanho;
    fread(&tamanho, sizeof(int), 1, arquivo_entrada);

    Sequencia * sequencia = (Sequencia *) malloc(sizeof(Sequencia) * 1);

    if (!sequencia)
    {
        printf("[LER-ENTRADA]: Não foi possível alocar memória para a Sequencia: %s", nome_arquivo_entrada);

        fclose(arquivo_entrada);

        return NULL;
    }

    int* entradas = (int*) malloc(sizeof(int) * tamanho);

    if (!entradas)
    {
        printf("[LER-ENTRADA]: Não foi possível alocar memória para a entrada: %s", nome_arquivo_entrada);

        fclose(arquivo_entrada);
        return NULL;
    }

    // Lendo os números aleatórios e imprimindo
    int numero = 0;
    for (int i = 0; i < tamanho; i++)
    {
        fread(&(entradas[i]), sizeof(int), 1, arquivo_entrada);
    }

    fclose(arquivo_entrada);

    sequencia->tamanho = tamanho;
    sequencia->vetor = entradas;

    return sequencia;
}
