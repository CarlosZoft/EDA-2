#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct no {
  char cityName[27];
  struct no *prox;
} no;

no *head, *filaShows;

void print(no *le){
  no *ptr = le;
  if(ptr != NULL){
    printf("%s\n", ptr->cityName);
    print(ptr->prox); 
  }
}

void makeList(no *city) {
  no *end = city;

  while (end->prox != NULL)end = end -> prox;

  for (no *list = city; list->prox != NULL; list = list -> prox){
    if (
      list -> cityName[strlen(list->cityName) - 1] == 
      list -> prox->cityName[0] + 32
    ){
      end -> prox = list -> prox;
      list -> prox = list -> prox->prox;
      end -> prox->prox = NULL;

      end = end->prox;
    }
  }
}

void scan(no *head, no *fila){
  no *ptr = malloc(sizeof(no));
  int i;
  for(
    i = scanf(" %s", fila->cityName);
    i == 1;
    ptr = malloc(sizeof(no))
  ){
    i = scanf(" %s", ptr->cityName);
    ptr -> prox = NULL;
    fila -> prox = ptr;
    if(i != 1){
      fila->prox = NULL;
      break;
    }
    else fila = fila->prox;
  }
  fila = head;

  filaShows = fila;
}

int main () {
  filaShows = head = malloc(sizeof(no));

  scan(head, filaShows);
  
  makeList(filaShows);

  print(filaShows);
  
  return 0;
}