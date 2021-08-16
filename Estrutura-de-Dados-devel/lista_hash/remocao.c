#include <stdio.h>
#include <stdlib.h>

#define hash(v,M) (618033 * (unsigned)v % M)

typedef struct item
{
    long long int chave,prev,next;
}Item;

Item NULLitem = {-1,-1,-1};

#define key(x) (x.chave)

#define null(A)(key(ht[A])==key(NULLitem))

#define eq(a,b)(a==b)

static int N,M;

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

Item HTsearch(long long v){
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


int main(int argc, char const *argv[])
{
    long long int x,y,z;
    Item p,a,aux={1,0,2};

    HTInit(250000);

    while(scanf("%llx %llx %llx" , &x,&y,&z)==3){
        p.chave = x;
        p.prev = y;
        p.next = z;
        HTinsert(p);
    }

    
    
    printf("\n%llx\n", a.next);

    return 0;
}
