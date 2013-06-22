#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {

  int i,
      j,
      dimensiones,
      elemento;

  ifstream archivo;

  archivo.open("eje.txt");

  archivo >> dimensiones;
  cout << dimensiones << " dimensiones  " << endl;

  int matriz[dimensiones][dimensiones];

  // filas 
  for (i = 0; i < dimensiones; i++) {
     // recorriendo las columnas
     for(j = 0; j < dimensiones; j++) {
        archivo >> elemento;
        matriz[i][j] = elemento;
     }
  }

  archivo.close();

  cout << "-- ~~ -- ~~ -- ~~ --" << endl;
  // recorriendo las filas
  for (i = 0; i < dimensiones; i++) {
     // recorriendo las columnas
     for(j = 0; j < dimensiones; j++) {
        // barra al inicio de las filas
        if (j == 0) {
            cout << "| ";
        }

        cout << matriz[i][j] << " | "; 

        // final de la linea
        if (j == dimensiones-1) {
            cout << endl;
        }
     }
  }
  cout << "-- ~~ -- ~~ -- ~~ --" << endl;

}

