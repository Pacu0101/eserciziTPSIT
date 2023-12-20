

#include <stdio.h>
void main(){

int n,scelta;
float sconto;

do{
    printf("inserisci una somma di dennaro: ");
        scanf("%i", &n);

        if(n>0 && n<=500){

            sconto= (n*10)/100;

            printf("Ecco il prezzo del tuo prodotto con lo sconto del 10 per cento: %.2f", sconto);
            
        }


        if(n>500 && n<=1000){

            sconto= (n*20)/100;

            printf("Ecco il prezzo del tuo prodotto con lo sconto del 20 per cento: %.2f", sconto);
            
        }

        
        if(n>1000){

            sconto= (n*30)/100;

            printf("Ecco il prezzo del tuo prodotto con lo sconto del 30 per cento: %.2f", sconto);
            
        }

        printf("\nPer inserire altre somme di denaro inserire il numero 1 ");
        printf("\nPer finire il programma inserire qualunque altro numero: ");
            scanf("%i", &scelta);

}while(scelta==1);
    
}