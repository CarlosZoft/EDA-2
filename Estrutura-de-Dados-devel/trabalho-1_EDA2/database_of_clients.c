#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveChars(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }

    s[writer]=0;
}

int countDistinct(char s[1000][101], int n) 
{ 
    int res = 1; 
  
    // Pick all elements one by one 
    for (int i = 1; i < n; i++) { 
        int j = 0; 
        for (j = 0; j < i; j++) 
            if (strcmp(s[i],s[j])==0) 
                break; 
  
        // If not printed earlier, then print it 
        if (i == j) 
            res++; 
    } 
    return res; 
}

int main(int argc, char const *argv[])
{
    int n, total=0;
    char emails[1000][101],provider[1000][101],s[101],*c;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", s);
        c = strtok(s,"@");
        strcpy(emails[i],c);
        c = strtok(NULL,"@");
        strcpy(provider[i],c);
        c = strtok(s,"+");
        strcpy(emails[i],c);
        RemoveChars(emails[i],'.');
        strcat(emails[i],provider[i]);
    }

    total = countDistinct(emails,n);

    printf("%d\n",total);

    // for(int i=0;i<n;i++){
    //     printf("%s@", emails[i]);
    //     printf("%s\n", provider[i]);
    // }


    return 0;
}
