#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *cidades[30], s[30];
    int i=0;
    cidades = (char *)malloc(sizeof(char)*30);

    while(scanf("%s", s)==1){
        strcpy(s,cidades[i++]);
    }
    for(int j=0 ;j< i;j++){
    printf("%s\n", cidades[i]);
    }

    free(*cidades);
    return 0;
}
