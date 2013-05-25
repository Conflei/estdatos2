#include <stdio.h>
#define MAXLINE 1000 /* largo maximo de linea */

int getlinea(char line[], int maxline);

// imprime las lineas de mas 80 caracteres
main () {
  int len,
      max;

  char line[MAXLINE];
  max = 79;

  while ( (len = getlinea(line, MAXLINE)) > 0 ) {
    if (len > max) {
      printf("%s", line);
    }
  }

  return 0;
}

// lee una linea y retorna el largo
int getlinea(char s[], int lim) {
  int c,
      i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

