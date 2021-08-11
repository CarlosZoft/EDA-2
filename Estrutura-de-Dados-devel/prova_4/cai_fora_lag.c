#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef struct 
{
    int v;
    int w;
}Edge;

Edge EDGE(int, int);

Edge EDGE(int v, int w){
    Edge E;
    E.v = v;
    E.w = w;

    return E;
}

typedef struct graph* Graph;

typedef struct node* link;

struct node
{
    int v;
    int c;
    int d;
    link next;
};

struct graph
{
    int V;
    int E;
    link *adj;
};

link New(int v,int custo,int dir, link next){
    link x = malloc(sizeof(*x));
    
    // if(x==NULL) tela_azul();

    x->v = v;
    x->c = custo;
    x->d= dir;
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

void GRAPHInsertE(Graph G, Edge E, int custo,int dir){
    int v = E.v;
    int w = E.w;
    G->adj[v] = New(w,custo,dir,G->adj[v]);
    // G->adj[w] = New(v,custo,G->adj[w]);

    G->E++;

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


int GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    int onqueu[2000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueu[v] = false;
    }
    pa[s] = s;
    dist[s] = 0;
    inicia();
    insere(s);
    onqueu[s] = true;
    int V = 5000;
    insere(V); //V = Sentinela maior que todos os vertices
    int k=0;
    while(1){
        int v = retira();
        if(v<V){
            for(link a=G->adj[v];a!=NULL;a=a->next){
                if(dist[v]+a->c < dist[a->v]){
                    dist[a->v] = dist[v]+a->c;
                    pa[a->v] = v;
                    if(onqueu[a->v]==false){
                        insere(a->v);
                        onqueu[a->v] = true;
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

int GRAPHcptBFSEM(Graph G, int s, int *pa, int *dist){
    int onqueu[2000];
    for(int v=0;v<G->V;v++){
        pa[v] = -1;
        dist[v] = __INT_MAX__;
        onqueu[v] = false;
    }
    pa[s] = s;
    dist[s] = 0;
    inicia();
    insere(s);
    onqueu[s] = true;
    int V = 5000;
    insere(V); //V = Sentinela maior que todos os vertices
    int k=0;
    while(1){
        int v = retira();
        if(v<V){
            for(link a=G->adj[v];a!=NULL;a=a->next){
                if(a->d==0){
                    if(dist[v]+a->c < dist[a->v]){
                        dist[a->v] = dist[v]+a->c;
                        pa[a->v] = v;
                        if(onqueu[a->v]==false){
                            insere(a->v);
                            onqueu[a->v] = true;
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
            GRAPHInsertE(G,EDGE(v,w),c,t);
            GRAPHInsertE(G,EDGE(w,v),c,t);
        }else{
            GRAPHInsertE(G,EDGE(v,w),c,t);
        }

        scanf("%d %d %d %d", &v, &w, &c, &t);
    }

    int ja_foi=__INT_MAX__;
    while(scanf("%d %d", &o, &x)==2){
        if(o==ja_foi){
                if(SP==0){
                printf("Impossibru\n");
            }else if(dist[x] == __INT_MAX__  ){
                printf("Impossibru\n");
            }
            else{
                
                printf("%d %d\n",distS[x], dist[x]);
            }
        }else{
            ja_foi = o;
            SP = GRAPHcptBF(G,o,pa,dist);
            SPS = GRAPHcptBFSEM(G,o,paS,distS);

            // for(int i=0;i<V;i++){
            //     printf("%d ", dist[i]);
            // }
            // printf("\n");
            // for(int i=0;i<V;i++){
            //     printf("%d ", distS[i]);
            // }
            // printf("\n");


            if(SP==0 || SPS ==0){
                printf("Impossibru\n");
            }else if(dist[x] == __INT_MAX__  ){
                printf("Impossibru\n");
            }
            else{
                
                printf("%d %d\n",distS[x], dist[x]);
            }
        }
    }



    return 0;
}
