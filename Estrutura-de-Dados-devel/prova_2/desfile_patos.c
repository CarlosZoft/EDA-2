#include <stdio.h>
#include <stdlib.h>

#define M 1000001



int main(int argc, char const *argv[])
{
    int n,x,patos[M],h,maior=0,pos;

    scanf("%d", &n);

    while (n)
    {
        for(int i=0;i<M;i++){
            patos[i]=0;
        }

        for(int i=0;i<n;i++){
            scanf("%d",&x);
            patos[x] = patos[x]+1;
            if(patos[x]>maior){
                pos = x;
                maior = patos[x];
            }
        }

        printf("%d\n", pos);
        maior =0;
        pos = 0;

        scanf("%d", &n);
    }
    

    return 0;
}
