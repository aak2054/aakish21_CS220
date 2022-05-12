#include "bigint.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // TODO sanitize
    BigInt *x = make_int(argv[1]);
    BigInt *y = make_int(argv[2]);
    BigInt *m = div10(x);
    BigInt *n = mul10(y);
    //BigInt *q = mult(x,y);
    //BigInt *a = checksum(y);
    //BigInt *a = mod10(x);

    print_int(m);
    print_int(n);
    //print_int(q);
   // print_int(a);

    free(x); 
    free(y); 
    //free(a); 
    free(m); 
    free(n);
    //free(q);

    return 0;

}
