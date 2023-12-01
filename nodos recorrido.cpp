#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Representación de un grafo dirigido mediante listas de adyacencia
map<int, vector<int>> grafo;

void agregarConexion(int nodoOrigen, int nodoDestino) {
    grafo[nodoOrigen].push_back(nodoDestino);
}

void recorrerGrafo(int numNodos, int nodoInicial) {
    queue<int> cola;
    map<int, bool> visitado;

    cola.push(nodoInicial);
    visitado[nodoInicial] = true;

    cout << "Orden de recorrido:" << endl;

    while (!cola.empty()) {
        int nodoActual = cola.front();
        cola.pop();

        // Imprimir el nodo actual mientras se recorre
        cout << nodoActual << " ";

        // Agregar los nodos adyacentes no visitados a la cola
        for (const int& vecino : grafo[nodoActual]) {
            if (!visitado[vecino]) {
                cola.push(vecino);
                visitado[vecino] = true;
            }
        }
    }

    cout << endl; // Salto de línea al final para mejorar la legibilidad
}

int main() {
    int numNodos, numConexiones;

    cout << "Ingrese el número de nodos: ";
    cin >> numNodos;

    cout << "Ingrese el número de conexiones: ";
    cin >> numConexiones;

    for (int i = 0; i < numConexiones; i++) {
        int nodoOrigen, nodoDestino;
        cout << "Ingrese conexión " << i + 1 << ": ";
        cin >> nodoOrigen >> nodoDestino;
        agregarConexion(nodoOrigen, nodoDestino);
    }

    int nodoInicial;
    cout << "Ingrese el nodo inicial: ";
    cin >> nodoInicial;

    recorrerGrafo(numNodos, nodoInicial);

    return 0;
}
