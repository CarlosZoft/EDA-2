#include <stdio.h>
#include <stdlib.h>

typedef struct _item
{
    int chave;
    char c;
}Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A.chave) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}


int main(int argc, char const *argv[])
{
    int n, total=0;
    char c, *msg;
    int inicio = __INT_MAX__, fim = 0;

    msg = malloc(sizeof(char)*2147483648);

    while(scanf("%d %c", &n, &c)==2){
        msg[n]=c;
        if(n<inicio){
            inicio=n;
        }
        if(n>fim){
            fim=n;
        }
    }

    for(int i=inicio;i<=fim;i++){
        printf("%c",msg[i]);
    }
    printf("\n");

    return 0;
}
