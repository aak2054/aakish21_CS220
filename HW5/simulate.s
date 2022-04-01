//static varialbes are stored in global memory
// local varibales note allocated to registers are stored on the stack
// the read-modfity-write operation is fundamental computer science concept
// ldr, modify, str

// ldr,str. the ARM processor is called a load/.store archieture
// all operation happen in register that are loaded from memory 
// and then stored
/*
int simulate(int n){

    const int DAYS = 366;
    int cal[366];

    static int seedhack = 0;
    srand(time(NULL) + seedhack++);
    memset(cal, 0, DAYS*sizeof(int));

    int i = 0;
    while(i<n){
       cal[rand() % DAYS]++;
       i++;
     }

    i = 0;
    while(i<DAYS){
       if(cal[i]>1 ){
            return 1;
       }
       i++;
     }

    return 0;


}
*/
.global simulate
.cpu cortex-a53
.data  // allocate global memory 

// a word is the width, in bytes, of the natual size of the machine
// 4 bytes

seedhack: .word 0

.text

mod:
   sdiv r2, r0,r1
   mul  r2, r2,r1
   sub  r0, r0,r2
   bx lr

simulate:
      push { r4-r8,r11,lr }
      mov r6, #366
      mov r5, r0
      
      // local variables get stored on the stack if you cann't put them
      // in the registers

      sub sp, sp, r6, lsl #2 // shift r1 by two and then subtract 
      mov r7, sp      // store starting addresss of array in r7
      ldr r4, =seedhack    // put the adress of seedhack in r4
      
      // read-modify-write
      ldr r8, [r4]    // get the value of seedhack 
      add r8,r8,#1
      str r8, [r4] // put the incremented value back im seedhack

      //call time
      mov r0,#0
      bl time
      add r0,r0,r8
      bl srand

      // set up call to memset
      mov r0, r7
      mov r1, #0
      mov r2, r6,lsl #2
      bl memset
      
      mov r4,#4

      mov r8,#0  //i
while1:     // top of the while loop
     cmp r8,r5
     bge endwhile1
     
     bl rand
     mov r1,r6
     bl mod
     
     mul r0,r0,r4
     add r0,r0,r7
      
     ldr r1,[r0]
     add r1,r1,#1
     str r1,[r0]
     add r8,r8,#1
     b while1

endwhile1:

mov r8,#0

while2:
     cmp r8,r6
     bge endwhile2
     
     mul r0,r8,r4
     add r0,r0,r7
     
     ldr r1,[r0]
     cmp r1,#1
     bgt return
     add r8,r8,#1
     b while2

return:
     mov r0,#1
     add sp, sp, r6, lsl #2
     pop { r4-r8,r11,lr}
     bx lr  

endwhile2:
     mov r0,#0
     add sp, sp, r6, lsl #2
     pop { r4-r8,r11,lr}
     bx lr
     

      


      
      






