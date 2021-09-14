#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int dado;
  struct no *esq, *dir;
} no;

void pre_ordem(no *le)
{
  if (le == NULL)
    return;

  printf("%d ", le->dado);
  pre_ordem(le->esq);
  pre_ordem(le->dir);
}

void em_ordem(no *le)
{
  if (le == NULL)
    return;
  em_ordem(le->esq);
  printf("%d ", le->dado);
  em_ordem(le->dir);
}

void pos_ordem(no *le)
{
  if (le == NULL)
    return;
  pos_ordem(le->esq);
  pos_ordem(le->dir);
  printf("%d ", le->dado);
}

no *insere(no *le, no *arvore)
{
  if (le == NULL)
    return arvore;
  if (le->dado > arvore->dado)
    le->esq = insere(le->esq, arvore);
  else
    le->dir = insere(le->dir, arvore);
  return le;
}

int main()
{
  int dado;

  no *raiz = NULL;

  while (scanf("%d", &dado) == 1)
  {
    no *arvore;
    arvore = malloc(sizeof(no));
    arvore->dado = dado;
    arvore->esq = arvore->dir = NULL;
    raiz = insere(raiz, arvore);
  }

  pre_ordem(raiz);
  printf(".\n");
  em_ordem(raiz);
  printf(".\n");
  pos_ordem(raiz);
  printf(".\n");

  return 0;
}
