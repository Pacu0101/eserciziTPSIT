/*Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi. */

#include <stdio.h>

int main()
{
    int n;
    
    do{
        printf("inserisci un numero positivo intero\n");
        scanf("%d", &n);
    }while(n<=0);
    
    do{
        n--;
        printf("%d\n", n);
    }while(n>0);
    
    return 0;
}
