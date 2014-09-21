
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <set>          // std::list
using namespace std;

int infinito = 9999;

//Dado: un grafo con 5 nodos implementado en una tabla (arreglo bidimensional)
//Dado: las columnas de la tabla representan el inicio y las filas el destino
//Dado: las aristas tienen un valor de 0 si apuntan a ellas, infinito si no esta conectada y de lo contrario significa que sí hay una conexion entre los nodos

//Devuelve verdadero si existe al menos un camino para llegar desde el nodo inicio hasta el nodo destino
bool existeCamino(int grafo[5][5], int inicio, int destino)
{
    return false;
}

//Devuelve el set de los nodos adjacentes dado el nodo inicial y la profunidad del recorrido
//Ej. si la profundidad es igual a 0 solo se devuelve el nodo inicial
//Ej. si la profundidad es igual a 1 se devuelve el nodo inicial y sus adjacentes
//Ej. si la profundidad es igual a 2 se devuelve el nodo inicial, sus adjacentes y los adjacentes de los adjacentes
set<int> obtenerAdjacentes(int grafo[5][5], int inicio, int profundidad)
{
    set<int> respuesta;//set de nodos adjacentes resultante

    respuesta.insert(inicio);//agrego el nodo de inicio al set resultante

    if(profundidad<=0)//caso base: si he llegado a la profunidad final termina la recursion
        return respuesta;

    for(int i=0;i<5;i++)//para cada nodo
        if(grafo[inicio][i]!=infinito && inicio!=i)//si es adjacente a inicio
        {
            set<int> adjacentes = obtenerAdjacentes(grafo,i,profundidad-1);//obtengo recursivamente los nodos adjacentes con un nivel de profundidad menos
            respuesta.insert(adjacentes.begin(),adjacentes .end());//agrego los nodos obtenidos a mi set resultante
        }

    return respuesta;//devuelvo los nodos resultantes
}

int main ()
{
    evaluar();

    return 1;
}
