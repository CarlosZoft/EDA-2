#include <stdio.h>
#include <stdlib.h>
typedef struct instruction {
  int code;
  char word[17];
} table;

#define key(A) (A)
#define less(A,B) (key(A).code < key(B).code)
#define exch(A,B) {table temp = A; A = B; B = temp;}
#define cmpexch(A,B){if(less(A,B))exch(A,B);}

void insertionSort(table *v, int l, int r){
  for(int i = r - 1; i > l; i--){
    cmpexch(v[i], v[i - 1]);
  }
  for(int i = l + 2; i < r ; i++){
    int j = i;
    table tmp = v[j];
    while(less(tmp, v[j - 1])){
      v[j] = v[j - 1];
      j--;
    }
    v[j] = tmp;
  }
}

int binarySearch (table *v, int size, int code) {
  int left = -1, right = size;

  while(left < right - 1){
    int half = (left + right) / 2;
    if(v[half].code < code) left = half ;
    else right = half ;
  }
  return (v[right].code == code) ? right : -1;
}


int main () {
  table v[15000];
  
  int inputElementTable; 
  scanf("%d", &inputElementTable);
  
  for(int i = 0; i < inputElementTable; i++)
    scanf("%d %s", &v[i].code, v[i].word);
   
  //sort
  insertionSort(v, 0, inputElementTable);

  int inputCodeElement;
  while(scanf("%d", &inputCodeElement) != EOF){
    int indexOfElement = binarySearch(v, inputElementTable, inputCodeElement);
    
    (indexOfElement == -1) ? printf("undefined\n") : printf("%s\n", v[indexOfElement].word);
  }

  return 0;
}