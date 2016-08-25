#include <stdio.h>

/*

Print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging.

*/

int main(void) {

  int c, count, i, j;
  int lengths[10];

  count = 0;

  for (i = 0; i < 10; ++i) {
    lengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++count;

    if (c == ' ' || c == '\t' || c == '\n') {
      if (count > 9) {
        ++lengths[9];
      } else {
        ++lengths[count - 1];
      }

      count = 0;
    }
  }

  printf("Histogram:\n");

  for (i = 0; i < 9; ++i) {
    // printf("\u256C");

    printf("%3d : ", i);

    for (j = 0; j < lengths[i]; ++j) {
      printf("\u256C ");
    }

    printf("\n");
  }

  printf("%2d+ : ", 9);
  for (j = 0; j < lengths[9]; ++j) {
    printf("\u256C");
  }
  printf("\n");

}
