typedef unsigned char byte;

typedef struct {
   byte *digits;   // array of digits;
   int n;          // length of the array of digits 
} BigInt;

// make_int allocates memory for the big integer.
// It is the job of the caller to free it when 
// done using it.

extern BigInt * make_int(const char *s);

extern void print_int(const BigInt *b);

extern BigInt *mul10(const BigInt *x);
extern BigInt *div10(const BigInt *x);

//extern byte mod10(const BigInt *x);

//extern int checksum(const BigInt *x);