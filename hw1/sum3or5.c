
int sum3or5(int n){
	// fill in code here and return
	int sum = 0;
	for(int i = 0; i<n;i++){
	   if(i %3==0 ||i%5==0){
		sum+=i;
	}
    }
	return sum;
}