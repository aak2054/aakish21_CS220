#include "bigint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BigInt * make_int(const char *s) {

    BigInt *b = malloc(sizeof(BigInt));
    
    b->n = strlen(s);   // (*b).n = strlen(s); 
    b->digits = malloc(b->n);

    // copy digits from s into digits array
    for (int i = 0; i < b->n; i++) 
        b->digits[i] = s[b->n - 1 - i] - '0';

    return b;
}

BigInt *make_zero(int n) {
    char tmp[n+1];
    memset(tmp, '0', n); 
    tmp[n] = 0;  // null terminate the string
    return make_int(tmp);
}

void print_int(const BigInt *b) {
    // TODO don't print leading zeros
    //for (int i = b->n - 1; i > -1; i--)
       // printf("%hhd", b->digits[i]);

    int idx = 0;
    for (int i = b->n - 1; i > -1; i--){
    if (b->digits[i] != 0){
        idx = i;
        break;
    }
    }
    // it will create
    for (int i = idx; i > -1; i--)
        printf("%hhd", b -> digits[i] );
         
printf("\n");

  }

BigInt *div10(const BigInt *x){

    BigInt *b = make_zero(x->n-1);

    for (int i= x->n-1;i>=1;i--){
          b->digits[i-1]=x->digits[i];   
     }
  return b;
}

BigInt *mul10(const BigInt *x){
	BigInt *c = make_zero(x->n+1);
        
       for (int i= x->n-1;i>=0;i--){
          c->digits[i+1]=x->digits[i];   
          //c->digits[i-1]=0;
      }
    return c;
        

}
//byte mod10(const BigInt *x){
     
    //byte *b = make_zero(x->n-1);

    //for (int i= x->n-1;i>=1;i--){
    //      b->digits[i+1]=x->digits[i];   
     //}

    //return b;


//}

int checksum(const BigInt *x){
    //BigInt *b = make_zero(x->n);

    int idx = 0;
    for (int i = 0; i < x->n-1; i++){
         idx += x->digits[i];  
    }
    
    
   return idx;



}
