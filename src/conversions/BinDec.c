#include "BinDec.h"
#include <stdlib.h>
#include <stdio.h>

/*Converting binary to decimal*/
void b2d(char* binary)
{
  // char* binary = "1010";
  int decimal = strtol(binary, NULL, 2);
  printf("%d\n", decimal);
}


/*Converting decimal to binary*/
void d2b(int decimal)
{
  // int decimal = 10;
  int binary[32];
  int i = 0;
  while (decimal > 0) {
      binary[i] = decimal % 2;
      decimal /= 2;
      i++;
  }
  for (int j = i - 1; j >= 0; j--) {
      printf("%d", binary[j]);
  }
  printf("\n");
}