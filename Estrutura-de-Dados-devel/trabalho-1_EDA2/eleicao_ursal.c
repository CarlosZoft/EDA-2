#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int voto,freq;
}Item;

#define Key(A)(A.freq) // Key(A) (A.chave)

#define KeyV(A)(A.voto) // Key(A) (A.chave)

#define less(A,B) (Key(A)<Key(B))

#define lesseq(A,B) (Key(A)<=Key(B))

#define lesseqV(A,B) (KeyV(A)<=KeyV(B))


#define exch(A,B) {Item t = A; A=B; B=t;}

#define cmpexch(A,B){if(less(B,A)) exch(A,B);}


void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0, i=l, j=r1+1;
    while(i<=r1 && j<=r2){
        if(lesseq(v[i],v[j]))
            v2[k++]=v[i++];
        else
            v2[k++]=v[j++];
    }
    while(i<=r1)
        v2[k++]=v[i++];
    while(j<=r2)
        v2[k++]=v[j++];
    k=0;
    for(i=l;i<=r2;i++){
        v[i]=v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);
}

void mergeV(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k=0, i=l, j=r1+1;
    while(i<=r1 && j<=r2){
        if(lesseqV(v[i],v[j]))
            v2[k++]=v[i++];
        else
            v2[k++]=v[j++];
    }
    while(i<=r1)
        v2[k++]=v[i++];
    while(j<=r2)
        v2[k++]=v[j++];
    k=0;
    for(i=l;i<=r2;i++){
        v[i]=v2[k++];
    }
    free(v2);
}

void mergeSortV(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    mergeSortV(v,l,meio);
    mergeSortV(v,meio+1,r);
    mergeV(v,l,meio,r);
}









Item ht[1000000];

int majority(int *v,int size){
    int major;
    int cnt=0;
    major = v[0];
    for(int i=0;i<size;i++){
        if(v[i]==major){
            cnt++;
        }else if(v[i]!=major){
            cnt--;
            if(cnt==0){
                major=v[i];
            }
        }
    }
    return major;
}

int confirmMajor(int *v, int size){
    int major = majority(v,size);
    int cnt=0;
    int half = size/2;
    for(int i=0;i<size;i++){
        if(v[i]==major) cnt++;
    }

    return cnt>half;

}




int main(int argc, char const *argv[])
{
    int s,f,e,n;
    int *P;
    
    for(int i=0;i<1000000;i++){
        ht[i].voto=0;
        ht[i].freq=0;
    }


    int total_p=0,total_invalido=0,total_valido=0;
    int total_s=0;

    scanf("%d %d %d", &s, &f, &e);

    P = malloc(sizeof(int)*8);

    while(scanf("%d",&n)==1){
        if(n>0){
            if(n<100){
                P[total_p++]=n;
                total_valido++;
                if(total_p>total_p%8){
                    P = realloc(P,sizeof(int)*(total_p+8));
                }
            }
            if(n>=100 && n < 1000000){
                ht[n].voto = n;
                ht[n].freq++;
                total_valido++;
            }
        }
        else{
            total_invalido++;
        }
    }

    mergeSortV(ht,100,999);
    mergeSort(ht,100,999);

    mergeSortV(ht,1000,9999);
    mergeSort(ht,1000,9999);

    mergeSortV(ht,10000,99999);
    mergeSort(ht,10000,99999);

    printf("%d %d\n",total_valido, total_invalido);

    if(confirmMajor(P,total_p))
        printf("%d\n", majority(P,total_p));
    else{
        printf("Segundo turno\n");
    }

    for(int i=999;i>99;i--){
        if(ht[i].voto!=0)
            if(s!=0){
                printf("%d", ht[i].voto);
                s--;
                if(s!=0){
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
    }

    for(int i=9999;i>999;i--){
        if(ht[i].voto!=0)
            if(f!=0){
                printf("%d", ht[i].voto);
                f--;
                if(f!=0){
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
    }

    for(int i=99999;i>9999;i--){
        if(ht[i].voto!=0)
            if(e!=0){
                printf("%d", ht[i].voto);
                e--;
                if(e!=0){
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
    }

    return 0;
}
