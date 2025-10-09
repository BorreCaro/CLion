#include <iostream>
#include <vector>
#include <algorithm>
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
    sort(empleados.begin(), empleados.end(), compararSalario);
    cout<<"El empleado mejor pago es: "<<empleados[0].nombre
    <<" y gana $"<<empleados[0].salario<<endl;
}
void masJoven( vector<Empleado> &empleados) {
    sort(empleados.begin(), empleados.end(), [](const Empleado &inicio, const Empleado &fin) {
        return inicio.edad < fin.edad;
    });
    cout<<"El empleado mas joven es: "<<empleados[0].nombre<<" con "<<empleados[0].edad<<" años de edad"<<endl;
}
void listaEmpleados(const vector<Empleado> &empleados) {
    cout<<endl<<"Lista de empleados: "<<endl;
    for (auto &empleado : empleados) {
        mostrarEmpleado(empleado);
        cout<<endl;
    }
}
int main() {
    vector<Empleado> empleados;
    vector<Empleado> empleadosExterior = {{"John", 28, 3500000},{"Lucas", 39, 5000000},{"Ana", 37, 4500000}};
    empleados.push_back({"Juan", 32, 2000000});
    empleados.push_back({"Santiago", 27, 1500000});
    empleados.push_back({"William", 24, 3000000});
    cout<<endl;
    listaEmpleados(empleados);
    mejorPago(empleados);
    masJoven(empleados);
    empleados.insert(empleados.end(), empleadosExterior.begin(), empleadosExterior.end());
    listaEmpleados(empleados);
    mejorPago(empleados);
    masJoven(empleados);
}