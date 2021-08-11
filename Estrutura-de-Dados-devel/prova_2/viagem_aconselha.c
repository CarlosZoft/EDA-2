#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int rest, nota;
} Item;



int main(int argc, char const *argv[])
{
    
    int r,x,y,day=0;
    

    while (scanf("%d", &r)==1)
    {
        // if(day) printf("\n");
        int tb[6] = {-1,-1,-1,-1,-1,-1};
        for(int i=0;i<r;i++){
            scanf("%d%d",&x,&y);
            if(tb[y]==-1) tb[y] = x;
            else if(tb[y]>x) tb[y] = x;
        }
        day++;
        printf("Dia %d\n",day);
        for(int i=5;i>=0;i--){
            if(tb[i]!=-1){
                printf("%d\n",tb[i]);
                break;
            }
        }
        printf("\n");
    }
    
    return 0;
}
