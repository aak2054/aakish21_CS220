#include <stdio.h>

void int2bin(int n){
	char snum[1024];
	int org_n = n;
	int i = 0;
	while(n>0){
	if(n%2==1){
           snum[i]=1;
	   n=n/2;
	   i++;
	}
	else{
	    snum[i]=0;
            n= n/2;
            i++;
         }

    }
	printf("%d=",org_n);
        for(int z=i-1; z>=0;z--){
	    printf("%d",snum[z]);
	}
       printf("\n");
}




