/*Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
ripetuta, il prodotto dei due numeri e visualizzarli.*/

#include <stdio.h>

int main()
{
    int n1,n2,som,i=0;

    do{
        printf("inserisci il primo numero");
        scanf("%d", &n1);
        printf("inserisci il secondo numero");
        scanf("%d", &n2);
    }while(n1<0 || n2<0);
    
    do{
        som = som+n1;
        printf("%d\n", som);
        i++;
    }while(i<n2);
    
    return 0;

}
