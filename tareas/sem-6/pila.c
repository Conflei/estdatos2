#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

struct stack {
  int stk[MAX];
  //char nombre[MAX];
  int top;
};

typedef struct stack pila;
pila s;

void push (void);
int  pop(void);
void imprimir (void);

int getId();
//char* getStr();
void clearBuffer(void);

int main() {
  // faltaba inicilizar la pila como 'vacia'
  s.top = -1;
  return menu();
}

void push(){
  int id;

  if (s.top == (MAX - 1)) {
    printf("Stack esta lleno\n");
    return;
  } else if (s.top == 0) {
    id=getId();
    clearBuffer();
    s.top = 1;
    s.stk[s.top]=id;
    printf("PRIMER elemento ingresado en la pila\n");
  } else {
    id=getId();
    clearBuffer();

    s.top=s.top + 1;
    s.stk[s.top]=id;
    printf("Elemento ingresado en la pila\n");
  }
  return;
}

int pop(){

  int num;

  if(s.top == -1) {
    printf("Stack esta vacio\n");
    return(s.top);
  } else {
    num = s.stk[s.top];
    printf("Elemento: %d\n", num);
    s.top = s.top - 1;
  }

  return num;
}

void imprimir(){
  int i;

  if(s.top == -1){
    printf ("La pila esta vacia\n");
    return;
  }else{
    printf ("\nElementos en la pila:\n");
    for(i=s.top; i>=0; i--){
      printf("%d\n", s.stk[i]);
    }
  }

  printf("\n");
}

int getId() {
  int num;
  printf("Ingrese el ID: ");
  scanf("%d" , &num);
  return num;
}

/*char* getStr() {
  char d,*newAr;

  int i = 0;

  newAr = (char*) malloc(sizeof(char)*100);

  printf("Ingrese el nombre: ");
  while((d = getchar()) != EOF && d != '\n') {
    newAr[i++] = d;
  }

  return newAr;
}*/

void clearBuffer() {
  while(getchar() != '\n')
    ;
}

int menu() {
  char c;

  do {
    printf("\n~~ MENU ~~\nHaga una seleccion:\n 1. Push.\n 2. Pop.\n 3. Display.\n q: salir.\n");
    c = getchar();
    switch(c) {
      case '1':
        clearBuffer();
        push();
        break;
      case '2':
        clearBuffer();
        pop();
        break;
      case '3':
        clearBuffer();
        imprimir();
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);

  return 1;
}

