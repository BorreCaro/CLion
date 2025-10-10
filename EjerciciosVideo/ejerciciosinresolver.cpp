#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Jugador {
    string nombre;
    int goles=0;
    int partidos=0;
    float promedio=0;
};


float calcularPromedio(const Jugador &jugador) {

}
Jugador crearJugador() {

    return jugador;
}
Jugador* ptrMejorJugador(vector<Jugador> &jugadores) {

    return mejorJugador;
}
int main() {
    int n;
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> n;
    cin.ignore();

    vector<Jugador> jugadores(n);

    // Llenar arreglo de jugadores con entrada del usuario
    for (int i = 0; i < n; ++i) {
        cout << "\nJugador #" << (i + 1) << endl;
        jugadores[i] = crearJugador();
    }


    // Mostrar estadisticas
    cout << "\n--- Estadísticas de jugadores ---\n";
    for (auto& jugador : jugadores) {
        cout << "Jugador: " << jugador.nombre
             << " | Goles: " << jugador.goles
             << " | Partidos: " << jugador.partidos
             << " | Promedio: " << fixed << setprecision(2) << jugador.promedio << endl;
    }

    // Hallar el jugador más efectivo (jugador con mejor promedio)
    auto mejorJugador = ptrMejorJugador(jugadores);
    cout << "\nJugador más efectivo: " << mejorJugador->nombre
         << " con un promedio de " << fixed << setprecision(2) << mejorJugador->promedio << " goles por partido.\n";

    return 0;
}