/*
    A explica��o do algoritmo � a seguinte:
        - N�s come�amos do segundo elemento do vetor,
        pois assume-se que primeiro j� est� ordenado.
        - Comparamos o segundo elemento com o primeiro elemento.
        Se o segundo elemento � menor, voc� troca os dois de posi��o.
        - Vai para o terceiro elemento e compara ele com os dois
        primeiros elementos. Coloca ele na posi��o correta caso seja
        necess�rio.
        - Isso � repetido at� que o array inteiro esteja ordenado.
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
