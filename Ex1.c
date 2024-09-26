
/*Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/
#include <stdio.h>
int main(){

    float n,n1;
    float div=0;
   do
    {
        printf("inserisci il primo numero\n");
        scanf("%f", &n);
        printf("inserisci il secondo numero\n");
        scanf("%f", &n1);

        if(n<n1){
            div=n/n1;
        }

        else{
            div=n1/n;
        }

        printf("risultato %f\n", div);

    } while(n!=0 && n1!=0);

    printf("hai inserito uno o due 0 nella divisione");
}
