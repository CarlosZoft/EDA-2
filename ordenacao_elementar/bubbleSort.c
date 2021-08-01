#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {int temp = A; A = B; B = temp;}

int main () {

  int v[1000];
  
  int i = 0;
  while(scanf("%d", &v[i]) != EOF)i++;

  //sort
  for(int j = 0; j < i - 1; j++){
    for (int h = 0; h < i - 1; h++){
      if (less(v[h + 1], v[h])){
        exch(v[h], v[h + 1])
      }
    }
  }
  
  //output
  for(int out = 0; out < i ; out++)
    (!out) ? 
    printf("%d", v[out]) :
    printf(" %d", v[out]);
  
  printf("\n");

  return 0;
}