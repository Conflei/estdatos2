#include <stdio.h>

main () {

  int x = 1, y = 2, yy = 0, z[10];
  int *ip; /* ip is a pointer to int */

  printf("x: %d | y: %d | yy: %d, z[0]: %d\n", x, y, yy, z[0]);

  ip = &x; /* ip now points to x */
  printf("ip = &x; \t// ip: %p\n", ip);

  printf("imprimiendo *ip: %d\n", *ip);

  y = *ip; /* y is now 1 */
  printf("y = *ip; \t// y: %d\n", y);

  *ip = 0; /* x is now 0 */
  printf("*ip = 0; \t// *ip: %d\n", *ip);

  ip = &z[0]; /* ip now points to z[0] */
  printf("ip = &z[0]; \t// ip: %p\n", ip);

  yy = *ip;
  printf("yy = *ip; \t// yy: %p\n", ip);

  printf("x: %d | y: %d | yy: %p\n", x, y, yy);


}
