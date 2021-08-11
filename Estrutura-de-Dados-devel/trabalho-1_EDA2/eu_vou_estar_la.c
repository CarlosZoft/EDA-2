#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int v;
    int w;
}Edge;

Edge EDGE(int, int);

typedef struct graph* Graph;

Graph GRAPHinit(int); //  quantidade de vertices

void GRAPHInsertE(Graph,Edge);

void GRAPHRemoveE(Graph,Edge);

int GRAPHEdges(Edge[],Graph G);

Graph GRAPHCopy(Graph);

void GRAPHDestroy(Graph);

Edge EDGE(int v, int w){
    Edge E;
    E.v = v;
    E.w = w;

    return E;
}


//Matriz de adjacencias
struct graph
{
    int V;
    int E;
    int **adj;
    int **tc;
};


int **MATRIXInit(int l, int c, int vi){
    int **m;
    m = malloc(sizeof(int*)*l);
    for(int i=0;i<l;i++){
        m[i] = malloc(sizeof(int)*c);
    }

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            m[i][j]=vi;
        }
    }

    return m;
}

Graph GRAPHinit(int V){
    Graph G = malloc(sizeof(*G));
    G->V =V;
    G->E = 0;
    G->adj = MATRIXInit(V,V,0);
    return G;
}

void GRAPHInsertE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w]==0){
        G->E++;
    }
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;

}

void GRAPHRemoveE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w]==1){
        G->E--;
    }
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}



int GRAPHEdges(Edge *a, Graph G){
    int v,w,E=0;

    for(v=0;v<G->V;v++){
        for(w=v+1;w<G->V;w++){
            if(G->adj[v][w]==1){
                a[E++] = EDGE(v,w);
            }
        }
    }

    return E;
}

int main(int argc, char const *argv[])
{
    int n,m,j,x,y;
    int *ja_esteve;

    scanf("%d %d %d", &n, &m, &j);

    Graph G = GRAPHinit(n);

    for(int i=0;i<n;i++){
        scanf("%d", &x);
        for(int j=0;j<x;j++){
            scanf("%d",&y);
            GRAPHInsertE(G,EDGE(i,y));
        }
    }

    ja_esteve = malloc(sizeof(int)*m);

    for(int i=0;i<m;i++){
        scanf("%d", &x);
        ja_esteve[i]=x;
    }

    for(int i=0;i<j;i++){
        scanf("%d", &x);
        int p=0;
        for(int j=0;j<m;j++){
            if(x==ja_esteve[j]){
                printf("Eu vou estar la\n");
                p=1;
                break;
            }
            if(G->adj[x][ja_esteve[j]]){
                printf("Eu vou estar la\n");
                p=1;
                break;
            }
        }
        if(p==0) printf("Nao vou estar la\n");
    }

    return 0;
}

