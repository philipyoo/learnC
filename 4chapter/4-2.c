#include <stdio.h>

#define MAXLINE 1000

/*
  Extend `atof` to handle scientific notation of the form:
    123.45e-6
  where a floating-point number may be followed by `e` or `E` and an
  optionally signed exponent.
*/

/* NOTES

It works! But definitely needs refactoring.

This new method only takes scientific notation, and I'd say its really
fragile. Maybe consider adding error handling instead of the program
going haywire on any little mistake.

Important to note! `et < (s[i] - '0');` is used within the loop to
find `epower` or exponent "power". I needed to convert the `s[i]` char to
number. I was a bit stuck on this part. Even though the char is the
correct number, I needed to convert to ASCII, thus subtracting char `0`.

*/

int getLine(char s[]);
double atof(char s[]);
int isspace(char c);
int isdigit(char c);

int main(void) {
  char s[MAXLINE];
  int c;

  while ((c = getLine(s)) > 0) {
    // 123.45e-6   == 0.00012345

    printf("%s, %.8f\n", s, atof(s));
  }
}

int getLine(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  s[i] = '\0';

  return i;
}

double atof(char s[]) {
  double val, power, epower;
  int i, sign, e, et;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    i++;
  }

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
  }
  if (s[i] == '+' || s[i] == '-') {
    e = s[i];
    i++;
  }

  if (isdigit(s[i])) {
    epower = 1.0;
    for (et = 0; et < (s[i] - '0'); et++) {
      epower *= 10.0;
    }
  }

  if (e == '-') {
    return (sign * val / power) / epower;
  } else {
    return (sign * val / power) * epower;
  }
}

int isspace(char c) {
  return (c - ' ' == 0);
}

int isdigit(char c) {
  int i;

  i = c - '0';

  return (i >= 0 && i < 10);
}
