#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX 10005 //maximo numero de vértices
#define PuntoEnRuta pair< int , float > //definimos el nodo como un par( first , second ) donde first es el vertice adyacente y second el peso de la arista
#define INF 1<<30 //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas

//La cola de prioridad de C++ por default es un max-Heap (elemento de mayor valor en el tope)
//por ello es necesario realizar nuestro comparador para que sea un min-Heap
struct cmp {
    bool operator() ( const PuntoEnRuta &a , const PuntoEnRuta &b ) {
        return a.second > b.second;
    }
};

vector< PuntoEnRuta > ady[ MAX ]; //lista de adyacencia
float distancia[ MAX ];      //distancia[ u ] distancia de vértice inicial a vértice con ID = u
bool visitado[ MAX ];      //para vértices visitados
priority_queue< PuntoEnRuta , vector<PuntoEnRuta> , cmp > ColaPrioridad; //priority queue propia del c++, usamos el comparador definido para que el de menor valor este en el tope
int V;                     //numero de vertices
int previo[ MAX ];         //para la impresion de caminos

//función de inicialización
void init() {
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
        visitado[ i ] = false; //inicializamos todos los vértices como no visitados
        previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
    }
}

//Paso de relajacion
void relajacion( int actual , int adyacente , float peso ) {
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
        previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
        ColaPrioridad.push( PuntoEnRuta( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
    }
}

// Impresion del camino mas corto desde el vertice inicial y final ingresados
void imprimirCamino(int destino) {
    if( previo[ destino ] != -1 ) {    //si aun poseo un vertice previo
        imprimirCamino( previo[ destino ] );  //recursivamente sigo explorando
    }
    printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
}

void dijkstra( int inicial ) {
    int actual, adyacente, destino;
    float peso;

    init(); //inicializamos nuestros arreglos
    ColaPrioridad.push( PuntoEnRuta( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
    distancia[ inicial ] = 0.0;      //Este paso es importante, inicializamos la distancia del inicial como 0

    while( !ColaPrioridad.empty() ){                   //Mientras cola no este vacia
        actual = ColaPrioridad.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
        ColaPrioridad.pop();                           //Sacamos el elemento de la cola
        if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
        visitado[ actual ] = true;         //Marco como visitado el vértice actual

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){ //reviso sus adyacentes del vertice actual
            adyacente = ady[ actual ][ i ].first;   //id del vertice adyacente
            peso = ady[ actual ][ i ].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
            if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
            }
        }
    }

    puts("\n**************Impresion de camino mas rapido**************");
    printf("Ingrese vertice destino: ");
    scanf("%d" , &destino );
    printf("Vertice %d, tiempo mas corto = %f\n" , destino , distancia[destino] );
    imprimirCamino( destino );
    printf("\n");
}

int main() {
    int totalConexiones , origen, destino , distancia, velocidad, inicial;
    float tiempo;

    cout << "Ingrese la cantidad de puntos en ruta: ";
    scanf("%d" , &V );

    cout << "Ingrese el total de conexiones entre ellos: ";
    scanf("%d" , &totalConexiones );

    while( totalConexiones-- ) {
        puts("Ingrese el origen | destino | distancia | velocidad: ");
        scanf("%d %d %d %d" , &origen , &destino , &distancia, &velocidad);
        tiempo = (float)(distancia)/(float)(velocidad);
        ady[ origen ].push_back( PuntoEnRuta( destino , tiempo ) ); //consideremos grafo dirigido
    }

    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    dijkstra( inicial );
    return 0;
}

