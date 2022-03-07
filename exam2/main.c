#include <stdio.h>
#include "digitsum.h"
#include <stdlib.h>

int main(int argc, char *argv[]){

     // TODO verify the number of arguments
     if(argc != 1){
	   printf("Error: Wrong about of argument");
           return 0;
     }
     
     int d1 = atoi(argv[1]);
     //int d2 = atoi(argv[2]);
     //int d3 = atoi(argv[3]);
     
      printf("%lf\n", digitsum(d1));
}