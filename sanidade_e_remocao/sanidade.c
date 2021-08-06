#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  unsigned long long curr, prev, next;
  int status;
} no;

no PTR1,PTR2;
no list[250001];
long long int lengthOfList = 0;
int tipo = 0;

long long int binarySearch1(no *v, unsigned long int size, unsigned long number) {
  long long int left = -1, right = size;

  while(left < right - 1){
    long long int half = (left + right) / 2;
    if(v[half].curr < number) left = half;
    else right = half;
  }
  return right;
}

long long int binarySearch(no *v, long long int size, unsigned long long element) {
  int left = -1, right = size;
  unsigned long long valor;

  while(left < right - 1){
    long long int half = (left + right) / 2;
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

void merge(no *v, long long int left, long long int half, long long int right){
  no *arr = malloc(sizeof(no) * (right - left + 1));

  long long int i = left, j = half + 1,
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
  for(i = left ; i <= right; ++i)
    v[i] = arr[i-left];

  free(arr);
}

void mergeSort(no *v, long long int left, long long int right){
  if(left < right){
    long long int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half+1, right);
    merge(v, left, half, right);
  }
}
void reverse(no *arr){
    long long int n = lengthOfList;
    no aux[n];
    for (long long int i = 0; i < n; i++) {
      aux[n - 1 - i] = arr[i];
    }
 
    for (long long int i = 0; i < n; i++) {
      arr[i] = aux[i];
    }
}
void verifica(){
  long long int indexPTR1 = binarySearch1(list, lengthOfList, PTR1.curr);
  long long int indexPTR2 = binarySearch1(list, lengthOfList, PTR2.curr);
  //printf("PTR1 = %d, PTR2 = %d, curr = %lx\n", indexPTR1, indexPTR2, PTR2.curr);
  if((indexPTR1 > indexPTR2) && 
      (
           (list[indexPTR2].next != list[indexPTR1].curr) 
        || (list[indexPTR2].curr != list[indexPTR1].prev)
        || (indexPTR1 - indexPTR2 == 1)

      )
  ){
    printf("insana\n");
        return;
  }
  else 
    for(long long int i = indexPTR1 + 1; i <= indexPTR2; i++){
      if(list[i-1].next != list[i].curr 
      || list[i-1].curr != list[i].prev){
        printf("insana\n");
        return;
      }
    }

  printf("sana\n");
}
int main () {
  no v[260000];
  long long int i = 0;

  while(scanf(" %llx %llx %llx", &v[i].curr, &v[i].prev, &v[i].next)!= EOF){
    if(i == 0)PTR1 = v[i];
    else if (i == 1)PTR2 = v[i]; 
    i++;
  }
  tipo = 0;
  mergeSort(v, 0, i-1);
  no start = PTR1;
  long long int result = 1;

  //antes de PTR1
  while(result != -1){
    result = binarySearch(v, i, start.curr);
    start = v[result];
  }
  reverse(list);
  list[lengthOfList++] = PTR1;

  start = PTR1;
  result = tipo = 1;
  mergeSort(v, 0, i-1);
  //depois de PTR1
  while(result != -1){
    result = binarySearch(v, i, start.next);
    start = v[result];
  }

//for(int j = 0 ; j < lengthOfList; ++j)
 //printf("%llx %llx %llx\n", list[j].curr, list[j].prev, list[j].next);
  verifica();
  return 0;
}