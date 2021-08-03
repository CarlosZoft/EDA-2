#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int left, int half, int right){
  int *arr = malloc(sizeof(int) * (right - left + 1));

  int i = left, j = half + 1,
  pos = 0;

  while(i <= half && j <= right){
    if(v[i] < v[j])
      arr[pos++] = v[i++];
    else 
      arr[pos++] = v[j++];
  }
  while(i <= half)
    arr[pos++] = v[i++];
  while(j <= right)
    arr[pos++] = v[j++];
  
  // Merge
  for(int i = left ; i <= right; ++i)
    v[i] = arr[i-left];

  free(arr);
}


void mergeSort(int *v, int left, int right){
  if(left < right){
    int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half+1, right);
    merge(v, left, half, right);
  }
}


int main () {

  int qtd;
  scanf("%d", &qtd);
  int *v = malloc(sizeof(int) * qtd);
  for(int i = 0; i < qtd; ++i)
    scanf("%d", &v[i]);
  //sort
  mergeSort(v, 0, qtd-1);

  for(int i = 0; i < qtd; ++i)
    (i) ? 
    printf(" %d", v[i]):
    printf("%d", v[i]);


  printf("\n");


  return 0;
}