#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

Producto productos[MAX_PRODUCTOS];
Venta ventas[MAX_VENTAS];
int numProductos=0;
int numVentas=0;
int idVentaCounter=1;

void registrarProducto() 
{
    if (numProductos>=MAX_PRODUCTOS)
	 {
        cout<<"No se pueden registrar mas productos. El limite ha sido alcanzado"<<endl;
        return;
    }

    Producto p;
    cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin,p.nombre);
    cout<<"Ingrese el precio del producto: ";
    cin>>p.precio;

    productos[numProductos++]=p;
    cout<<"Producto registrado exitosamente"<<endl;
}

int main() {
    char opcion;
    do {
        cout << "Menu:";
        cout << "A: Registrar un nuevo producto\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'A':
            case 'a':
                registrarProducto();
                break;
                 }
    } while (opcion != 'S' && opcion != 's');

    return 0;
}