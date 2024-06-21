#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<char> alfabeto = { 'a', 'b', 'c', 'd' };
map<char, int> orden = { {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3} };

bool f(char x, char y) {
    return orden[x] + 1 == orden[y];
}


bool precedeonoprecede(char u, char v) {
    int n = alfabeto.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (f(alfabeto[i], alfabeto[j])) {
                dp[orden[alfabeto[i]]][orden[alfabeto[j]]] = true;
            }
        }
    }

    return dp[orden[u]][orden[v]];
}

int main() {
    char u = 'a';
    char v = 'd';
    if (precedeonoprecede(u, v)) 
        cout << "la '" << u << "' precede directamente a la '" << v << "'";
    else cout << "la '" << u << "' no precede directamente a la '" << v << "'";
    return 0;
}
