
/*
int sum3or5(int n){

    int sum = 0;
    int i = 1;

    while(i<n){
      if(i%3==0 || i%5==0){
        sum +=i;
      }
     i++;
   }
   return sum;

}
*/

.global sum3or5
.cpu cortex-a53
.text

mod:
   sdiv r2, r0,r1
   mul  r2, r2,r1
   sub  r0, r0,r2
   bx lr

sum3or5:
     push {r4-r7,lr}
     mov r3,r0  // n
     mov r4,#0 // sum = 0
     mov r5,#1  // i = 1
     mov r6, #3
     mov r7, #5

while:     // top of the while loop
     cmp r5,r3
     bge endwhile
     mov r0, r5 // set up arguments to mod
     mov r1, r6
     bl mod
     cmp r0,#0
     bne endif1
     add r4,r4,r5
     add r5,r5,#1
     b while

endif1:
     mov r0, r5 // set up arguments to mod
     mov r1, r7
     bl mod
     cmp r0,#0
     bne exit
     add r4,r4,r5
     add r5,r5,#1
     b while
exit:
    add r5,r5,#1
    b while

endwhile:
     mov r0, r4  // return i
     pop {r4-r7,lr}
     bx lr
    
      
      
     
     
     






     
     
       