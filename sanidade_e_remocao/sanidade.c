#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char dado;
  struct celula *next,*prev;
} celula;

celula *PTR1, *PTR2;
int length = 0;

celula *newCelula(char x){
  celula *new = malloc(sizeof(celula));
  new->dado = x;
  new->prev = new->next = NULL;
  return new;
}
void insertBegin (char x) {
  celula *new = newCelula(x);  

	if(PTR1 != NULL){
    celula *current;
		current = PTR1;
		new->next = current;
		current->prev = new;
		PTR1 = new;
  }
	else PTR1 = PTR2 = new;
	length++;
}
void insertEnd(char x){
  celula *new = newCelula(x); 

	if(PTR1 != NULL){
    celula *current;
		current = PTR2;
		new->prev = current;
		current->next = new;
		PTR2 = new;
  }
  else PTR1 = PTR2 = new;

	length++;
}
void imprime () {
  celula *ptr = PTR1;
  
  while (ptr) {
    printf ("%c", ptr->dado);
    printf (" -> ");
    ptr = ptr->next;
  }
  printf ("NULL\n");
}

int main () {

  PTR1 = PTR2 = NULL;
  char current,previous,later;

  for(int i = 0; i < 2; i++){
    scanf(" %c %c %c", &current, &previous, &later);
  
    insertBegin(later);
    insertBegin(current);
    insertBegin(previous);
    printf("%c %c %c\n", later, current, previous);
  }
  
  //while(scanf(" %c %c %c", &later, &current, &previous) != EOF){

  //} 
  imprime();
  printf("%d\n", length );
  return 0;
}