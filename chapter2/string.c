#include <stdio.h>

/*

Strings in C are really different from Strings in other languages.

To really solidify use of Strings, I want to do an overview of Strings.

Also, I've only ever used I/O so far in C, so I will stick to using it here.

The hardest thing to test is that all my inputs via terminal will always
have a newline. Also I can't really emulate stretch cases like multiple
newlines in the input, or inputting null characters randomly.

`printf` and the %s tag will print the char array as a string, and will
stop printing once it meets '\0'. Convenient!

'\0' is something used to find the end of a char array specifically.

*/

#define MAXLINE 1000

int getLength(char s[]);

int main(void) {
  int len;
  char input[MAXLINE];

  /*
  This while loop only breaks when I end the program.
  Using an empty input by pressing the return button will still create
  a newline char, so length will still be 1.
  I don't really know how to give input without using the return key, so
  I can't test out if this still would still work for empty input with only
  null char.
  When breaking out of the program, we still call `getLength`, but we
  get EOF, and the array at index 0 will be '\0' null, so length == 1.

  How does the `input` char array reset?
  It doesn't. The old data is still stored in there. We're just overwriting
  the data each time we call `getLength`.
  The '\0' is a special char in char arrays, and those signify a stoppage
  point. So really no need to erase all the old data.
  */
  while ((len = getLength(input)) > 0) {
    printf("len = %d\n", len);
    printf("%s", input);
  }

}

int getLength(char s[]) {
  int i, c;

  /*
  So this method is really doing 2 things. Incrementing `i`, which is a
  counter to get total length (including '\n' and '\0'), and it's setting
  the char array `s` based on input using `getchar()`.

  The conditionals for this loop are:
  1) We cannot set `s[i]`` if `i` is greater than `MAXLINE - 1`. This is
     the total amount of storage we allocated for this array initially,
     and we subtract 1 because we need to take into account the addition
     of '\0' null char at end.
  2) We get the next char using `getchar()` and set it to int `c`. If `c`
     is not `EOF`, then we're good and we continue our loop. `EOF`
     indicates end of file/input.
  3) `c` should not equal `\n`. This is to set a break point in the loop.

  To clarify point 3 above, if we don't set that conditional, the
  terminal will not spit out the results until EOF. Adding the `\n`
  conditional, our program will spit out the results for every line of
  user input it receives.
  */
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = '\n';
  }

  s[i] = '\0';

  return i;
}
