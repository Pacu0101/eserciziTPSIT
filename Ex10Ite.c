/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri dispari.*/

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
        if(i%2 != 0){
             som=som+i;
      
        }
       
        
    }while(i<n);


    printf("la somma e: %d", som);
    
    return 0;


}
