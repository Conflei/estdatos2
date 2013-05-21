#include <stdio.h>

main() {
  float centigrados,
      farenheit,
      limiteSup,
      limiteInf,
      incremento;  

  limiteInf = 0;
  limiteSup = 100;
  incremento = 25;
  centigrados = limiteInf;  

  printf("Cent\t| Fare\n");
  while (centigrados < limiteSup) {
    farenheit = (centigrados * 9/5) + 32;
    //farenheit = centigrados * 33.8;
    printf("%3.0f\t| %4.1f\n", centigrados, farenheit);    
    centigrados += incremento;
  }
}
