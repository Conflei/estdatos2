#include <stdio.h>

main() {
  // patron a buscar
  char patron[] = "leonard"; 
  // largo del patron (length)
  int largoPatron = sizeof(patron) / sizeof(patron[0]);
  // string de prueba
  char prueba[] = "leonNNnnardoOO lLLeonardo leEEnard \n";
  // almacenando cada caracter en un array
  int conteo[largoPatron];
  // contadores
  int i,
      j,
      k;

  i = j = k = 0;

  // llenando el arreglo con 0's
  for (k; k < largoPatron-1; k++) {
    conteo[k] = 0;
  }

  // recorriendo el string de prueba
  while(prueba[i] != '\n') {
    switch(prueba[i]) {
      case 'l':
      case 'L':
        conteo[0]++;
        break;
      case 'e':
      case 'E':
        conteo[1]++;
        break;
      case 'o':
      case 'O':
        conteo[2]++;
        break;
      case 'n':
      case 'N':
        conteo[3]++;
        break;
      case 'a':
      case 'A':
        conteo[4]++;
        break;
      case 'r':
      case 'R':
        conteo[5]++;
        break;
      case 'd':
      case 'D':
        conteo[6]++;
        break;
      default:
        break;
    }
    i++;
  }

  // imprimiendo el conteo
  while(j < largoPatron-1) {
    printf("%c: %d\n", patron[j], conteo[j]);
    j++;
  }

}

