/*
#include "sqrt.h"

double fabs(double n) {
    if (n < 0) 
        n = -n;

    return n;
}

#define epsilon .0000001

double sqrt(double n) {

    double r = n;  // initial guess at r

    while (fabs(n - r*r) > epsilon)
        r = (r + n/r) / 2.0; 

    return r;
}

*/
.global fabs
.global sqrt
.cpu cortex-a53
.fpu neon-vfpv4
.text

fabs:
   ldr r0, =zero
   vldr.f64 d1, [r0]
   vcmp.f64 d0, d1 
   vmrs APSR_nzvc, FPSCR  // copy floating-point flags to the integer CPU 
   bge end_fabs   // bgt uses the integer program status register
   ldr r0, =neg_one
   vldr.f64 d1, [r0]  // load -1.0 into d1
   vmul.f64 d0, d0, d1 
end_fabs:
   bx lr

sqrt:
   push { lr }    
   vpush { d8-d9 }
   //vpush { d8-d9 }
   vmov.f64 d8, d0  // n
   vmov.f64 d9, d8   // r is in d9
   
while:
    vmul.f64 d7,d9,d9  
    vsub.f64 d0,d8,d7
    bl fabs

    ldr r0, =epsilon
    vldr.f64 d1, [r0] 

    vcmp.f64 d0,d1
    vmrs APSR_nzvc, FPSCR  // copy floating-point flags to the integer CPU 
    blt endwhile

    vdiv.f64 d7,d8,d9
    vadd.f64 d9,d9,d7
    
    ldr r0, =two
    vldr.f64 d2, [r0] 
    vmrs APSR_nzvc, FPSCR  // copy floating-point flags to the integer CPU
    
    vdiv.f64 d9,d9,d2
    b while
   
endwhile:
    vmov.f64 d0,d9
    pop {lr}  
    vpop {d8-d9}
    bx lr
  
     

.data
.align 3
neg_one:  .double -1.0
zero:  .double 0.0 
epsilon: .double 0.0000001
two:  .double 2.0






