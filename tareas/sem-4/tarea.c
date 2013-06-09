#include <stdio.h>
#include <stdlib.h>

int menu();
char* storeArr();
int getId();
//struct persona* setPersona(struct persona* siguiente);
void setPersona();
void clearBuffer();

struct persona {
  int id;
  char *nombre;
  struct persona *siguiente;
};

struct persona *nodoTemp;

main() {

  return menu();
}

int menu() {
  char c;
  nodoTemp = (struct persona*) malloc(sizeof(struct persona));

  do {
    printf("~~ MENU ~~\nHaga una seleccion:\n 1. Ingresar nuevo nodo.\n 2. Imprimir la lista.\n 3. Contar los nodos.\n q: salir.\n ");
    c = getchar();
    switch(c) {
      case '1':
        setPersona();
        break;
      case '2':
        printf("dos");
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);

}

// retorna un int, >= 0 && < 10
int getId() {
  char c;
  int id = 0;
  
  printf("Ingrese el ID: (0 ~ 9): ");
  while((c = getchar()) != '\n' && c != EOF) {
    id = (int) c - '0';
  }

  return id;
}

// retorna un nuevo puntero a un arreglo
char* storeArr() {
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

//struct persona* setPersona(struct persona* siguiente) {
void setPersona() {
  struct persona *actual;
  actual = (struct persona*) malloc(sizeof(struct persona));

  clearBuffer();
  actual->nombre = storeArr();
  actual->id = getId();

  printf("id:\t%d\n", actual->id);
  printf("nom:\t%s\n", actual->nombre);
  printf("dir:\t%p\n", actual);
  printf("sig:\t%p\n", actual->siguiente);
  printf("ndtmp:\t%p\n", nodoTemp);
  nodoTemp->siguiente = actual; 
  nodoTemp = actual;
}

// http://cboard.cprogramming.com/c-programming/92513-cin-ignore-c.html
// http://stackoverflow.com/questions/10199897/cin-getline-is-skipping-an-input-in-c
// cuando se manejan menus que tienen breaklines, se ocupa limpiar el buffer
// antes de empezar a leer caracteres
void clearBuffer() {
  while(getchar() != '\n')
    ;
}

