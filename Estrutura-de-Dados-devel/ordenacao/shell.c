#include <stdio.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void insertionSortH(Item *V, int l, int r, int h){
    for(int i=l+h;i<=r;i++){
        int j=i;
        Item tmp = V[i];
        while (j>=l+h && less(tmp,V[j-h]))
        {
            V[j]=V[j-h];
            j-=h;
        }
        V[j]=tmp;
    }
}

void shellSort(Item *V, int l, int r){
    int h;
    for(h =1;h<=(r-l)/9;h=3*h+1);
    for(;h>0;h=h/3){
        insertionSortH(V,l,r,h);
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

    shellSort(vetor,0,total-1);

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