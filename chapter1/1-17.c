#include <stdio.h>

#define MAXLINE 1000

/*
  Print all input lines that are longer than 80 chars.
*/

/* NOTES

Using `sizeof` to get the size of the array doesn't work. This
returns the total storage allocation of the array (MAXLINE).

Instead, just loop through and count, but don't include the `\0`.


WHY?? Does the '\0' do anything for the array? I realize as I loop
through the array and print everything out, if I have multiple
'\0' in there, it doesn't matter. It will continue looping and
printing. If no '\0' exists at all, it loops and prints anyways as
well. Why?


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

  // output[tlen] = '\0';

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

  // line[i] = '\0';

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
