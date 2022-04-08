// Homework 6 Due Friday, April 8
// Anamo Kisho, CS220 Spring 22

#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"
#include "pow.h"

int main(int argc, char * argv[]) {

    // TODO sanitize the input

    if(argc == 2){
         double x = atoi(argv[1]);
	 printf("%f\n", fabs(x));
         return 0;
    }
   
    if(argc == 3){
         int n = atoi(argv[1]);
         int m = atoi(argv[2]);

	 printf("%d\n", pow1(n,m));
         return 0;
    }
    
    if(argc != 3){
	   printf("Error: Wrong number of argument\n");
           return 0;
	}
    
}