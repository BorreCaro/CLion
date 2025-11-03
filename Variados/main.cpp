#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
//error de sintaxis en las estructuras??
struct Usuario {
    int idUsuario;
    string nombre, correoElectronico, contraseña, direccion, metodoDePago;
};

struct Producto {
    int idProducto;
    string nombre, descripcion;
    double precio;
    int stock;
};

struct CarritoDeCompras {
    int idCarrito;
    Usuario usuario;
    vector<int> productos;
    double subtotal, impuestos;
};

struct OrdenDeCompra {
    int idOrden;
    vector<Producto> productos;
    double subtotal, impuestos, envio, total;
};

struct Categoria {
    int idCategoria;
    string nombre;
};

struct Comentario {
    int idComentario;
    Producto produc;
    Usuario user;
    string comento;
    string fecha;
};
/////////Datos::////////////////
vector<Usuario> Usuarios = {
        {1, "Juan Pérez", "juan.perez@email.com", "Qwerty123",
        "Carrera 45 #10-20", "Tarjeta de crédito"},
        {2, "Ana Gómez", "ana.gomez@email.com", "Pass456",
        "Calle 21 #35-50", "PayPal"},
        {3, "Rosario Tijeras", "ros.tijeras@email.com", "Pass458",
    "Calle 24 #35-50", "PayPal"},
        {4, "Victor Doom", "vic.doom@email.com", "Pass457",
    "Calle 30 #35-50", "Tarjeta de crédito"},
    };
vector<Producto> Productos = {
    {1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10},
    {2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20},
    {3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15},
    {4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25}
    };
vector<Comentario> comentarios = {
    {1, Productos[0], Usuarios[0], "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"},
    {2, Productos[1], Usuarios[1], "Buena cámara pero la batería dura poco.", "3/05/2025"},
    {3, Productos[2], Usuarios[2], "No me gustó; pantalla de baja calidad.", "5/05/2025"},
    {4, Productos[3], Usuarios[3], "Sonido aceptable pero el material parece frágil.", "6/05/2025"}
};
//mostrar todos los usairoos 
void listarUsuarios (){
    cout<<"//////Lista de Usuarios//////"<<endl;
    for(const auto& u : Usuarios){
        cout<<"ID: "<<u.idUsuario<<endl;
        cout<<"Nombre: "<<u.nombre<<endl;
        cout<<"Correo: "<<u.correoElectronico<<endl;
        cout<<"Direccion: "<<u.direccion<<endl;
        cout<<"Metodo de Pago: "<<u.metodoDePago<<endl;
        cout<<"-----------------------"<<endl;
    }
    cout<<"Usuarios cargados: "<<endl;
}
//booleano para comparar dos fechas
bool compararFechas(const string& s1, const string& s2){
    int a1,a2,m1,m2,d1,d2;

    // Parsear s1 (formato: d/m/a)
    size_t pos1 = s1.find('/');
    size_t pos2 = s1.find('/', pos1 + 1);
    d1 = stoi(s1.substr(0, pos1));
    m1 = stoi(s1.substr(pos1 + 1, pos2 - pos1 - 1));
    a1 = stoi(s1.substr(pos2 + 1));

    // Parsear s2 (formato: d/m/a)
    pos1 = s2.find('/');
    pos2 = s2.find('/', pos1 + 1);
    d2 = stoi(s2.substr(0, pos1));
    m2 = stoi(s2.substr(pos1 + 1, pos2 - pos1 - 1));
    a2 = stoi(s2.substr(pos2 + 1));

    if(a1!=a2) return a1>a2;
    if (m1!=m2) return m1>m2;
    return d1>=d2;
}
//mostrar comentarios con la comparacion 
void cargarComentarios(string date){
    cout<<"Cargando Comentarios..."<<endl;
    system("cls");
    bool mostrar = false; 
    for(auto& comment : comentarios){
        if(compararFechas(comment.fecha, date)){
            mostrar = true;
            cout<<"Id. Comentario: "<<comment.idComentario<<endl;
            cout<<"Producto: " <<comment.produc.nombre<<endl;
            cout<<"Usuario: " <<comment.user.nombre<<endl;
            cout<<"Comentario: "<<comment.comento<<endl;
            cout<<"Fecha: "<<comment.fecha<<endl;
        }
    }
    if(!mostrar){
        cout<<"0 comentario encontrado. "<<endl;
    }
}
int main(){
    SetConsoleOutputCP(65001);
    listarUsuarios();
    cargarComentarios("3/05/2025");
    return 0;
}