#include <stdio.h>
#include <stdlib.h>

void printLumber



int main(int argc, char const *argv[])
{
    int L,G, pos_g;
    char x,pos_l;
    char matriz[1000][11];

    scanf("%d", &L);

    for(int i=0;i<L;i++){
        for(int j=0;j<4;j++){
            matriz[i][j]=' ';
        }
        for(int j=4;j<7;j++){
            matriz[i][j] = '|';
        }
        for(int j=7;j<11;j++){
            matriz[i][j]=' ';
        }
    }

    scanf("%d", &G);

    for(int i=0;i<G;i++){
        scanf(" %c %d", &x, &pos_g);
        if(x=='D') {
            matriz[pos_g][7] = '-';
            matriz[pos_g][8] = '-';
            matriz[pos_g][9] = '-';
        }else if(x=='E'){
            matriz[pos_g][1] = '-';
            matriz[pos_g][2] = '-';
            matriz[pos_g][3] = '-';
        }
    }

    scanf("%c", &pos_l);

    if(pos_l=='D') {
        matriz[0][7] = 'L';
        matriz[1][7] = 'L';
    }
    if(pos_l=='E') {
        matriz[0][3] = 'L';
        matriz[1][3] = 'L';
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<11;j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}
