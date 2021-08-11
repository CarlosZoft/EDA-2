#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n,x,soma=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        soma+=x;
    }
    printf("%d\n",soma);
    return 0;
}
