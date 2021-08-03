#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *v, int size, int number) {
  int left = -1, right = size;

  while(left < right - 1){
    int half = (left + right) / 2;
    if(v[half] < number) left = half;
    else right = half;
  }
  return right;
}

int main () {

  int N, M;

  scanf("%d %d", &N, &M);
  int *v = malloc((sizeof (int)) * N);

  for(int i = 0; i < N; i++)
    scanf("%d", &v[i]);

  int aux;
  for(int i = 0; i < M; i++){
    scanf("%d", &aux);
    printf("%d\n", binarySearch(v, N, aux));
  }  

  return 0;
}