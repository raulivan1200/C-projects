#include <iostream>

using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo* anterior;
};

// Función para imprimir los valores de la lista
void imprimir_lista(Nodo* cabeza) {
	// Verifica si la lista est� vac�a

    if (cabeza == NULL) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    cout << "Lista: \n ";
    // Crea un puntero al nodo actual y lo inicializa con la cabeza de la lista
    Nodo* nodo_actual = cabeza;
    // Recorre la lista mientras el nodo actual no sea NULL
    while (nodo_actual != NULL) {
        cout << "anterior: " << nodo_actual->anterior << " siguiente: " << nodo_actual->siguiente << " actual: " << nodo_actual->valor;
        cout << " direccion de memoria de nuestro nodo " << &nodo_actual->valor << "\n";
        // Actualiza el nodo actual para apuntar al siguiente nodo en la lista
        nodo_actual = nodo_actual->siguiente;
    }
    cout << endl;
}

void buscar(Nodo* cabeza, int valor_buscado) {
    if (cabeza == NULL) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo* nodo_actual = cabeza;
    while (nodo_actual != NULL) {
        if (nodo_actual->valor == valor_buscado) {
            cout << "El valor " << valor_buscado << " esta en la lista." << endl;
            return;
        }
        nodo_actual = nodo_actual->siguiente;
    }

    cout << "El valor " << valor_buscado << " no esta en la lista." << endl;
}

// Función para insertar un nodo al inicio de la lista
void insertar_al_inicio(Nodo*& cabeza, int valor) {
    // Crear un nuevo nodo y establecer su valor
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    // Establecer el nodo anterior como nulo cuando se inserta al inicio de la lista
    nuevo_nodo->anterior = NULL;
    // Establecer el siguiente nodo como la cabeza actual de la lista
    nuevo_nodo->siguiente = cabeza;
    // Si la lista no está vacía, establecer el nodo anterior de la cabeza actual como el nuevo nodo
    if (cabeza != NULL) {
        cabeza->anterior = nuevo_nodo;
    }
    // Establecer la cabeza de la lista como el nuevo nodo
    cabeza = nuevo_nodo;
    // Imprimir un mensaje para indicar que se insertó un nuevo nodo al inicio de la lista y mostrar la lista actualizada
    cout << "Se inserto el valor " << valor << " al inicio de la lista." << endl;
    imprimir_lista(cabeza);
}

// Función para insertar un nodo al final de la lista
void insertar_al_final(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;// El nuevo nodo ser� el �ltimo, por lo tanto su siguiente es NULL
    if (cabeza == NULL) {
        cabeza = nuevo_nodo;
        nuevo_nodo->anterior = NULL;// El nuevo nodo es el �nico de la lista, por lo tanto su anterior es NULL
    } else {
        Nodo* nodo_actual = cabeza;// Iniciamos desde la cabeza de la lista
        
        while (nodo_actual->siguiente != NULL) { // Buscamos el �ltimo nodo de la lista
            nodo_actual = nodo_actual->siguiente;
        }
        nodo_actual->siguiente = nuevo_nodo;// El �ltimo nodo de la lista apuntar� al nuevo nodo
        nuevo_nodo->anterior = nodo_actual;// El nuevo nodo tendr� como anterior al �ltimo nodo de la lista
    }
    cout << "Se inserto el valor " << valor << " al final de la lista." << endl;
    imprimir_lista(cabeza);
}



// Funci�n para insertar un nodo en una posici�n especifica de la lista
void insertar_en_posicion(Nodo*& cabeza, int valor, int posicion) {
	//posicion valida?
if (posicion < 1) {
cout << "La posicion ingresada no es valida." << endl;
return;
}
//posicion =  1?
if (posicion == 1) {
    insertar_al_inicio(cabeza, valor);
    return;
}
// Crear un nuevo nodo con el valor a insertar

Nodo* nuevo_nodo = new Nodo;
nuevo_nodo->valor = valor;
// Encontrar la posici�n de inserci�n

Nodo* nodo_actual = cabeza;
Nodo* nodo_anterior = NULL;
int contador = 1;
while (nodo_actual != NULL && contador < posicion) {
    nodo_anterior = nodo_actual;
    nodo_actual = nodo_actual->siguiente;
    contador++;
}
// Verificar si la posici�n es v�lida

if (nodo_actual == NULL && contador < posicion) {
    cout << "La posicion ingresada no es valida." << endl;
    return;
}
// Insertar el nuevo nodo en la posici�n encontrada

nuevo_nodo->siguiente = nodo_actual;
nuevo_nodo->anterior = nodo_anterior;

if (nodo_actual != NULL) {		//mantener la conexi�n entre los nodos de la lista 
    nodo_actual->anterior = nuevo_nodo;
}
//doblemente enlazada despu�s de la inserci�n del nuevo nodo en una posici�n espec�fica.
nodo_anterior->siguiente = nuevo_nodo;

cout << "Se inserto el valor " << valor << " en la posicion " << posicion << " de la lista." << endl;
imprimir_lista(cabeza);
}





// Función para eliminar el primer nodo de la lista
void eliminar_inicio(Nodo*& cabeza) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
// Guarda el nodo a borrar y actualiza la cabeza de la lista
    Nodo* nodo_a_borrar = cabeza;
    cabeza = cabeza->siguiente;
    
    // Si la lista no qued� vac�a, actualiza el puntero al nodo anterior
    if (cabeza != NULL) {
        cabeza->anterior = NULL;
    }
    delete nodo_a_borrar;

    cout << "Se eliminó el primer elemento de la lista." << endl;
    imprimir_lista(cabeza);
}

// Función para eliminar el último nodo de la lista
void eliminar_final(Nodo*& cabeza) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
        return;
    }
    
    if (cabeza->siguiente == NULL) {
        delete cabeza;
        cabeza = NULL;
        cout << "Se eliminó el único elemento de la lista." << endl;
        return;
    }
// Recorre la lista hasta el �ltimo elemento

    Nodo* nodo_actual = cabeza;
    while (nodo_actual->siguiente != NULL) {
        nodo_actual = nodo_actual->siguiente;
    }
// Obtiene el nodo anterior al �ltimo y actualiza sus punteros

    Nodo* nodo_anterior = nodo_actual->anterior;
    nodo_anterior->siguiente = NULL;
    delete nodo_actual;

    cout << "Se eliminó el último elemento de la lista." << endl;
    imprimir_lista(cabeza);
}

// Función para eliminar un nodo en una posición especifica de la lista
void eliminar_en_posicion(Nodo*& cabeza, int posicion) {
	//checa que sea posicion valida
    if (posicion < 1) {
        cout << "La posición ingresada no es válida." << endl;
        return;
    }
// Si la posici�n es la primera, se utiliza la funci�n eliminar_inicio()

    if (posicion == 1) {
        eliminar_inicio(cabeza);
        return;
    }
// Recorrer la lista hasta llegar a la posici�n deseada

    Nodo* nodo_actual = cabeza;
    int contador = 1;
    while (nodo_actual != NULL && contador < posicion) {
        nodo_actual = nodo_actual->siguiente;
        contador++;//se usa para determinar si se ha llegado a la posici�n deseada.
    }
// Verificar si se lleg� al final de la lista sin encontrar la posici�n

    if (nodo_actual == NULL) {		// Si no se encuentra el nodo, es una posicion invalida
        cout << "La posición ingresada no es válida." << endl;
        return;
    }
// Guardar el nodo anterior y el nodo siguiente al nodo a eliminar
// Si se encuentra el nodo, se borra de la lista actualizando los apuntadores de los nodos vecinos

    Nodo* nodo_anterior = nodo_actual->anterior;
    nodo_anterior->siguiente = nodo_actual->siguiente;
    if (nodo_actual->siguiente != NULL) {
        nodo_actual->siguiente->anterior = nodo_anterior;
    }
    // Eliminar el nodo y mostrar la lista actualizada

    delete nodo_actual;
    cout << "Se eliminó el elemento en la posición " << posicion << " de la lista." << endl;
    imprimir_lista(cabeza);
}



// FunciÃ³n para mostrar el menÃº de opciones
void mostrar_menu() {
cout << "Menu:" << endl;
cout << "1. Insertar al inicio" << endl;
cout << "2. Insertar al final" << endl;
cout << "3. Insertar en posicion" << endl;
cout << "4. Eliminar inicio" << endl;
cout << "5. Eliminar final" << endl;
cout << "6. Eliminar en posicion" << endl;
cout << "7. buscar" << endl;
cout << "8. mostrar" << endl;
cout << "0. Salir" << endl;
}

int main() {
Nodo* cabeza = NULL;
int opcion, valor, posicion;
do {
    mostrar_menu();
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            insertar_al_inicio(cabeza, valor);
            break;
        case 2:
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            insertar_al_final(cabeza, valor);
            break;
        case 3:
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            cout << "Ingrese la posicion donde desea insertarlo: ";
            cin >> posicion;
            insertar_en_posicion(cabeza, valor, posicion);
            break;
        case 4:
            eliminar_inicio(cabeza);
            break;
        case 5:
            eliminar_final(cabeza);
            break;
        case 6:
            cout << "Ingrese la posicion que desea eliminar: ";
            cin >> posicion;
            eliminar_en_posicion(cabeza, posicion);
            break;
case 7:
    int valor_buscado;
    cout << "Ingrese el valor que desea buscar: ";
    cin >> valor_buscado;
    buscar(cabeza, valor_buscado);
    break;
    case 8:
    	imprimir_lista(cabeza);
    	break;

        case 0:
  cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Ingrese otra opcion." << endl;
            break;
    }
} while (opcion != 0);

return 0;}
