#include <stdio.h>
#include <stdlib.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void bubbleSort(Item *V, int l, int r){
    for(int i=0;i<r;i++)
        for(int j=l; j<r;j++)
            cmpexch(V[j],V[j+1]);
}

void bubbleSortO(Item *V, int l, int r){
    int troca = 0;
    for(int i=0;i<r;i++){
        for(int j=l; j<r;j++){
            if(less(V[j+1],V[j])){
                exch(V[j+1],V[j]);
                troca=1;
            }
        }
        if(troca==0)
            break;
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

    bubbleSortO(vetor,0,total-1);

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
