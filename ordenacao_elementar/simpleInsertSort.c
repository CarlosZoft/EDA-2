#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}

void insertionSort(int *v, int l, int r){
  for(int j = l+1; j < r; j++){
    for (int h = j; h > l; h--){
      if (less(v[h], v[h-1])){
        exch(v[h], v[h - 1])
      }
    }
  }
} 


int main () {

  int v[1000];
  
  int i = 0;
  while(scanf("%d", &v[i]) != EOF)i++;
  
  //sort
  insertionSort(v, 0, i);

  //output
  for(int out = 0; out < i ; out++)
    (!out) ? 
    printf("%d", v[out]) :
    printf(" %d", v[out]);
  
  printf("\n");

  return 0;
}