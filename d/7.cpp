#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Función para calcular el costo mínimo de unir los eslabones
int minChainCost(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Llenar la tabla dp
    for (int length = 2; length < n; length++) {
        for (int i = 0; i < n - length; i++) {
            int j = i + length;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + p[i] + p[j - 1] + p[k];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    cout << "Ingrese el número de eslabones: ";
    cin >> n;

    vector<int> p(n);
    cout << "Ingrese los pesos de los eslabones: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "El costo mínimo para unir todos los eslabones es: " << minChainCost(p) << endl;

    return 0;
}
