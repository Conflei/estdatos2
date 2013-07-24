#include <iostream> // Para manejar entrada y salida
#include <queue> // Usado la cola implementada de C
#include <stdio.h>  // Para leer la entrada de ints
#include <vector> // Usado para el grafo

using namespace std;

#define MAX 10005 // Maximo numero de puntos
#define INF 1<<30 // definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del distancia en alguna de las aristas

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
int listaDistancias[MAX]; // listaDistancias[ u ] distancia de vértice inicial a vértice con ID = u
int listaPtoAnterio[MAX]; // para la impresion de caminos
int totalPuntos; // numero de puntos
priority_queue<Punto, vector<Punto>, cmp > ColaRutas; // priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
vector<Punto> grafo[MAX]; // lista de adyacencia

//función de inicialización
void init() {
    for (int i = 0 ; i <= totalPuntos; ++i) {
        listaTiempos[i] = 1E+37;
        listaDistancias[i] = INF;  //inicializamos todas las distancias con valor infinito
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

//Paso de relajacion
void evaluarDistancia(int actual, int adyacente, int distancia, int velocidad, float tiempo) {
    //Si la distancia del origen al punto actual + peso de su arista es menor a la distancia del origen al punto adyacente
    if (listaDistancias[actual] + distancia < listaDistancias[adyacente]) {
        listaDistancias[adyacente] = listaDistancias[actual] + distancia;  //relajamos el punto actualizando la distancia
        // ocupamos otra lista para la ruta de distancia
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
    int actual, adyacente, destino, distancia, velocidad;
    float tiempo;

    init(); //inicializamos nuestros arreglos
    ColaRutas.push(Punto(inicial, 0, 0, 0.0)); //Insertamos el vértice inicial en la Cola de Prioridad
    listaDistancias[inicial] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    listaTiempos[inicial] = 0.0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    while (!ColaRutas.empty()) {                   //Mientras cola no este vacia
        actual = ColaRutas.top().adyacente;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        ColaRutas.pop();                           //Sacamos el elemento de la cola
        if (listaPuntosVisitados[actual]) {
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
                //evaluarDistancia(actual, adyacente, distancia, velocidad, tiempo); //realizamos el paso de relajacion
            }
        }
    }

    cout << "**************Impresion de camino mas corto**************" << endl;
    cout << "Ingrese punto final: " << endl;
    scanf("%d" , &destino);
    //cout << "Para el punto " << destino << ", la distancia mas corta es = " << listaDistancias[destino] << endl;
    cout << "Para el punto " << destino << ", el tiempo mas corto es = " << (float)(listaTiempos[destino]) << endl;
    cout << "Ruta: ";
    imprimirCamino(destino);
    cout << ".<" << endl;
}

int main() {
    float tiempo;
    int puntoDestino,
        distancia,
        inicial,
        puntoOrigen,
        velocidad,
        totalRutas;

    cout << "Ingrese la cantidad de puntos: ";
    scanf("%d" , &totalPuntos);

    cout << "Ingrese el total de rutas: ";
    scanf("%d" , &totalRutas);

    while (totalRutas--) { // mientras el total de rutas sea mayor a cero
        cout << "Ingrese la ruta en formato:  origen | destino | distancia | velocidad: " << endl;
        scanf("%d %d %d %d" , &puntoOrigen , &puntoDestino , &distancia, &velocidad);
        tiempo = (float)(distancia)/(float)(velocidad);
        grafo[puntoOrigen].push_back(Punto(puntoDestino, distancia, velocidad, tiempo)); //consideremos grafo dirigido
    }

    cout << "Ingrese el punto inicial: " << endl;
    scanf("%d", &inicial);
    dijkstra(inicial);
    return 0;
}

