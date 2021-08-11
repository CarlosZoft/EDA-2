#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vetor_m[2000];
int vetor_n[2000][2000];

int main(int argc, char const *argv[])
{
    int n, m, j, posi, lugares, num_aux;
    scanf("%d", &n); //vizinhanças
    int *num = malloc(n * sizeof(int));
    scanf("%d", &m); //lugares que ele ja esteve
    scanf("%d", &j); //lugar que ele vai visitar
    // int *vetor_m = malloc(2000 * sizeof(int));
    // int **vetor_n = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        for (int k = 0; k < num[i]; k++)
        {
            scanf("%d", &vetor_n[i][k]);
        }
    }
    for (int i = 0; i < 2000; i++)
    {
        vetor_m[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num_aux);
        vetor_m[num_aux] = num_aux;
    }

    for (int i = 0; i < j; i++)
    {
        scanf("%d", &lugares);
        posi = 0;
        if (vetor_m[lugares] == lugares)
        {
            printf("Eu vou estar la\n");
        }
        else
        {
            if (lugares < n)
            {
                for (int k = 0; k < num[lugares]; k++)
                {
                    if (vetor_m[vetor_n[lugares][k]] != -1)
                    {
                        printf("Eu vou estar la\n");
                        posi = 1;
                        break;
                    }
                }
                if (posi == 0)
                    printf("Nao vou estar la\n");
            }
            else
            {
                printf("Nao vou estar la\n");
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     free(vetor_n[i]);
    // }
    // free(vetor_n);
    // free(vetor_m);
    // free(num);

    return 0;
}