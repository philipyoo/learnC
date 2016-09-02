#include <stdio.h>

/*
  Write a version of binary search with only one test inside the loop
  and measure the difference in run time.
*/

/* NOTES

The binary search should return the index position of the matching number.
If there are no matching numbers, then return -1. Index position starts at
0.

I initially had doubts if my solution with setting `mid` in the while
conditional would work. I realize now that the while loop will break
out correctly with the correct `mid` value. I need to set `mid` one last
time with the correct `low` and `high` values and then break out, which
the code is doing right now.

*/

int myBinSearch(int x, int v[], int n);
int binSearch(int x, int v[], int n);

int main(void) {
  int x, len, result;
  int v[30] = {2, 5, 6, 8, 10, 12, 15, 18, 19, 22,
              24, 27, 30, 31, 32, 35, 39, 40, 43, 44,
              46, 47, 49, 52, 53, 57, 61, 63, 66, 70};

  x = 6; /* search for this */

  result = myBinSearch(x, v, 31);

  printf("%d\n", result);
}

int myBinSearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high && v[mid = (low + high) / 2] != x) {
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return (x == v[mid]) ? mid : -1;
}

int binSearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;  /* no match */
}
