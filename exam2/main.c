#include <stdio.h>
#include "digitsum.h"
#include <stdlib.h>

int main(int argc, char *argv[]){

     // TODO verify the number of arguments
     if(argc != 2){
	printf("Error: Wrong number of arguments\n");
        return 0;
     }

     unsigned int num = atoi(argv[1]);
     printf("%d\n", digitsum(num));
}
