/*Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato 
di N2.*/
#include <stdio.h>

int main()
{   
       int n,n2;
    
    do{
        
        printf("inserisci un numero\n");
        scanf("%d", &n);
        printf("inserisci un numero\n");
        scanf("%d", &n2);
        
    }while(n<=0);
 
    
    if(n2*n2==n){
        printf("e il quadrato ");
    }else{
        printf(" non e il quadrato ");
    }
    
    return 0;

    
    return 0;
}
