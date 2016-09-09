#include <stdio.h>

/*
This file is just a scratch pad for testing things out :)
*/



int main(void) {
  int i;
  int f = 0;
  int t = 1;

  for (i = 0; f && i < 4; i++) {
    printf("%i", i);
  }

  for (i = 10; t && i < 13; i++) {
    printf("%i", i);
  }

  printf("%d", '0' - '0');
}
