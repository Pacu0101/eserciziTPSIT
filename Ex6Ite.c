/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N. */

#include <stdio.h>

int main()
{
    int n,i=0;
    
    do{
        printf("inserisci un numero intero positivo\n");
        scanf("%d", &n);
    }while(n<0);
    
    i = -n;
    
    do{
        i++;
        printf("%d\n", i);
    }while(i<n);
    
    return 0;
}
