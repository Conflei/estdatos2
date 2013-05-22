#include <stdio.h>

main() {
  int c = 0,
      isBlank = 0;

  // trim whitespace

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (isBlank == 0) {
        isBlank = 1;
        putchar(c);
      }
    } else {
      isBlank = 0;
      putchar(c);
    }
  }
}

