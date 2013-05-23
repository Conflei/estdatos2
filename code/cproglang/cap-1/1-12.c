#include <stdio.h>

main() {
  int c;

  // imprime cada palabra ingresada en una linea separada
  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    } else {
      putchar('\n');
    }
  }

}
