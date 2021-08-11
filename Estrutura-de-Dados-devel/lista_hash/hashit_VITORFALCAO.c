#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define FORI(i, s, e)   for(int i = s; i < e; i++)
#define FORD(i, s, e)   for(int i = s; i >= e; i--)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
 
#define SZ 101
 
char hashtable[SZ][15];
char NULL_KEY[] = "NULL_KEY";
int N;
 
int hash(char key[15]) {
    int i = 0;
    int sum = 0;
    while(key[i] != '\0') {
        sum += key[i] * (i + 1);
        i++;
    }
    sum *= 19;
    sum %= SZ;
    return sum;
}
 
int find(char name[15]) {
    int h = hash(name);
    int pos = 0;
    int j = 0;
    while(j < 20) {
        pos = (h + (j * j) + 23 * j) % SZ;
        if(!strcmp(hashtable[pos], name)) return pos;
        j++;
    }
    return -1;
}
 
void del(char name[15]) {
    int pos = find(name);
    if(pos == -1) return;
    strcpy(hashtable[pos], NULL_KEY);
    N--;
}
 
void insert(char name[15]) {
    if(find(name) != -1) return;
    int h = hash(name);
    int pos = 0;
    int j = 0;
    while(j < 20) {
        pos = (h + (j * j) + 23 * j) % SZ;
        if(!strcmp(hashtable[pos], NULL_KEY)) {
            strcpy(hashtable[pos], name);
            N++;
            return;
        }
        j++;
    }
}
 
void init() {
    N = 0;
    FORI(i, 0, SZ) strcpy(hashtable[i], NULL_KEY);
}
 
int main() {
    // vai toma no cu escrever tabela hash so
    // n eh mais chato q lista encadeada
    CASET {
        init();
        int ops;
        char entry[19], name[15], cmd[3];
        RI(ops);
        FORI(i, 0, ops) {
            RS(entry);
            strncpy(name, entry + 4, sizeof(char) * 15);
            strncpy(cmd, entry, sizeof(char) * 3);
 
            if(cmd[0] == 'A') insert(name);
            else del(name);
        }
 
        printf("%d\n", N);
        FORI(i, 0, SZ) {
            if(strcmp(hashtable[i], NULL_KEY))
                printf("%d:%s\n", i, hashtable[i]);
        }
    }
 
    return 0;
}