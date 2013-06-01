#include <stdio.h>

void nada();

main() {
  struct punto {
    int x;
    int y;
  };

  struct punto miPunto = { 10, 20 };
  //miPunto.x = 10;
  //miPunto.y = 20;
  nada();

}

void nada() {
  printf("hola!\n");
}

