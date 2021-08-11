#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 101

int N;
char ht[M][15];
char NULLitem[] = "NULL_KEY";

int hashU(char *v){
    int h,i=1;
    for(h=0;*v!='\0';v++){
        h += i*(*v);
        i++;
    }
    return (h*19) % M;
}


void HTInit(){
    int i;
    N=0;
    for(i=0;i<M;i++)
        strcpy(ht[i],NULLitem);
}

int HTcount(){return N;}


int HTsearch(char *v){
    int i = hashU(v);
    int j=1;
    int pos=i;
    while (j<20)
    {
        if(strcmp(ht[pos],v)==0)
            return pos;
        else{
            pos = (i + (j*j) + 23*j) % M;
            j++;
        }
    }
    return -1;
    
}

void HTinsert(char *v){
    int i = hashU(v);
    int j = 1;
    int pos = i;
    int find = HTsearch(v);
    if(find==-1){

        while(strcmp(ht[pos],NULLitem)!=0){
            if(j>=20){
                return;
            }
            pos = (i +(j*j) +23*j)%M;
            j++;
            
        }
        strcpy(ht[pos],v);
        N++;
    }
}


void HTdelete(char *v){
    int find = HTsearch(v);
    if(find!=-1){
        strcpy(ht[find],NULLitem);
        N--;
    }
}



int main(int argc, char const *argv[])
{
    int t,n;
    char s[40];

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        HTInit();

        for(int i=0;i<n;i++){
            scanf("%s", s);

            char *op = strtok(s, ":");
            char *chave = strtok(NULL,"");

            if(op[0]=='A'){
                HTinsert(chave);
            }else{
                HTdelete(chave);
            }
        }

        printf("%d\n",HTcount());
        for(int i=0;i<101;i++){
            if(strcmp(ht[i],NULLitem)!=0)
            printf("%d:%s\n",i,ht[i]);
        }


    }

    
    // HTInit(101);

    // while (scanf("%s", s)==1)
    // {
    //     HTinsert(s);
    //     int pos = HTsearch(s);
    //     printf("\n%d : %s\n",pos,ht[pos]);
    //     HTInit(101);
    // }
    
    // HTinsert(s);

    // scanf("%s", s);

    // scanf("%s", s);
    // HTinsert(s);


    // scanf("%s", s);
    // HTinsert(s);



    // scanf("%s", s);
    // HTdelete(s);

    // for(int i=0;i<101;i++){
    //     if(strcmp(ht[i],"\0")!=0)
    //         printf("\n%d : %s\n",HTsearch(ht[i]),ht[i]);
    // }


    return 0;
}


