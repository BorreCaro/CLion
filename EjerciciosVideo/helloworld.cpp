#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

struct Jugador {
    string nombre;
    int goles=0;
    int partidos=0;
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
    return jugador;
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


    float mejorPromedio = -1;
    string mejorJugador;

    cout << "\n--- Estadísticas de jugadores ---\n";
    for (const auto& jugador : jugadores) {
        const float promedio = calcularPromedio(jugador);
        cout << "Jugador: " << jugador.nombre
             << " | Goles: " << jugador.goles
             << " | Partidos: " << jugador.partidos
             << " | Promedio: " << fixed << setprecision(2) << promedio << endl;

        if (promedio > mejorPromedio) {
            mejorPromedio = promedio;
            mejorJugador = jugador.nombre;
        }
    }

  
    cout << "\nJugador más efectivo: " << mejorJugador
         << " con un promedio de " << fixed << setprecision(2) << mejorPromedio << " goles por partido.\n";

    return 0;
}