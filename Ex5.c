/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/

#include <stdio.h>
int main(){
    int a,b,somma=0,cont=0,n;
    float media;

    do{
        printf("inserisci il primo numero");
        scanf("%d", &a);
        printf("inserisci il secondo numero");
        scanf("%d", &b);
    }while(a>b);

    do{
        printf("\ninserisci un numero che sia nell' intervalo tra il primo e il secondo numero");
        scanf("%d", &n);

        if(n>=a && n<=b){
            somma = somma+n;
            cont++;
        }

    }while(n>=a && n<=b);

    media=somma/cont;
    printf("la media e: %.2f", media);

    return 0;
}
