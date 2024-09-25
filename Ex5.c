
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
}