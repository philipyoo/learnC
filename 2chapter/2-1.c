#include <stdio.h>

/*
  Determine the ranges of char, short, int, and long variables, both
  signed and unsigned, by printing appropriate values from standard
  headers and by direct computation.
*/

/* NOTES

Unsigned are any positive values and 0. (i.e. 0 to 255)
Signed are negative to positive values. (i.e. -128 to 127)

Using bitwise operators and type casting, we can figure out the max
and min values for different basic types.

However, figuring out the ranges on signed types was really just a
calculation for its unsigned type.

Proper printf flags were important to get the right outputs.

*/

int main(void) {
  printf("Signed Char\n");
  printf("\tMIN: %d\n", -((unsigned char) ~0 >> 1) - 1);
  printf("\tMAX: %d\n\n", (unsigned char) ~0 >> 1);

  printf("Unsigned Char\n");
  printf("\tMIN: %u\n", (unsigned char) 0);
  printf("\tMAX: %u\n\n", (unsigned char) ~0);

  printf("Signed Short\n");
  printf("\tMIN: %d\n", -((unsigned short) ~0 >> 1) - 1);
  printf("\tMAX: %d\n\n", (unsigned short) ~0 >> 1);

  printf("Unsigned Short\n");
  printf("\tMIN: %u\n", (unsigned short) 0);
  printf("\tMAX: %u\n\n", (unsigned short) ~0);

  printf("Signed Int\n");
  printf("\tMIN: %d\n", -((unsigned int) ~0 >> 1) - 1);
  printf("\tMAX: %d\n\n", (unsigned int) ~0 >> 1);

  printf("Unsigned Int\n");
  printf("\tMIN: %u\n", (unsigned int) 0);
  printf("\tMAX: %u\n\n", ((unsigned int) ~0));

  printf("Signed Long\n");
  printf("\tMIN: %ld\n", -((unsigned long) ~0 >> 1) - 1);
  printf("\tMAX: %ld\n\n", ((unsigned long) ~0 >> 1));

  printf("Unsigned Long\n");
  printf("\tMIN: %lu\n", (unsigned long) 0);
  printf("\tMAX: %lu\n\n", (unsigned long) ~0);


}
