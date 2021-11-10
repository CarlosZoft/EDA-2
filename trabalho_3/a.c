#include <stdio.h>
#include <stdlib.h>

int visitados[5000];
int conectados;
int conexos;

int qtd_cidades;
int t, v, w;

// Graph **********************************************************
typedef struct
{
  int v, w;
} Edge;

// Edge EDGE(int, int);
typedef struct graph *Graph;
// Graph GRAPHInit(int);
// void GRAPHInsertE(Graph, Edge);
typedef struct node *link;

Edge EDGE(int v, int w)
{
  Edge E;
  E.v = v;
  E.w = w;
  return E;
}

typedef struct node
{
  int v;
  link next;
} node;

struct graph
{
  int V, E;
  link *adj;
};

link New(int v, link next)
{
  link x = malloc(sizeof(node));

  x->v = v;
  x->next = next;

  return x;
}

Graph GRAPHInit(int V)
{
  Graph G = malloc(sizeof(*G));

  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(link));
  for (v = 0; v < V; v++)
  {
    visitados[v] = -1;
    G->adj[v] = NULL;
  }

  return G;
}

void GRAPHInsertE(Graph G, Edge E)
{
  v = E.v;
  w = E.w;
  G->adj[v] = New(w, G->adj[v]);
  G->adj[w] = New(v, G->adj[w]);

  G->E++;
}
// ******************************************************************

void dfsR(Graph G, Edge E)
{
  visitados[w] = conectados++;
  link l = G->adj[w];

  while(l != NULL){
    if (visitados[l->v] == -1)
      dfsR(G, EDGE(w, t));
    l = l->next;
  }
}

void GRAPHSearch(Graph G)
{
  conexos = 0;
  conectados = 0;

  for (v = 0; v < G->V; v++)
  {
    if (visitados[v] == -1)
    {
      dfsR(G, EDGE(v, v));
      conexos++;
    }
  }
}

int main()
{
  scanf("%d", &qtd_cidades);

  // inicia grafo
  Graph G = GRAPHInit(qtd_cidades);

  // inserir
  while (scanf("%d %d", &v, &w) == 2)
    GRAPHInsertE(G, EDGE(v, w));

  // busca conexos
  GRAPHSearch(G);

  printf("%d\n", conexos);

  return 0;
}
