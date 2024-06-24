#include <iostream>
#include <vector>
using namespace std;

double calculateProbabilityFixedP(int n, double P) {
    std::vector<std::vector<double>> prob(n + 1, std::vector<double>(n + 1, 0.0));

    for (int i = 0; i <= n; ++i) {
        prob[i][0] = 1.0;
        prob[0][i] = 0.0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prob[i][j] = P * prob[i - 1][j] + (1 - P) * prob[i][j - 1];
        }
    }
    return prob[n][n];
}

int main() {
    int n;
    double P;
    cout << "Ingrese el número de victorias necesarias (n): ";
    cin >> n;
    cout << "Ingrese la probabilidad fija P de que Informáticos CB gane un partido: ";
    cin >> P;

    double result = calculateProbabilityFixedP(n, P);
    cout << "La probabilidad de que Informáticos CB gane el play-off es: " << result << std::endl;

    return 0;
}
