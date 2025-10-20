#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

// ========== CONSTANTES ==========
constexpr int MAX_ASPIRANTES = 100;
const string niveles[] = {"Tecnico", "Tecnologo", "Profesional", "Posgrado"};

// ========== PROTOTIPOS ==========
// Funciones de validación
bool idRepetida(const long long* ids, int n, const long long &id);
void leerEnRango(int &valor, int min, int max, const string &mensaje, const string &error);

// Funciones de cálculo
int calcularPuntaje(const int &idNivel, const int &experiencia, const int &pruebas, const int &entrevista);
void promedios(const int* puntajes, int n, float* promedio);
int indiceMayorPuntaje(const int* puntajes, int n);

// Funciones de búsqueda y ordenamiento
int buscarAspirante(const long long* ids, int n, const long long &id);
void ordenarPuntajes(int* indices, const int* puntajes, int n);

// Funciones de visualización
void cabecera();
void mostrarAspirante(const string& nombre, long long id, int edad, int idNivel, int experiencia, int pruebas, int entrevista, int puntaje);
void mostrarPuntajes(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, int n, int* indices = nullptr);

// Funciones principales del menú
int registrar(long long* ids, int* edad, int* idNiveles, int* experiencia, int* pruebas, int* entrevista, string* nombres, int* puntajes);
void reportes(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, int n);
void aspiranteDestacado(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, int n);

// ========== FUNCIONES DE VALIDACIÓN ==========
bool idRepetida(const long long* ids, const int n, const long long &id) {
    for (int i=0; i<n; i++) {
        if (*(ids+i) == id) return true;
    }
    return false;
}

void leerEnRango(int &valor, const int min, const int max, const string &mensaje, const string &error) {
    do {
        cout << mensaje;
        cin>>valor;
        if (valor<min||valor>max) {
            cout<<error<<endl;
        }
    } while (valor<min||valor>max);
}

// ========== FUNCIONES DE CÁLCULO ==========
int calcularPuntaje(const int &idNivel, const int &experiencia, const int &pruebas, const int &entrevista) {
    int puntaje=0;
    switch (idNivel) {
        case 0: puntaje+=15; break;
        case 1: puntaje+=20; break;
        case 2: puntaje+=25; break;
        case 3: puntaje+=30; break;
    }
    if (experiencia>6) puntaje+=20;
    else if (experiencia>=4) puntaje+=15;
    else if (experiencia>=1) puntaje+=10;
    else puntaje+=5;

    if (pruebas>=90) puntaje+=30;
    else if (pruebas>=80) puntaje+=25;
    else if (pruebas>=60) puntaje+=20;
    else puntaje+=10;

    if (entrevista>=90) puntaje+=20;
    else if (entrevista>=80) puntaje+=15;
    else if (entrevista>=60) puntaje+=10;
    else puntaje+=5;

    return puntaje;
}

void promedios(const int* puntajes, const int n, float* promedio) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(puntajes + i);
    }
    *promedio = suma / n;
    float countEncima = 0;
    for (int i = 0; i < n; i++) {
        if (*(puntajes + i) > *promedio) {
            countEncima++;
        }
    }
    *(promedio + 1) = countEncima / n;
}

int indiceMayorPuntaje(const int* puntajes, const int n) {
    int idxMax = 0;
    int maxPuntaje = *(puntajes + 0);
    for (int i = 1; i < n; i++) {
        if (*(puntajes + i) > maxPuntaje) {
            maxPuntaje = *(puntajes + i);
            idxMax = i;
        }
    }
    return idxMax;
}

// ========== FUNCIONES DE BÚSQUEDA Y ORDENAMIENTO ==========
int buscarAspirante(const long long* ids, const int n, const long long &id) {
    for (int i = 0; i < n; i++) {
        if (*(ids + i) == id) {
            return i;
        }
    }
    return -1;
}

void ordenarPuntajes(int* indices, const int* puntajes, const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(puntajes + *(indices+j)) > *(puntajes + *(indices+ j + 1))) {
                const int temp = *(indices + j);
                *(indices + j) = *(indices + j + 1);
                *(indices + j + 1) = temp;
            }
        }
    }
}

// ========== FUNCIONES DE VISUALIZACIÓN ==========
void cabecera() {
    cout << left
         << setw(25) << "Nombre"
         << setw(18) << "ID"
         << setw(6)  << "Edad"
         << setw(13) << "Nivel"
         << setw(8)  << "Exp"
         << setw(8)  << "Prueba"
         << setw(12) << "Entrevista"
         << setw(8)  << "Puntaje"
         << '\n';
    cout << setfill('-')
         << setw(25) << "" << setw(18) << "" << setw(6) << "" << setw(13) << ""
         << setw(8)  << "" << setw(8)  << "" << setw(12) << "" << setw(8)  << ""
         << setfill(' ') << '\n';
}

void mostrarAspirante(const string& nombre, const long long id, const int edad, const int idNivel, const int experiencia, const int pruebas, const int entrevista, const int puntaje) {
    cout << left
         << setw(25) << nombre
         << setw(18) << id
         << setw(6)  << edad
         << setw(13) << niveles[idNivel]
         << setw(8)  << experiencia
         << setw(8)  << pruebas
         << setw(12) << entrevista
         << setw(8)  << puntaje
         << '\n';
}

void mostrarPuntajes(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, const int n, int* indices) {
    cout << "Aspirantes:\n";
    cabecera();
    if (indices == nullptr) {
        for (int i = 0; i < n; i++) {
            mostrarAspirante(*(nombres + i), *(ids + i), *(edad + i), *(idNiveles + i), *(experiencia + i), *(pruebas + i), *(entrevista + i), *(puntajes + i));
        }
    } else {
        for (int i = 0; i < n; i++) {
            const int k = *(indices+i);
            mostrarAspirante(*(nombres + k), *(ids + k), *(edad + k), *(idNiveles + k), *(experiencia + k), *(pruebas + k), *(entrevista + k), *(puntajes + k));
        }
    }
}

// ========== FUNCIONES PRINCIPALES DEL MENÚ ==========
int registrar(long long* ids, int* edad, int* idNiveles, int* experiencia, int* pruebas, int* entrevista, string* nombres, int* puntajes) {
    int i = 0;
    char continuar;
    do {
        system("cls");
        cout<<"Aspirante "<<i+1<<endl;
        if (i == 0) cin.ignore();
        cout<<"Nombre: "; getline(cin, *(nombres+i));
        bool seRepite;
        do {
            cout<<"Identificacion: "; cin>>*(ids+i);
            seRepite = idRepetida(ids, i, *(ids+i));
            if (seRepite) cout<<"Numero de identificacion repetido, ingrese otro\n";
        } while (seRepite);
        leerEnRango(*(edad+i), 18, 999, "Edad: ", "La edad minima son 18 años");
        leerEnRango(*(idNiveles+i), 0, 3, "Nivel de estudios (0-Tecnico, 1-Tecnologo, 2-Profesional, 3-Posgrado): ", "Nivel invalido");
        leerEnRango(*(experiencia+i), 0, *(edad+i), "Años de experiencia: ", "Valor invalido");
        leerEnRango(*(pruebas+i), 0, 100, "Puntaje prueba tecnica (0-100): ", "Puntaje invalido");
        leerEnRango(*(entrevista+i), 0, 100, "Puntaje entrevista (0-100): ", "Puntaje invalido");
        *(puntajes+i) = calcularPuntaje(*(idNiveles+i), *(experiencia+i), *(pruebas+i), *(entrevista+i));
        i++;
        if (i >= MAX_ASPIRANTES) {
            cout<<"Se alcanzo el limite maximo de aspirantes ("<<MAX_ASPIRANTES<<")\n";
            break;
        }
        cout<<"Desea registrar otro aspirante? (s/n): ";
        cin>>continuar;
        cin.ignore();
    } while (continuar == 's' || continuar == 'S');

    return i;
}

void aspiranteDestacado(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, const int n) {
    long long idBuscar;
    cout << "Ingrese el ID del aspirante a consultar: ";
    cin >> idBuscar;
    if (const int indice = buscarAspirante(ids, n, idBuscar); indice != -1) {
        cabecera();
        mostrarAspirante(*(nombres + indice), *(ids + indice), *(edad + indice), *(idNiveles + indice), *(experiencia + indice), *(pruebas + indice), *(entrevista + indice), *(puntajes + indice));
    } else {
        cout << "Aspirante no encontrado.\n";
    }
}

void reportes(const string* nombres, const long long* ids, const int* edad, const int* idNiveles, const int* experiencia, const int* pruebas, const int* entrevista, const int* puntajes, const int n) {
    system("cls");
    cout << "Reportes y consultas\n";
    cout<<"a. Listado general de aspirantes registrados\n";
    cout<<"b. Reporte ordenado ascendentemente por puntaje total\n";
    cout<<"c. Consulta de aspirante destacado\n";
    char op;
    do {
        cout<<"Selccione una opcion: ";
        cin>>op;
        op = tolower(op);
        if (op < 'a' || op > 'c') {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (op < 'a' || op > 'c');
    system("cls");
    switch(op) {
        case 'a': {
            mostrarPuntajes(nombres, ids, edad, idNiveles, experiencia, pruebas, entrevista, puntajes, n);
            cout<<endl<<endl;
            cout<<"Aspirante con mayor puntaje total: "<<endl;
            const int mi = indiceMayorPuntaje(puntajes, n);
            cabecera();
            mostrarAspirante(*(nombres+mi), *(ids+mi), *(edad+mi), *(idNiveles+mi), *(experiencia+mi), *(pruebas+mi), *(entrevista+mi), *(puntajes+mi));
            break;
        }
        case 'b': {
            int indices[MAX_ASPIRANTES];
            float promedio[2];
            for(int i = 0; i < n; i++) *(indices+i) = i;
            ordenarPuntajes(indices, puntajes, n);
            mostrarPuntajes(nombres, ids, edad, idNiveles, experiencia, pruebas, entrevista, puntajes, n, indices);
            cout<<endl;
            promedios(puntajes, n, promedio);
            cout<<"Puntaje promedio: "<<promedio[0]<<endl;
            cout<<"Porcentaje de aspirantes por encima del promedio: "<<promedio[1]*100<<"%"<<endl;
            break;
        }
        case 'c':{
            aspiranteDestacado(nombres, ids, edad, idNiveles, experiencia, pruebas, entrevista, puntajes, n);
            break;
        }
    }
    cout<<endl;
}

// ========== FUNCIÓN PRINCIPAL ==========
int main(){
    SetConsoleOutputCP(65001);
    string nombres[MAX_ASPIRANTES];
    long long ids[MAX_ASPIRANTES];
    int edad[MAX_ASPIRANTES], idNiveles[MAX_ASPIRANTES], experiencia[MAX_ASPIRANTES], pruebas[MAX_ASPIRANTES], entrevista[MAX_ASPIRANTES], puntajes[MAX_ASPIRANTES];
    int numAspirantes = 0;
    bool registro=false;
    for (short opcion;;) {
        system("cls");
        cout<<"TechSolutions S.A\n";
        cout<<"1. Registro de datos de aspirantes\n";
        cout<<"2. Cálculo del puntaje total\n";
        cout<<"3. Reportes y consultas\n";
        cout<<"4. Salir\n";
        do {
            cout<<"Selecciona opcion:"<<endl; cin>>opcion;
            if (opcion>4||opcion<1) cout<<"Opcion invalida\n";
        } while (opcion>4||opcion<1);
        system("cls");
        switch (opcion) {
            case 1: {
                numAspirantes = registrar(ids, edad, idNiveles, experiencia, pruebas, entrevista, nombres, puntajes);
                registro=true;
                cout<<"Registro exitoso. Total de aspirantes registrados: "<<numAspirantes<<endl;
                break;
            }
            case 2: {
                if (!registro) {
                    cout<<"Debe realizar el registro primero\n";
                    break;
                }
                mostrarPuntajes(nombres, ids, edad, idNiveles, experiencia, pruebas, entrevista, puntajes, numAspirantes);
                break;
            }
            case 3: {
                if (!registro) {
                    cout<<"Debe realizar el registro primero\n";
                    break;
                }
                reportes(nombres, ids, edad, idNiveles, experiencia, pruebas, entrevista, puntajes, numAspirantes);
                break;
            }
            case 4:
                cout<<"Gracias"; return 0;
        }
        system("pause");
    }
}

