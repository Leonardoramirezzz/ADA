#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct Vertice {
    int id;
    vector<pair<Vertice*, int>> conexiones;

    Vertice(int id) : id(id) {}
};

struct CompareArista {
    bool operator()(const pair<int, pair<Vertice*, Vertice*>>& a, const pair<int, pair<Vertice*, Vertice*>>& b) {
        return a.first > b.first;
    }
};

struct Grafo {
    vector<Vertice> vertices;

    Grafo(const vector<Vertice>& v) {
        for (const auto& vertice : v) {
            vertices.push_back(vertice);
        }
    }

    void conectar(Vertice& a, Vertice& b, int costo) {
        a.conexiones.push_back({ &b, costo });
        b.conexiones.push_back({ &a, costo });
    }
};

void prim(Grafo& grafo, Vertice& raiz) {
    priority_queue<pair<int, pair<Vertice*, Vertice*>>, vector<pair<int, pair<Vertice*, Vertice*>>>, CompareArista> pq;
    vector<bool> visitado(grafo.vertices.size(), false);
    vector<pair<int, pair<Vertice*, Vertice*>>> mst;

    auto agregarAristas = [&](Vertice& v) {
        visitado[v.id] = true;
        for (auto& conexion : v.conexiones) {
            if (!visitado[conexion.first->id]) {
                pq.push({ conexion.second, {&v, conexion.first} });
            }
        }
    };

    agregarAristas(raiz);

    while (!pq.empty() && mst.size() < grafo.vertices.size() - 1) {
        auto menorArista = pq.top();
        pq.pop();

        Vertice* v1 = menorArista.second.first;
        Vertice* v2 = menorArista.second.second;

        if (visitado[v2->id]) continue;

        mst.push_back(menorArista);
        agregarAristas(*v2);
    }

    cout << "Aristas del arbolito:" << endl;
    for (const auto& arista : mst) {
        cout << arista.second.first->id << " - " << arista.second.second->id << " : " << arista.first << endl;
    }
}

int main() {
    vector<Vertice> vertices;
    for (int i = 0; i < 9; ++i) {
        vertices.push_back(Vertice(i));
    }

    Grafo grafo(vertices);
    grafo.conectar(vertices[0], vertices[1], 12);
    grafo.conectar(vertices[0], vertices[4], 5);
    grafo.conectar(vertices[0], vertices[3], 7);
    grafo.conectar(vertices[1], vertices[2], 5);
    grafo.conectar(vertices[1], vertices[7], 5);
    grafo.conectar(vertices[1], vertices[8], 11);
    grafo.conectar(vertices[2], vertices[3], 3);
    grafo.conectar(vertices[3], vertices[4], 6);
    grafo.conectar(vertices[3], vertices[5], 8);
    grafo.conectar(vertices[3], vertices[7], 4);
    grafo.conectar(vertices[4], vertices[5], 4);
    grafo.conectar(vertices[5], vertices[6], 9);
    grafo.conectar(vertices[6], vertices[7], 7);
    grafo.conectar(vertices[7], vertices[8], 6);

    prim(grafo, vertices[0]);

    return 0;
}
