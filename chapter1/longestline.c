#include <stdio.h>

/*  NOTES

MAXLINE is necessary to set the size of the array. We select a large
number so that we guarantee we capture the entire input line.
"set aside storage"


In the first while loop within `main`, the function `getline` is
called. The args passed are declared char array `line` and constant
`MAXLINE`. It looks funny how a declared, but not initialized array
`line` is being used here. Does this mean that this empty array holds
default values?
http://stackoverflow.com/questions/12750265/what-is-the-default-value-of-members-of-a-char-array-in-c
Based on the SO answer, this array that is declared at block scope,
and is not declared static, and does not have an explicit initializer,
the contents of the array are indeterminate (essentially garbage
values).
Testing this out by initially printing the arrays contents, I see an
empty output. The indeterminate values essentially print nothing out.


Within `grabline`, why do we pass the second arg? Is it just
convention?


Using `\0` as the last char in the array signifies the end of the
array. char `\0` is the null char, whose value is zero. This
convention is also used by the C language. A string constant is
stored as an array of chars containing the chars of the string and
terminated with a '\0' at the end.


The %s tag in `printf` expects a string represented as a char array
with a '\0' end, like mentioned above.


The `copy` fxn sets each char into the `longest` array, including
the last `\0`, which breaks after this is set. Nifty~

*/

#define MAXLINE 1000    /* max input line size */

int grabline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void) {
  int len;                /* current line length */
  int max;                /* max length seen so far */
  char line[MAXLINE];     /* current input line */
  char longest[MAXLINE];  /* longest line saved here */

  max = 0;
  while ((len = grabline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int grabline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
