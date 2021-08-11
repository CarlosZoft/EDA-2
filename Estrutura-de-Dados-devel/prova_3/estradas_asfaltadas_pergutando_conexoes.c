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

Graph GRAPHInit(int V){
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
    // G->adj[w][v] = 1;

}

void GRAPHtc(Graph G){
    int i,s,t;
    G->tc = MATRIXInit(G->V,G->V,0);

    for(s=0;s<G->V;s++){
        for(t=0;t<G->V;t++){
            G->tc[s][t]=G->adj[s][t];
        }
    }

    for(s=0;s<G->V;s++) G->tc[s][s]=1;

    for(i=0;i<G->V;i++)
        for(s=0;s<G->V;s++)
            if(G->tc[s][i]==1)
                for(t=0;t<G->V;t++)
                    if(G->tc[i][t]==1)
                        G->tc[s][t]=1;
}

int GRAPHreach(Graph G, int s, int t){
    return G->tc[s][t];
}

int main(int argc, char const *argv[])
{
    int v, x, y, z, s,t;

    scanf("%d", &v);

    Graph G = GRAPHInit(v);

    scanf("%d %d %d", &x, &y, &z);

    while (z)
    {
        if(z==1){
            GRAPHInsertE(G,EDGE(x,y));
        }else{
            GRAPHInsertE(G,EDGE(x,y));
            GRAPHInsertE(G,EDGE(y,x));
        }

        scanf("%d %d %d", &x, &y, &z);
    }

    GRAPHtc(G);
    
    while(scanf("%d %d", &s, &t)==2){
        if(GRAPHreach(G,s,t)==1 && GRAPHreach(G,t,s)==1) printf("Ida e Volta\n");
        else if(GRAPHreach(G,s,t)==1) printf("Apenas Ida\n");
        else if(GRAPHreach(G,t,s)==1) printf("Apenas Volta\n");
        else printf("Impossibru\n");
    }

    return 0;
}
