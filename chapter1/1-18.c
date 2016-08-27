#include <stdio.h>

#define MAXLINE 1000  /* max array size */

/*
  remove trailing blanks and tabs from each line of input, and delete
  entirely blank lines
*/

/* NOTES

What's a little weird with the solution I came up with is that both
my helper methods are returning length. I realized since `getLength`
not only returns length, but also sets the char array. Having these
helper fxns do multiple different tasks makes my code harder to
handle. Single responsibility. This could use some refactoring,
but will revisit at a later time to do so.


Also, another thing to consider, the run time for this non-single
responsibility answer will be a little faster than one where I do
use single responsibility. Maybe I don't see an easy fix because
I don't know a lot of the built-in methods yet. But I realize
as of right now, for me to refactor this, the `getLength` would
have to loop the array to determine length. I would also need to build
a `buildArray` method to build the char array, which is an additional
loop.


In this example, use of '\0' to end the char array is important.
Using the %s tag in the `printf` call will stop printing once it meets
the '\0' null char.
In addition, the `input` char array, I don't think it resets the values after the '\0'. Those chars still exist. My code isn't erasing
them. This is something I feel I will learn to solve later on once
I understand C and its built-in functions better. For now, I will
just leave as is, since the program is running without errors.

*/

int getLength(char line[]);
int filter(char line[], int length);

int main(void) {
  int len;
  char input[MAXLINE];

  while ((len = getLength(input)) > 0) {
    // filter the string
    len = filter(input, len);

    // if conditonals are met, then print
    if (len == 1 && input[0] != '\n') {
      printf("%s\n", input);
    } else if (len > 1) {
      printf("%s\n", input);
    }
  }

  return 0;
}

int getLength(char line[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  line[i] = '\0';

  return i;
}

int filter(char line[], int length) {
  int i;

  i = length;

  while (line[i] == ' ' || line[i] == '\t' || line[i] == '\0' || line[i] == '\n') {
    --i;
  }

  line[++i] = '\0';

  return i;
}
