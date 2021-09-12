#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Item;
typedef struct caracter
{
  int chave;
  int valor;
} charMap;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define hash(A, B) (A % B)

void merge(charMap *v, int left, int half, int right)
{
  charMap *arr = malloc(sizeof(charMap) * (right - left + 1));

  int i = left, j = half + 1,
      pos = 0;

  while (i <= half && j <= right)
  {
    if (v[i].valor < v[j].valor)
      arr[pos++] = v[i++];
    else if (v[i].valor == v[j].valor)
    {
      if (v[i].chave < v[j].chave)
        arr[pos++] = v[i++];
      else
        arr[pos++] = v[i++];
    }
    else
      arr[pos++] = v[j++];
  }
  while (i <= half)
    arr[pos++] = v[i++];
  while (j <= right)
    arr[pos++] = v[j++];

  // Merge
  for (int i = left; i <= right; ++i)
    v[i] = arr[i - left];

  free(arr);
}

void mergeSort(charMap *v, int left, int right)
{
  if (left < right)
  {
    int half = (left + right) / 2;
    mergeSort(v, left, half);
    mergeSort(v, half + 1, right);
    merge(v, left, half, right);
  }
}

void fillArray(charMap *arr, int size)
{
  for (int i = 0; i < size; i++)
    arr[i].valor = 0;
}
int main(int argc, char const *argv[])
{
  char string[1001];
  charMap map[130];
  fillArray(map, 130);

  while (scanf(" %s", string) == 1)
  {
    for (int i = 0; i < strlen(string); i++)
    {
      int pos = (int)string[i];
      map[pos].valor++;
      map[pos].chave = pos;
    }
    mergeSort(map, 0, 130 - 1);

    for (int i = 0; i < 130; i++)
      if (map[i].valor)
        printf("%d %d\n", map[i].chave, map[i].valor);

    fillArray(map, 130);
  }
  return 0;
}
