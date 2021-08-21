#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct celula {
  char dado[27];
  struct celula *prox;
} celula;

celula *cria_fila () {
  celula *ptr = malloc (sizeof (celula));
  ptr->prox = ptr;
  return ptr;
}

void enfileira (celula *f, char *x){
    celula *ptr = malloc(sizeof(celula));
     strcpy( ptr->dado , x);
      ptr ->prox = f -> prox;
        f -> prox = ptr;
}
celula *enfileira1 (celula *fila, char *x){
    celula *ptr = malloc(sizeof(celula));
    ptr -> prox = fila -> prox;
    fila->prox = ptr;
    strcpy( fila -> dado, x);
    return ptr;
}

int desenfileira (celula *f, char *y){
    celula *lixo = f -> prox;
    if(lixo == f) return 0;
    strcpy( y , lixo -> dado);
    f -> prox = lixo -> prox;
    free(lixo);
    
    return 1; 
}

void imprime1(celula *le){
  celula *outroptr= le->prox;
  while(outroptr!=le){
    printf("%s ", outroptr->dado);
    outroptr=outroptr->prox;
  }
  printf("\n");
}

int main () {
  celula *filaShows = cria_fila();

  char cidadeShow[27];
  while(scanf(" %s", cidadeShow) != EOF)
    filaShows = enfileira1(filaShows, cidadeShow);
  
  celula *PTR = filaShows -> prox;

  while(PTR != NULL){
    if(PTR -> dado[strlen(PTR -> dado) - 1] == PTR -> prox -> dado[0] - 32){

    }
  }


  imprime1(filaShows);

  return 0;

}