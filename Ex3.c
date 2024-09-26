/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/

#include <stdio.h>
#include <math.h>
int main()
{
    int n,n1;
    float div,radice;
    
    do{
        printf("\ninserisci il primo numero reale");
        scanf("%d", &n);
        printf("\ninserisci il secondo numero reale");
        scanf("%d", &n1);
        
        if(n>n1){
            div=n/n1;
        }
        else{
            div=n1/n;
        }
        
        if(div>0){
             radice=sqrt(div);
        printf("\nLa radice e %.2f", radice); 
        }
      
        
    }while(div>0);
    
    printf("\nATTENTO!! Il numero sotto radice era negativo o uguale a zero");
    return 0;
}
