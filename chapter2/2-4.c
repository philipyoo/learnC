#include <stdio.h>

#define MAXLINE 1000

/*
  Write an alternate version of squeeze(s1, s2) that deletes each character
  in s1 that matches any character in string s2.
*/

void setString(char s[]);
void squeeze(char s1[], char s2[]);

int main(void) {
  char s1[MAXLINE];
  char s2[MAXLINE];
  int l1, l2;

  setString(s1);
  setString(s2);

  squeeze(s1, s2);

  printf("%s\n", s1);
}

void setString(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  s[i] = '\0';
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  k = 0;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
      ;

    if (s2[j] == '\0') {
      s1[k++] = s1[i];
    }
  }

  s1[k] = '\0';
}
