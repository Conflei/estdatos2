#include <stdio.h>
                          
main() {
  int c = 0; 

  for (; c < 256; c++) {
    printf("%d: \t%c\t\t", c, c);
  }
  printf("\n");
}

