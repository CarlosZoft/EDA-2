#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define hash(v,M) (v%M)

#define hashtow(v,M) (v%97+1)

typedef struct item
{
    int chave;
    long e1,e2;
    long elemento;
}Item;

Item NULLitem = {0,0,0,0};

#define key(x) (x.chave)

#define null(A)(key(ht[A])==key(NULLitem))

#define eq(a,b)(a==b)

static int N,M;

static Item *ht;

void expand(){
    int i;
    Item *t = ht;
    ht = malloc(sizeof(Item)*M*2);
    M=M*2;
    for(i=0;i<M;i++){
        if(key(t[i])!=key(NULLitem)){
            HTinsert(t[i]);
        }
    }
    free(t);
}

void HTInit(int max){
    int i;
    N=0, M=2*max;
    ht = malloc(sizeof(Item)*M);
    for(i=0;i<M;i++)
        ht[i]=NULLitem;
}

int HTcount(){return N;}

void HTinsert(Item item){
    int v = key(item);
    int i = hash(v,M);
    int k = hashtow(v,M);
    while (!null(i))
    {
        i = (i+k) % M;
    }
    ht[i] = item;
    N++;
    if(N>=M/2){
        expand();
    }
}

Item HTsearch(int v){
    int i = hash (v,M);
    int k = hashtow(v,M);

    while (!null(i))
    {
        if(eq(v,key(ht[i]))){
            return ht[i];
        }
        else{
            i = (i+k) %M;
        }
    }
    return NULLitem;
}