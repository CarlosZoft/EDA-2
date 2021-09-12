#include <stdio.h>

typedef int Item;

#define Key(A) (A)

#define less(A, B) (Key(A) < Key(B))

#define lesseq(A, B) (Key(A) <= Key(B))

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

int main(int argc, char const *argv[])
{

  return 0;
}
