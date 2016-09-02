#include <stdio.h>

/*
  Write a loop equivalent to the `for` loop above w/out using && or ||
*/

int main(void) {
  int i, c;
  int lim = 10;
  char s[lim];

  // REWRITE THIS
  // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
  //   s[i] = c;
  // }

  for (i = 0; i < lim - 1; ++i) {
    c = getchar();

    if (c == '\n') {
      break;
    } else if (c == EOF) {
      break;
    }

    s[i] = c;
  }
  
}
