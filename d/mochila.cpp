#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

void todo(int W, vector<int>& weights, vector<int>& benefits) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<vector<set<int>>> solutions(n + 1, vector<set<int>>(W + 1));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                if (dp[i - 1][w] > dp[i - 1][w - weights[i - 1]] + benefits[i - 1]) {
                    dp[i][w] = dp[i - 1][w];
                    solutions[i][w] = solutions[i - 1][w];
                } else if (dp[i - 1][w] < dp[i - 1][w - weights[i - 1]] + benefits[i - 1]) {
                    dp[i][w] = dp[i - 1][w - weights[i - 1]] + benefits[i - 1];
                    solutions[i][w] = solutions[i - 1][w - weights[i - 1]];
                    solutions[i][w].insert(i - 1);
                } else {
                    dp[i][w] = dp[i - 1][w];
                    solutions[i][w] = solutions[i - 1][w];
                    solutions[i][w].insert(solutions[i - 1][w - weights[i - 1]].begin(), solutions[i - 1][w - weights[i - 1]].end());
                    solutions[i][w].insert(i - 1);
                }
            } else {
                dp[i][w] = dp[i - 1][w];
                solutions[i][w] = solutions[i - 1][w];
            }
        }
    }

    // Imprimir todas las soluciones óptimas
    set<int> optimalItems = solutions[n][W];
    for (auto item : optimalItems) {
        cout << item + 1 << " ";
    }
    cout << endl;
}

int main() {
    vector<int> weights = { 3, 7, 4, 2, 1, 6 };
    vector<int> benefits = { 12, 3, 7, 4, 3, 8 };
    int W = 15;
    cout << "Max beneficio: " << mochila(W, weights, benefits) << endl;
    return 0;
}
