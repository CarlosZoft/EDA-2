#include <stdio.h>
#include <stdlib.h>

int binarySearch (long long int *v, long int size, long long int element) {
  long int left = -1, right = size;
  while(left < right - 1){
    long int half = (left+right)/2;
    if(v[half] < element) left = half;
    else right = half;
  }
  return (v[right] == element) ? 1 : 0;
}

void merge(long long int *v, long long int left, long long int half, long long int right){
  long long int *arr = malloc(sizeof(long long int) * (right - left + 1));

  long long int i = left, j = half + 1,
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
  for(i = left ; i <= right; ++i)
    v[i] = arr[i-left];

  free(arr);
}


void mergeSort(long long int *v, long long int left, long long int right){
  if(left < right){
    long long int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half+1, right);
    merge(v, left, half, right);
  }
}

int main () {

  long int lengthBannedNumbers;

  scanf("%ld", &lengthBannedNumbers);

  long long int *arrayBannedNumbers = malloc(
      lengthBannedNumbers * sizeof(long long int)
    );


  for(long int i = 0; i < lengthBannedNumbers; i++)
    scanf("%lld", &arrayBannedNumbers[i]);

  mergeSort(arrayBannedNumbers, 0, lengthBannedNumbers - 1);

  long long int possibleBannedNumber;
  while(scanf("%lld", &possibleBannedNumber) != EOF)
    (binarySearch(arrayBannedNumbers,lengthBannedNumbers,possibleBannedNumber)) ? 
      printf("sim\n") : 
      printf("nao\n");


  return 0;
}