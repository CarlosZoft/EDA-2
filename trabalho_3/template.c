#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int v;
    int w;
}Edge;

Edge EDGE(int, int);
typedef struct graph* Graph;
Graph initGraph(int); 
void insertNode(Graph,Edge);
void removeNode(Graph,Edge);
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


int **adjMatrix(int linha, int coluna, int vi){
    int **m;
    m = malloc(sizeof(int*)*linha);
    for(int i=0;i<linha;i++){
        m[i] = malloc(sizeof(int)*coluna);
    }

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            m[i][j] = vi;
        }
    }

    return m;
}

Graph initGraph(int V){
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = adjMatrix(V,V,0);
    return G;
}

void insertNode(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w]==0){
        G->E++;
    }
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;

}

void removeNode(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w]==1){
        G->E--;
    }
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}



int GRAPHEdges(Edge *a, Graph G){
    int v, w, E=0;

    for(v=0;v<G->V;v++){
        for(w=v+1;w<G->V;w++){
            if(G->adj[v][w]==1){
                a[E++] = EDGE(v,w);
            }
        }
    }

    return E;
}

int *pre;
int cnt;
int conexos;

void dfsR( Graph G, Edge E){
    int t, w = E.w;
    pre[w] = cnt++;
    link l;

    for(l = G -> adj[w] ; l != NULL ; l = l->next){
        t = l->v;
        if(pre[t] == -1){
            dfsR(G,EDGE(w,t));
        }
    }

    
}



void GRAPHSearch(Graph G){
    int v;
    conexos = 0;
    cnt=0;
    for(v=0; v<G->V; v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++; 
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph G = initGraph(n);

    return 0;
}

