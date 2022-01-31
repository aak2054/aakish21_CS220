#include <stdio.h>

void diamond(int input){

    while(input != -1){
	
    for (int i = 1; i <= input; i++){
    
        for (int j = i; j <= input; j++){
        printf(" ");
	}        
        
        for (int x = 1; x <= 2*i-1; x++){
        printf("*");
        }
        printf("\n");    
    }    
    
    // for decrement 
    for (int i= input-1; i >= 1; i--){
    
        for (int j= input; j >= i; j--){
        printf(" ");
        }
        
        for (int x = 1 ; x <= 2*i-1; x++){
        printf("*");
        }
        printf("\n"); 
     }   
        
    printf("Enter non-negative odd integer: ");
    scanf("%d", &input);
   }

if(input==-1){
printf("BYE!!!\n");
//printf("\n");
}
    
}