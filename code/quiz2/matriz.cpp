#include <cstdlib>
#include <fstream>
#include <iostream>

void floyd(int grafo[][100], int dimensiones);
void imprimirGrafo(int grafo[][100], int dimensiones);

using namespace std;

int main() {

  int i,
      j,
      dimensiones,
      elemento;

  ifstream archivo;
  archivo.open("eje.txt");
  archivo >> dimensiones;

  // revienta
  int grafo[dimensiones][100];

  // filas 
  for (i = 0; i < dimensiones; i++) {
     // recorriendo las columnas
     for(j = 0; j < dimensiones; j++) {
        archivo >> elemento;
        grafo[i][j] = elemento;
     }
  }

  archivo.close();

  imprimirGrafo(grafo, dimensiones);
  floyd(grafo, dimensiones);
}

/*
   Encuentra todos los caminos más cortos en un grafo, iniciando en cualquier nodo.
   • C: matriz de costos.
   • A: matriz de costos de los caminos más cortos.
   • n: número de nodos en el grafo.
   • Eficiencia: O(n3)
   A←C
   for k=1 to n
    for i=1 to n
     for j=1 to n
      A[i,j] ← min(A[i,j],A[i,k]+A[k,j])
*/ 
void floyd(int grafo[][100], int dimensiones) {
   int costosMasCortos[dimensiones][100];
   int i, j, k;

   // A←C
   for (i = 0; i < dimensiones; i++) {
     for(j = 0; j < dimensiones; j++) {
       costosMasCortos[i][j] = grafo[i][j];
     }
   }

   // for k=1 to n
   for (k = 1; k < dimensiones; k++) {
     // for i=1 to n
     for (i = 1; i < dimensiones; i++) {
       // for j=1 to n
       for (j = 1; j < dimensiones; j++) {
         // A[i,j] ← min(A[i,j],A[i,k]+A[k,j])
         costosMasCortos[i][j] = min(costosMasCortos[i][j], costosMasCortos[i][k] + costosMasCortos[k][j]);
       }
     }
   }

   imprimirGrafo(costosMasCortos, dimensiones);
}

void imprimirGrafo(int grafo[][100], int dimensiones) {
  cout << "-- ~~ -- ~~ -- ~~ --" << endl;

  for (int i = 0; i < dimensiones; i++) {
    for(int j = 0; j < dimensiones; j++) {
      cout << "| " << grafo[i][j] << "\t"; 

      if (j == dimensiones-1) {
        cout << "|" << endl;
      }
    }
  }

  cout << "-- ~~ -- ~~ -- ~~ --" << endl;
}

