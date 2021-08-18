#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A)(A)
#define less(A,B) (Key(A)<Key(B))
#define lesseq(A,B) (Key(A)<=Key(B))
#define exch(A,B) {Item t = A; A=B; B=t;}
#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

int deleteEquals(Item *v, Item size) { 
    Item *aux = malloc(sizeof(Item) * size + 1);
    int j = 0; 
 
    for(int i = 0; i < size; i++) 
      if (v[i] != v[i + 1]) 
        aux[j++] = v[i]; 

    // set new array;  
    for (int i = 0; i < j; i++) 
      v[i] = aux[i]; 
 
    return j; 
}

int separa(Item *V, int l, int r){
    Item elementRight = V[r];
    int indexElement = l;
    for(int i=l ; i<r ;i++)
        if(lesseq(V[i], elementRight)){
          exch(V[i],V[indexElement]);
          indexElement++;
        }
            
    exch(V[indexElement], V[r]);
    return indexElement;
}

void quickSortM3(Item *V, int l, int r){
    if(r<=l) return;
    cmpexch(V[(r+l)/2],V[r]);
    cmpexch(V[l],V[(r+l)/2]);
    cmpexch(V[r],V[(r+l)/2]);

    int j = separa(V,l,r);
    quickSortM3(V,l,j-1);
    quickSortM3(V,j+1,r);
}

int main () {
  int qtdTeste;
  scanf("%d", &qtdTeste);

  int *array = malloc(sizeof(int) * ((qtdTeste/2) + qtdTeste) + 1);

  for(int i = 0; i < qtdTeste; i++)
    scanf("%d", &array[i]);

  quickSortM3(array, 0, qtdTeste - 1);
  qtdTeste = deleteEquals(array, qtdTeste);
  
  if(qtdTeste % 2) array[qtdTeste++] = 1000000000;

  int auxIndex = qtdTeste;
  for(int i = 1; i < qtdTeste; i+=2)
    array[auxIndex++] = array[i] + array[i-1];

  quickSortM3(array, 0, auxIndex - 1);
  qtdTeste = deleteEquals(array, auxIndex);


  for(int i = 0 ; i < qtdTeste; i+=4)
    printf("%d\n", array[i]);

  printf("Elementos: %d\n", qtdTeste);

  free(array);
  return 0;
}