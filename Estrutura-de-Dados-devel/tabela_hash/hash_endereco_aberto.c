#include <stdio.h>
#include <stdlib.h>

#define hash(v,M) (v%M) // M primo

#define hash(v,M) (618033*(unsigned)v%M)

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

int hashU(char *v, int M){
    int h, a = 31415, b = 27813;
    for(h=0;*v!='\0';v++){
        a = a*b%(M-1);
        h = (a*h+*v) % M;
    }
    return h;
}


static Item *ht;

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

    while(!null(i)){
        i=(i+1)%M;
    }
    ht[i]=item;
    N++;
}

Item HTsearch(int v){
    int i = hash(v,M);
    while (!null(i))
    {
        if(eq(v,key(ht[i])))
            return ht[i];
        else
            i = (i+1) %M;
    }
    return NULLitem;
    
}






