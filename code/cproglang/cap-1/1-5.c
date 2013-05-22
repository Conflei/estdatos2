#include <stdio.h>

main() {
  float farenheit,
        centigrados;
  int i = 300;

  for (i; i > 0; i -= 10) {
    printf("%d\t%.1f\n", i, (5.0/9.0) * (i - 32.0));
  }
}

