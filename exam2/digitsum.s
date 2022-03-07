
/*
int digitsum(int d1,int d2, int d3){

    int sum =0;
    int sum = d1 + d2 + d3;
    return sum
    
    int i = 0;
    while(i<3){
      
    }

}
*/


.global digitsum
.cpu cortex-a53
.text

digitsum:
        mov r3,#0
        add r0,r0,r1
        add r3,r0,r2
        mov r0,r2
        bx lr
        
