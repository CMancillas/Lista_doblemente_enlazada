#include <iostream>
#include "DoublyLinkedList.h"

// **************************************************************
// **************************************************************
// *******************METODOS CONTRUCTORES***********************
// **************************************************************
// Metodo constructor del Struct
template <typename T>
DoublyLinkedList<T>::Element::Element(int value,
                                   DoublyLinkedList::Element *next /*= nullptr*/,
                                   DoublyLinkedList::Element *previous/* = nullptr*/){}
// **************************************************************
// Metodo constructor por default
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : size(0), first(nullptr), last(nullptr)
{

}
// **************************************************************
// Metodo destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}
// **************************************************************
// Metodo constructor de copias
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & list) : size(0), first(nullptr), last(nullptr)
{
    *this = list;
}
// **************************************************************
// Metodo operador de asignación
template <typename T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list){
    if (this == &list) return *this;
    // Vaciar lista por copiar por si en dado caso ya contiene otros valores
    clear();

    Element *aux = list.first;
    while (aux != nullptr)
    {
        insertLast(aux->value);
        aux = aux->next;
    }
    return *this;
}
// **************************************************************
// **************************************************************
// **************************************************************
// Metodo insertar al principio de la lista
template <typename T>
void DoublyLinkedList<T>::insertBeginning(T value)
{
    Element *aux = new Element(value, first, nullptr);

    if (isEmpty())
    {
        first = aux;
        last = aux;
    }
    else
    {
        first->previous = aux;
        first =aux;
    }

    ++size;
}
// **************************************************************
// Metodo insertar elemento a lo ultimo de la lista
template <typename T>
void DoublyLinkedList<T>::insertLast(T value)
{
    Element *aux = new Element(value, nullptr, last);

    if (isEmpty())
    {
        first = aux;
        last = aux;
    }
    else
    {
        last->next = aux;
        last = aux;
    }
    ++size;
}
// **************************************************************
// Metodo insertar elemnto en la posicion indicada de la lista

/////***********CORREGIR**********///////
template <typename T>
void DoublyLinkedList<T>::insertIndicatedIndex(T value, int index)
{
    if (index < 0 || index > size) throw "Indice fuera de rango";
    if (index == 0) insertBeginning(value);
    else if (index == size) insertLast(value);
    else
    {
        Element *aux = first;
        for (int i = 1; i < index; ++i) aux = aux->next;
        Element *aux2 = new Element(value, aux->next, aux->previous)
        aux->next = aux2;
        ++size;
    }
}
// **************************************************************
// Metodo eliminar primer elemento de la lista
template <typename T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (isEmpty()) throw "Error: lísta vacía."

    Element *aux = first;
    first = first->next;
    if (first != nullptr)
    {
        first->previous = nullptr;
    }

    delete aux;
    --size;
}
// **************************************************************
// Metodo eliminar ultimo elemento de la lista
template <typename T>
void DoublyLinkedList<T>::deleteLast()
{
    if (isEmpty()) throw "Error: lísta vacía."

    Element *aux = last;

    last = last->previous;

    if (last != nullptr)
    {
        last->next = nullptr;
    }
    else
    {
        first = nullptr;
    }

    delete aux;
    --size;

}
// **************************************************************
// Metodo eliminar elemento de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::deleteIndicatedIndex(int index)
{
    if (index < 0 || index >= size) throw "Error: indice fuera de rango";
    if (index == 0) deleteFirst();
    else if (index == size - 1) deleteLast();
    else
    {
        // Elemento que va a borrar el indice indicado
        Element *aux = first;
        for (int i = 0; i < index; ++i) aux = aux->next;
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
        delete aux;
        --size;
    }
}
// **************************************************************
// Metodo para verificar si existe un elemento en la lista
template <typename T>
bool DoublyLinkedList<T>::searchValue(T value) const
{
    if (isEmpty()) throw "Error: lista vacía"

    Element *aux = first;

    while (aux != nullptr)
    {
        if (aux->value == value) return true;
        aux = aux->next;
    }

    return false;
}
// **************************************************************
// Metodo para obtener la posicion de un elemento de la lista
template <typename T>
int DoublyLinkedList<T>::searchIndex(T value) const
{
    if (!searchValue(value)) return -1; // Valor no encontrado
    int counter = 0;
    Element *aux = first;

    while (aux != nullptr)
    {
        if (aux->value == value) return counter;
        aux = aux->next;
        ++counter;
    }

    return -1;
}
// **************************************************************
// Metodo para verificar si la lista esta vacia
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{

}
// **************************************************************
// Metodo para obtener el primer elemento de la lista
template <typename T>
T DoublyLinkedList<T>::getFirstValue() const
{

}
// **************************************************************
// Metodo para obtener el ultimo elemento de la lista
template <typename T>
T DoublyLinkedList<T>::getLastValue() const
{

}
// **************************************************************
// Metodo para obtener el valor de la posicion indicada de la lista
template <typename T>
T DoublyLinkedList<T>::getValueIndicatedIndex(int index) const
{
    if (index < 0 || index >= size) throw Error: Fuera de rango";

    Element *aux = first;

    for (int i = 0; i < index; ++i) aux = aux->next;

    return aux->value;
}
// **************************************************************
// Metodo para modificar el valor de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::modifyValueIndicatedIndex(int index, T value)
{
    if (index < 0 || index >= size) throw "Error: Fuera de rango";

    Element *aux = first;

    for (int i = 0; i < index; ++i) aux = aux->next;

    aux->value = value;
}
// **************************************************************
// Metodo para obtener el tamaño de la lista
template <typename T>
int DoublyLinkedList<T>::sizeList() const
{
    return size;
}
// **************************************************************
// Metodo para vaciar la lista
template <typename T>
void DoublyLinkedList<T>::clear()
{

}
// **************************************************************
// Metodo para imprimir la lista de primero a ultimo
template <typename T>
void DoublyLinkedList<T>::printForward() const
{

}
// **************************************************************
// Metodo para imprimir la lista de ultimo a primero
template <typename T>
void DoublyLinkedList<T>::printBackwards() const
{
    if (isEmpty())
    {
        std::cout << "()" << std::endl;
        return;
    }

    Element *aux = last;
    std::cout << "(";

    while (aux != nullptr)
    {
        std::cout << aux->value;
        if (aux->previous != nullptr)
            {
            std::cout << ", ";
            aux = aux->previous;
        }

    }
    std::cout << "\b\b)" << std::endl;

}