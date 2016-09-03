#include <stdio.h>

/*
  Convert string to integer - Pg.61
*/

/* NOTES

  Not exactly sure on boolean types yet. I won't venture ahead, but just
  take note of this method and what its doing.

  The `for` loop increments I thought were creative and something I
  haven't experienced before in other languages.

  `stoi` works for cases where the array might have empty spaces before
  and then has int numbers later. The numbers must not have empty spaces
  or other types in-between. If there are, it'll just stop and end loop.

  i.e:
  input: [' ', '1', '0', '1', ' ', '2', '1'];
  output: 101
  // does not read further to get the 2 and 1 at end.

  The standard lib provides a more elaborate fxn `strtol` for conversion
  of strings to long ints. Section 5 of Appendix B

*/

int stoi(char s[]);

int main(void) {
  // stuff here
}

int stoi(char s[]) {
  int i, n, sign;

  // Increment `i` if current char is an empty space
  for (i = 0; isspace(s[i]); i++)
    ;

  // Record the sign (+/-) for later
  sign = (s[i] == '-') ? -1 : 1;

  // If there was a sign (+/-), increment `i`
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  // Add together each digit, `n` records in right 0'th place while `i`
  // continues to increment for use of reading through the array
  for (n = 0; isdigit(s[i]); i++) {
    n = 10 * n + (s[i] - '0');
  }

  return sign * n;
}
