#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Funciones relacionadas al pasajero
char* setNombre();
int setPasaporte();
char* setNacionalidad();
char* setDestinoFinal();

// Funciones relacionadas a la lista
void agregar();
void imprimir();
void remover();
int estaVacia();

// Utilitarios
void menu();
void clearBuffer();

// Estructura para el Pasajero
struct pasajero {
  char *nombre;
  int pasaporte;
  char *nacionalidad;
  char *destinoFinal;
  struct pasajero *siguiente;
};

typedef struct pasajero Nodo;

Nodo *inicio;
Nodo *final;

using namespace std;

int main() {
  inicio = final = 0;
  menu();
}

void menu () {
  char c;

  do {
    cout << "~~ FlyAirways: Lista de Pasajeros ~~" << endl;
    cout << "Haga una seleccion:" << endl;
    cout << "1. Agregar pasajero" << endl;
    cout << "2. Imprimir lista de pasajeros" << endl;
    cout << "q: Salir." << endl;
    c = getchar();
    switch(c) {
      case '1':
        agregar();
        break;
      case '2':
        imprimir();
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);
}

int estaVacia() {
  if (!final) {
    return 1;
  } else {
    return 0;
  }
}

// almacena el numero de pasaporte
int setPasaporte() {
  int num;

  cout << "Ingrese el numero de pasaporte: ";
  scanf("%d" , &num);

  return num;
}

// retorna el nombre del pasajero en la forma de un puntero 
char* setNombre() {
  char c,
       *nombre;

  int i = 0;

  nombre = (char*) malloc(sizeof(char)*100);

  cout << "Ingrese el nombre: ";

  while((c = getchar()) != EOF && c != '\n') {
    nombre[i++] = c; 
  }

  return nombre;
}

// similar a setNombre, pero para la nacionalidad
char* setNacionalidad() {
  char c,
       *nacionalidad;

  int i = 0;

  nacionalidad = (char*) malloc(sizeof(char)*100);

  cout << "Ingrese la nacionalidad: ";

  while((c = getchar()) != EOF && c != '\n') {
    nacionalidad[i++] = c; 
  }
  
  return nacionalidad;
}

// retorna un nuevo puntero a un arreglo
char* setDestinoFinal() {
  char c,
       *destinoFinal;

  int i = 0;

  destinoFinal = (char*) malloc(sizeof(char)*10);
  cout << "Ingrese el destino final: ";
  while((c = getchar()) != EOF && c != '\n') {
    destinoFinal[i++] = c; 
  }

  return destinoFinal;
}

// imprime el primer valor ingresado
// el penultimo valor es el nuevo inicio
// el primer valor es borrado de la lista
void remover() {
  Nodo *actual,
       *temporal;
  
  if (estaVacia()) {
    cout << "La lista de pasajeros esta vacia." << endl;
  } else {
    if (final == inicio) { // si solo hay 1 nodo
      cout << "Nombre:" << final->nombre << endl;
      cout << "Pasaporte:" << final->pasaporte << endl;
      cout << "Nacionalidad: " << final->nacionalidad << endl;
      cout << "Destino final: " << final->destinoFinal << endl;
      final = inicio = 0; // dejamos los punteros en null
    } else { // si hay mas de 1 nodo
      actual = final;
      while (actual != inicio) { // recorra la cola y quede en el penultimo
        temporal = actual; // temporal guarda la direccion del penultimo
        actual = temporal->siguiente;
      }
      cout << "Nombre:" << inicio->nombre << endl;
      cout << "Pasaporte:" << inicio->pasaporte << endl;
      cout << "Nacionalidad: " << inicio->nacionalidad << endl;
      cout << "Destino final: " << inicio->destinoFinal << endl;
      inicio = temporal; // el penultimo es ahora el ultimo
    }
  }
}

// agrega un nodo nuevo al final de la cola
void agregar() {
  Nodo *nodoNuevo,
       *temporal;

  nodoNuevo = (Nodo*) malloc(sizeof(Nodo));
  clearBuffer();

  nodoNuevo->nombre = setNombre();
  nodoNuevo->pasaporte = setPasaporte();
  clearBuffer();
  nodoNuevo->nacionalidad = setNacionalidad();
  clearBuffer();
  nodoNuevo->destinoFinal = setDestinoFinal();

  if (estaVacia()) { // si la cola esta vacia
    final = nodoNuevo; // el nodo toma el primer
    inicio = nodoNuevo; // y el ultimo lugar
  } else { // si hay al menos 1 nodo
    temporal = final; // almacenamos el ultimo nodo agregado
    final = nodoNuevo; // el nodoNuevo toma el primer lugar
    final->siguiente = temporal; // apuntando al nodo que estaba en primer lugar
  }
  clearBuffer();
}

// imprime la lista completa de pasajeros, es una llamada iterativa al metodo
// remover hasta que se limpie la cola
void imprimir() {
  while(!estaVacia()) {
    remover(); 
  }
  clearBuffer();
  cout << "Ese fue el ultimo pasajero, la lista esta vacia." << endl;
}

void clearBuffer() {
  while(getchar() != '\n')
    ;
}

