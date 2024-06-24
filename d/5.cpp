#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

int tsp(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Vuelve al nodo de inicio
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    int n;
    cout << "Ingrese el número de nodos: ";
    cin >> n;
    
    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Ingrese la matriz de distancias: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << "La longitud del circuito hamiltoniano minimal es: " << tsp(1, 0, dist, dp, n) << endl;

    return 0;
}
