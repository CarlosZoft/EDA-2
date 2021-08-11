#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;




void inicia(node *FILA)
{
 FILA->prox = NULL;
}

int vazia(node *FILA)
{
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca(int dado)
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  novo->num = dado;
  return novo;
 }
}

void insere(node *FILA, int dado)
{
 node *novo=aloca(dado);
 novo->prox = NULL;

 if(vazia(FILA))
  FILA->prox=novo;
 else{
  node *tmp = FILA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
}


int retira(node *FILA)
{
  node *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  return tmp->num;

}


void exibe(node *FILA)
{
 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = FILA->prox;
 printf("Fila :");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}

void libera(node *FILA)
{
 if(!vazia(FILA)){
  node *proxNode,
     *atual;

  atual = FILA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}


int main(void)
{
 node *FILA = (node *) malloc(sizeof(node));
 if(!FILA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(FILA);
 int v;
 scanf("%d", &v);

    for(int i=0;i<v;i++){
        insere(FILA,i+1);
    }

    while (!vazia(FILA))
    {
        int x = retira(FILA);
        printf("%d ", x);
    }
    

 free(FILA);
 return 0;
 }
}



