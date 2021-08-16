#include<stdio.h> 
 
int sep( int v[], int p, int r) {
    int q, i, j, t;
    i = p; q = (p + r) / 2; j = r;
    do {
      while (v[i] < v[q]) ++i;
      while (v[j] > v[q]) --j;
      if (i <= j) {
        t = v[i], v[i] = v[j], v[j] = t;
        ++i, --j;
      }
    } while (i <= j);
    return i-1;
}

int main(int argc, char const *argv[])
{
    int v[] = {106,210,270,67,69,127,303,236,249};

    for(int i=0;i<9;i++){
        printf("%d ", v[i]);
    }

    int i = sep(v,0,9);

    printf("\n\n%d\n\n", i);

    for(int i=0;i<9;i++){
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}
