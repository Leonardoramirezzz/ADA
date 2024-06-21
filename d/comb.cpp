#include <iostream>
#include <vector>

using namespace std;


vector<int> pesos = { 2, 3, 4, 5 }; 
vector<int> beneficios = { 3, 4, 5, 6 }; 
int capacidad = 5; 
int mejor_beneficio = 0;

void combinatorio(int nivel, int peso_actual, int beneficio_actual) {
    if (nivel == pesos.size()) {
        if (beneficio_actual > mejor_beneficio)
            mejor_beneficio = beneficio_actual;
        return;
    }

    if (peso_actual + pesos[nivel] <= capacidad) 
        combinatorio(nivel + 1, peso_actual + pesos[nivel], beneficio_actual + beneficios[nivel]);

    combinatorio(nivel + 1, peso_actual, beneficio_actual);
}

int main() {
    combinatorio(0, 0, 0);
    cout << "beneficio maximo: " << mejor_beneficio << endl;
    return 0;
}
