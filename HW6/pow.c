

int pow1(int x,int y){
    if(x==0){
       return 0;
     }
    if(y==0){
       return 1;
     }
     if(y%2==0){
       return pow1(x,y/2)*pow1(x,y/2);
     }
    

    return  x*pow1(x,y-1);

}