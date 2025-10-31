void shell_sort(int *vetor, int n, int *vetorGaps, int numGaps)
{
    int pos;
    int i;
    int j;
    int span;
    int chave;

    for(pos = 0; pos < numGaps; pos++)
    {
        span = vetorGaps[pos];

        for(i = span; i < n; i++)
        {
            chave = vetor[i];

            for(j = i - span; j >= 0 && vetor[j] > chave; j -= span)
            {
                vetor[j + span] = vetor[j];
            }

            vetor[j + span] = chave;
        }
    }
}
