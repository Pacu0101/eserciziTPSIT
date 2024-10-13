/*Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
danno per somma il numero stesso. Non considerare la proprietà commutativa. */

#include <stdio.h>

int main()
{   
    int n,cont=1,x;
    
    do{
        
        printf("inserisci un numero\n");
        scanf("%d", &n);
        
    }while(n<=0);
    
    x = n-1;
    
    do{
  
        printf("%d+%d=%d\n", cont,x,n );
            
        
           cont++;
           x--;
        
    }while(cont<n);
    
    return 0;
}
