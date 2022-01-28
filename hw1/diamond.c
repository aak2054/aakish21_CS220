#include <stdio.h>

void diamond(){
 int input, c, k, Slen = 1;
    
    printf("Enter non-negative odd integer: ");
    scanf("%d", &input);
    
    Slen = input - 1;
    
    for (k = 1; k <= input; k++)
    {
    
        for (c = 1; c <= Slen; c++)
        printf(" ");
        
        Slen--;
        
        for (c = 1; c <= 2*k-1; c++)
        printf("*");
        
        printf("\n");    
    
    }    
    Slen = 1;
    
    for (k = 1; k <= input - 1; k++)
    {
    
        for (c = 1; c <= Slen; c++)
        printf(" ");
        
        Slen++;
        
        for (c = 1 ; c <= 2*(input-k)-1; c++)
        printf("*");
        
        printf("\n");    
        
    }
    
}