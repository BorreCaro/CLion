#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;
struct Producto {
    int id;
    string nombre;
    int stock, precio;
};
void listaProductos(vector<Producto> const &inv) {
    cout<<endl<<"Productos: "<<endl;
    for (const Producto &p : inv)
        cout <<p.id<<". "<<p.nombre << " - $"<< p.precio << " | "<<p.stock<<" uds"<<endl;

}
void bajoStock(vector<Producto> const &inv) {
    cout<<endl<<"Productos con stock bajo: "<<endl;
    for (const auto &p : inv) {
        if (p.stock < 10) {
            cout <<p.id<<". "<<p.nombre << " - $"<< p.precio << " | "<<p.stock<<" uds"<<endl;
        }
    }
}
void total(vector<Producto> const &inv) {
    int valorTotal = 0, unidades = 0;
    for (const auto &p : inv) {
        valorTotal+=p.precio*p.stock;
        unidades+=p.stock;
    }
    cout<<endl<<"Unidades totales en el inventario: "<<unidades<<endl;
    cout<<"El valor total en el inventario es de $"<<valorTotal<<endl;
}
void addInventario(vector<Producto> &inventario, const string &nombre, const int uds, const int precio=0) {
    const auto index = find_if(inventario.begin(), inventario.end(), [&](const Producto &p) {
        return p.nombre == nombre;
    });
    if (index == inventario.end()) {
        inventario.push_back({inventario.back().id + 1, nombre, uds, precio});
    } else {
        index->stock += uds;
    }
}
int main() {
    SetConsoleOutputCP(65001); // Consola en español

    vector<Producto> inventario = {
        {1, "Mouse Logitech", 27, 120000},
        {2, "Teclado Razer", 32, 200000},
        {3, "GTX 1650 ti", 9, 850000},
        {4,"Monitor Samsung", 37, 700000}
    };
    listaProductos(inventario);
    bajoStock(inventario);
    total(inventario);

    cout<<endl<<"Añado productos"<<endl;

    addInventario(inventario, "Moto G20", 12, 540000);
    addInventario(inventario, "Mouse Logitech", 8);
    addInventario(inventario, "Teclado Razer", 7);
    listaProductos(inventario);
    bajoStock(inventario);
    total(inventario);
}