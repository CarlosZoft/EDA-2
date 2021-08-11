#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, m, j, posi, num_aux, lugar;
    scanf("%d", &n); //vizinhanças
    int *num = malloc(n * sizeof(int));
    scanf("%d", &m); //lugares que ele ja esteve
    scanf("%d", &j); //lugar que ele vai visitar
    int *vetor_m = malloc(2000 * sizeof(int));
    for (int i = 0; i < 2000; i++)
    {
        vetor_m[i] = -1;
    }
    int **vetor_n = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        for (int k = 0; k < num[i]; k++)
        {
            vetor_n[i] = malloc(num[i] * sizeof(int));
        }
        for (int k = 0; k < num[i]; k++)
        {
            scanf("%d", &vetor_n[i][k]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num_aux);
        vetor_m[num_aux] = num_aux;
        if (num_aux < n)
        {
            for (int j = 0; j < num[num_aux]; j++)
            {
                //para cada valor da coluna insira no vetor_m
                vetor_m[vetor_n[num_aux][j]] = vetor_n[num_aux][j];
            }
        }
    }
    for (int i = 0; i < j; i++)
    {
        scanf("%d", &lugar);
        if (vetor_m[lugar] == lugar)
        {
            printf("Eu vou estar la\n");
        }
        else
        {
            printf("Nao vou estar la\n");
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(vetor_n[i]);
    }
    free(vetor_n);
    free(vetor_m);
    free(num);

    return 0;
}