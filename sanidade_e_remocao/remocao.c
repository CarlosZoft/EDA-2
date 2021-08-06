#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  unsigned long  curr, prev, next;
  int status;
} no;

no PTR1,PTR2;
no list[250000];
int lengthOfList = 0;
int tipo = 0;

long int binarySearch(no *v, int size, unsigned long element, int tipo) {
  int left = -1, right = size;
  unsigned long valor;

  while(left < right - 1){
    int half = (left + right) / 2;
    valor = (tipo == 1) ? v[half].curr : v[half].next;
    if(valor < element) left = half;
    else right = half;
  }
  valor = (tipo == 1) ? v[right].curr : v[right].next;
  if(valor == element){
    list[lengthOfList++] = v[right];
    return right;
  } 
  else return -1;
}

void merge(no *v, int left, int half, int right){
  no *arr = malloc(sizeof(no) * (right - left + 1));

  int i = left, j = half + 1,
  pos = 0;

  while(i <= half && j <= right){
    //printf("tipo = %d\n", tipo);
    if(tipo == 1 && v[i].curr <= v[j].curr){
        arr[pos++] = v[i++];
    }
    else if(tipo == 0 && v[i].next <= v[j].next){
        arr[pos++] = v[i++];
    }
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

void mergeSort(no *v, int left, int right){
  if(left < right){
    int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half+1, right);
    merge(v, left, half, right);
  }
}
void reverse(no *arr, int n){
    no aux[n];
    for (int i = 0; i < n; i++) {
      aux[n - 1 - i] = arr[i];
    }
 
    for (int i = 0; i < n; i++) {
      arr[i] = aux[i];
    }
}
int main () {
  no v[250000];
  int i = 0;
  
  for(i = 0 ; i < 17; i++){
    scanf(" %lx %lx %lx", &v[i].curr, &v[i].prev, &v[i].next);
    if(i == 0)PTR1 = v[i];
    else if (i == 1)PTR2 = v[i];  
  }
  tipo = 0;
  mergeSort(v, 0, i-1);
  printf("\nsort 1\n");
  for(i = 0 ; i < 17; i++)
    printf("%lx %lx %lx\n", v[i].curr, v[i].prev, v[i].next);
  printf("\n");
  no start = PTR1;
  long int result = 1;

  //antes de PTR1
  while(result != -1){
    result = binarySearch(v, i, start.curr, 0);
    start = v[result];
  }
  reverse(list, lengthOfList);
  list[lengthOfList++] = PTR1;  
  start = PTR1;
  result = 1;

  tipo = 1;
  mergeSort(v, 0, i-1);
  printf("sort 2\n");
  for(i = 0 ; i < 17; i++)
    printf("%lx %lx %lx\n", v[i].curr, v[i].prev, v[i].next);
  printf("\n");
  //depois de PTR1
  while(result != -1){
    result = binarySearch(v, i, start.next, 1);
    start = v[result];
    //printf("prev = %lx, result = %ld\n", start.next, result);
  }


  for(int j = 0 ; j < lengthOfList; ++j)
    printf("%lx %lx %lx\n", list[j].curr, list[j].prev, list[j].next);

  return 0;
}