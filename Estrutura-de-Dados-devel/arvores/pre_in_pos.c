#include <stdio.h>
#include <stdlib.h>

typedef struct reg{
    int chave;
    struct reg *esq, *dir;
} no;

typedef no *arvore;


void pre_order(arvore r){
    if(r != NULL){
        printf("%d ",r->chave);
        pre_order(r->esq);
        pre_order(r->dir);
    }
}

void in_order(arvore r){
    if(r != NULL){
        in_order(r->esq);
        printf("%d ",r->chave);
        in_order(r->dir);
    }
}

void pos_order(arvore r){
    if(r != NULL){
        pos_order(r->esq);
        pos_order(r->dir);
        printf("%d ",r->chave);
    }
}

arvore insere(arvore r, no *novo){
    if(r == NULL) return novo;
    if(r->chave > novo->chave){
        r->esq = insere(r->esq,novo);
    } 
    else{
        r->dir = insere(r->dir, novo);
    }
    return r;c
}

int main(int argc, char const *argv[])
{
    int x,n;

    arvore r = NULL;

    while (scanf("%d",&n)==1)
    {
        no *novo;
        novo = malloc(sizeof(no));
        novo->chave = n;
        novo->esq = novo->dir = NULL;
        r = insere(r,novo);
    }

    pre_order(r);
    printf(".\n");

    in_order(r);
    printf(".\n");

    pos_order(r);
    printf(".\n");
    
    return 0;
}

