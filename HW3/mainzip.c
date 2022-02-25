// Homework 3 Due Friday, Feb 25
// Anamo Kisho, CS220 Spring 22

#include<stdio.h>
#include<string.h>
#include "distance.h"

int main(int argc, char *argv[]){
	// error checking
	if(argc != 3){
	   printf("Error: Wrong about of argument");
           return 0;
	}
	
	//get our zipcode
	//char zip1[5] = argv[0];
        //char zip2[5] = argv[1];


	//temp val
        char code[6], state[3] , city[30];
        double lng, lat;

	//zip1 information
	char state1[3] , city1[30];
        double lng1, lat1;


	//zip2 information
	char state2[3],city2[30];
        double lng2, lat2;

	//opeing5 file
	FILE *f = fopen("../CS220_data/zips.csv", "r");

	int count = 0;

	while (count<2){
		
		int rc = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",code,state,city,&lng,&lat);
                if (rc==EOF){
		printf("reached end of the file\n");
 		break;
                }
		if(strcmp(code,argv[1])==0){
			strcpy(state1 , state);
                        strcpy(city1, city);
                        lng1 = lng;
                        lat1 = lat;
			count++;
		}

		if(strcmp(code,argv[2])==0){
                        strcpy(state2 , state);
	                //state2 = state;
                        //city2  = city;
                        strcpy(city2, city);
                        lng2 = lng;
                        lat2 = lat;
                      count++;	
		}
		
	}

	double zdist = distance(lat1,lat2,lng1,lng2);

   printf("The distance from %s,%s to %s, %s is %0.1lf miles\n",city1,state1,city2,state2,zdist);




}