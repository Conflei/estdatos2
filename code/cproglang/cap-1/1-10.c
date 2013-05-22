#include <stdio.h>

main() {
  int c;

  while ((c = getchar()) != EOF) {
    // tab
    if (c == '\t') {
      c = 't';
      putchar('\\');
    }
    // backspace: CONTROL+H
    if (c == '\b') {
      c = 'b';
      putchar('\\');
    }
    putchar(c);
  }
}

