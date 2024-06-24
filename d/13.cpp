#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Estructura para representar un borde en el grafo
struct Edge {
    int src, dest, weight;
};

// Función para detectar ciclos negativos usando el algoritmo de Bellman-Ford
bool detectNegativeCycle(int vertices, vector<Edge>& edges) {
    vector<int> dist(vertices, INT_MAX);
    dist[0] = 0; // Iniciamos desde el nuevo nodo

    // Relajar todas las aristas |V|-1 veces
    for (int i = 1; i <= vertices - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Verificar ciclos negativos
    for (const auto& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            return true; // Se encontró un ciclo negativo
        }
    }

    return false;
}

int main() {
    int V, E;
    cout << "Ingrese el número de nodos: ";
    cin >> V;
    cout << "Ingrese el número de aristas: ";
    cin >> E;

    vector<Edge> edges(E + V);

    cout << "Ingrese las aristas (formato: src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Añadir el nuevo nodo y las aristas de coste 0
    for (int i = 0; i < V; i++) {
        edges[E + i] = {V, i, 0};
    }

    if (detectNegativeCycle(V + 1, edges)) {
        cout << "El grafo contiene un ciclo negativo." << endl;
    } else {
        cout << "El grafo no contiene ciclos negativos." << endl;
    }

    return 0;
}
