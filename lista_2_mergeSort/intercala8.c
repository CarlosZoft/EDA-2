#include <stdio.h>
#include <stdlib.h>

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
  long long int len = 0, i = 0, qtdArray = 8,
  *arr = malloc(10 *sizeof(long long int) );

  while(qtdArray != 0){
    scanf("%lld", &len);
    arr = (long long int*)realloc(arr, (i + len)  * sizeof(long long int));
    while(len != 0){
      scanf("%lld", &arr[i]);
      len--;
      i++;
    }
    qtdArray--;
  } 
  mergeSort(arr, 0, i-1);

  for(long long int j = 0; j < i ; ++j)
    (j != i-1) ? printf("%lld ", arr[j]) : printf("%lld\n", arr[j]);
  
  free(arr);
  return 0;
}