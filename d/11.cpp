#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Función para calcular la fiabilidad de una fase con k dispositivos en paralelo
double fiabilidadFase(double r, int k) {
    return 1.0 - pow(1.0 - r, k);
}

// Función para maximizar la fiabilidad del sistema con una limitación de coste
double maximizarFiabilidad(vector<double>& r, vector<int>& c, int n, int C) {
    vector<vector<double>> dp(n + 1, vector<double>(C + 1, 0.0));

    // Llenar la tabla DP
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= C; ++j) {
            dp[i][j] = dp[i - 1][j]; // No usar dispositivos en la fase i
            for (int k = 1; k * c[i - 1] <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i - 1]] * fiabilidadFase(r[i - 1], k));
            }
        }
    }

    return dp[n][C];
}

int main() {
    int n; // Número de fases
    int C; // Coste total permitido

    cout << "Ingrese el número de fases: ";
    cin >> n;
    cout << "Ingrese el coste total permitido: ";
    cin >> C;

    vector<double> r(n);
    vector<int> c(n);

    cout << "Ingrese las fiabilidades de los dispositivos: ";
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    cout << "Ingrese los costes de los dispositivos: ";
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    double fiabilidadMaxima = maximizarFiabilidad(r, c, n, C);
    cout << "La máxima fiabilidad del sistema con el coste dado es: " << fiabilidadMaxima << endl;

    return 0;
}
