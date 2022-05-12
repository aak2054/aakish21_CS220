/*

unsigned int reverse(unsigned int n, unsigned int r) {
    if (n == 0)
        return r;
    else
        return reverse(n >> 1, (r<<1) | (n & 1));
}
*/

.global reverse
.text

reverse:
    push { r4-r5, lr }
    mov r4, r0       // save n in r4 
    mov r5, r1       // save r in r5

    cmp r4, #0       // base case
    bne else
    mov r0, r5
    pop { r4-r5, pc }
else:                // recursive case
    lsr r0, r4, #1
    lsr r1, r5, #1
    bl reverse
    and r2, r4, #1
    add r0, r0, r2
    pop { r4-r5, pc }




