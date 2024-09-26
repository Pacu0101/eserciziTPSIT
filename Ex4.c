/*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/

#include <stdio.h>
int main(){
    int a, b ,c;
    int diff;
    int pari=0,dispari=0,null=0;

    do{
        printf("inserisci il primo numero");
        scanf("%d", &a);
        printf("inserisci il secondo numero");
        scanf("%d", &b);
        printf("inserisci il terzo numero");
        scanf("%d", &c);
        
        diff = a-c;

        if(diff==0){
            null++;
        }

        if(diff %2==0){
            pari++;
        }
        
        else{
            dispari++;
        }

    }while(a + b>=c);

    printf("\nla differenza e stata zero %d volte", null);
    printf("\nla differenza e stata pari %d volte", pari);
    printf("\nla differenza e stata dispari %d volte", dispari);
}
