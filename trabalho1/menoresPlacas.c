#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(x,y) (key(x)<key(y))
#define eq(x,y) (key(x)==key(y))
#define exch(x,y){ Item t=x;x=y;y=t; }
#define cmpexch(x,y){ if(less(y,x))exch(x,y); }

typedef long int Item; 

int separa(Item *arrayPlacas, int l, int r) {
    Item c = arrayPlacas[r];
    int j=l, k;
    for(k=l; k<r; k++){
        if(less(arrayPlacas[k], c)) {
          exch(arrayPlacas[k], arrayPlacas[j]);
          j++;
        }
    }
    exch(arrayPlacas[k], arrayPlacas[j]);
    return j;
}
void quickselect(Item *v, int l, int r, int n) {
  if (r <= l)return;

  int qtdPlacas = separa(v, l, r);
  if (qtdPlacas > n) quickselect(v, l, qtdPlacas-1, n);
  else if (qtdPlacas < n)quickselect(v, qtdPlacas+1, r, n);
}

void quickSortM3(Item *arrayPlacas, int l, int r) {
  if(r<=l)return;

  cmpexch(arrayPlacas[(l+r)/2], arrayPlacas[r]);
  cmpexch(arrayPlacas[l], arrayPlacas[(l+r)/2]);
  cmpexch(arrayPlacas[r], arrayPlacas[(l+r)/2]);

  int j = separa(arrayPlacas, l,r);
  quickSortM3(arrayPlacas, l, j-1);
  quickSortM3(arrayPlacas, j+1, r);
}

int main() {
  long int codigo, nota, qtdPlacas=0;

  Item *arrayPlacas = malloc(137 * sizeof(Item));
  while(scanf("%ld %ld", &codigo, &nota) == 2) {
    if(qtdPlacas >= qtdPlacas % 137)
      arrayPlacas = realloc(arrayPlacas, sizeof(Item) * (qtdPlacas + 137));
    
    if(codigo == 1)arrayPlacas[qtdPlacas++] = nota;

    else if(codigo == 2){
      quickselect(arrayPlacas, 0, qtdPlacas-1, nota-1);
      quickSortM3(arrayPlacas, 0, nota-1);     

      for(long int index = 0; index < nota; index++)
        printf("%ld%c",  arrayPlacas[index], index != nota - 1 ? ' ': '\n');
    }
  }

  free(arrayPlacas);

  return 0;
}
