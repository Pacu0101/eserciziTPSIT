

#include <stdio.h>
int main(){
    int n1,n2,prod,somProd=0;

    do{
        printf("\ninserisci il primo numero");
        scanf("%d", &n1);
        printf("\ninserisci il secondo numero");
        scanf("%d", &n2);

        prod=n1*n2;
        printf("\nProdotto: %d ", prod);
        somProd=somProd+prod;

    }while(n1!=0 && n2!=0);

    printf("\nLa somma e: %d", somProd);

}