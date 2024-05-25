#include<iostream>
#include<vector>
#include <stack>
using namespace std;


bool verifica(double vuelto_restante, double moneda) {
if (moneda <= vuelto_restante) return true;
return false;
}


vector<double> monedasvuelto(double vuelto, vector<double>& conjunto_monedas) {
vector<double> respuesta;

for (int i = 0; i < conjunto_monedas.size(); i++) {
if (vuelto == 0) break;
if (verifica(vuelto, conjunto_monedas[i])) {
respuesta.push_back(conjunto_monedas[i]);
vuelto -= conjunto_monedas[i];
i--;
}
}
if (vuelto != 0) cout << "no hay solucion" << endl;

return respuesta;
}


int main() {
vector<double> monedas = { 5.0,2.0,1.0,0.5,0.2,0.1 };
vector<double> vuelto = monedasvuelto(10.80, monedas);

for (int i = 0; i < vuelto.size(); i++) {
cout << vuelto[i] << " ";
}
}
