#include <stdio.h>
#include <stdlib.h>

char* getPtrNom();
int getId();
int menu();
void clearBuffer();
void contarNodos();
void imprimirLista();
void setPersona();

struct persona {
  int id;
  char *nombre;
  struct persona *siguiente;
};

typedef struct persona Nodo;

Nodo *lista;
Nodo *nodoTemp;

main() {
  lista = (Nodo*) malloc(sizeof(Nodo));
  return menu();
}

int menu() {
  char c;
  nodoTemp = (Nodo*) malloc(sizeof(Nodo));

  do {
    printf("\n~~ MENU ~~\nHaga una seleccion:\n 1. Ingresar nuevo nodo.\n 2. Imprimir la lista.\n 3. Contar los nodos.\n q: salir.\n");
    c = getchar();
    switch(c) {
      case '1':
        setPersona();
        break;
      case '2':
        imprimirLista();
        break;
      case '3':
        contarNodos();
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);
}

int getId() {
  int num;
  printf("Ingrese el ID: ");
  scanf("%d" , &num);
  return num;
}

// retorna un nuevo puntero a un arreglo
char* getPtrNom() {
  char d,
       *newAr;

  int i = 0;

  newAr = (char*) malloc(sizeof(char)*100);

  printf("Ingrese el nombre: ");

  while((d = getchar()) != EOF && d != '\n') {
    newAr[i++] = d; 
  }

  return newAr;
}

void setPersona() {
  Nodo *actual;
  actual = (Nodo*) malloc(sizeof(Nodo));

  clearBuffer();
  actual->nombre = getPtrNom();
  actual->id = getId();

  // si es el primer nodo
  if (lista->siguiente == 0) {
    lista->siguiente = actual;
  } else {
    nodoTemp->siguiente = actual; 
  }
  nodoTemp = actual;
  clearBuffer();
}

void imprimirLista() {
  Nodo *temporal;

  if (lista->siguiente) {
    printf("Imprimiendo lista \n");

    temporal = lista->siguiente;

    while(temporal) {
      printf("ID:\t%d\n", temporal->id);
      printf("Nombre:\t%s\n", temporal->nombre);
      temporal = temporal->siguiente;
    }
  } else {
    printf("la lista esta vacia.\n\n");
  }
  clearBuffer();
}

void contarNodos() {
  Nodo *temporal;
  temporal = lista->siguiente;
  int i = 0;

  while(temporal) {
    i++;
    temporal = temporal->siguiente;
  }
  
  printf("Total: %d nodos.\n", i); 
  clearBuffer();
}

// http://cboard.cprogramming.com/c-programming/92513-cin-ignore-c.html
// http://stackoverflow.com/questions/10199897/cin-getline-is-skipping-an-input-in-c
// cuando se manejan menus que tienen breaklines, se ocupa limpiar el buffer
// antes de empezar a leer caracteres
void clearBuffer() {
  while(getchar() != '\n')
    ;
}

