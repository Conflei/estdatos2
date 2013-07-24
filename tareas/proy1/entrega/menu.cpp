#include <iostream>
#include <stdio.h>

void menu();

using namespace std;

int main() {
  menu();
  return 1;
}

void menu () {
  char c;

  do {
    cout << "~~ Optimizador de Rutas AutoAjustable ~~" << endl;
    cout << "Haga una seleccion:" << endl;
    cout << "1. Cargar puntos de ruta de archivo." << endl;
    cout << "2. Calcular ruta mas corta entre dos puntos." << endl;
    cout << "3. Actualizar datos de una ruta." << endl;
    cout << "q: Salir." << endl;

    cin >> c;

    switch(c) {
      case '1':
        // cargarPuntos();
        break;
      case '2':
        // calcularRuta();
        break;
      case '3':
        // actualizarRuta();
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);
}

