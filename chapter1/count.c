#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0  /* outside a word */

/*

Whenever we "enter" into a word (since we are looping through each
char), our `state = IN`. Once we hit a char that is an empty space,
our state changes to `state = OUT`.

Every time our `state = OUT`, we are incrementing the word counter.

So, why not just keep track of all empty spaces, whether it be a
space, tab, or newline and just increment up? If the string of chars
have multiple spaces, tabs, or newlines, it'll start incrementing
the word counter even though we aren't getting more words. We're
just getting more separators.

Keeping state, and tracking state change is a viable solution to this
problem.

*/

int main(void) {

  int c, n1, nw, nc, state;

  state = OUT;
  n1 = nw = nc = 0;

  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n') {
      ++n1;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", n1, nw, nc);
}
