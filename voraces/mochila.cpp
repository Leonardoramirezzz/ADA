#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int peso;
    int beneficio;
    double ratio;
};


bool comparador(const Objeto& a, const Objeto& b) {
    return a.ratio > b.ratio;
}

void Mochila(int M, vector<int> b, vector<int> p, vector<double>& X) {
    int n = b.size();
    vector<Objeto> objetos(n);

    for (int i = 0; i < n; ++i) {
        objetos[i].peso = p[i];
        objetos[i].beneficio = b[i];
        objetos[i].ratio = (double)b[i] / p[i];
    }
    sort(objetos.begin(), objetos.end(), comparador);
    for (int i = 0; i < n; ++i) {
        X[i] = 0.0;
    }
    int pesoAct = 0;
    for (int i = 0; i < n && pesoAct < M; ++i) {
        if (pesoAct + objetos[i].peso <= M) {
            X[i] = 1.0;
            pesoAct += objetos[i].peso;
        }
        else {
            X[i] = (double)(M - pesoAct) / objetos[i].peso;
            pesoAct = M;
        }
    }
}

int main() {
    int M = 20;
    vector<int> p = { 18, 15, 10 };
    vector<int> b = { 25, 24, 15 };
    vector<double> X(p.size());

    Mochila(M, b, p, X);

    cout << "Solución: " << endl;
    for (int i = 0; i < X.size(); ++i) {
        cout << "Objeto " << i + 1 << ": " << X[i] << endl;
    }

    return 0;
}
