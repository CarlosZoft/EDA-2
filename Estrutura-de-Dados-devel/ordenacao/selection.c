#include <stdio.h>
#include <stdlib.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void selectionSort(Item *V, int l, int r){
    if(l==r)return;

    int min = l;

    for(int j=l+1; j<=r;j++){
        if(less(V[j],V[min])){
            min = j;
        }
    }
    exch(V[min],V[l]);
    selectionSort(V,l+1,r);
}

void selectionSortI(Item *V, int l, int r){

    for(int i=l;i<=r;i++){

        int min = i;

        for(int j=l+1; j<=r;j++){
            if(less(V[j],V[min])){
                min = j;
            }
        }
        exch(V[min],V[i]);
    }
}

int main(int argc, char const *argv[])
{
    Item *vetor,n;
    int total;

    scanf("%d", &total);

    vetor = malloc(sizeof(Item)*total);

    for(int i=0;i<total;i++){
        scanf("%ld", &n);
        vetor[i]=n;
    }

    selectionSort(vetor,0,total-1);

    for(int i=0;i<total;i++){
        if(i+1==total){
        printf("%ld\n", vetor[i]);
        }else{
        printf("%ld ", vetor[i]);
        }
    }

    free(vetor);
    return 0;
}
