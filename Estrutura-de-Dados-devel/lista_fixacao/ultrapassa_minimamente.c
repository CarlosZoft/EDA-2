#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int limite,soma=0,n,*vetor,total=0, *pos,j=0;
    
    scanf("%d", &n);
    vetor = malloc(sizeof(int));
    pos = malloc(sizeof(int));
    
    while(n){
        vetor[total++]=n;        
        vetor = realloc(vetor,sizeof(int)*(total+1));        
        scanf("%d", &n);
    }
    scanf("%d", &limite);

    for(int i=0;i<total;i++){
        if(soma<=90){
            soma+=vetor[i];
        }
        if(soma>90){
            pos[j++] = i;
            pos = realloc(pos,sizeof(int)*(j+1));
            soma=0;
        }
    }

    for(int i=j-1;i>=0;i--){
        printf("%d\n", vetor[pos[i]]);
    }

    free(pos);
    free(vetor);
    return 0;
}
