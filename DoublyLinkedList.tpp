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

}
// **************************************************************
// Metodo constructor de copias
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & list) : size(0), first(nullptr), last(nullptr)
{

}
// **************************************************************
// Metodo operador de asignación
template <typename T>
DoublyLinkedList<T> & DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list)
        {

}
// **************************************************************
// **************************************************************
// **************************************************************
// Metodo insertar al principio de la lista
template <typename T>
void DoublyLinkedList<T>::insertBeginning(T value)
{

}
// **************************************************************
// Metodo insertar elemento a lo ultimo de la lista
template <typename T>
void DoublyLinkedList<T>::insertLast(T value)
{

}
// **************************************************************
// Metodo insertar elemnto en la posicion indicada de la lista
template <typename T>
void DoublyLinkedList<T>::insertIndicatedIndex(T value, int index)
{

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