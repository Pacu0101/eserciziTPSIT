/*Dato N un numero intero positivo, generare e visualizzare il numero 
successivo.*/
#include <stdio.h>
int main(){
    int n;

    do{
        printf("inserisci un numero");
        scanf("%d", &n);

    }while(n<0);

    n += 1;

    printf("il numero successivo e: %d", n);
}