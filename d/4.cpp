#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> incrementocreciente(vector<int> V) {
    int n = V.size();
    vector<int> dp(n, 1), parent(n, -1), lis;

    int max_length = 1, end_index = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[i] > V[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > max_length) {
            max_length = dp[i];
            end_index = i;
        }
    }

    for (int i = end_index; i != -1; i = parent[i])
        lis.push_back(V[i]);

    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };
    vector<int> lis = incrementocreciente(V);

    for (int i : lis)
        cout << i << " ";
    cout << endl;

    return 0;
}