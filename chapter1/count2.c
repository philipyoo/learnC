#include <stdio.h>

/*
count digits, white space, others
*/

/*

`++ndigit[c-'0']`
Input `c` is a char type. You give the array an index of the
input (char), but the index of an array must be a number.

That given index will correspond to the number from the ASCII
table.

Now, if the input is '5', the ASCII number is `53 - '0'`
(ASCII = 48). Thus the output is 5.

*/

int main(void) {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;

  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c-'0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits =");

  for (i = 0; i < 10; ++i) {
    printf(" %d ", ndigit[i]);
  }

  printf(", white space = %d, other = %d\n", nwhite, nother);

  printf("%d", 'z' - 'a');
}
