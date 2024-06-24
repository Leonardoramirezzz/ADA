#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, unordered_map<char, char>> multiplicacion = {// Multiplicacion de tabla
    {'a', {{'a', 'b'}, {'b', 'b'}, {'c', 'a'}}},
    {'b', {{'a', 'c'}, {'b', 'b'}, {'c', 'a'}}},
    {'c', {{'a', 'a'}, {'b', 'c'}, {'c', 'c'}}}
};

bool multi(string V, char target) {
    int n = V.size();
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(3, false)));

    for (int i = 0; i < n; i++)
        dp[i][i][V[i] - 'a'] = true;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                for (int x = 0; x < 3; x++) {
                    if (!dp[i][k][x]) continue;
                    for (int y = 0; y < 3; y++) {
                        if (!dp[k + 1][j][y]) continue;
                        int z = multiplicacion['a' + x]['a' + y] - 'a';
                        dp[i][j][z] = true;
                    }
                }
            }
        }
    }

    return dp[0][n - 1][target - 'a'];
}

int main() {
    string V = "abcabc";
    char target = 'a';
    cout << (multi(V, target) ? "True" : "False") << endl;

    return 0;
}