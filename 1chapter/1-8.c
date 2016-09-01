#include <stdio.h>

/* count blanks, tabs, and newlines  */

int main(void) {
  int count, c;

  count = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      ++count;
    }
  }

  printf("%d\n", count);


}
