#include <stdio.h>

#define MAXLINE 1000

/*
  Write a fxn `expand(s1, s2)` that expands shorthand notation like "a-z"
  in the string s1, to a complete list like "abc...xyz" in s2.
  Allow for letters of either case and digits and be prepared to handle
  cases like "a-b-c" and "a-z0-9".
*/

int getLine(char s[]);
void expand(char s1[], char s2[]);

int main(void) {
  char s1[MAXLINE], s2[MAXLINE];
  int c;

  while ((c = getLine(s1)) > 0) {
    expand(s1, s2);
    printf("%s", s2);
  }
}

int getLine(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';

  return i;
}

void expand(char s1[], char s2[]) {
  int i, j;
  int c;

  i = j = 0;

  while ((c = s1[i++]) != '\0') {
    if (s1[i] == '-' && s1[++i] > c) {
      while (c < s1[i]) {
        s2[j++] = c;
        c++;
      }
    } else {
      s2[j++] = c;
    }
  }

  s2[j] = '\0';
}
