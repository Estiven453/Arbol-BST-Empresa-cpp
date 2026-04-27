#include <iostream>
#include <algorithm>
#include "ArbolBST.h"

using namespace std;

ArbolBST::ArbolBST() : raiz(nullptr) {}

Nodo* ArbolBST::insertar(Nodo* nodo, Empleado emp) {
    if (nodo == nullptr) return new Nodo(emp);
    if (emp.codigo < nodo->dato.codigo)
        nodo->izquierdo = insertar(nodo->izquierdo, emp);
    else if (emp.codigo > nodo->dato.codigo)
        nodo->derecho = insertar(nodo->derecho, emp);
    return nodo;
}

Nodo* ArbolBST::buscar(Nodo* nodo, int codigo) {
    if (nodo == nullptr || nodo->dato.codigo == codigo) return nodo;
    if (codigo < nodo->dato.codigo) return buscar(nodo->izquierdo, codigo);
    return buscar(nodo->derecho, codigo);
}

void ArbolBST::mostrarEmpleado(Nodo* nodo) {
    cout << "ID: " << nodo->dato.codigo << " | " << nodo->dato.nombre << " (" << nodo->dato.cargo << ")" << endl;
}

// Implementación de recorridos
void ArbolBST::inorden(Nodo* nodo) {
    if (nodo) { inorden(nodo->izquierdo); mostrarEmpleado(nodo); inorden(nodo->derecho); }
}

void ArbolBST::preorden(Nodo* nodo) {
    if (nodo) { mostrarEmpleado(nodo); preorden(nodo->izquierdo); preorden(nodo->derecho); }
}

void ArbolBST::postorden(Nodo* nodo) {
    if (nodo) { postorden(nodo->izquierdo); postorden(nodo->derecho); mostrarEmpleado(nodo); }
}

int ArbolBST::altura(Nodo* nodo) {
    if (!nodo) return 0;
    return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
}

void ArbolBST::mostrarHojas(Nodo* nodo) {
    if (!nodo) return;
    if (!nodo->izquierdo && !nodo->derecho) mostrarEmpleado(nodo);
    mostrarHojas(nodo->izquierdo);
    mostrarHojas(nodo->derecho);
}

// Métodos públicos que llaman a los privados
void ArbolBST::insertarEmpleado(Empleado emp) { raiz = insertar(raiz, emp); }
void ArbolBST::mostrarInorden() { inorden(raiz); }
void ArbolBST::mostrarPreorden() { preorden(raiz); }
void ArbolBST::mostrarPostorden() { postorden(raiz); }
void ArbolBST::mostrarAltura() { cout << "Altura: " << altura(raiz) << endl; }
void ArbolBST::mostrarNodosHoja() { mostrarHojas(raiz); }
void ArbolBST::mostrarRaiz() { if(raiz) mostrarEmpleado(raiz); }

void ArbolBST::buscarEmpleado(int codigo) {
    Nodo* res = buscar(raiz, codigo);
    if (res) mostrarEmpleado(res);
    else cout << "No encontrado." << endl;
}

void ArbolBST::cargarDatosPrueba() {
    insertarEmpleado({50, "CEO Principal", "Raiz"});
    insertarEmpleado({30, "Gerente IT", "Interno"});
    insertarEmpleado({70, "Gerente RRHH", "Interno"});
    insertarEmpleado({20, "Analista 1", "Hoja"});
    insertarEmpleado({40, "Analista 2", "Hoja"});
    insertarEmpleado({60, "Asistente 1", "Hoja"});
    insertarEmpleado({80, "Asistente 2", "Hoja"});
}
