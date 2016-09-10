#include <stdio.h>

/* NOTES

Pointers example on pg.95-96

Unary operator `*` is used when:
-> referencing the pointer (i.e. as arg in printf)
-> when declaring the pointer initially

Unary operator `&` is used when:
-> the pointer points to a certain value (i.e. `px = &x`). Note that we
   don't use the `*` to "reference" the pointer when setting it.


`*` basically is used as referencing with the exception when `&` is used
to set the value of the pointer to another variable. Another exception to
this is:
  `*ip = 0`
The pointer is referenced with `*` and set to a value directly. Another:
  `*ip = *ip + 10`  // to increment the pointers existing value


Beginning of pg.95, I'm confused on the increment using unary `++`.
`++*ip` would increment the pointer and not the value of what it points
to. `(*ip)++` increments the pointed value.
Unary operators like `*` and `++` associate right to left, thus the
parentheses are required here.
I tried to test this out, but wasn't exactly sure. Reason I wanted to
test this out, I didn't quite understand how you can increment the pointer
when the pointer is a variable that stores an address to something.
Below is my attempt to increment the pointer and not the value it points
to, but didn't work successfully.

*/

void swap(int *px, int *py);

int main(void) {
  int *ip;
  int *pi;

  int x = 2, y = 5;

  ip = &x;

  *pi = *ip;


  printf("B: %i, %i\n", *ip, *pi);
  // (*ip)++;
  // ++*ip;
  printf("A: %i, %i, %i\n", (*ip)++, *pi, x);
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
