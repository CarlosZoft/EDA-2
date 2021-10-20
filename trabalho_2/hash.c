#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct node {
  struct node *next;
  long int *value;
  char key[];
} node;

typedef struct table {
  struct node **elems;
  int capacity;
  int size;
} *table;

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

void map_set(table m, const char *key, long int *value) {
  int b = hash(key) % m->capacity;
  node *curr = m->elems[b];

  while(curr != NULL) {
    if (!strcmp(curr->key, key)) {
      curr->value = value;
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
  m->size += 1;
}


long int *map_get(const table m, const char *key) {
  int b = hash(key) % m->capacity;

 
  for (node *curr = m->elems[b]; curr != NULL; curr = curr->next) {
    if (!strcmp(curr->key, key)) return curr->value;
  }

  bool key_found = false;
  assert(key_found);
  exit(1);
}

long int *map_remove(table m, const char *key) {
  int b = hash(key) % m->capacity;

  struct node **curr;
  for (curr = &m->elems[b]; *curr != NULL; curr = &(*curr)->next) {
    if (!strcmp((*curr)->key, key)) {

      node *found = *curr;
      *curr = (*curr)->next;

      long int *value = found->value;
      free(found);
      m->size -= 1;
      return value;
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


int main () {
  table teste = map_create();
  long int value = 123123;
  long int value2 = 12312;
  long int value3 = 11;
  long int value4 = -50;

  map_set(teste, "1-1", &value);
  map_set(teste, "1-2", &value2);
  map_set(teste, "1-3", &value3);
  map_set(teste, "2-2", &value4);

  printf("valor encontrado = %ld\n", *map_get(teste, "1-1"));
  printf("valor encontrado = %ld\n", *map_get(teste, "1-2"));
  printf("valor encontrado = %ld\n", *map_get(teste, "1-3"));
  printf("valor encontrado = %ld\n", *map_get(teste, "2-2"));
  return 0;
}