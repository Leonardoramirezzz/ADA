#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochila(int W, vector<int>& weights, vector<int>& benefits) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + benefits[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weights = { 3, 7, 4, 2, 1, 6 };
    vector<int> benefits = { 12, 3, 7, 4, 3, 8 };
    int W = 15;
    cout << "Max beneficio: " << mochila(W, weights, benefits) << endl;
    return 0;
}
