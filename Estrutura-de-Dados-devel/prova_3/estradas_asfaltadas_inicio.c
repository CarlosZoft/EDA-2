#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int v;
    int w;
}Edge;

Edge EDGE(int, int);

typedef struct graph* Graph;

Graph GRAPHInit(int); //  quantidade de vertices

void GRAPHInsertE(Graph,Edge);

typedef struct node* link;

Edge EDGE(int v, int w){
    Edge E;
    E.v = v;
    E.w = w;

    return E;
}

struct node
{
    int v;
    link next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};

link New(int v, link next){
    link x = malloc(sizeof(*x));
    
    // if(x==NULL) tela_azul();

    x->v = v;
    x->next = next;

    return x;
}

Graph GRAPHInit(int V){
    int v;
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = malloc(V*sizeof(link));
    for(v =0 ; v<V ;v++){
        G->adj[v] = NULL;
    }

    return G;
}

void GRAPHInsertE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    G->adj[v] = New(w,G->adj[v]);
    G->adj[w] = New(v,G->adj[w]);

    G->E++;

}


int *pre;
int cnt;
int conexos;

void dfsR( Graph G, Edge E){    //LISTA DE ADJACENCIAS
    int t,w= E.w;
    pre[w] = cnt++;
    link l;

    for(l = G->adj[w];l!=NULL;l=l->next){
        t = l->v;
        if(pre[t]==-1){
            dfsR(G,EDGE(w,t));
        }
    }

    
}



void GRAPHSearch(Graph G){
    int v;
    conexos = 0;
    cnt=0;
    // for(v=0;v<G->V;v++){
    //     pre[v]=-1;
    // }
    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
            dfsR(G,EDGE(v,v));
            conexos++; 
        }
    }
}

int main(int argc, char const *argv[])
{
    int v, x, y;

    scanf("%d", &v);

    Graph G = GRAPHInit(v);

    pre = malloc(sizeof(int)*v);

    for(int i=0;i<v;i++) pre[i]= -1;

    while(scanf("%d %d", &x, &y)==2){
        GRAPHInsertE(G,EDGE(x,y));
    }

    GRAPHSearch(G);

    printf("%d\n",conexos);

    return 0;
}
