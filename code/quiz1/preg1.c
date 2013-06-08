#include <stdio.h>
#define LARGOMAX 1024

int getlinea(char line[], int max);

main() {
  char *preguntas[4] = {
    "1. Defina qué es una Estructura de Datos\n",
    "2. Explique qué es una Estructura de Datos dinámica y una estática ?\n",
    "3. Cuáles son los tipos de datos básicos de C ?\n",
    "4. Cómo se representan los datos booleanos (true/false) en C\n"
  };
  int i = 0;
  char lineaActual[LARGOMAX];

  while(i < 4) {
    printf("%s", preguntas[i]);
    while(getlinea(lineaActual, LARGOMAX) > 0)
      ;
    i++;
  }
}

int getlinea(char line[], int max) {
  int c,
      i;

  i = 0;

  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    line[i++] = c;
  }

  if (c == '\n') {
    line[i] = '\0';
    return i;
  }
}
