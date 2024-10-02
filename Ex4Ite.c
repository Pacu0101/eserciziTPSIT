/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri pari minori o uguali a N.*/

#include <stdio.h>
int main(){
        int n,crescente=0;

     do{
        printf("inserisci un numero\n");
        scanf("%d", &n);
    }while(n<=0);

     do{
        crescente++;
        if(crescente%2 == 0){
            printf("%d\n", crescente);
        }
        
    }while(crescente<n);

    return 0;
}