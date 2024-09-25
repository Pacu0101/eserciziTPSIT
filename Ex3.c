#include <stdio.h>
#include <math.h>
int main()
{
    int n,n1;
    float div,radice;
    
    do{
        printf("\ninserisci il primo numero reale");
        scanf("%d", &n);
        printf("\ninserisci il secondo numero reale");
        scanf("%d", &n1);
        
        if(n>n1){
            div=n/n1;
        }
        else{
            div=n1/n;
        }
        
        if(div>0){
             radice=sqrt(div);
        printf("\nLa radice e %.2f", radice); 
        }
      
        
    }while(div>0);
    
    printf("\nATTENTO!! Il numero sotto radice era negativo o uguale a zero");
    return 0;
}
