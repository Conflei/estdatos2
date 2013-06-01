#include <stdio.h>

int atoi(char s[]);

main() {
  char c[] = "12345";
  int x;

  x = atoi2(c);
  printf("x vale: %d\n", x);
}

/* atoi: convert s to integer */
int atoi2(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

