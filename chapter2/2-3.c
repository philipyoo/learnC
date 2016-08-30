#include <stdio.h>
#include <math.h>

/*
  Write fxn `htoi(s)` which converts a string of hexadecimal digits
  (including optional "0x" || "0X") into its equivalent integer value.
*/

/* NOTES

Hexadecimal is a numeric system with base 16. It can contain numbers
0 thru 9, and letters A thru F (not case sensitive).

Hexadecimal can be prefixed with `0X`. Based on SO, the `0` tells
the parser it's dealing with a constant (and not an identifier/reserved
word). Something is still needed to specify the number base: the `x`
is an arbitrary choice.

How can we convert a hex to integer?
Using "7DE" as our hex..
7DE = (7 * 16^2) + (13 * 16^1) + (14 * 16^0)
7DE == 2014 (in decimal number)

A = 10
B = 11
C = 12
D = 13
E = 14
F = 15

Test cases:
FFFFFF == 16777215
00a01a == 40986
7DE == 2014

*/

#define MAXLINE 1000

int setline(char line[]);
int htoi(char hex[], int len);
int convert(char a);

int main(void) {
  int i, len, total;
  char input[MAXLINE];

  len = setline(input);

  total = htoi(input, len);

  printf("Total: %d\n", total);
}

int setline(char line[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && c !='\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i++] = c;
  }

  line[i] = '\0';

  return i - 2;  // Take into account the newline and null, and remove from length
}

int htoi(char hex[], int len) {
  int i, total;

  i = 0;
  total = 0;

  while (len >= 0) {
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
      len -= 2;
      i += 2;
    } else {
      // get the string and convert
      total += (pow(16, len--) * convert(hex[i++]));
    }
  }

  return total;
}

int convert(char a) {
  int value;

  if (a >= 97 && a <= 102) {   /* lowercase letter a-f */
    value = a - 87;
  } else if (a >= 65 && a <= 70) { /* uppercase letter A-F */
    value = a - 55;
  } else if (a >= 48 && a <= 57) {
    value = a - 48;
  }

  return value;
}
