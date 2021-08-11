#include <stdio.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

int separa(Item *V, int l, int r){
    Item c = V[r];
    int j=l;
    for(int k=l;k<r;k++){
        if(lessequal(V[k],c)){
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