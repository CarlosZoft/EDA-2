#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    long int semente;
    long int nota;
}Item;// Struct{ int chave; char nome[100]}

#define Key(A)(A.nota) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define KeyS(A)(A.semente) // Key(A) (A.chave)

#define lessS(A,B) (KeyS(A)<KeyS(B))

#define lesseqS(A,B) (KeyS(A)<=KeyS(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

#define cmpexchS(A,B){if(lessS(B,A)) exch(A,B);}

int compn(Item a, Item b){
    if(a.nota==b.nota){
        return a.semente<b.semente;
    }else{
        return a.nota<b.nota;
    }
}


int separa(Item *V, int l, int r){

    if(lesseq(V[r],V[(r+l)/2])){
        if(V[(r+l)/2].nota==V[r].nota){
            cmpexchS(V[(r+l)/2],V[r]);
        }else{
            exch(V[(r+l)/2],V[r]);
        }
    }

    if(lesseq(V[(r+l)/2],V[l])){
        if(V[(r+l)/2].nota==V[l].nota){
            cmpexchS(V[l],V[(r+l)/2]);
        }else{
            exch(V[(r+l)/2],V[l]);
        }
    }

    if(lesseq(V[(r+l)/2],V[r])){
        if(V[(r+l)/2].nota==V[r].nota){
            cmpexchS(V[r],V[(r+l)/2]);
        }else{
            exch(V[(r+l)/2],V[r]);
        }
    }

    Item c = V[r];
    int j=l;
    for(int k=l;k<r;k++){
        if(compn(V[k],c)){
            exch(V[k],V[j]);
            j++;
        }
    }
    exch(V[j],V[r]);
    return j;
}

void quickSelect(Item *v, int l, int r, int p){

    if(r<=l) return;
    int i;


    i = separa(v,l,r);


    if(i>p){
        quickSelect(v,l,i-1,p);
    }
    if(i<p){
        quickSelect(v,i+1,r,p);
    }


}

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0, i=l, j=r1+1;
    while(i<=r1 && j<=r2){
        if(lesseqS(v[i],v[j]))
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
int total=0;


void mergeSort(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);
}


int main(int argc, char const *argv[])
{
    long int k, s, n, aux;

    scanf("%ld", &k);
    Item *sementes = malloc(sizeof(Item)*4);

    aux = k;

    while(scanf("%ld %ld", & s,&n)==2){
        sementes[total].nota = n;
        sementes[total++].semente = s;
        if(total>= total%4){
            sementes = realloc(sementes,sizeof(Item)*(total+4));
        }
    }

    quickSelect(sementes,0,total-1,k);

    mergeSort(sementes,0,k-1);



    for(int i=0;i<aux;i++){
        printf("%ld %ld\n", sementes[i].semente, sementes[i].nota);
    }




    return 0;
}