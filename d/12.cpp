#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minAssemblyTime(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int n) {
    vector<int> T1(n), T2(n);

    // Initialize base cases
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    // Fill tables T1[] and T2[] using the given relationships
    for (int i = 1; i < n; ++i) {
        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
    }

    // Consider exit times and return the minimum
    return min(T1[n - 1] + x[0], T2[n - 1] + x[1]);
}

int main() {
    int n = 6;  // Number of stations

    vector<vector<int>> a = {
        {7, 9, 3, 4, 8, 4},
        {8, 5, 6, 4, 5, 7}
    };

    vector<vector<int>> t = {
        {0, 2, 3, 1, 3, 4},  // Transfer times from line 1 to line 2
        {0, 2, 1, 2, 2, 1}   // Transfer times from line 2 to line 1
    };

    vector<int> e = { 2, 4 };  // Entry times
    vector<int> x = { 3, 2 };  // Exit times

    cout << "Minimum time: " << minAssemblyTime(a, t, e, x, n) << endl;

    return 0;
}
