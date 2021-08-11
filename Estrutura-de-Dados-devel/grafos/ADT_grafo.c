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


// Lista de Adjacencias

typedef struct node* link;

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

void GRAPHInsert(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    G->adj[v] = New(w,G->adj[v]);
    G->adj[w] = New(v,G->adj[w]);

    G->E++;

}

int GRAPHEdges(Edge a[], Graph G){
    int v,E=0;
    link t;
    for(v=0;v<G->V;v++){
        for(t=G->adj[v];t!= NULL;t=t->next){
            if(v<t->v){
                a[E++] = EDGE(v,t->v);
            }
        }
    }

    return E;
}


// Busca em Profundidade (DFS)

int *pre;
int cnt=0;

void dfsR( Graph G, Edge E){    //MATRIZ ADJACENCIA
    int t,w= E.w;
    pre[w] = cnt++;

    for(t=0;t<G->V;t++){
        if(G->adj[w][t]!=0){
            if(pre[t]==-1){
                dfsR(G,EDGE(w,t));
            }
        }
    }
}


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
    int v, conexos=0;
    cnt=0;
    for(v=0;v<G->V;v++){
        pre[v]=-1;
    }
    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
            dfsR(G,EDGE(v,v));
            conexos++; 
        }
    }
}


//Busca em Largura (BFS)

void bfs(Graph G, Edge E){
    int v,w,t;
    link l;
    Queueput(E);
    pre[E.w] = cnt++;
    while(!Queueempty()){
        E = Queueget();
        w = E.w;
        for(l =G->adj[w];l!=NULL;l=l->next){
            t = l->v;
            if(pre[t]==-1){
                Queueput(EDGE(w,t));
                pre[t]=cnt++;
            }
        }
    }
}

// Floyd Warshall   Fecho Transitivo

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

//Grafos com pesos nas arestas

//Lista adjacencias

typedef struct node* link;

struct node
{
    int v;
    int c;
    link next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};

link New(int v,int custo, link next){
    link x = malloc(sizeof(*x));
    
    // if(x==NULL) tela_azul();

    x->v = v;
    x->c = custo;
    x->next = next;

    return x;
}


// Bellmon Ford

bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    bool onqueu[1000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueu[v] = false;
    }
    pa[s] = s;
    dist[s] = 0;
    Queueinit(G->E);
    Queuput(s);
    onqueu[s] = true;
    Queueput(V); //V = Sentinela maior que todos os vertices
    int k=0;
    while(1){
        int v = Queueget();
        if(v<V){
            for(link a=G->adj[v];a!=NULL;a=a->next){
                if(dist[v]+a->c < dist[a->v]){
                    dist[a->v] = dist[v]+a->c;
                    pa[a->v] = v;
                    if(onqueu[a->v]==false){
                        Queueput(a->v);
                        onqueu[a->v] = true;
                    }
                }
            }
        }else{
            if(Queueempty()) return true;
            if(++k>=G->V) return false;
            Queueput(V);
            for(int t=0;t<G->V;t++){
                onqueu[t] = false;
            }
        }
    }
}


// Dijkstra

void GRAPHcptD1(Graph G, int s, int *pa, int *dist){
    bool mature[1000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        mature[v]=false;
        dist[v] = __INT_MAX__;
    }
    pa[s] = s;
    dist[s]=0;
    while(1){
        int min = __INT_MAX__;
        int y;
        for(int z=0;z<G->V;z++){
            if(mature[z]) continue;
            if(dist[z]<min){
                min = dist[z];
                y = z;
            } 
        }
        if(min==__INT_MAX__) break;
        for(link a=G->adj[y];a!=NULL;a=a->next){
            if(mature[a->v]) continue;
            if(dist[y]+a.c < dist[a->v]){
                dist[a->v] = dist[y]+a.c;
                pa[a->v] = y;
            }
        }
        mature[y] = true;
    }
}