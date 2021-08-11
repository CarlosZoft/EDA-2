#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* link;
typedef struct graph* Graph;
typedef struct 
{
    int v;
    int w;
}Edge;

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

Graph GRAPHinit(int V){
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


void GRAPHDestroy(Graph G){
    for(int i=0;i<G->V;i++){
        free(G->adj[i]);
    }
    free(G->adj);
    free(G);
}

Edge EDGE(int v, int w){
    Edge E;
    E.v = v;
    E.w = w;

    return E;
}



int *pre;
int cnt;
int *con;
int conexos;

void dfsR( Graph G, Edge E){    //LISTA DE ADJACENCIAS
    int t,w= E.w;
    pre[w] = cnt++;
    link l;

    for(l = G->adj[w];l!=NULL;l=l->next){
        t = l->v;
        if(pre[t]==-1){
            dfsR(G,EDGE(w,t));
            con[t]=conexos;
        }
    }

    
}

void GRAPHSearch(Graph G){
    int v; 
    conexos=0;
    cnt=0;
    for(v=0;v<G->V;v++){
        pre[v]=-1;
    }
    for(v=0;v<G->V;v++){
        if(pre[v]==-1){
            con[v]=conexos;
            dfsR(G,EDGE(v,v));
            conexos++; 
        }
    }
}



int main(int argc, char const *argv[])
{
    int n,c,r,maior=0,val_x,val_y;

    char x[31],y[31];

    char nomes[5000][31]; 

    Graph G;
    scanf("%d %d",&c,&r);

    while(c){
        G = GRAPHinit(c);

        pre = malloc(sizeof(int)*c);
        con = malloc(sizeof(int)*c);

        for(int i=0;i<c;i++){
            scanf("%s", nomes[i]);
        }

        for(int i=0;i<r;i++){
            scanf("%s %s", x, y);
            for(int j=0;j<c;j++){
                if(strcmp(nomes[j],x)==0){
                    val_x = j;
                }
                if(strcmp(nomes[j],y)==0){
                    val_y = j;
                }
            }

            GRAPHInsertE(G,EDGE(val_y,val_x));
        }

        GRAPHSearch(G);

        int *soma_con;
        soma_con = malloc(sizeof(int)*conexos);

        for(int i=0;i<conexos;i++) soma_con[i] = 0;

        for(int i=0;i<c;i++){
            soma_con[con[i]]++;
        }

        int maior = 0;
        for(int i=0;i<conexos;i++){
            if(maior<soma_con[i]){
                maior = soma_con[i];
            }
        }

        printf("%d\n\n", maior);
        

        free(pre);

        

        scanf("%d %d",&c,&r);
    }

    return 0;
}
