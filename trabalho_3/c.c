#include <stdio.h>
#include <stdlib.h>

// Graph *******************************************
typedef struct
{
  int v, w;
} Edge;

typedef struct graph *Graph;
typedef struct node *link;

Edge EDGE(int v, int w)
{
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

link New(int v, link next)
{
  link x = malloc(sizeof(*x));
  x->v = v;
  x->next = next;

  return x;
}

Graph GRAPHInit(int V)
{
  int v;
  Graph G = malloc(sizeof(*G));
  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(link));
  for (v = 0; v < V; v++)
    G->adj[v] = NULL;
  
  return G;
}

void GRAPHInsertE(Graph G, Edge E)
{
  int v = E.v;
  int w = E.w;
  G->adj[v] = New(w, G->adj[v]);
  G->adj[w] = New(v, G->adj[w]);

  G->E++;
}
// ********************************************************************
int *visitados, *con, conectados, conexos;

void dfsR(Graph G, int w)
{
  int t;
  visitados[w] = conectados++;
  link l;

  for (l = G->adj[w]; l != NULL; l = l->next)
  {
    t = l->v;
    if (visitados[t] == -1)
    {
      dfsR(G, w);
      con[t] = conexos;
    }
  }
}

void GRAPHSearch(Graph G)
{
  int v;
  conexos = 0;
  conectados = 0;

  for (v = 0; v < G->V; v++)
    if (visitados[v] == -1)
    {
      con[v] = conexos;
      dfsR(G, v);
      conexos++;
    }
}

int gera_maior_conexao(int v)
{
  int soma[conexos], maior_conexao = 0, maior = 0;

  for (int i = 0; i < conexos; i++)
    soma[i] = 0;

  for (int i = 0; i < v; i++)
    soma[con[i]]++;

  for (int i = 0; i < conexos; i++)
  {
    if (maior < soma[i])
    {
      maior_conexao = i;
      maior = soma[i];
    }
  }
  return maior_conexao;
}

int main()
{
  int qtd_cidades, j;
  int v = -1, w;
  int menorI = 0, i = 0;

  scanf("%d %d", &qtd_cidades, &j);

  Graph G = GRAPHInit(qtd_cidades);

  con = visitados = malloc(sizeof(int) * qtd_cidades);
   
  for (i = 0; i < qtd_cidades; i++)
  {
    con[i] = -1;
    visitados[i] = -1;
  }

  while (scanf("%d %d", &v, &w) == 2)
    GRAPHInsertE(G, EDGE(v, w));

  GRAPHSearch(G);

  int soma[conexos];

  int maior_conexao = gera_maior_conexao(qtd_cidades);

  for (i = 0; i < qtd_cidades; i++)
    if (con[i] == maior_conexao)
    {
      menorI = i;
      break;
    }

  if (v == -1)
    printf("Fique em casa\n");
  else if (soma[maior_conexao] == soma[con[j]])
    printf("Bora pra estrada\n");
  else if (maior_conexao == con[j])
    printf("Bora pra estrada\n");
  else
    printf("Vamos para %d\n", menorI);

  return 0;
}