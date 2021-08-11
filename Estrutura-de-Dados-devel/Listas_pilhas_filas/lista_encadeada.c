#include <stdio.h>
#include <stdlib.h>

typedef int Item; // Struct{ int chave; char nome[100]}

typedef struct _Node
{
    Item info;
    struct _Node *next,*prev, *head, *tail;
    unsigned long _size;
}Node;

Node *list(){
    Node *n = malloc(sizeof(Node));
    n->head=NULL;
    n->tail=NULL;
    n->_size =0;
    return n;
}

Item front(Node *n){
    if(n->head)
        return n->head->info;
}

Item back(Node *n){
    if(n->tail)
        return n->tail->info;
}

int empty(Node *n){
    return n->head==NULL;
}

unsigned long size(Node *n){
    return n->_size;
}

void push_front(Node *n, Item info){
    Node *aux = malloc(sizeof(Node));
    aux->info = info;
    aux->next = n->head;
    aux->prev = NULL;
    
    if(n->head){
        n->head->prev = aux;
    }else{
        n->tail = aux;
    }
    n->head = aux;
    n->_size++;
}

void push_back(Node *n, Item info){
    Node *aux = malloc(sizeof(Node));
    aux->info = info;
    aux->next = NULL;
    aux->prev = n->tail;

    if(n->tail){
        n->tail->next = aux;
    }else{
        n->head = aux;
    }
    n->tail = aux;
    n->_size++;
}

void pop_front(Node *n){
    if(!n->head) return;
    Node *aux = n->head;
    n->head = n->head->next;
    free(aux);

    if(n->head){
        n->head->prev = NULL;
    }else{
        n->tail = NULL;
    }

    n->_size--;
}

void pop_back(Node *n){
    if(!n->tail) return;

    Node *aux = n->tail;
    n->tail = n->tail->prev;
    free(aux);

    if(n->tail){
        n->tail->next = NULL;
    }else{
        n->head = NULL;
    }

    n->_size--;

}

void delete(Node *n){
    Node *aux = n->head;

    while(aux){
        Node *next = aux->next;
        free(aux);
        aux = next; 
    }
    n->_size=0;
    n->head = NULL;
}

int main(int argc, char const *argv[])
{
    Node *p = list();


    printf("%ld\n", size(p));

    push_front(p,10);
    printf("%d\n", front(p));
    push_front(p,20);
    printf("%d\n", front(p));

    push_front(p,30);
    printf("%d\n", front(p));

    pop_front(p);
    printf("%d\n", front(p));

    delete(p);

    return 0;
}
