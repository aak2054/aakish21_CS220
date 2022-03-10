// Homework 4 Due Friday, March 11
// Anamo Kisho, CS220 Spring 22

#include <stdio.h>
#include <stdlib.h>
#include "sum3or5.h"
#include "sequence.h"
#include "verifyarg.h"
#include <string.h>

int main(int argc, char*argv[]){
        
        if(argc != 2){
	   printf("Error: Wrong about of argument\n");
           return 0;
	}

        char *strv = argv[1];
        int x = atoi(argv[1]);

        verifyarg(strv);

	printf("sum3or5 of %d is %d\n",x, sum3or5(x));
        printf("sequence of %d is %d\n",x, sequence(x));

}