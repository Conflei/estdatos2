#include <stdio.h>
#define MAXLINE 1000 /* largo maximo de linea */

int getlinea(char line[], int maxline);
void copy(char to[], char from[]);

// imprime la linea mas larga:
main () {
  int len;
  int max;

  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;

  while ( (len = getlinea(line, MAXLINE)) > 0 ) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

// lee una linea y retorna el largo
int getlinea(char s[], int lim) {
  int c;
  int i;

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

void copy(char to[], char from[]) {
  int i;
  
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i; 
  }

}

