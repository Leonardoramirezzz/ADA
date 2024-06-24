#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum benefit
int maximizeBenefit(const vector<vector<int>>& benefit, int n, int r) {
    // Create a 2D array to store the maximum benefit
    vector<vector<int>> dp(r + 1, vector<int>(n + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= r; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];  // No resource allocated to the i-th project
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + benefit[i - 1][k]);
            }
        }
    }

    // The maximum benefit is found in dp[r][n]
    return dp[r][n];
}

int main() {
    // Define the number of units of resource and projects
    int n = 5;  // Number of units
    int r = 3;  // Number of projects

    // Define the benefit matrix
    vector<vector<int>> benefit = {
        {0, 3, 6, 8, 9, 12},
        {0, 2, 4, 7, 9, 10},
        {0, 1, 3, 5, 8, 10}
    };

    // Find and print the maximum benefit
    int maxBenefit = maximizeBenefit(benefit, n, r);
    cout << "Maximum Benefit: " << maxBenefit << endl;

    return 0;
}
