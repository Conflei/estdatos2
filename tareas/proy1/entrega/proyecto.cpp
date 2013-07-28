#include <fstream> // Usado para leer contenido de archivos.
#include <iostream> // Para manejar entrada y salida de texto.
#include <queue> // Usado la cola de prioridad de C++.
#include <stdio.h>  // Para leer/parsear la entrada de ints.
#include <vector> // Usado para la matriz de adyacencia.

#define COLUMNAS 4 // Cantidad de columnas que tendra la matriz de adyacencia.
#define INF 1<<30 // Definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del distancia en alguna de las aristas
#define MAX 10005 // Maximo numero de puntos en el grafo.
#define MAXTIEMPO 1000.1000 // Maximo tiempo entre dos puntos.

using namespace std;

// Clase Punto
// Adyacente: punto con que conecta la ruta.
// Distancia: 'peso' entre puntos.
// Velocidad: en km/h, velocidad entre dos puntos.
// Tiempo: distancia/velocidad.
class Punto {
  public:
    Punto(int pAdyacente, int pDistancia, int pVelocidad, float pTiempo) : adyacente(pAdyacente), distancia(pDistancia), velocidad(pVelocidad), tiempo(pTiempo) {}
    Punto(int pAdyacente, int pDistancia) : adyacente(pAdyacente), distancia(pDistancia), velocidad(0), tiempo(0.0) {}
    Punto(): adyacente(0), distancia(0), velocidad(0), tiempo(0.0) {}
    int adyacente;
    int distancia;
    int velocidad;
    float tiempo;
};

// La cola de prioridad de C++ obtiene el valor de mayor valor, tenemos que
// sobrescribir la funcion de comparacion para que tome el menor valor.
struct compararPuntos {
    bool operator() (const Punto &a, const Punto &b) {
        return a.tiempo > b.tiempo;
    }
};

// Variables globales
bool listaPuntosVisitados[MAX]; // Arreglo usado para puntos visitados.
float listaTiempos[MAX]; // Arreglo de distancias acumuladas desde el punto inicial.
int listaPuntosAnteriores[MAX]; // Arreglo usado para la impresion de caminos cortos.
int totalPuntos; // Total de puntos en el grafo.
int totalRutas; // Total de rutas en el grafo (conexiones entre puntos).
priority_queue<Punto, vector<Punto>, compararPuntos> ColaRutas; // Usado para almacenar los datos durante Dijkstra.
vector<Punto> matrizAdyacencia[MAX]; // Matriz de adyacencia.

// Prototipos para las funciones:
void _init(); // Preparacion para Dijkstra.
void dijkstra(); // Implementacion del algoritmo.
void evaluarTiempo(); // Backtracking de Dijkstra.
void imprimirCamino(); // Imprime la ruta entre dos puntos.
void menu(); // Maneja la interaccion con el usuario.
void cargarPuntos(); // Lectura desde archivo.
void calcularRuta(); // Calcula distancia entre dos puntos.
void actualizarRuta(); // Sobrescribe valores leidos de archivo.

// Inicializa los arreglos usados por Dijkstra con valores iniciales.
void _init() {
    for (int i = 0 ; i <= totalPuntos; ++i) {
        listaPuntosAnteriores[i] = -1; // Inicializamos el punto previo del punto i con -1.
        listaPuntosVisitados[i] = false; // Inicializamos todos los puntos como no visitados.
        listaTiempos[i] = MAXTIEMPO; // Inicializamos todos los tiempos con MAXTIEMPO. 
    }
}

// Backtracking de Dijkstra: compara si el punto encontrado es mas rapido que el
// punto anteriormente almacenado.
void evaluarTiempo(int actual, int adyacente, int distancia, int velocidad, float tiempo) {
    // Si la distancia del origen al punto actual + peso de su arista es menor a la distancia del origen al punto adyacente
    if (listaTiempos[actual] + tiempo < listaTiempos[adyacente]) {
        listaTiempos[adyacente] = listaTiempos[actual] + tiempo;  //relajamos el punto actualizando la distancia
        listaPuntosAnteriores[adyacente] = actual;                         //a su vez actualizamos el punto previo
        ColaRutas.push(Punto(adyacente, distancia, velocidad, listaTiempos[adyacente])); //agregamos adyacente a la cola de prioridad
    }
}

// Funcion recursiva para la impresion del camino mas corto.
void imprimirCamino(int destino) {
    if (listaPuntosAnteriores[destino] != -1) {    //si aun poseo un punto previo
        imprimirCamino(listaPuntosAnteriores[destino]);  //recursivamente sigo explorando
    }
    cout << destino << "->";
}

void dijkstra(int inicial) {
    int actual, adyacente, distancia, velocidad;
    float tiempo;

    _init(); //inicializamos nuestros arreglos
    ColaRutas.push(Punto(inicial, 0, 0, 0.0)); //Insertamos el vértice inicial en la Cola de Prioridad
    listaTiempos[inicial] = 0.0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    while (!ColaRutas.empty()) {                   //Mientras cola no este vacia
        actual = ColaRutas.top().adyacente;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        ColaRutas.pop();                           //Sacamos el elemento de la cola
        if (listaPuntosVisitados[actual]){
            continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        }
        listaPuntosVisitados[ actual ] = true;         //Marco como visitado el vértice actual

        for (int i = 0; i < matrizAdyacencia[actual].size(); ++i) { //reviso sus adyacentes del punto actual
            adyacente = matrizAdyacencia[actual][i].adyacente;   //id del punto adyacente
            distancia = matrizAdyacencia[actual][i].distancia;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            velocidad = matrizAdyacencia[actual][i].velocidad;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            tiempo = matrizAdyacencia[actual][i].tiempo;        //peso de la arista que une actual con adyacente ( actual , adyacente )

            if(!listaPuntosVisitados[adyacente]) {        //si el punto adyacente no fue visitado
                evaluarTiempo(actual, adyacente, distancia, velocidad, tiempo); //realizamos el paso de relajacion
            }
        }
    }


}


void cargarPuntos() {
    int elemento,
        puntos,
        i,
        j;

    //Leyendo valores de archivo txt
    ifstream archivo;
    archivo.open("Grafo1.txt");
    archivo >> totalPuntos;
    cout  << "- Total de Puntos:  " << totalPuntos << endl;
    archivo >> totalRutas;
    cout << "- Total de Rutas:  " << totalRutas << endl;
    int matriz[totalRutas][COLUMNAS]; // Matriz de adyacencia

    // filas
    for (i = 0; i < totalRutas; i++) {
        // recorriendo las columnas
        for(j = 0; j < COLUMNAS; j++) {
          archivo >> elemento;
          matriz[i][j] = elemento;
        }
    }
    archivo.close();

    //Impriendo valores que van a ser ingresados en el grafo
    cout << "Matriz de Adyacencia." << endl;
    cout << "-- ~~ -- ~~ -- ~~ --" << endl;
    cout << "Org. | Dest. | Dist. | Vel." << endl;
    // recorriendo las filas
    for (i = 0; i < totalRutas; i++) {
     // recorriendo las columnas
     for(j = 0; j < COLUMNAS; j++) {
        // barra al inicio de las filas
        if (j == 0) {
            cout << "| ";
        }

        cout << matriz[i][j] << " | ";

        // final de la linea
        if (j == COLUMNAS-1) {
            cout << endl;
        }
     }
    }
    cout << "-- ~~ -- ~~ -- ~~ --" << endl;

    // Ingresando valores de archivo en el grafo
    float tiempo;
    int puntoOrigen,
        puntoDestino,
        distancia,
        velocidad;

    // recorriendo las filas
    for (i = 0; i < totalRutas; i++) {
        puntoOrigen = matriz[i][0];
        puntoDestino = matriz[i][1];
        distancia = matriz[i][2];
        velocidad = matriz[i][3];
        tiempo = (float)(distancia)/(float)(velocidad);
        matrizAdyacencia[puntoOrigen].push_back(Punto(puntoDestino, distancia, velocidad, tiempo)); //consideremos grafo dirigido
    }
}

void calcularRuta() {
    int inicial,
        destino;

    cout << "**************Impresion de camino mas corto**************" << endl;
    cout << "Ingrese el punto inicial: " << endl;
    scanf("%d", &inicial);
    dijkstra(inicial);
    cout << "Ingrese punto final: " << endl;
    scanf("%d" , &destino);
    cout << "Para el punto " << destino << ", el tiempo mas corto es = " << (float)(listaTiempos[destino]) << endl;
    cout << "Ruta: ";
    imprimirCamino(destino);
    cout << ".<" << endl;
}

void actualizarRuta() {
    int nuevaVelocidad,
        ptOrigen,
        ptDestino;

    cout << "Ingrese punto de origen: "<< endl;
    scanf("%d", &ptOrigen);

    cout << "Ingrese punto de destino: "<< endl;
    scanf("%d", &ptDestino);

    cout << "Ingrese la nueva velocidad: "<< endl;
    scanf("%d", &nuevaVelocidad);

    for (int i = 0; i < matrizAdyacencia[ptOrigen].size(); ++i) { //reviso sus adyacentes del punto actual
        if(matrizAdyacencia[ptOrigen][i].adyacente == ptDestino){
            matrizAdyacencia[ptOrigen][i].velocidad = nuevaVelocidad;
            matrizAdyacencia[ptOrigen][i].tiempo = (float)matrizAdyacencia[ptOrigen][i].distancia / nuevaVelocidad;
        }
    }

    dijkstra(ptOrigen);
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
        cargarPuntos();
        break;
      case '2':
        calcularRuta();
        break;
      case '3':
        actualizarRuta();
        break;
      default:
        break;
    }
  } while(c != 'q' && c != EOF);
}

int main() {
    menu();
    return 1;
}
