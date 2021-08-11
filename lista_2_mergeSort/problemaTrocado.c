#include <stdio.h>
#include <stdlib.h>

int main () {
  int arr[12331];
  int index = 0;
  do {
    scanf("%d", &arr[index]);
  }while(arr[index++] != 42);

  for(int i = 0 ; i < index - 1; ++i){
    printf("%d\n", arr[i]);
  }
  return 0;
}