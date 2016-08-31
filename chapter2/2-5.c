#include <stdio.h>

#define MAXLINE 1000

/*
  Write function any(s1, s2), which returns the first location in the
  string s1 where any character from the string s2 occurs, or -1 if
  s1 contains no characters from s2.
*/

int any(char s1[], char s2[]);
void setArray(char s[]);

int main(void) {
  int idx;
  char s1[MAXLINE], s2[MAXLINE];

  setArray(s1);
  setArray(s2);

  idx = any(s1, s2);

  if (idx == -1) {
    printf("No matching letters found.\n");
  } else {
    printf("The index where first letter matches is: %i\n", idx);
  }
}

void setArray(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  s[i] = '\0';
}

int any(char s1[], char s2[]) {
  int i, j, match;
  match = -1;

  for (i = 0; s1[i] != '\0' && match == -1; ++i) {
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        match = i + 1;
        break;
      }
    }
  }

  return match;
}
