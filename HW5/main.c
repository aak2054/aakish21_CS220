// Homework 5 Due Monday, April 4
// Anamo Kisho, CS220 Spring 22

#include "simulate.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

     // TODo verify command line argument 
     if(argc != 3){
	   printf("Error: Wrong number of argument\n");
           return 0;
     }

     int n = atoi(argv[1]);
     int runs = atoi(argv[2]);
     int sum = 0;

     for(int i = 0; i<runs; i++){
         sum = sum + simulate(n);
     }

     // cast runs to a double
     printf("%.2f\n", sum/(double)runs);
}
