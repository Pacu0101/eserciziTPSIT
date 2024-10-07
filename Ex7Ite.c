/*Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente. */

#include <stdio.h>

int main()
{
    int n,i;
    
    do{
        printf("inserire un numero maggiore di 1\n");
        scanf("%d", &n);
        
    }while(n<1);
    
    i=n-1;
    printf("%d",i);
    
    return 0;
}
