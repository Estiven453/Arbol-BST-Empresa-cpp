#include <iostream>
#include "ArbolBST.h"

using namespace std;

int main() {
    ArbolBST arbol;
    int opcion, cod;

    do {
        cout << "\n===== MENU ARBOL BST EMPRESARIAL =====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Buscar empleado\n";
        cout << "3. Mostrar raiz del arbol\n"; 
        cout << "4. Recorrido en orden\n";
        cout << "5. Recorrido preorden\n";
        cout << "6. Recorrido postorden\n";
        cout << "7. Mostrar altura\n";
        cout << "8. Mostrar hojas\n";
        cout << "9. Cargar datos de prueba \n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                Empleado e;
                cout << "Codigo: "; cin >> e.codigo;
                cout << "Nombre: "; cin.ignore(); getline(cin, e.nombre);
                cout << "Cargo: "; getline(cin, e.cargo);
                arbol.insertarEmpleado(e);
                break;
            }
            case 2: 
                cout << "Ingrese codigo a buscar: "; 
                cin >> cod; 
                arbol.buscarEmpleado(cod); 
                break;
            case 3: 
                arbol.mostrarRaiz(); 
                break;
            case 4: 
                arbol.mostrarInorden(); 
                break;
            case 5: 
                arbol.mostrarPreorden(); 
                break;
            case 6: 
                arbol.mostrarPostorden(); 
                break;
            case 7: 
                arbol.mostrarAltura(); 
                break;
            case 8: 
                arbol.mostrarNodosHoja(); 
                break;
            case 9: 
                arbol.cargarDatosPrueba(); 
                break;
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}
