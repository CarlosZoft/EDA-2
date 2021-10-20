#include <stdio.h>
#include <stdlib.h>

#define hash(v,M) (618033*(unsigned)v%M)

typedef int Item; 

#define key(A)(A) 

Item NULLitem = -1;

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




int main(int argc, char const *argv[])
{
    Item n,t,c,x;


    scanf("%d", &n);

    HTInit(140000);

    for(int i=0;i<n;i++){
        scanf("%d", &t);
        HTinsert(t);
    }

    while (scanf("%d", &c)==1)
    {
        x = HTsearch(c);
        if(x==-1){
            printf("nao\n");
        }else{
            printf("sim\n");
        }
    }
    

    return 0;
}
