#include <stdio.h>

#define SI 1 /* es palabra */
#define NO 0 /* no es palabra */

main() {
  int c,
      nuevaLinea,
      nuevaPalabra,
      nuevoCaracter,
      esPalabra;

  esPalabra = NO;
  c = nuevaLinea = nuevaPalabra = nuevoCaracter = 0;

  while ((c = getchar()) != EOF) {
    ++nuevoCaracter;
    if (c == '\n') {
      ++nuevaLinea;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      esPalabra = NO;
    } else if (esPalabra == NO) {
      esPalabra = SI;
      ++nuevaPalabra;
    }
  }
  printf("lineas: %d \npalabras: %d \ncaracteres: %d\n", nuevaLinea, nuevaPalabra, nuevoCaracter);
}

