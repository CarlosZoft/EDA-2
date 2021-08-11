#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;


typedef struct 
{
    int v;
    int w;
}Edge;


typedef struct graph* Graph;



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

void GRAPHInsertE(Graph G, Edge E,int peso){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w]==0){
        G->E++;
    }
    G->adj[v][w] = peso;
    // G->adj[w][v] = peso;

}

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;


node *FILA;

void inicia()
{
    FILA = (node *) malloc(sizeof(node));
    FILA->prox = NULL;
    tam=0;
}

int vazia()
{
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca(int dado)
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  novo->num = dado;
  return novo;
 }
}

void insere(int dado)
{
 node *novo=aloca(dado);
 novo->prox = NULL;

 if(vazia())
  FILA->prox=novo;
 else{
  node *tmp = FILA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}


int retira()
{
  node *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  tam--;
  return tmp->num;

}

void libera()
{
 if(!vazia()){
  node *proxNode,
     *atual;

  atual = FILA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
 free(FILA);
}

bool GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    bool onqueu[1000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueu[v] = false;
    }
    pa[s] = s;
    dist[s] = 0;
    inicia(G->E);
    insere(s);
    onqueu[s] = true;
    int V = 5000;
    insere(V); //V = Sentinela maior que todos os vertices
    int k=0;
    while(1){
        int v = retira();
        if(v<V){
            for(int t=0;t<G->V;t++){
                // if(G->adj[v][t]==G->adj[t][v]){
                    if(dist[v]+G->adj[v][t] < dist[t] && G->adj[v][t] != 0){
                        dist[t] = dist[v]+G->adj[v][t];
                        pa[t] = v;
                        if(onqueu[t]==false){
                            insere(t);
                            onqueu[t] = true;
                        }
                    }
                // }
            }
        }else{
            if(vazia()) return true;
            if(++k>=G->V) return false;
            insere(V);
            for(int t=0;t<G->V;t++){
                onqueu[t] = false;
            }
        }
    }
    libera();
}

bool GRAPHcptBFSEM(Graph G, int s, int *pa, int *dist){
    bool onqueu[1000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueu[v] = false;
    }
    pa[s] = s;
    dist[s] = 0;
    inicia(G->E);
    insere(s);
    onqueu[s] = true;
    int V = 5000;
    insere(V); //V = Sentinela maior que todos os vertices
    int k=0;
    while(1){
        int v = retira();
        if(v<V){
            for(int t=0;t<G->V;t++){
                if(G->adj[v][t]==G->adj[t][v]){
                    if(dist[v]+G->adj[v][t] < dist[t] && G->adj[v][t] != 0){
                        dist[t] = dist[v]+G->adj[v][t];
                        pa[t] = v;
                        if(onqueu[t]==false){
                            insere(t);
                            onqueu[t] = true;
                        }
                    }
                }
            }
        }else{
            if(vazia()) return true;
            if(++k>=G->V) return false;
            insere(V);
            for(int t=0;t<G->V;t++){
                onqueu[t] = false;
            }
        }
    }
    libera();
}

void FloydWarshall(int **matriz, int n){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			for(int z = 0; z < n; z++){
				if( matriz[y][z] > (matriz[y][x] + matriz[x][z]) )
					matriz[y][z] = matriz[y][x] + matriz[x][z];
			}	
		}	
	}
}

int main(int argc, char const *argv[])
{
    int V,v,w,c,t,o,x;
    Graph G;
    int *pa, *dist, *paS, *distS;
    int SPS, SP;

    scanf("%d", &V);


    G = GRAPHInit(V);
    pa = malloc(sizeof(int)*V);
    dist = malloc(sizeof(int)*V);
    paS = malloc(sizeof(int)*V);
    distS = malloc(sizeof(int)*V);

    scanf("%d %d %d %d", &v, &w, &c, &t);
    while(v!=0 || c!= 0 || w != 0 || t!=0){
        if(t==0){
            GRAPHInsertE(G,EDGE(v,w),c);
            GRAPHInsertE(G,EDGE(w,v),c);
        }else{
            GRAPHInsertE(G,EDGE(v,w),c);
        }

        scanf("%d %d %d %d", &v, &w, &c, &t);
    }

    // while(scanf("%d %d", &o, &x)==2){
    //     SP = GRAPHcptBF(G,o,pa,dist);
    //     SPS = GRAPHcptBFSEM(G,o,paS,distS);

    //     // for(int i=0;i<V;i++){
    //     //     printf("%d ", dist[i]);
    //     // }
    //     // printf("\n");


    //     if(SP==0 || SPS==0){
    //         printf("Impossibru\n");
    //     }else if(dist[x] == __INT_MAX__  ){
    //         printf("Impossibru\n");
    //     }
    //     else{
            
    //         printf("%d %d\n",distS[x], dist[x]);
    //     }
    // }

    FloydWarshall(G->adj,G->V);

    printf("Matriz:\n");
	for (int i = 0; i < G->V; ++i){
		for (int e = 0; e < G->V; ++e){
            printf("%d ", G->adj[i][e]);
		}
		printf("\n");
	}
	printf("\n");


    return 0;
}

