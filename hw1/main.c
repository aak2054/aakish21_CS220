
// Homework 1 Due Friday, January 28
// Anamo Kisho, CS220 Spring 22

//angle brackets around a header file indicate that
//it is a system header file.

#include <stdio.h>

#include "sum3or5.h"
#include "sequence.h"
#include "diamond.h"


int main(void){
	printf("sum3or5 of 10 is %d\n", sum3or5(1000));

	printf("sequence of 10 is %d\n", sequence(10));
	
        printf("The longest sequence is %d\n", longest());
	
	int input;

        printf("Enter non-negative odd integer: ");
    	scanf("%d", &input);

        diamond(input);
	
	
	

}