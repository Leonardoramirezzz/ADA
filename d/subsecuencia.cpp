#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subsecuencia(vector<int>& V) {
    int n = V.size();
    if (n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> previous(n, -1);

    int maxLength = 1;
    int maxIndex = 0;

    // Llenar el arreglo dp
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[j] < V[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previous[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    vector<int> lis;
    for (int i = maxIndex; i >= 0; i = previous[i]) {
        lis.push_back(V[i]);
        if (previous[i] == -1) break;
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };
    vector<int> lis = subsecuencia(V);

    cout << "La secuencia creciente de máxima longitud es: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
