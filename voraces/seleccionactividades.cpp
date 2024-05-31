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
