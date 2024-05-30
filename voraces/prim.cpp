#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct Vertice;
struct Arista;

struct Vertice {
    int id;
    vector<Arista> conexiones;

    Vertice(int id) : id(id) {}
};

struct Arista {
    Vertice* inicio;
    Vertice* fin;
    int costo;

    Arista(Vertice* a, Vertice* b, int costo) : inicio(a), fin(b), costo(costo) {}
};

struct Grafo {
    vector<Vertice> vertices;
    vector<Arista> aristas;

    Grafo(const vector<Vertice>& v) {
        for (const auto& vertice : v) {
            vertices.push_back(vertice);
        }
    }

    void conectar(Vertice& a, Vertice& b, int costo) {
        Arista arista(&a, &b, costo);
        a.conexiones.push_back(arista);
        b.conexiones.push_back(arista);
        aristas.push_back(arista);
    }
};

struct CompareArista {
    bool operator()(Arista* a, Arista* b) {
        return a->costo > b->costo;
    }
};

void prim(Grafo& grafo, Vertice& raiz) {
    priority_queue<Arista*, vector<Arista*>, CompareArista> pq;
    vector<bool> visitado(grafo.vertices.size(), false);
    vector<Arista*> mst;

    auto agregarAristas = [&](Vertice& v) {
        visitado[v.id] = true;
        for (auto& arista : v.conexiones) {
            if (!visitado[arista.fin->id]) {
                pq.push(&arista);
            }
        }
    };

    agregarAristas(raiz);

    while (!pq.empty() && mst.size() < grafo.vertices.size() - 1) {
        Arista* menorArista = pq.top();
        pq.pop();

        if (visitado[menorArista->fin->id]) continue;

        mst.push_back(menorArista);
        agregarAristas(*menorArista->fin);
    }

    cout << "Aristas en el Árbol de Expansión Mínima (MST):" << endl;
    for (const auto& arista : mst) {
        cout << arista->inicio->id << " - " << arista->fin->id << " : " << arista->costo << endl;
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
    grafo.conectar(vertices[6], vertices[7], 9);
    grafo.conectar(vertices[7], vertices[8], 6);

    prim(grafo, vertices[0]);

    return 0;
}
