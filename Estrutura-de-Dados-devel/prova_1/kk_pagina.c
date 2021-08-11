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


void quickSelect(Item *v, int l, int r, int k){

    if(r<=l) return;
    int i;
    i = separa(v,l,r);



    if(i>k){
        quickSelect(v,l,i-1,k);
    }
    if(i<k){
        quickSelect(v,i+1,r,k);
    }


}

void insertionSortO(Item *V, int l, int r){
    for(int i=r;i>l;i--){
        cmpexch(V[i-1],V[i]);
    }

    for(int i=l+2;i<=r;i++){
        int j=i;
        Item tmp = V[j];
        while(less(tmp,V[j-1])){
            V[j] = V[j-1], j--;
        }
        V[j] = tmp;
    }
}

void quickSortMediana(Item *V, int l, int r){
    if(l-r <= 32)return;

    exch(V[(l+r)/2],V[r-1]);
    cmpexch(V[l],V[r-1]);
    cmpexch(V[l],V[r]);
    cmpexch(V[r-1],V[r]);


    int j = separa(V,l+1,r-1);
    quickSortMediana(V,l,j-1);
    quickSortMediana(V,j+1,r);
}

void sort(Item *v, int l, int r){
    quickSortMediana(v,l,r);
    insertionSortO(v,l,r);
}


int main(int argc, char const *argv[])
{
    Item n,p,x,*produtos, a;
    int pos_i,pos_f;

    scanf("%ld %ld %ld", &n, &p, &x);

    produtos = malloc(sizeof(Item)*n);

    for(int i=0;i<n;i++){
        scanf("%ld", &a);
        produtos[i]=a;
    }

    pos_i = x*p;
    pos_f = pos_i+(x-1);

    while (pos_f>=n)
    {
        pos_f--;
    }

    quickSelect(produtos,0,n-1,pos_f);
    quickSelect(produtos,0,pos_f-1,pos_i);
    sort(produtos,pos_i,pos_f);


    for(int i=pos_i;i<=pos_f;i++){
        printf("%ld\n", produtos[i]);
    }
    



    return 0;
}
