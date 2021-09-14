#include <stdio.h>
#include <stdlib.h>

typedef struct no
{ // Arvóre
  int dado;
  struct no *esq, *dir;
} no;

typedef struct reg
{
  no *conteudo;
  struct reg *prox;
} celula;

celula *pi;

void criapilha(void)
{
  pi = malloc(sizeof(celula)); // cabeça
  pi->prox = NULL;
}

void empilha(no *y)
{
  if (pi == NULL)
    return;
  celula *nova;
  nova = malloc(sizeof(celula));
  nova->conteudo = y;
  nova->prox = pi->prox;
  pi->prox = nova;
}

no *desempilha(void)
{
  celula *p;
  p = pi->prox;
  no *x = p->conteudo;
  pi->prox = p->prox;
  free(p);
  return x;
}

int pilhavazia()
{
  if (pi->prox == NULL)
    return 1;
  else
    return 0;
}

void liberapilha()
{
  no *x;
  while (!pilhavazia())
  {
    x = desempilha();
  }
  free(x);
}

void pre_ordem(no *raiz)
{
  criapilha();
  if (raiz == NULL)
    return;
  else
  {
    empilha(raiz);
    no *x;
    int i = 0;
    while (1)
    {
      x = desempilha();
      if (x != NULL)
      {
        printf("%d ", x->dado);
        empilha(x);
        empilha(x->esq);
      }
      else
      {
        if (pilhavazia())
          break;
        x = desempilha();
        empilha(x->dir);
      }
    }
    printf("\n");
  }
}