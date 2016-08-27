#include <stdio.h>

#define MAXLINE 1000

/*
  Print all input lines that are longer than 10 chars.
*/

/* NOTES

Using `sizeof` to get the size of the array doesn't work. This
returns the total storage allocation of the array (MAXLINE).

Instead, just loop through and count. Since index starts at 0,
counting the '\0' at the end is ok and works in this case.
We are getting the correct length because we need to add 1 to the
final.


Using '\0' isn't an array convention (I think). In this case, we
need it for `store` method. The while loop condition is looking for
the '\0'.


Again, is it convention to pass constant MAXLINE as a param to
a method call. I decided to use `MAXLINE - 1` within a for loop
conditional and it works as its supposed to. Convention?

*/

int grabsize(char line[]);
int store(char line[], char storage[], int tlen);

int main(void) {
  int len;   /* length of line */
  int tlen;   /* total length of output array - for storage purposes */
  char input[MAXLINE];   /* current input line */
  char output[MAXLINE];   /* store all strings that meet condition */

  while ((len = grabsize(input)) > 0) {
    if (len > 10) {
      // store into larger array
      tlen = store(input, output, tlen);
    }
  }

  printf("%s", output);

  return 0;
}

int grabsize(char line[]) {
  int c, i;

  i = 0;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

int store(char line[], char storage[], int tlen) {
  int i;

  i = 0;

  while ((storage[tlen + i] = line[i]) != '\0') {
    ++i;
  }

  return tlen + i;
}
