#include <stdio.h>

main() {
  int c, i,
      totalEspacios,
      totalOtros;
  int totalDigitos[10];

  totalEspacios = totalOtros = i = 0;

  for (i; i < 10; ++i) {
    totalDigitos[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    // si el caracter ingresado cumple con [0-9]
    // agregue el caracter en la posicion c aumentando el valor
    if (c >= '0' && c <= '9') {
      ++totalDigitos[c-'0'];
      //totalDigitos[c-'0'] = c;
    } else if (c == ' ' || c == '\t' || c == '\n') {
      ++totalEspacios;    
    } else {
      ++totalOtros;
    }
  }

  printf("digitos:");
  for (i = 0; i < 10; ++i) {
    printf(" %d", totalDigitos[i]);
  }
  printf(", espacios en blanco: %d, otros: %d \n", totalEspacios, totalOtros);

/*int c, i, nwhite, nother;
int ndigit[10];
nwhite = nother = 0;
for (i = 0; i < 10; ++i)
  ndigit[i] = 0;
while ((c = getchar()) != EOF)
  if (c >= '0' && c <= '9')
    ++ndigit[c-'0'];
  else if (c == ' ' || c == '\n' || c == '\t')
   ++nwhite;
  else
    ++nother;
printf("digits =");
for (i = 0; i < 10; ++i)
  printf(" %d", ndigit[i]);
printf(", white space = %d, other = %d\n", nwhite, nother);*/

}
