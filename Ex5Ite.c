/*Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. */

#include <stdio.h>

int main()
{
    int n1,n2,i=0;
    
    do{
        printf("inserisci il primo numero\n");
        scanf("%d", &n1);
        
         printf("inserisci il secondo numero.ATTENTO il secondo numero deve essere maggiore del primo\n");
        scanf("%d", &n2);
        
    }while(n2<n1);
    
    do{
        i++;
        if(i>=n1 && i<=n2){
            printf("%d\n", i);
        }
        
    }while(i<n2);
    return 0;
}
