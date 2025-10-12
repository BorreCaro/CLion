#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
//REGISTRO DE LOS CORREDORES.
struct Corredor {
    string nombre;
    string pais;
    vector<float> tiempos;
};

float promedio(const vector<float>& v) {
    float suma = 0;
    for(float tp : v){
        suma+=tp;
    }
    return suma / v.size();
}

float mejorTiempo(const vector<float>& v) {
    return *min_element(v.begin(), v.end());
}


bool comparar(const Corredor& a,  const Corredor& b) {
    const float promA = promedio(a.tiempos);
    const float promB = promedio(b.tiempos);

    if (promA != promB)  // Si los promedios son distintos
        return promA < promB;        // Menor promedio = mejor

    // Si empatan, gana el de mejor tiempo individual
    return mejorTiempo(a.tiempos) < mejorTiempo(b.tiempos);
}


vector<Corredor> top3Corredores(vector<Corredor>& datos) {
    sort(datos.begin(), datos.end(), comparar);
    if (datos.size() > 3)
        datos.resize(3); 
    return datos;
}


int main() {
    vector<Corredor> datos = {
        {"Ana", "COL", {12.5, 12.1, 11.9}},
        {"Luis", "MEX", {11.8, 12.0, 11.9}},
        {"Maria", "ARG", {12.3, 12.4, 12.0}},
        {"John", "USA", {11.9, 11.7, 11.8}},
        {"Akira", "JPN", {11.7, 11.6, 11.9}}
    };

    vector<Corredor> top = top3Corredores(datos);

    cout << "TOP 3 CORREDORES \n";
    for (int i = 0; i < top.size(); i++) {
        cout << i + 1 << ". " << top[i].nombre << " (" << top[i].pais << ")"
             << " - Promedio: " << fixed << setprecision(2) << promedio(top[i].tiempos)
             << " - Mejor tiempo: " << mejorTiempo(top[i].tiempos) << "s\n";
    }
}
