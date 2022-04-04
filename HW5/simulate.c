#include "simulate.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int simulate(int n){

    const int DAYS = 366;
    int cal[366];
     
    // a static varibale retains its values
    static int seedhack = 0;
    srand(time(NULL) + seedhack++);
    memset(cal, 0, DAYS*sizeof(int));

    int i = 0;
    while(i<n){
       cal[rand() % DAYS]++;
       i++;
     }

    i = 0;
    while(i<DAYS){
       if(cal[i]>1 ){
            return 1;
       }
       i++;
     }

    return 0;


}