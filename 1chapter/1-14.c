#include <stdio.h>
// #include <ctype.h>   // to use `tolower(c)`
// but instead of including this, I can use ASCII semantics Line:25

#define BASE 97   /* ASCII for 'a' */

/*

Print a histogram of the frequencies of different characters in
its input.

*/

int main(void) {

  int i, j, c;
  int letters[26];

  for (i = 0; i < 26; ++i) {
    letters[i] = 0;
  }

  while ((c = getchar()) != EOF) {

    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;

    if (c - BASE >= 0 && c - BASE <= 26) {
      ++letters[c - BASE];
    }

  }

  for (i = 0; i < 26; ++i) {
    printf("%c : ", i + BASE);

    for (j = 0; j < letters[i]; ++j) {
      printf("\u256C ");
    }

    printf("\n");
  }
}
