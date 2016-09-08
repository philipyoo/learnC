#include <stdio.h>

#define MAXLINE 1000

/*
  Write the function `strrindex(s,t)` which returns the index position of
  the rightmost occurrence of t in s, or -1 if there is none.
*/

/* NOTES

The function `strrindex` is very similar to the books `strindex`. The only
modification needed is to track the last matching index position. So it
really is an additional variable that keeps track of this index, otherwise
its default returns -1.

The rightmost index returned is the index of the first matching letter,
the last match in the string, starting with a 0 index.

*/

int getLine(char s[]);
void reverse(char from[], char to[], int len);
int strrindex(char s[], char t[]);

int main(void) {
  int c, i;
  char d[MAXLINE]; /* Will hold initial string for `t` */
  char s[MAXLINE], t[MAXLINE]; /* `t` will be reversed string */

  while (getLine(s) > 0 && getLine(t) > 0) {
    // reverse(d, t, c);
    i = strrindex(s, t);
    printf("Rightmost occurrence: %d\n", i);
  }
}

int getLine(char d[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    d[i] = c;
  }

  /* Don't include newline char */
  d[i] = '\0';

  return i;
}

/* reverse a string */
void reverse(char from[], char to[], int len) {
  int i, j;

  for (i = 0, j = len; i < len; i++) {
    to[i] = from[--j];
  }

  to[i] = '\0';
}

int strrindex(char s[], char t[]) {
  int idx, i, j, k;
  idx = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      idx = i;
    }
  }

  return idx;
}
