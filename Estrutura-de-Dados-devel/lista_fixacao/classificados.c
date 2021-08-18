#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    long int semente;
    long int nota;
}Item;// Struct{ int chave; char nome[100]}

#define Key(A)(A.nota) // Key(A) (A.chave)

#define Keys(A)(A.semente) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lessS(A,B) (Keys(A)<Keys(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define lesseqS(A,B) (Keys(A)<=Keys(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

#define cmpexchS(A,B){if(lessS(B,A)) exch(A,B);}


int separa(Item *V, int l, int r){

    cmpexch(V[(r+l)/2],V[r]);
    cmpexch(V[l],V[(r+l)/2]);
    cmpexch(V[r],V[(r+l)/2]);
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

void quickSelect(Item *v, int l, int r, int p){

    if(r<=l) return;
    int i = separa(v,l,r);

    if(i>p){
        quickSelect(v,l,i-1,p);
    }
    if(i<p){
        quickSelect(v,i+1,r,p);
    }


}

void insertionSorts(Item *V, int l, int r, int h){
    for(int i=l+h;i<=r;i++){
        int j=i;
        Item tmp = V[i];
        while (j>=l+h && lessS(tmp,V[j-h]))
        {
            V[j]=V[j-h];
            j-=h;
        }
        V[j]=tmp;
    }
}

void shellSorts(Item *V, int l, int r){
    int h;
    for(h =1;h<=(r-l)/9;h=3*h+1);
    for(;h>0;h=h/3){
        insertionSorts(V,l,r,h);
    }
}


int main(int argc, char const *argv[])
{
    long int k, s, n, total=0;

    scanf("%ld", &k);
    Item *sementes = malloc(sizeof(Item)*4);

    while(scanf("%ld %ld", &s ,&n)==2){
        sementes[total].nota = n;
        sementes[total++].semente = s;
        if(total>= total%4){
            sementes = realloc(sementes,sizeof(Item)*(total+4));
        }
    }

    quickSelect(sementes,0,total,k);

    // shellSort(sementes,0,k);
    shellSorts(sementes,0,k-1);

    for(int i=0;i<k;i++){
        printf("%ld %ld\n", sementes[i].semente, sementes[i].nota);
    }




    return 0;
}