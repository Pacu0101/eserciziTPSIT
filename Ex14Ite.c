/*Data una misura di tempo espressa in secondi S1, convertirla in ore H,
minuti M e secondi S.

Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
dal programma, 0h 27m 10s.*/

#include <stdio.h>

int main()
{
    int s1,ore=0,minuti=0,secondi=0;
    
    
    printf("inserisci i secondi\n");
    scanf("%d", &s1);
    
    for(int i=0;i<s1;i++){
        secondi++;
        if(secondi>=60){
            minuti++;
            secondi=0;
        }

        if(minuti>=60){
            ore++;
            minuti=0;
        }
    }
    
    printf("%dh %dm %ds", ore,minuti,secondi);
   

    return 0;

}
