#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
typedef long int Item;
#define key(a) (a)
#define bigger(a, b) (a > b)
#define notEquals(a, b) (key(a) != key(b))

long int x, y, pontuation, turns; // dados a serem lidos no incício do jogo
int edazinhos = 1;           // quantidade de movimentos = qtd de EDAzinhos
int turn_mov = 1;            // quantidade de movimentos no turno
int value_allocated = 8;     // valor de alocação para realloc
int heap_size = 0;           // tamanho da heap = quantidade de valores possíveis de dominar

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

//  POSITION ------------------------------------------------------
typedef struct Position
{
    Item x, y, pontuation;
    int is_valid;

} Position;

#define swap(A, B)      \
    {                   \
        Position t = A; \
        A = B;          \
        B = t;          \
    }

// Critério de ordenação
int less(Position a, Position b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

Position *create_position(Item x, Item y, Item pontuation)
{
    Position *pos = malloc(sizeof(Position));
    pos->x = x;
    pos->y = y;
    pos->pontuation = pontuation;

    return pos;
}

// SET ------------------------------------------------------

typedef struct Set
{
    Position *arr;
    unsigned int capacity; // Capacidade total
    unsigned int size;     // Qtd de elementos já inseridos
} Set;

// Posições já dominadas
Set *dominated_positions;

// Posições já sondadas
Set *probing_positions;

// Posições válidas para sondagem
Set *val_pos_probing;

// Posições válidas para dominar
Position *val_pos_dominate;
int len_val_pos_dominate = 0;

// Posições sondadas na rodada anterior
Position *pos_sondagem_prev;

// Posição dominada na rodada anterior
Position pos_dominated;

Set *create_set()
{
    Set *set = malloc(sizeof(Set));
    set->size = 0;
    set->capacity = value_allocated;
    set->arr = (Position *)malloc(sizeof(Position) * set->capacity);

    return set;
}

void reallocate_set(Set *set)
{
    set->capacity = set->capacity * 2;
    set->arr = (Position *)realloc(set->arr, sizeof(Position) * set->capacity);
}

Position random_remove(Set *set)
{
    int prev = 1;
    int i = 1;

    while (i < set->capacity && set->arr[i].is_valid)
    {
        prev = i;
        i = right(i);
    }

    set->arr[prev].is_valid = 0;
    set->size -= 1;

    return set->arr[prev];
}

void insert_set(Set *set, Item x, Item y, Item pontuation)
{
    int i = 1;
    while (set->arr[i].is_valid)
    {
        if (set->arr[i].x == x && set->arr[i].y == y)
            return;
        if (x < set->arr[i].x)
            i = left(i);
        else if (x > set->arr[i].x)
            i = right(i);
        else if (y < set->arr[i].y)
            i = left(i);
        else if (y > set->arr[i].y)
            i = right(i);
        if (i >= set->capacity)
            reallocate_set(set);
    }
    set->arr[i].pontuation = pontuation;
    set->arr[i].x = x;
    set->arr[i].y = y;
    set->arr[i].is_valid = 1;
    set->size += 1;
}

void print_set(Set *set)
{
    printf("set->size = %d\n", set->size);
    for (int i = 0; i < set->capacity; i++)
    {
        if (set->arr[i].is_valid)
            printf("idx = %d  -- (x=%ld, y=%ld)   --  VALID = %d\n", i, set->arr[i].x, set->arr[i].y, set->arr[i].is_valid);
        else
        {
            printf("idx = %d  -- (x=X, y=X)\n", i);
        }
    }
    printf("****************************************************************\n");
}

void destroy_set(Set *set)
{
    free(set->arr);
    free(set);
}
int position_exists_set(Set *set, Item x, Item y)
{
    int i = 1;
    while (set->arr[i].is_valid)
    {
        if (set->arr[i].x == x && set->arr[i].y == y)
            return 1;
        if (x < set->arr[i].x)
            i = left(i);
        else if (x > set->arr[i].x)
            i = right(i);
        else if (y < set->arr[i].y)
            i = left(i);
        else if (y > set->arr[i].y)
            i = right(i);
        if (i >= set->capacity)
            return 0;
    }
    return 0;
}

// HEAP ------------------------------------------------------
void insert_heap(Position *arr, Position x)
{
    arr[heap_size + 1] = x;
    //printf("(%ld, %ld) = %ld\n", arr[heap_size + 1].x, arr[heap_size + 1].y, arr[heap_size + 1].pontuation);

    // pos do valor que acabou de entrar
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
        else
        {
            n = 0;
        }
    }

    return x;
}

void printHeap(Position *arr)
{
    Position tmp;

    while (heap_size--)
    {
        tmp = pop_heap(arr);
        //printf("Pontuation é %ld\n", tmp.pontuation);
    }
}

void reallocate_heap(Position *heap)
{
    heap = realloc(heap, sizeof(Position) * value_allocated);
}

// ------------------------------------------------------------

void generate_adj(Set *set, Item x, Item y)
{
    for (int i = -1; i != 2; i++)
    {
        for (int j = -1; j != 2; j++)
        {

            if (i == 0 && j == 0)
                continue;
            else if (position_exists_set(dominated_positions, x + i, y + j))
                continue;
            else if (position_exists_set(probing_positions, x + i, y + j))
                continue;

            //printf("x= %ld, y= %ld\n", x + i, y + j);
            insert_set(set, x + i, y + j, 0);
        }
    }
}

/*
 * Pega a melhor pontuação, domina e add na posição dominada na rodada
 */
int dominate()
{
    if (heap_size < 1)
    {
        return 0;
    }
    Position best_pos = pop_heap(val_pos_dominate);

    char str[100];
    printf("dominar %ld %ld\n", best_pos.x, best_pos.y);

    char tipo[10];
    Item pontuation;
    scanf(" %s %ld", tipo, &pontuation);

    pos_dominated.pontuation = pontuation;
    pos_dominated.x = best_pos.x;
    pos_dominated.y = best_pos.y;
    edazinhos++;

    return 1;
}

void probing()
{
    Position pos_prob = random_remove(val_pos_probing);
    insert_set(probing_positions, pos_prob.x, pos_prob.y, pos_prob.pontuation);
    char str[100];
    printf("sondar %ld %ld\n", pos_prob.x, pos_prob.y);
    
    char tipo[10]; 
    Item linha, coluna, pontuation;
    scanf(" %s %ld %ld %ld", tipo, &linha, &coluna, &pontuation);

    Position temp;
    temp.x = linha;
    temp.y = coluna;
    temp.pontuation = pontuation;

    pos_prob = temp;
    insert_heap(val_pos_dominate, pos_prob);
}

void run_strategy()
{
    int qtd_mov_turno = edazinhos;
    int is_dominated = dominate();

    while (qtd_mov_turno--)
    {
        probing();
    }
    if (is_dominated)
    {
        insert_set(dominated_positions, pos_dominated.x, pos_dominated.y, pos_dominated.pontuation);
        generate_adj(val_pos_probing, pos_dominated.x, pos_dominated.y);
    }
    printf("fimturno\n");
}
// -----------------------------------------------------------

int main()
{
    clock_t tic = clock();
    dominated_positions = create_set();
    probing_positions = create_set();
    val_pos_probing = create_set();

    pos_sondagem_prev = malloc(sizeof(Position) * value_allocated);
    val_pos_dominate = malloc(sizeof(Position) * value_allocated);

    scanf("%ld %ld %ld %ld", &x, &y, &pontuation, &turns);
    insert_set(dominated_positions, x, y, pontuation);
    generate_adj(val_pos_probing, x, y);

    for (int i = 1; i <= turns; i++)
    {
        run_strategy();
    }

    destroy_set(probing_positions);
    destroy_set(val_pos_probing);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  
    return 0;
}