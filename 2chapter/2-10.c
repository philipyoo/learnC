#include <stdio.h>

#define MAXLINE 1000

/*
  Rewrite the function `lower`, which converts uppercase letters to
  lowercase, with a conditional expression instead of if-else.
*/

int getLine(char s[]);
int lower(int c);

int main(void) {
  char s[MAXLINE];
  int i, len;

  len = getLine(s);

  for (i = 0; i < len; ++i) {
    s[i] = lower(s[i]);
  }

  printf("%s", s);
}

int getLine(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = '\n';
  }

  s[i] = '\0';

  return i - 1;
}

int lower(int c) {
  return c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
