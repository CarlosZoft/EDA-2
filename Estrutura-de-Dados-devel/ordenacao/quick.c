#include <stdio.h>
#include <stdlib.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}


int separa(Item *V, int l, int r){
    Item c = V[r];
    int j=l;
    for(int k=l;k<r;k++){
        if(lesseq(V[k],c)){
            exch(V[k],V[j]);
            j++;
        }
    }
    exch(V[j],V[r]);
    return j;
}

void quickSort(Item *V, int l, int r){
    int j;
    if(r<=l) return;
    j = separa(V,l,r);
    quickSort(V,l,j-1);
    quickSort(V,j+1,r);
}

void quickSortMediana(Item *V, int l, int r){
    int j;
    if(r<=l) return;
    cmpexch(V[(r+l)/2],V[r]);
    cmpexch(V[l],V[(r+l)/2]);
    cmpexch(V[r],V[(r+l)/2]);


    j = separa(V,l,r);
    quickSortMediana(V,l,j-1);
    quickSortMediana(V,j+1,r);
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

    quickSortMediana(vetor,0,total-1);

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
