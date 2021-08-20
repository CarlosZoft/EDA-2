#include <stdio.h>
#include <stdlib.h>

#define exch(a, b) {int t = a; a = b; b = t;}
#define less(a,b) (a < b) 

size_t asize=0;
size_t tmpsize=0;

size_t parent(int i) { return i/2; }
size_t left(int i) { return 2 * i; }
size_t right(int i) { return 2 * i + 1; }
size_t size() { return asize; }

void insert(int *arr, int x) {
    arr[asize + 1] = x;

    // pos do valor que acabou de entrar
    int i = asize + 1;
    int p = parent(i);

    while(p &&  less(arr[i], arr[p])) {
        exch(arr[p], arr[i]);
        i = p;
        p = parent(i);
    }
    asize++;
}

int pop(int *arr) {
    int x = arr[1], i=1;
    
    exch(arr[1], arr[asize]);
    asize--;
    
    int n = left(i) > asize ? 0 : left(i);

    while(n != 0) {   
        int r = right(i) > asize ? 0 : right(i);
        if(r != 0 && arr[r] < arr[n]) {
            n = r;
        } else if(arr[i] > arr[n]) {
            exch(arr[i], arr[n]);
            i = n;
            n = left(i) > asize ? 0 : left(i);
        } else {
            n = 0;
        }
    }

    return x;
}

void printMinors(int *arr, int *tmp, int k){
    int tam = k;

    while(k--) {
        tmp[tmpsize] = pop(arr);
        printf("%d%c", tmp[tmpsize], tmpsize + 1 == tam ? '\n' : ' ');
        tmpsize++;
    }

    for(int i=0; i<tmpsize; i++) {
        insert(arr, tmp[i]);
    }
    tmpsize=0;
}

int main() {

    int i=0;
    int num, x;

    int *arr = malloc(sizeof(int) * 8); 
    int *tmp = malloc(sizeof(int) * 100); 

    while(scanf("%d %d", &num, &x) != EOF){
      if(i >= i%8){
         arr = realloc(arr, sizeof(int)*(i+8));
      }

      if(num == 1){
        insert(arr, x);
        i++;
      }
      else if(num == 2) printMinors(arr, tmp, x);
    }

  free(arr);
  free(tmp);

    return 0;
}