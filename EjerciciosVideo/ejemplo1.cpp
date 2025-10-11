#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
struct Empleado {
    string nombre;
    int edad;
    int salario;
};
void mostrarEmpleado(const Empleado &empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Edad: " << empleado.edad << endl;
    cout << "Salario: $" << empleado.salario << endl;
}
bool compararSalario(const Empleado &inicio, const Empleado &fin) {
    return inicio.salario > fin.salario;
}
void mejorPago( vector<Empleado>&empleados){
    const auto emp = max_element(empleados.begin(), empleados.end(), compararSalario);
    cout<<"El empleado mejor pago es: "<<emp->nombre
    <<" y gana $"<<emp->salario<<endl;
}
void masJoven( vector<Empleado> &empleados) {
    const auto emp = min_element(empleados.begin(), empleados.end(), [](const Empleado &inicio, const Empleado &fin) {
        return inicio.edad < fin.edad;
    });
    cout<<"El empleado mas joven es: "<<emp->nombre<<" con "<<emp->edad<<" años de edad"<<endl;
}
void listaEmpleados(const vector<Empleado> &empleados) {
    cout<<endl<<"Lista de empleados: "<<endl;
    for (auto &empleado : empleados) {
        mostrarEmpleado(empleado);
        cout<<endl;
    }
}
int main() {
    SetConsoleOutputCP(65001); // Tildes
    vector<Empleado> empleados = {
        {"Juan", 32, 2000000},
        {"Santiago", 27, 1500000},
        {"William", 24, 3000000}
    };
    vector<Empleado> empleadosExterior = {
        {"John", 28, 3500000},
        {"Lucas", 39, 5000000},
        {"Ana", 37, 4500000}
    };
    cout<<endl<<"vector empleados: "<<endl;
    listaEmpleados(empleados);
    mejorPago(empleados);
    masJoven(empleados);
    cout<<endl<<"Se insertan los empleados del exterior"<<endl;
    empleados.insert(empleados.end(), empleadosExterior.begin(), empleadosExterior.end());
    listaEmpleados(empleados);
    mejorPago(empleados);
    masJoven(empleados);
}