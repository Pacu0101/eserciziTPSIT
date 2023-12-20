

#include <stdio.h>
void main()
{
    int i;
    float n,num,cont,contn;
    float media, median;

    printf("Inserisci quanti numeri vuoi scirvere: ");
        scanf("%i", &i);
        n=i;

        while(i>0){

            printf("inserisci dei numeri: ");
                scanf("%f", &num);

            if (num>0){

                cont=cont+num;
                
                media=cont/n;


            }

                 if (num<0){

                contn=contn+num;

                median=contn/n;


            }



            i--;

        }
        printf("\nla somma dei numeri positivi è': %.2f", cont);
        printf("\nla somma dei numeri negativi è': %.2f", contn);
        printf("\nla media dei numeri positivi e': %.2f", media);
        printf("\nla media dei numeri negativi e': %.2f", median);

}