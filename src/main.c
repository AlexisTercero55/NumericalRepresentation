// #include "conversions/BinDec.h"
#include <stdio.h>
#include <stdint.h>
/*

IEEE 754-2019
float x = 3.14159f; // single-precision floating-point number
double y = 2.71828; // double-precision floating-point number

Ref: https://www.geeksforgeeks.org/program-for-conversion-of-32-bits-single-precision-ieee-754-floating-point-representation/

*/
typedef union {
 /*
 In C, the colon : is used as a bit field operator 
 to specify the width of a bit field within a struct 
 or union. Bit fields are used to allocate a specific 
 number of bits for a field, which can help to conserve 
 memory and optimize data storage.
 */
  float f;
  struct
  {
      // Order is important.
      // Here the members of the union data structure
      // use the same memory (32 bits).
      // The ordering is taken
      // from the LSB to the MSB.
      unsigned int mantissa : 23;
      unsigned int exponent : 8;
      unsigned int sign : 1;// ':'

  } raw;
} myfloat;

// A union that allows us to access the bits of a float as an unsigned integer
union float_bits {
  float f;
  uint32_t u;
};

// void bitwiseDemo(void);

void printBinary(int n, int i);
void printIEEE(myfloat var);

int main()
{
  // Create a new float value
  float n = 21.3;

  // Create a union of the float and an unsigned integer
  union float_bits fb;
  fb.f = n;

  // Print the float value in decimal
  printf("Float value: %f\n", n);

  // Print the binary representation of the float value
  printf("Binary representation: ");
  for (int i = 31; i >= 0; i--) {
    uint32_t bit = (fb.u >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
  //-------------------------------------
  // Instantiate the union
  // myfloat var;

  // // Get the real value
  // var.f = -2.25;

  // // Get the IEEE floating point representation
  // printf("IEEE 754 representation of %f is : \n",
  //         var.f);
  // printIEEE(var);
  //-----------------------------------------
  return 0;
}

// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{
 
    // Prints the IEEE 754 representation
    // of a float value (32 bits)
 
    printf("%d | ", var.raw.sign);
    printBinary(var.raw.exponent, 8);
    printf(" | ");
    printBinary(var.raw.mantissa, 23);
    printf("\n");
}

void printBinary(int n, int i)
{
 
    // Prints the binary representation
    // of a number n up to i-bits.
    int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}

// void bitwiseDemo(void)
// {
//   int a = 0b1011;
//   int b = 0b1100;
//   int r = 0;

//   printf("a = %d = ",a);
//   d2b(a);

//   printf("b = %d = ",b);
//   d2b(b);

//   r = a & b;
//   printf("a & b = %d = ",r);
//   d2b(r); 

//   r = a | b;
//   printf("a | b = %d = ", r);
//   d2b(r);

//   r = a ^ b;
//   printf("a ^ b = %d = ", r);
//   d2b(r);

//   r = ~a;
//   printf("~a = %d = ", r);
//   d2b(r);

//   r = a << 1;
//   printf("a << 1 = %d = ", r);
//   d2b(r);

//   r = a >> 1;
//   printf("a >> 1 = %d = ", r);
//   d2b(r);
// }