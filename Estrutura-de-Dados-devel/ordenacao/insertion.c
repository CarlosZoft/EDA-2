#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int aluno;
    int nota;
}Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A.nota) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void insertionSort(Item *V, int l, int r){
    for(int i=l+1;i<=r;i++){
        for(int j=i;j>l;j--){
            cmpexch(V[j-1],V[j]);
        }
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


int main(int argc, char const *argv[])
{
    Item *vetor;
    int total,n,a;
    

    scanf("%d", &total);

    vetor = malloc(sizeof(Item)*total);

    for(int i=0;i<total;i++){
        scanf("%d %d", &a, &n);
        vetor[i].nota=n;
        vetor[i].aluno=a;
    }

    insertionSortO(vetor,0,total-1);

    for(int i=0;i<total;i++){
        printf("Aluno %d | %d\n", vetor[i].aluno, vetor[i].nota);
    }

    free(vetor);
    return 0;
}