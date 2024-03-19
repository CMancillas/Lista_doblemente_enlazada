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

}
// **************************************************************
// Metodo eliminar ultimo elemento de la lista
template <typename T>
void DoublyLinkedList<T>::deleteLast()
{

}
// **************************************************************
// Metodo eliminar elemento de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::deleteIndicatedIndex(int index)
{
    if (index < 0 || index >= size) throw "Indice fuera de rango";
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

}
// **************************************************************
// Metodo para obtener la posicion de un elemento de la lista
template <typename T>
int DoublyLinkedList<T>::searchIndex(T value) const
{

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

}
// **************************************************************
// Metodo para modificar el valor de la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::modifyValueIndicatedIndex(int index, T value)
{

}
// **************************************************************
// Metodo para obtener el tamaño de la lista
template <typename T>
int DoublyLinkedList<T>::sizeList() const
{

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

}