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
void listarProductos() {
    cout<<"\nLista de productos:\n";
    for (int i=0; i<numProductos; i++) 
	{
        cout<<"Nombre: "<< productos[i].nombre<< ", Precio: "<<productos[i].precio<<endl;
    }
}
void buscarProducto() {
    string nombre;
    cout<<"Ingrese el nombre del producto a buscar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre==nombre) {
            cout << "Producto encontrado: Nombre: "<<productos[i].nombre<<", Precio: "<<productos[i].precio<<endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout<<"Producto no encontrado.\n";
    }
}

void actualizarProducto() {
    string nombre;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombre);

    int aux=-1;
    for (int i=0;i<numProductos;i++) {
        if (productos[i].nombre==nombre) {
            aux=i;
            break;
        }
    }

    if (aux!=-1) {
        cout << "Producto encontrado. Ingrese los nuevos datos.\n";
        cout << "Nuevo nombre: ";
        getline(cin, productos[aux].nombre);
        cout<<"Nuevo precio: ";
        cin>>productos[aux].precio;
        cout<<"Producto actualizado exitosamente.\n";
    } else {
        cout<<"Producto no encontrado.\n";
    }
}

int main() 
{
    char opcion;
    do {
        cout<<"Menu:";
        cout<<"A: Registrar un nuevo producto\n";
        cout<<"B: Listar los productos registrados\n";
        cout << "C: Buscar un producto por nombre\n";
        cout << "D: Actualizar los datos de un producto\n";
        cout<<"Seleccione una opcion: ";
        
        cin>>opcion;

        switch (opcion) 
		{
            case 'A':
            case 'a':
                registrarProducto();
                break;
                case 'B':
            case 'b':
                listarProductos();
                break;
                 case 'C':
            case 'c':
                buscarProducto();
                break;
                case 'D':
            case 'd':
                actualizarProducto();
                break;
                 }
    } while(opcion !='S'&&opcion!='s');

    return 0;
}
