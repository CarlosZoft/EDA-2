#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

char strX[65], strY[65], aux[132];
// HEAP ------------------------------------------------------
#define bigger(a, b) (a > b)
#define swap(A, B)      \
    {                   \
        Position t = A; \
        A = B;          \
        B = t;          \
    }

typedef long int Item;
typedef struct Position
{
    Item x, y, pontuation;
    const char *key;
} Position;

Position pos_dominated;
Position *val_pos_dominate;

int heap_size = 0; 
int value_allocated = 8;   
int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

void insert_heap(Position *arr, Position x)
{
    arr[heap_size + 1] = x;

    int i = heap_size + 1;
    int p = parent(i);

    while (p && bigger(arr[i].pontuation, arr[p].pontuation))
    {
        swap(arr[p], arr[i]);
        i = p;
        p = parent(i);
    }
    heap_size++;
}

Position pop_heap(Position *arr)
{
    Position x = arr[1];
    int i = 1;

    swap(arr[1], arr[heap_size]);
    heap_size--;

    int n = left(i) > heap_size ? 0 : left(i);

    while (n != 0)
    {
        int r = right(i) > heap_size ? 0 : right(i);
        if (r && arr[r].pontuation > arr[n].pontuation)
            n = r;
        else if (arr[i].pontuation < arr[n].pontuation)
        {
            swap(arr[i], arr[n]);
            i = n;
            n = left(i) > heap_size ? 0 : left(i);
        }
        else n = 0;
        
    }

    return x;
}

void printHeap(Position *arr)
{
    Position tmp;

    while (heap_size--)
      tmp = pop_heap(arr);
  
}
void printPosition(Position a)
{
  printf("key=%s\nx=%ld\ny=%ld\npontuation=%ld\n", a.key, a.x, a.y, a.pontuation);
}
void reallocate_heap(Position *heap)
{
    heap = realloc(heap, sizeof(Position) * value_allocated);
}

// HASH ------------------------------------------------
typedef struct node {
  struct node *next;
  long int *value;
  long int x;
  long int y;
  char key[];
} node;

typedef struct table {
  struct node **elems;
  int capacity;
  int size;
} *table;
// Tables ------------------------------------------------
table dominated_positions, probing_positions, val_pos_probing;

static unsigned int hash(const char *key) {
  unsigned int hash = -1;
  while (*key) {
    hash *= 31;
    hash ^= (unsigned char) *key;
    key++;
  }
  return hash;
}


static void extend(table m) {
  if (m->size < m->capacity)
    return;

  int capacity = m->capacity;
  node **elems = m->elems;

  m->capacity *= 2;
  m->elems = calloc(m->capacity, sizeof (node *));

  for (int i = 0; i < capacity; i++) {
    node *curr = elems[i];
    while (curr != NULL) {
      node *next = curr->next;

      int b = hash(curr->key) % m->capacity;
      curr->next = m->elems[b];
      m->elems[b] = curr;

      curr = next;
    }
  }

  free(elems);
  
}

table map_create() {
  table m = malloc(sizeof (table));

  assert(m != NULL);
  m->elems = calloc(1, sizeof (node *));
  assert(m->elems != NULL);

  m->capacity = 1;
  m->size = 0;
  return m;
}

void map_destroy(table m) {

  for (int i = 0; i < m->capacity; i++) {
    node *curr = m->elems[i];
    while (curr != NULL) {
      node *next = curr->next;
      free(curr);
      curr = next;
    }
  }

  free(m->elems);
  free(m);
}

int map_size(const table m) {
  return m->size;
}

bool map_contains(const table m, const char *key) {
  int b = hash(key) % m->capacity;
  node *curr = m->elems[b];

  while (curr != NULL) {
    if (!strcmp(curr->key, key)) return true;
    curr = curr->next;
  }
  
  return false;
}

void map_set(table m, const char *key, Item *value, Item x, Item y) {
  int b = hash(key) % m->capacity;
  node *curr = m->elems[b];

  while(curr != NULL) {
    if (!strcmp(curr->key, key)) {
      curr->value = value;
      curr->x = x;
      curr->y = y;
      return;
    }
    curr = curr->next;
  }

  extend(m);
  b = hash(key) % m->capacity;

  node *new = malloc(sizeof (node) + strlen(key) + 1);
  new->next = m->elems[b];
  new->value = value;
  strcpy(new->key, key);
  m->elems[b] = new;
  m->size ++;
}


node *map_get(const table m, const char *key) {
  int b = hash(key) % m->capacity;

 
  for (node *curr = m->elems[b]; curr != NULL; curr = curr->next) {
    if (!strcmp(curr->key, key)) return curr;
  }

  bool key_found = false;
  assert(key_found);
  exit(1);
}

node *map_remove(table m, const char *key) {
  int b = hash(key) % m->capacity;

  struct node **curr;
  for (curr = &m->elems[b]; *curr != NULL; curr = &(*curr)->next) {
    if (!strcmp((*curr)->key, key)) {

      node *found = *curr;
      *curr = (*curr)->next;

      free(found);
      m->size -= 1;
      return found;
    }
  }

  bool key_found = false;
  assert(key_found);
  exit(1);
}

const char *map_first(table m) {

  for (int i = 0; i < m->capacity; i++) 
    if (m->elems[i] != NULL) 
      return m->elems[i]->key;

  return NULL;
}

const char *map_next(table m, const char *key) {

  node *curr = (void *) (key - sizeof (node));
  if (curr->next != NULL) 
    return curr->next->key;
  

  int b = hash(key) % m->capacity;
  for (int i = b + 1; i < m->capacity; i++) 
    if (m->elems[i] != NULL) 
      return m->elems[i]->key;
  
  return NULL;
}

// Gerando adjacentes
void generate_adj(table map, Item x, Item y)
{
    
    for (int i = -1; i != 2; i++)
    {
        for (int j = -1; j != 2; j++)
        {

            sprintf(strX, "%ld", x + i);
            sprintf(strY, "%ld", y + j);
            char *key = strcat(strcat(strX, "-"), strY);
            if (i == 0 && j == 0)
                continue;
            else if (map_contains(dominated_positions, key))
                continue;
            else if (map_contains(probing_positions, key))
                continue;

            printf("key = %s\n", key);
  
            Item pont = 0;
            //printf("\n%s, %ld, %ld, %ld\n", key, pont, x+i, y+j);
            map_set(map, key, &pont, x+i, y+j);
            strY[0] = strX[0] = aux[0] = '\0';
        }
    }
}

// Funções do jogo

int dominate()
{
    if (heap_size < 1)return 0;
   
    Position best_pos = pop_heap(val_pos_dominate);
    
    printf("dominar %ld %ld\n", best_pos.x, best_pos.y);

    char tipo[10];
    Item pontuation;
    scanf(" %s %ld", tipo, &pontuation);

    pos_dominated.pontuation = pontuation;
    pos_dominated.x = best_pos.x;
    pos_dominated.y = best_pos.y;
    pos_dominated.key = best_pos.key;

    return 1;
}

void probing()
{   
    if(!map_size(val_pos_probing)) return;
    const char *key = map_first(val_pos_probing);
    printf("key ===  %s", key);
    node *position = map_remove(val_pos_probing ,key);
    map_set(probing_positions, key, position->value, position->x, position->y);
    printf("sondar %ld %ld\n", position->x, position->y);
    
    char tipo[10]; 
    Item linha, coluna, pontuation;
    scanf(" %s %ld %ld %ld", tipo, &linha, &coluna, &pontuation);

    Position temp;
    temp.x = linha;
    temp.y = coluna;
    temp.pontuation = pontuation;
    temp.key = key;
    printPosition(temp);
    insert_heap(val_pos_dominate, temp);
}

void run_strategy()
{
    int qtd_mov_turno = map_size(dominated_positions);
    int is_dominated = dominate();

    while (qtd_mov_turno--)
      probing();
    
    if (is_dominated)
    {
        map_set(dominated_positions, pos_dominated.key, &pos_dominated.pontuation, pos_dominated.x, pos_dominated.y);
        generate_adj(val_pos_probing, pos_dominated.x, pos_dominated.y);
    }
    printf("fimturno\n");
}



int main () {
  dominated_positions = map_create();
  probing_positions = map_create();
  val_pos_probing = map_create();
  val_pos_dominate = malloc(sizeof(Position) * value_allocated);

  Item pontuation, turns, x, y;

  scanf("%ld %ld %ld %ld", &x, &y, &pontuation, &turns);
  sprintf(strX, "%ld", x);
  sprintf(strY, "%ld", y);

  char *key = strcat(strcat(strX, "-"), strY);
  map_set(dominated_positions, key, &pontuation, x, y);
  strY[0] = strX[0] = aux[0] = '\0';
  generate_adj(val_pos_probing, x, y);

  while(turns--)
        run_strategy();
  
  printf("valor encontrado = %ld\n", *map_get(dominated_positions, "5-5")->value);
  printf("valor encontrado = %ld\n", *map_get(val_pos_probing, "4-4")->value);
  return 0;
}