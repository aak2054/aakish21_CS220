
/*
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
*/

.global pow1
.cpu cortex-a53

.text
mod:
   sdiv r2, r0,r1
   mul  r2, r2,r1
   sub  r0, r0,r2
   bx lr

pow1:
    push {r4-r6,lr}
    mov r3,#0
    mov r4,r0  //x
    mov r5,#2 
    mov r6,r1 //y

if:
  cmp r4,r3
  bne endif1
  mov r0, #0
  pop {r4-r6,lr}
  bx lr

endif1:
     cmp r1,r3
     bne endif2
     mov r0, #1
     pop {r4-r6,lr}
     bx lr

endif2:
     mov r0, r1 // set up arguments to mod
     mov r1, r5
     bl mod
     cmp r0,#0
     bne return
     sdiv r1,r6,r5
     mov r0,r4
     bl pow1
     mul r0,r0,r0
     pop {r4-r6,lr}
     bx lr


return:
      sub r1,r6,#1
      mov r0,r4
      bl pow1
      mul r0,r4,r0

      pop {r4-r6,lr}
      bx lr
      
     


