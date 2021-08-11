#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n,x,soma_d, soma=0, *valor_contas;

    scanf("%d", &n);

    valor_contas = malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        scanf("%d", &x);
        valor_contas[i] = x;
        soma+=x;
    }
    scanf("%d", &soma_d);

    if(soma_d==soma) printf("Acertou\n");
    else printf("Errou\n");

    return 0;
}
