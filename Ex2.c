/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

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
