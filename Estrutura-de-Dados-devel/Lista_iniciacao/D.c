#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int l,n,linha,coluna,index, len;
    char s[1000][1000];
    char comando;

    scanf("%d",&l);

    for(int i=0;i<l;i++){
        scanf(" %[^\n]s",s[i]);
    }

    scanf("%d %d", &linha,&coluna);
    index = coluna-1;
    linha--;

    while(scanf("%c",&comando)==1){
        if(comando=='j'){
            linha++;
            if(linha>=l){
                linha = l-1;
            }
            len = strlen(s[linha]);
            if(len>index){
                printf("%d %d %c\n", linha+1, index+1, s[linha][index]);
            }else{
                printf("%d %d %c\n", linha+1,len,s[linha][len-1]);
            }
        }else if(comando=='k'){
            linha--;
            if(linha<0){
                linha = 0;
            }
            len = strlen(s[linha]);
            if(len>index){
                printf("%d %d %c\n", linha+1, index+1, s[linha][index]);
            }else{
                printf("%d %d %c\n", linha+1,len,s[linha][len-1]);
            }
        }
    }

    return 0;
}
