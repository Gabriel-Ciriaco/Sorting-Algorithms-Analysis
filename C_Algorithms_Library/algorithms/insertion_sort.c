/*
    A explicação do algoritmo é a seguinte:
        - Nós começamos do segundo elemento do vetor,
        pois assume-se que primeiro já está ordenado.
        - Comparamos o segundo elemento com o primeiro elemento.
        Se o segundo elemento é menor, você troca os dois de posição.
        - Vai para o terceiro elemento e compara ele com os dois
        primeiros elementos. Coloca ele na posição correta caso seja
        necessário.
        - Isso é repetido até que o array inteiro esteja ordenado.
*/

void insertion_sort(int *vetor, int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = vetor[i];

        int j;

        for(j = i - 1; j >= 0 && vetor[j] > key; j--)
        {
            vetor[j + 1] = vetor[j];
        }

        vetor[j + 1] = key;

    }
}
