#include <stdio.h>
#include <stdlib.h>
 
typedef struct celula {
  char dado[27];
  struct celula *prox;
} celula;

celula *cria_fila () {
  celula *ptr = malloc (sizeof (celula));
  ptr->prox = ptr;
  return ptr;
}

void enfileira (celula **f, char *x){
    celula *ptr = malloc(sizeof(celula));
    ptr ->prox = (*f) -> prox;
    (*f) -> prox = ptr;
    (*f) -> dado = x;
    *f = ptr;
}

int desenfileira (celula *f, char *y){
    celula *lixo = f -> prox;
    if(lixo == f) return 0;
    *y  = lixo -> dado;
    f -> prox = lixo -> prox;
    free(lixo);
    
    return 1; 
}

void imprime_rec (celula *le){
	
	celula *elem = le->prox;
  if(elem != NULL){
		printf("%d -> ", elem ->dado);
		imprime_rec(elem);
  }
  else
    printf("NULL\n");
  
}

int main () {
  celula *filaShows = cria_fila();

  enfileira(filaShows, "pinoquio");

  enfileira(filaShows, "irmao");

  enfileira(filaShows, "violao");

  imprime_rec(filaShows);

  return 0;

}