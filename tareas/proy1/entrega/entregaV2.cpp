#include <iostream> // Para manejar entrada y salida
#include <queue> // Usado la cola implementada de C
#include <stdio.h>  // Para leer la entrada de ints
#include <vector> // Usado para el grafo
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAX 10005 // Maximo numero de puntos
#define INF 1<<30 // definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del distancia en alguna de las aristas
#define MAXFILAS 4 // Cantidad de filas que tendra archivo .txt

// puntos en el mapa
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

//La cola de prioridad de C++ por default es un max-Heap (elemento de mayor valor en el tope)
//por ello es necesario realizar nuestro comparador para que sea un min-Heap
struct cmp {
    bool operator() ( const Punto &a , const Punto &b ) {
        return a.tiempo > b.tiempo;
    }
};

bool listaPuntosVisitados[MAX]; // para vértices visitados
float listaTiempos[MAX];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
int listaPtoAnterio[MAX]; // para la impresion de caminos
int totalPuntos; // numero de puntos
int totalRutas; // total de rutas
priority_queue<Punto, vector<Punto>, cmp > ColaRutas; // priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
vector<Punto> grafo[MAX]; // lista de adyacencia

void menu();
void init();
void evaluarTiempo();
void imprimirCamino();
void dijkstra();
void cargarPuntos();
void calcularRuta();
void actualizarRuta();
void imprimirResultado();

//función de inicialización
void init() {
    for (int i = 0 ; i <= totalPuntos; ++i) {
        listaTiempos[i] = 1000.1000;
        listaPuntosVisitados[i] = false; //inicializamos todos los vértices como no visitados
        listaPtoAnterio[i] = -1;      //inicializamos el previo del punto i con -1
    }
}

//Paso de relajacion
void evaluarTiempo(int actual, int adyacente, int distancia, int velocidad, float tiempo) {
    //Si la distancia del origen al punto actual + peso de su arista es menor a la distancia del origen al punto adyacente
    if (listaTiempos[actual] + tiempo < listaTiempos[adyacente]) {
        listaTiempos[adyacente] = listaTiempos[actual] + tiempo;  //relajamos el punto actualizando la distancia
        listaPtoAnterio[adyacente] = actual;                         //a su vez actualizamos el punto previo
        ColaRutas.push(Punto(adyacente, distancia, velocidad, listaTiempos[adyacente])); //agregamos adyacente a la cola de prioridad
    }
}

// Impresion del camino mas corto desde el punto inicial y final ingresados
void imprimirCamino(int destino) {
    if( listaPtoAnterio[ destino ] != -1 ) {    //si aun poseo un punto previo
        imprimirCamino( listaPtoAnterio[ destino ] );  //recursivamente sigo explorando
    }
    cout << destino << "->";
}

void dijkstra(int inicial) {
    int actual, adyacente, distancia, velocidad;
    float tiempo;

    init(); //inicializamos nuestros arreglos
    ColaRutas.push(Punto(inicial, 0, 0, 0.0)); //Insertamos el vértice inicial en la Cola de Prioridad
    //listaDistancias[inicial] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    listaTiempos[inicial] = 0.0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    while (!ColaRutas.empty()) {                   //Mientras cola no este vacia
        actual = ColaRutas.top().adyacente;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        ColaRutas.pop();                           //Sacamos el elemento de la cola
        if (listaPuntosVisitados[actual]){
            continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        }
        listaPuntosVisitados[ actual ] = true;         //Marco como visitado el vértice actual

        for (int i = 0; i < grafo[actual].size(); ++i) { //reviso sus adyacentes del punto actual
            adyacente = grafo[actual][i].adyacente;   //id del punto adyacente
            distancia = grafo[actual][i].distancia;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            velocidad = grafo[actual][i].velocidad;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            tiempo = grafo[actual][i].tiempo;        //peso de la arista que une actual con adyacente ( actual , adyacente )

            if(!listaPuntosVisitados[adyacente]) {        //si el punto adyacente no fue visitado
                evaluarTiempo(actual, adyacente, distancia, velocidad, tiempo); //realizamos el paso de relajacion
            }
        }
    }


}


void cargarPuntos(){

    int i,
        j,
        puntos,
        elemento;

    //Leyendo valores de archivo txt
    ifstream archivo;
    archivo.open("PuntosRuta.txt");
    archivo >> totalPuntos;
    cout  << "- Total de Puntos:  " << totalPuntos << endl;
    archivo >> totalRutas;
    cout << "- Total de Rutas:  " << totalRutas << endl;
    int matriz[totalRutas][MAXFILAS]; // Matriz de adyacencia

    // filas
    for (i = 0; i < totalRutas; i++) {
        // recorriendo las columnas
        for(j = 0; j < MAXFILAS; j++) {
        archivo >> elemento;
        matriz[i][j] = elemento;
        }
    }
    archivo.close();

    //Impriendo valores que van a ser ingresados en el grafo
    cout << "- Matriz de Adyacencia: " << endl;
    cout << "-- ~~ -- ~~ -- ~~ --" << endl;
    // recorriendo las filas
    for (i = 0; i < totalRutas; i++) {
     // recorriendo las columnas
     for(j = 0; j < MAXFILAS; j++) {
        // barra al inicio de las filas
        if (j == 0) {
            cout << "| ";
        }

        cout << matriz[i][j] << " | ";

        // final de la linea
        if (j == MAXFILAS-1) {
            cout << endl;
        }
     }
    }
    cout << "-- ~~ -- ~~ -- ~~ --" << endl;

    //Ingresando valores de archivo en el grafo
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
        grafo[puntoOrigen].push_back(Punto(puntoDestino, distancia, velocidad, tiempo)); //consideremos grafo dirigido
    }

    int inicial;
    cout << "Ingrese el punto inicial: " << endl;
    scanf("%d", &inicial);
    dijkstra(inicial);

}

void calcularRuta(){
    int destino;

    cout << "**************Impresion de camino mas corto**************" << endl;
    cout << "Ingrese punto final: " << endl;
    scanf("%d" , &destino);
    cout << "Para el punto " << destino << ", el tiempo mas corto es = " << (float)(listaTiempos[destino]) << endl;
    cout << "Ruta: ";
    imprimirCamino(destino);
    cout << ".<" << endl;
}

void actualizarRuta(){
    int nuevaVelocidad,
        ptOrigen,
        ptDestino;

    cout << "Ingrese punto de origen: "<< endl;
    scanf("%d", &ptOrigen);

    cout << "Ingrese punto de destino: "<< endl;
    scanf("%d", &ptDestino);

    cout << "Ingrese la nueva velocidad: "<< endl;
    scanf("%d", &nuevaVelocidad);

    for (int i = 0; i < grafo[ptOrigen].size(); ++i) { //reviso sus adyacentes del punto actual
        if(grafo[ptOrigen][i].adyacente == ptDestino){
            grafo[ptOrigen][i].velocidad = nuevaVelocidad;
            grafo[ptOrigen][i].tiempo = (float)grafo[ptOrigen][i].distancia / nuevaVelocidad;
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
