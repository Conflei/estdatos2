#include <stdio.h>

// de farenheit a celsius

main() {
  float celsius,
      fahr,
      lower,
      step,
      upper;

  lower = 0;
  step = 10;
  upper = 100;

  fahr = lower;
  printf("\t  Cel\tFahr\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("\t%6.1f\t%3.0f\n", celsius, fahr);
    fahr += step;
  }

}
