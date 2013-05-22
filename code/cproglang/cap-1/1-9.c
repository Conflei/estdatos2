#include <stdio.h>

main() {
  int c = 0;
  // probar con un flag??
  bool isBlank = false;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      c = ' ';
    }
    putchar(c);
  }

}
