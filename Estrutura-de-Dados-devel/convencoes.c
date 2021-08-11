#include <stdio.h>

typedef int Item; // Struct{ int chave; char nome[100]}

#define Key(A)(A) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}


int main(int argc, char const *argv[])
{
    Item a=3,b=5;
    printf("Keys: %d %d\n", Key(a), Key(b));
    printf("Less:");
    if(less(a,b)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    exch(a,b);
    printf("Keys: %d %d\n", Key(a), Key(b));
    printf("Less:");
    if(less(a,b)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    cmpexch(a,b);
    printf("Keys: %d %d\n", Key(a), Key(b));
    printf("Less:");
    if(less(a,b)){
        printf("True\n");
    }else{
        printf("False\n");
    }
    return 0;
}
