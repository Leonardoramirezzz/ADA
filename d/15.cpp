#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Función para calcular el ABB óptimo
double optimalBST(vector<double>& p, vector<double>& q, int n, vector<vector<double>>& e, vector<vector<int>>& root) {
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    
    return e[1][n];
}

// Función para imprimir el ABB óptimo
void printOptimalBST(vector<vector<int>>& root, int i, int j, int parent, bool left) {
    if (i > j) {
        if (left) {
            cout << "d" << parent << " izquierda: NULL" << endl;
        } else {
            cout << "d" << parent << " derecha: NULL" << endl;
        }
        return;
    }
    int r = root[i][j];
    if (parent == -1) {
        cout << "Root: k" << r << endl;
    } else if (left) {
        cout << "k" << parent << " izquierda: k" << r << endl;
    } else {
        cout << "k" << parent << " derecha: k" << r << endl;
    }
    printOptimalBST(root, i, r - 1, r, true);
    printOptimalBST(root, r + 1, j, r, false);
}

int main() {
    int n;
    cout << "Ingrese el número de claves: ";
    cin >> n;
    
    vector<double> p(n);
    vector<double> q(n + 1);
    
    cout << "Ingrese las probabilidades de acceso p_i: ";
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    cout << "Ingrese las probabilidades de acceso infructuoso q_i: ";
    for (int i = 0; i <= n; ++i) {
        cin >> q[i];
    }
    
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));
    
    double coste = optimalBST(p, q, n, e, root);
    
    cout << "El coste mínimo esperado es: " << coste << endl;
    cout << "El árbol binario de búsqueda óptimo es:" << endl;
    printOptimalBST(root, 1, n, -1, false);
    
    return 0;
}

