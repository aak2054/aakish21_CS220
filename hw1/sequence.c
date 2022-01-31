
int sequence(int n){
	
	int z = 1;

	while(n>1){
	  if(n%2==0){
	    n=n/2;
	}
	else{
	    n = 3*n+1;	
	}
	z+=1;

   }
return z;

}

	
int longest(void){
    int longlen = 0;
    long long num = 0;
    int finalnum = 0;
    int Slength = 0;

    for (long long i = 1; i <= 1000000; i++) {
        Slength = 1;
        num = i;
        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = 3 * num + 1;
            }
            Slength++;
        }
        if (Slength > longlen) {
            longlen = Slength;
            finalnum = i;
        }
    }

    return finalnum;
}
