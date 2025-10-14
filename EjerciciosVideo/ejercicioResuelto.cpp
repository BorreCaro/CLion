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
  return (jugador.partidos > 0) ? static_cast<float>(jugador.goles) / static_cast<float>(jugador.partidos) : 0;
}
Jugador crearJugador() {
    Jugador jugador;
    cout << "Nombre: ";
    getline(cin, jugador.nombre);
    cout << "Goles: ";
    cin >> jugador.goles;
    cout << "Partidos jugados: ";
    cin >> jugador.partidos;
    cin.ignore();
    jugador.promedio = calcularPromedio(jugador);
    return jugador;
}
Jugador* ptrMejorJugador(vector<Jugador> &jugadores) {
    Jugador* mejorJugador = &jugadores[0];
    for (auto &jugador : jugadores) {
        if (mejorJugador->promedio < jugador.promedio) {
            mejorJugador = &jugador;
        }
    }
    return mejorJugador;
}
int main() {
    int n;
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> n;
    cin.ignore();

    vector<Jugador> jugadores(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nJugador #" << (i + 1) << endl;
        jugadores[i] = crearJugador();
    }


    cout << "\n--- Estadísticas de jugadores ---\n";
    for (auto& jugador : jugadores) {
        cout << "Jugador: " << jugador.nombre
             << " | Goles: " << jugador.goles
             << " | Partidos: " << jugador.partidos
             << " | Promedio: " << fixed << setprecision(2) << jugador.promedio << endl;
    }

    auto mejorJugador = ptrMejorJugador(jugadores);
    cout << "\nJugador más efectivo: " << mejorJugador->nombre
         << " con un promedio de " << fixed << setprecision(2) << mejorJugador->promedio << " goles por partido.\n";

    return 0;
}