#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* verifyarg(char* vstr){
   
    int count=0,i;
    char *str1 = "True";    
    char *str2 = "False";

    for(i=0;i<strlen(vstr);i++){

      if(vstr[i] >= '0' && vstr[i] <= '9'){
        count++;
        }
    }

    if(count!=strlen(vstr)){

      printf("Error: %s\n", str2);
      exit(0);
     }

     printf("%s\n", str1);
     
       
}