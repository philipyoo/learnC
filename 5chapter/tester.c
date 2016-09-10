#include <stdio.h>
// #include <ctype.h>

/*
This file is just a scratch pad for testing things out :)
*/

void swap(int *px, int *py);

int main(void) {

  int *px;
  int *py;

  int x = 2, y = 5;

  px = &x;
  py = &y;

  printf("BEFORE: %i, %i\n", *px, *py);

  swap(px, py);

  printf("AFTER: %i, %i\n", *px, *py);


}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
