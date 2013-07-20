#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX 10005 //maximo numero de vértices
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del distancia en alguna de las aristas

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
        return a.distancia > b.distancia;
    }
};

//float listaDistancias[MAX];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool listaPuntosVisitados[MAX]; // para vértices visitados
int listaDistancias[MAX]; // listaDistancias[ u ] distancia de vértice inicial a vértice con ID = u
int listaPtoAnterio[MAX]; // para la impresion de caminos
int totalPuntos; // numero de puntos
priority_queue<Punto, vector<Punto>, cmp > ColaRutas; // priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
vector<Punto> grafo[MAX]; // lista de adyacencia

//función de inicialización
void init() {
    for( int i = 0 ; i <= totalPuntos; ++i ){
        listaDistancias[i] = INF;  //inicializamos todas las distancias con valor infinito
        listaPuntosVisitados[i] = false; //inicializamos todos los vértices como no visitados
        listaPtoAnterio[i] = -1;      //inicializamos el previo del punto i con -1
    }
}

//Paso de relajacion
//void relajacion( int actual , int adyacente , float tiempo) {
void relajacion( int actual , int adyacente , int peso) {
    //Si la distancia del origen al punto actual + peso de su arista es menor a la distancia del origen al punto adyacente
    if( listaDistancias[ actual ] + peso < listaDistancias[ adyacente ] ){
        //listaDistancias[ adyacente ] = listaDistancias[ actual ] + tiempo;  //relajamos el punto actualizando la distancia
        listaDistancias[ adyacente ] = listaDistancias[ actual ] + peso;  //relajamos el punto actualizando la distancia
        listaPtoAnterio[ adyacente ] = actual;                         //a su vez actualizamos el punto previo
        ColaRutas.push(Punto(adyacente, listaDistancias[adyacente])); //agregamos adyacente a la cola de prioridad
    }
}

// Impresion del camino mas corto desde el punto inicial y final ingresados
void imprimirCamino(int destino) {
    if( listaPtoAnterio[ destino ] != -1 ) {    //si aun poseo un punto previo
        imprimirCamino( listaPtoAnterio[ destino ] );  //recursivamente sigo explorando
    }
    cout << destino << "->";
}

void dijkstra( int inicial ) {
    int actual, adyacente, destino, peso;
    //float tiempo;

    init(); //inicializamos nuestros arreglos
    ColaRutas.push(Punto(inicial, 0)); //Insertamos el vértice inicial en la Cola de Prioridad
    //listaDistancias[ inicial ] = 0.0;      //Este paso es importante, inicializamos la distancia del inicial como 0
    listaDistancias[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    while( !ColaRutas.empty() ){                   //Mientras cola no este vacia
        actual = ColaRutas.top().adyacente;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        ColaRutas.pop();                           //Sacamos el elemento de la cola
        if (listaPuntosVisitados[actual]) {
            continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        }
        listaPuntosVisitados[ actual ] = true;         //Marco como visitado el vértice actual

        for (int i = 0; i < grafo[actual].size(); ++i ){ //reviso sus adyacentes del punto actual
            adyacente = grafo[ actual ][ i ].adyacente;   //id del punto adyacente
            //tiempo = grafo[actual][i].tiempo;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            peso = grafo[actual][i].distancia;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if(!listaPuntosVisitados[adyacente]) {        //si el punto adyacente no fue visitado
                relajacion(actual, adyacente, peso); //realizamos el paso de relajacion
            }
        }
    }

    cout << "**************Impresion de camino mas corto**************" << endl;
    cout << "Ingrese punto destino: " << endl;
    scanf("%d" , &destino );
    cout << "Para el punto " << destino << ", la distancia mas corta es = " << listaDistancias[destino] << endl;
    imprimirCamino( destino );
    cout << ".<" << endl;
}

int main() {
    float tiempo;
    int destino,
        distancia,
        inicial,
        origen,
        velocidad,
        totalRutas;

    cout << "Ingrese la cantidad de puntos: ";
    scanf("%d" , &totalPuntos);

    cout << "Ingrese el total de rutas: ";
    scanf("%d" , &totalRutas);

    while (totalRutas--) { // mientras el total de rutas sea mayor a cero
        cout << "Ingrese la ruta en formato:  origen | destino | distancia | velocidad: " << endl;
        scanf("%d %d %d %d" , &origen , &destino , &distancia, &velocidad);
        //tiempo = (float)(distancia)/(float)(velocidad);
        //grafo[origen].push_back( Punto( destino , tiempo ) ); //consideremos grafo dirigido
        grafo[origen].push_back(Punto(destino, distancia)); //consideremos grafo dirigido
    }

    cout << "Ingrese el punto inicial: " << endl;
    scanf("%d", &inicial);
    dijkstra(inicial);
    return 0;
}

