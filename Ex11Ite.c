/*Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine decrescente i numeri compresi tra N1 e N2.  */

#include <stdio.h>

int main()
{
    int n1,n2,i=0;
    
    do{
        printf("inserisci il primo numero\n");
        scanf("%d", &n1);
        printf("inserisci il secondo numero\n");
        scanf("%d", &n2);
    }while(n2<n1);
    
    i=n2;
    
    do{
        i--;
        printf("%d\n", i);
        
    }while(i>n1);
    
    return 0;
}
