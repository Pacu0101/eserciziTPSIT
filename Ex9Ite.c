
/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri interi.   */

#include <stdio.h>

int main()
{
    int n,i=0,som;
    
    do{
        printf("inserisci un numero positivo intero\n");
        scanf("%d", &n);
    }while(n<=0);
    
    do{
        i++;
        som=som+i;
        
    }while(i<n);
   
    printf("la somma e: %d", som);
    
    return 0;
}
