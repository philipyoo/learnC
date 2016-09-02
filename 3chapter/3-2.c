#include <stdio.h>

#define MAXLINE 1000

/*
  Write a function `escape(s, t)` that converts characters like newline and
  tab into visible escape sequences like \n and \t as it copies the string
  t to s. Use a switch. Write a function for the other direction as well,
  converting escape sequences into the real characters.
*/

/* NOTES

It seems like I have a lot of lines of code for such a simple function.
I think I'm spoiled by what Ruby had to offer.

After learning more of C, I'd like to revisit these problems and see
if I can refactor them.

The `getLength` function is something I built to help determine where
to put the new stuff in the old string array. It seems very redundant
given `getLine` will also return length. 

*/

int getLine(char s[]);
void escape(char s[], char t[]);
int getLength(char s[]);

int main(void) {
  char s[MAXLINE];  /* All combined strings, escaped */
  char t[MAXLINE];  /* Line to add to end of string `s` */
  int len;

  while ((len = getLine(t)) > 0) {
    escape(s, t);
    printf("%s\n", s);
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

void escape(char s[], char t[]) {
  int len, i, j, c;

  len = getLength(s);

  for (i = len, j = 0; i < MAXLINE - 1 && (c = t[j]) != '\0'; ++i, ++j) {
    switch (c) {
      case '\n':
        s[i++] = '\\';
        s[i] = 'n';
        break;
      case '\t':
        s[i++] = '\\';
        s[i] = 't';
        break;
      default:
        s[i] = c;
        break;
    }
  }

  s[i] = '\0';
}

int getLength(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;

  return i;
}
