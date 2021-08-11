#include <stdio.h>
#include <stdlib.h>

typedef long int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void *intercala2(Item *v, int r1, Item *w, int r2){
    int total = r1+r2;
    Item *v2 = malloc(sizeof(Item)*total);
    int k=0, i=0, j=0;
    while(i<r1 && j<r2){
        if(lesseq(v[i],w[j])){
            v2[k]=v[i];
            i++;
        }
        else{
            v2[k]=w[j];
            j++;
        }
        k++;
    }
    while(i<r1)
        v2[k++]=v[i++];
    while(j<r2)
        v2[k++]=w[j++];
    return v2;
}

void *intercala4(Item *v1, int r1, Item *v2, int r2, Item *v3, int r3, Item *v4, int r4){
    Item *a, *b, *c;
    a = intercala2(v1,r1,v2,r2);
    b = intercala2(v3,r3,v4,r4);
    c = intercala2(a,r1+r2,b,r3+r4);
    // free(a);
    // free(b);
    return c;
}

void *intercala8(Item *v1, int r1, Item *v2, int r2, Item *v3, int r3, Item *v4, int r4,Item *v5, int r5, Item *v6, int r6, Item *v7, int r7, Item *v8, int r8){
    Item *a = intercala4(v1,r1,v2,r2,v3,r3,v4,r4);
    Item *b = intercala4(v5,r5,v6,r6,v7,r7,v8,r8);
    Item *c = intercala2(a,r1+r2+r3+r4,b,r5+r6+r7+r8);
    // free(a);
    // free(b);
    return c;
}




int main(int argc, char const *argv[])
{
    Item *v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*vetor,n;
    long int n1,n2,n3,n4,n5,n6,n7,n8,total=0;

    scanf("%ld", &n1);
    total+=n1;

    v1 = malloc(sizeof(Item)*n1);

    for(int i=0;i<n1;i++){
        scanf("%ld", &n);
        v1[i] = n;
    }

    //////

    scanf("%ld", &n2);
    total+=n2;

    v2 = malloc(sizeof(Item)*n2);

    for(int i=0;i<n2;i++){
        scanf("%ld", &n);
        v2[i] = n;
    }

    //////

    scanf("%ld", &n3);
    total+=n3;

    v3 = malloc(sizeof(Item)*n3);

    for(int i=0;i<n3;i++){
        scanf("%ld", &n);
        v3[i] = n;
    }

    ///////

    scanf("%ld", &n4);
    total+=n4;

    v4 = malloc(sizeof(Item)*n4);

    for(int i=0;i<n4;i++){
        scanf("%ld", &n);
        v4[i] = n;
    }

    /////////

    scanf("%ld", &n5);
    total+=n5;

    v5 = malloc(sizeof(Item)*n5);

    for(int i=0;i<n5;i++){
        scanf("%ld", &n);
        v5[i] = n;
    }

    //////

    scanf("%ld", &n6);
    total+=n6;

    v6 = malloc(sizeof(Item)*n6);

    for(int i=0;i<n6;i++){
        scanf("%ld", &n);
        v6[i] = n;
    }

    //////

    scanf("%ld", &n7);
    total+=n7;

    v7 = malloc(sizeof(Item)*n7);

    for(int i=0;i<n7;i++){
        scanf("%ld", &n);
        v7[i] = n;
    }

    ///////

    scanf("%ld", &n8);
    total+=n8;

    v8 = malloc(sizeof(Item)*n8);

    for(int i=0;i<n8;i++){
        scanf("%ld", &n);
        v8[i] = n;
    }

    ////////

    vetor = intercala8(v1,n1,v2,n2,v3,n3,v4,n4,v5,n5,v6,n6,v7,n7,v8,n8);


    for(int i=0;i<total;i++){
        if(i+1==total){
            printf("%ld\n", vetor[i]);
        }else{
            printf("%ld ", vetor[i]);
        }
    }
       

    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);
    free(v6);
    free(v7);
    free(v8);
    free(vetor);

    return 0;
}
