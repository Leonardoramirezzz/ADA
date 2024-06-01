/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct actividad {
    int inicio, fin;
};

bool fin_act(actividad a, actividad b) {
    return a.fin < b.fin;
}

vector<actividad> seleccionActividades (vector<actividad>& a) {
    sort(a.begin(), a.end(), fin_act);
    vector<actividad> respuesta;

    respuesta.push_back(a[0]);
    int x = 0;
    
    for (int i = 1; i < a.size(); ++i) {
        if (a[i].inicio >= a[x].fin) {
            respuesta.push_back(a[i]);
            x = i;
        }
    }
    return respuesta;
}

int main()
{
    vector<actividad> actividades = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    vector<actividad> r = seleccionActividades(actividades);

    cout << "actividades seleccionadas:" << endl;

    for (int i = 0; i < r.size();i++) {
        cout << "(" << r[i].inicio << ", " << r[i].fin << ")" << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fichero {
    int id;
    int longitud;
};

bool comparadorLongitud(Fichero a, Fichero b) {
    return a.longitud < b.longitud;
}

double TMRminimo(vector<Fichero>& ficheros, int longitudCinta) {
    sort(ficheros.begin(), ficheros.end(), comparadorLongitud);

    double tiempoTotal = 0;
    double tiempoAcumulado = 0;

    for (const auto& fichero : ficheros) {
        tiempoAcumulado += fichero.longitud;
        tiempoTotal += tiempoAcumulado;
    }

    double TMR = tiempoTotal / ficheros.size();

    return TMR;
}

int main() {
    std::vector<Fichero> ficheros = {{1,4},{2,2},{3,1},{4,3},{5,5}};
    int longitudCinta = 15;
    double TMR = TMRminimo(ficheros, longitudCinta);
    cout << "El TMR mínimo es: " << TMR << std::endl;
    cout << "La permutación óptima de los ficheros es:\n";
    for (const auto& fichero : ficheros) 
        cout << "Fichero " << fichero.id << " con longitud " << fichero.longitud << std::endl;
    

    return 0;
}
