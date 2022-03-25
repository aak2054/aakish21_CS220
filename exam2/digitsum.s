
/*
int digitsum(int x){
     
    int sum = 0;

    while(x>0){
      sum += x % 10;
      x = x /10;
    }
   
    return sum;

}
*/


.global digitsum
.cpu cortex-a53
.text

mod:
   sdiv r2, r0,r1
   mul  r2, r2,r1
   sub  r0, r0,r2
   bx lr 

digitsum:
 	push {r4-r7,lr}
        mov r4,r0 //x
        mov r5,#0 // sum
        mov r6, #10 
        mov r7, #0
while: // top of the while loop
     cmp r4,r7
     beq endwhile
     mov r0, r4 // set up arguments to mod
     mov r1, r6 
     bl mod       
     add r5, r5,r0
     sdiv r4,r4,r6 
     b while 
 
endwhile:
     mov r0, r5  // return sum
     pop {r4-r7,lr}
     bx lr
     
