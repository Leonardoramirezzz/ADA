#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

// Función para encontrar el camino de coste mínimo en un grafo multitapa
int shortestPath(vector<vector<pair<int, int>>>& graph, int stages) {
    int n = graph.size();
    vector<int> cost(n, INT_MAX);  // Almacenar los costos mínimos
    vector<int> path(n, -1);       // Almacenar el camino
    cost[0] = 0;                   // El costo desde el origen a sí mismo es 0

    // Calcular los costos mínimos para cada vértice en cada etapa
    for (int stage = 1; stage < stages; ++stage) {
        for (int u = 0; u < n; ++u) {
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (cost[u] != INT_MAX && cost[u] + weight < cost[v]) {
                    cost[v] = cost[u] + weight;
                    path[v] = u;
                }
            }
        }
    }

    // Imprimir el camino
    vector<int> result;
    for (int v = n - 1; v != -1; v = path[v]) {
        result.push_back(v);
    }
    reverse(result.begin(), result.end());

    cout << "Camino de coste mínimo: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return cost[n - 1];
}

int main() {
    int stages = 5;  // Número de etapas
    int n = 11;      // Número de vértices
    vector<vector<pair<int, int>>> graph(n);

    // Representación del grafo (vértice, peso)
    graph[0] = {{1, 5}, {2, 3}};
    graph[1] = {{3, 6}, {4, 7}};
    graph[2] = {{4, 4}, {5, 2}};
    graph[3] = {{6, 2}};
    graph[4] = {{6, 3}, {7, 4}};
    graph[5] = {{7, 1}};
    graph[6] = {{8, 4}};
    graph[7] = {{8, 2}, {9, 3}};
    graph[8] = {{10, 2}};
    graph[9] = {{10, 2}};

    cout << "El coste mínimo desde el origen al destino es: " << shortestPath(graph, stages) << endl;

    return 0;
}
