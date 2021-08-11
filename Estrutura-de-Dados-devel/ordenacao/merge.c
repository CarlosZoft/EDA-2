#include <stdio.h>
#include <stdlib.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}


void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0, i=l, j=r1+1;
    while(i<=r1 && j<=r2){
        if(lesseq(v[i],v[j]))
            v2[k++]=v[i++];
        else
            v2[k++]=v[j++];
    }
    while(i<=r1)
        v2[k++]=v[i++];
    while(j<=r2)
        v2[k++]=v[j++];
    k=0;
    for(i=l;i<=r2;i++){
        v[i]=v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);
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

    mergeSort(vetor,0,total-1);

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