#include <stdio.h>
#include <stdlib.h>

struct indices
{
    int antes;
    int valor;
};
typedef struct indices pos;

void merge(pos *v, int left, int half, int right){
  pos *arr = malloc(sizeof(pos) * (right - left + 1));

  int i = left, j = half + 1,
  pos = 0;

  while(i <= half && j <= right){
    if(v[i].valor < v[j].valor)
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

void mergeSort(pos *v, int left, int right){
  if(left < right){
    int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half+1, right);
    merge(v, left, half, right);
  }
}

int binarySearch(pos *v, int size, int number) {
  int left = -1, right = size;

  while(left < right - 1){
    int half = (left + right) / 2;
    if(v[half].valor < number) left = half;
    else right = half;
  }
  return (v[right].valor == number) ? v[right].antes : -1;
}

int main(void)
{
    pos *aux;
    int size, sizeArray, sizeBusca, number, flag = 0;
    scanf("%d %d", &sizeArray, &sizeBusca);
    aux = malloc(sizeArray * sizeof(pos));

    for (size = 0; size < sizeArray; size++, aux[size].antes = size)
    {
        scanf("%d", &aux[size].valor);
    }

    mergeSort(aux,0,sizeArray-1);

    for (int i = 0; i < sizeBusca; i++)
    {
        scanf("%d", &number);
        printf("%d\n", binarySearch(aux, sizeArray, number));
    }
    return 0;
}