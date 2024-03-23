#include "DoublyLinkedList.hpp"
#include <exception>
#include <iostream>
#include <functional>

// Función de comparación para ordenamiento ascendente
bool ascendingOrder(const int& a, const int& b) {
    return a > b;
}

// Función para determinar si un valor es par (utilizada en deleteCondition)
bool isEven(const int& value) {
    return value % 2 == 0;
}

int main() {
    try {
    
        DoublyLinkedList<int> list;

        // Insertar elementos al principio y al final
        list.insertBeginning(3);
        list.insertLast(1);
        list.insertLast(4);
        list.insertLast(1);
        list.insertLast(5);
            
        // Insertar en índice indicado
        list.insertIndicatedIndex(9, 2); // Inserta el 9 en la posición 2

        // Imprimir la lista
        std::cout << "Lista después de inserciones: ";
        list.printForward();

        // Eliminar el primer y último elemento
        list.deleteFirst();
        list.deleteLast();

        // Eliminar en índice indicado
        list.deleteIndicatedIndex(2); // Elimina el elemento en la posición 1
        // Imprimir la lista después de las eliminaciones
        std::cout << "Lista después de eliminaciones: ";
        list.printForward();

        // Buscar un valor y obtener su índice
        int valueToSearch = 4;
        if (list.searchValue(valueToSearch)) {
            std::cout << "Valor " << valueToSearch << " encontrado en el índice " << list.searchIndex(valueToSearch) << std::endl;
        } else {
            std::cout << "Valor " << valueToSearch << " no encontrado." << std::endl;
        }

        // Modificar un valor en un índice específico
        list.modifyValueIndicatedIndex(1, 2); // Cambia el valor en el índice 1 a 2

        // Imprimir la lista después de la modificación
        std::cout << "Lista después de modificar el índice 1: ";
        list.printForward();

        // Ordenar la lista
        list.sort(ascendingOrder);

        // Imprimir la lista después de ordenar
        std::cout << "Lista después de ordenar: ";
        list.printForward();

        // Eliminar elementos bajo una condición (eliminar números pares)
        list.deleteCondition(isEven);

        // Imprimir la lista después de eliminar elementos pares
        std::cout << "Lista después de eliminar números pares: ";
        list.printForward();

        // Eliminar ocurrencias de un valor específico
        list.deleteOcurrence(1); // Elimina la primera ocurrencia del valor 1

        // Imprimir la lista después de eliminar ocurrencias de 1
        std::cout << "Lista después de eliminar la primera ocurrencia de 1: ";
        list.printForward();

        // Comprobar si la lista está vacía
        if (list.isEmpty()) {
            std::cout << "La lista está vacía." << std::endl;
        } else {
            std::cout << "La lista no está vacía." << std::endl;
        }

        // Obtener el tamaño de la lista
        std::cout << "Tamaño de la lista: " << list.size() << std::endl;

        // Limpiar la lista
        list.clear();

        // Comprobar si la lista está vacía después de limpiar
        if (list.isEmpty()) {
            std::cout << "La lista está vacía después de limpiar." << std::endl;
        } else {
            std::cout << "La lista no está vacía después de limpiar." << std::endl;
        }

    } catch (std::exception& msg) {
        std::cout << msg.what() << std::endl;
    }

    return 0;
}
