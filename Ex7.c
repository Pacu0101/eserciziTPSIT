/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande 
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv){

    int n1,bev,som1=0,ris,som2=0,cont1=0,cont2=0;
    char ex[10];
    float med1,med2;

    do{
        do{
        printf("inserire la tipologia di consumazione.Inserire 1 per bevande.Inserire 2 per ristorazione\n");
            scanf("%d",  &n1);
        }while(n1!=1 && n1!=2);
        
        if(n1==1){
            printf("inserire la quantita di bevande\n");
            scanf("%d", &bev);
            som1=som1+bev;
            cont1++;
        }

        if(n1==2){
            printf("inserire la quantita di ristorazioni\n");
            scanf("%d", &ris);
            som2=som2+ris;
            cont2++;
        }

        printf("Scrivi 'esci' se vuoi finire l'inserimento\n");
        scanf("%s", &ex);

    }while(strcmp(ex,"esci")!=0);

    med1=som1/cont1;
    med2=som2/cont2;

    printf("la media delle bevande e: %.2f\n", med1);
    printf("la media delle ristorazioni e: %.2f\n", med2);

    if(som1>som2){
        printf("sono state vendute piu bevande\n");
    } else if (cont1 < cont2) {
        printf("Sono state vendute più ristorazioni.\n");
    } else {
        printf("Le vendite di bevande e ristorazioni sono uguali.\n");
    }

    return 0;

}