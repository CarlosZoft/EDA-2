#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
    int val,freq;
}Item;

#define Key(A)(A.freq) // Key(A) (A.chave)

#define KeyV(A)(A.val) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define lesseqV(A,B) (KeyV(A)<=KeyV(B))


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

void mergeV(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0, i=l, j=r1+1;
    while(i<=r1 && j<=r2){
        if(lesseqV(v[i],v[j]))
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

void mergeSortV(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    mergeSortV(v,l,meio);
    mergeSortV(v,meio+1,r);
    mergeV(v,l,meio,r);
}









Item ht[128];

int main(int argc, char const *argv[])
{
    char s[1000],*t;
    int n,total=0;

    while(scanf("%s", s) == 1){
        t = s;
        for(int i=0;i<128;i++){
            ht[i].freq = 0;
            ht[i].val = 0;
        }
        for(int i=0;*t!='\0';t++){
            ht[*t].freq++;
            ht[*t].val = *t;
            total++;
        }

        mergeSortV(ht,0,127);
        mergeSort(ht,0,127);

        for(int i=0;i<128;i++){
            if(ht[i].val != 0) printf("%d %d\n",ht[i].val, ht[i].freq);
        }
    }

    return 0;
}

