#include <stdio.h>

/*
  fahrenheit - celsius conversion using functions
*/

/*
Use double and floats to offset round-down errors.

If I want to keep whole numbers, but take into account rounding, I can:
#include <math.h>
printf("%.0f\n", roundf(fahrToCelc(20)));

The method `roundf` rounds numbers to the nearest value.
*/

double fahrToCelc(int fahr);
double celcToFahr(int celc);

int main(void) {
  printf("1: %.1f\n", fahrToCelc(-20));  // -29
  printf("2: %.1f\n", fahrToCelc(0));  // -18
  printf("3: %.1f\n", fahrToCelc(20)); //-7

  printf("4: %.1f\n", celcToFahr(-20));  //-4
  printf("5: %.1f\n", celcToFahr(0));  // 32
  printf("6: %.1f\n", celcToFahr(20));  // 68
}

double fahrToCelc(int fahr) {
  return (5.0 / 9.0) * (fahr - 32);
}

double celcToFahr(int celc) {
  return (9.0 / 5.0) * celc + 32;
}
