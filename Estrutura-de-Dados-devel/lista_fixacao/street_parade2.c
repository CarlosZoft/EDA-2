#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int n,a[1000], b[1000], st;
    int j,k,l,i;

    scanf("%d", &n);

    while (n)
    {
        st=1;j=0;k=0;
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }

        while(1){
            if(a[j]==st){
                j++;
                st++;    
            }else if(b[k-1]==st){
                k--;
                st++;
            }
            else{
                b[k++] = a[j];
                a[j++]=0;
            }
            if(st>=n) break;
            if(k>=n) break;

        }

        if(st==n){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        scanf("%d", &n);
    }
    

    return 0;
}
