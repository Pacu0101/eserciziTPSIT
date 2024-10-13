/*Dato un numero intero positivo N verificare se N è un numero primo.*/

#include <stdio.h>

int main()
{   
    int n;
    
    do{
        printf("inserisci un numero\n");
        scanf("%d", &n);
    }while(n<=0);
    
    if(n%2!=0){
        printf("il numero inserito e un numero primo");
    }
    
    else{
        printf("il numero inserito non e un numero primo");
    }
    
    return 0;
}
