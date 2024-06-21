
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxbeneficio(int n, int r, const vector<vector<int>>& N) {
    vector<vector<int>> dp(r + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= r; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + N[i - 1][k]);
            }
        }
    }

    return dp[r][n];
}

int main() {
    int n = 5;
    int r = 3;

    vector<vector<int>> N = {
        {0, 1, 2, 3, 4, 5},
        {0, 2, 4, 6, 8, 10},
        {0, 1, 3, 6, 10, 15}
    };

    int max_benefit = maxbeneficio(n, r, N);

    cout << "beneficio maximo: " << max_benefit << endl;

    return 0;
}
