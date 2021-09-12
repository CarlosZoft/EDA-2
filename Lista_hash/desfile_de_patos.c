#include <stdio.h>

typedef long int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define hash(A, B) (A % B)
#define exch(A, B) \
  {                \
    Item t = A;    \
    A = B;         \
    B = t;         \
  }
#define cmpexch(A, B) \
  {                   \
    if (less(B, A))   \
      exch(A, B);     \
  }

void fillArray(Item *arr, int size)
{
  for (int i = 0; i < size; i++)
    arr[i] = 0;
}
void fillArrayAlterados(Item *arr, Item *arrAlter, int size)
{
  for (int i = 0; i < size; i++)
  {
    arr[arrAlter[i]] = 0;
    arrAlter[i] = 0;
  }
}

int main(int argc, char const *argv[])
{
  int qtdPatos = 0, lengthArray = 1000001;
  Item arrayCores[lengthArray];
  fillArray(arrayCores, lengthArray);
  Item alterados[5001];

  while (1)
  {
    scanf("%d", &qtdPatos);
    if (!qtdPatos)
      return 0;
    Item cor = 0, maior = 0, index = 0, len = 0;
    for (int i = 0; i < qtdPatos; i++)
    {
      scanf("%ld", &cor);
      arrayCores[cor]++;
      if (arrayCores[cor] > maior)
      {
        maior = arrayCores[cor];
        index = cor;
      }
      alterados[len++] = cor;
    }
    fillArrayAlterados(arrayCores, alterados, len);
    if (qtdPatos)
      printf("%ld\n", index);
  }

  return 0;
}
