/*
n =10
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
*/

.global sequence
.cpu cortex-a53
.text


mod:
   sdiv r2, r0,r1
   mul  r2, r2,r1
   sub  r0, r0,r2
   bx lr

sequence:
        push {r4-r7,lr}
        mov r3,#1
        mov r4,r0 // n
        mov r5,#1 //z
        mov r6,#2
        mov r7,#3

while:
     cmp r4,r3
     beq endwhile
     mov r0, r4 // set up arguments to mod
     mov r1, r6
     bl mod
     cmp r0,#0
     bne endif     //n=n/2;
     sdiv r4,r4,r6
     add r5,r5,#1
     b while
     
endif:
     mul r4,r7,r4   // n = 3*n+1;
     add r4,r4,#1
     add r5,r5,#1
     b while

endwhile:
     mov r0, r5  // return z
     pop {r4-r7,lr}
     bx lr
     






