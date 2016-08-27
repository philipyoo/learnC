#include <stdio.h>

#define MAXLINE 1000

/*
  Create function `reverse(s)` that reverses the char string `s`.
  Use it to write a program that reverses its input a line at a
  time.
*/

/* NOTES

Some difficulties I faced were dealing with the reversed char array.
The contents within starting from the back include '\0' char and
'\n' char. Once setting conditionals to ignore those and reset
relevant counters, I got it to work fine. The last line in `reverse`,
the prepend `++` is important. Using append `++` will not work.

*/

int getLength(char line[]);
void reverse(char from[], char to[], int len);

int main(void) {
  int len;
  char line[MAXLINE];
  char reversed[MAXLINE];

  while ((len = getLength(line)) > 0) {
    reverse(line, reversed, len);

    printf("%s", reversed);
  }

  return 0;
}

int getLength(char line[]) {
  int i, c;

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

void reverse(char from[], char to[], int len) {
  int i, j;

  i = 0;

  for (j = len; i < len - 1; --j, ++i) {
    if (from[j] == '\0' || from[j] == '\n') {
      --i;
    } else {
      to[i] = from[j];
    }
  }

  to[i] = '\n';
  to[++i] = '\0';
}
