/* Figura 11.3: fig11_03.c
   Crea un archivo secuencial */
#include <stdio.h>

int main()
{ 
   int cuenta;        /* número de cuenta */
   char nombre[ 30 ]; /* nombre de cuenta */
   double saldo;      /* saldo de la cuenta */

   FILE *ptrCf;     /* ptrCf = apuntador al archivo clientes.dat */

   /* fopen abre el archivo. Si no es capaz de crear el archivo, sale del programa  */
   if ( ( ptrCf = fopen( "clientes.dat", "w" ) ) == NULL ) {
      printf( "El archivo no pudo abrirse\n" );
   } /* fin de if */
   else { 
      printf( "Introduzca la cuenta, el nombre, y el saldo.\n" );
      printf( "Introduzca EOF (CTRL-D) al final de la entrada.\n" );
      printf( "? " );
      scanf( "%d%s%lf", &cuenta, nombre, &saldo );

      /* escribe la cuenta, el nombre y el saldo dentro del archivo con fprintf */
      while ( !feof( stdin ) ) { 
         fprintf( ptrCf, "%d %s %.2f\n", cuenta, nombre, saldo );
         printf("-> %d %s %.2f\n", cuenta, nombre, saldo );
         printf( "? " );
         scanf( "%d%s%lf", &cuenta, nombre, &saldo );
      } /* fin de while */
     
      fclose( ptrCf ); /* fclose cierra el archivo */
   } /* fin de else */
	printf("FIN\n");
   return 0; /* indica terminación exitosa */

} /* fin de main */


/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

