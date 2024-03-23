#include <iostream>

// **************************************************************
// **************************************************************
// *******************METODOS CONTRUCTORES***********************
// **************************************************************
// Metodo constructor del Struct
template <typename T>
DoublyLinkedList<T>::Element::Element(T value,
                                   DoublyLinkedList::Element *next /*= nullptr*/,
                                      DoublyLinkedList::Element *previous/* = nullptr*/) : value(value), next(next), previous(previous) {}
// **************************************************************
// Metodo constructor por default
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : size_(0), first(nullptr), last(nullptr)
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
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & list) : size_(0), first(nullptr), last(nullptr)
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
    Element *aux;

    if (isEmpty()) {
        aux = new Element(value, nullptr, nullptr);
        first = aux;
        last = aux;
    } else {
        aux = new Element(value, first, nullptr);
        first->previous = aux;
        first =aux;
    }

    ++size_;
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
    ++size_;
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
        Element *aux2 = new Element(value, aux->next, aux->previous);
        aux->next = aux2;
        ++size_;
    }
}
// **************************************************************
// Metodo eliminar primer elemento de la lista
template <typename T> void DoublyLinkedList<T>::deleteFirst() {
    if (isEmpty())
        return;//throw "Error: The list is empty.";
    Element *aux = first;
    first = aux->next;
    if(first == nullptr) last = nullptr;
    else first->previous = nullptr;
    delete aux;
    --size_;
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
    if (index < 0 || index >= size()) throw "Indice fuera de rango";
    if (index == 0) deleteFirst();
    else if (index == size() - 1) deleteLast();
    else
    {
        // Elemento que va a borrar el indice indicado
        Element *aux = first;
        for (int i = 0; i < index; ++i) aux = aux->next;
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;
        delete aux;
        --size_;
    }
}
// **************************************************************
// Metodo para verificar si existe un elemento en la lista
template <typename T>
T DoublyLinkedList<T>::searchValue(int index) const
{
    if (index < 0 || index >= size())
        throw "Fuera de rango";

    Element *aux = first; 

    for(int i = 0 ; i < index; ++i) 

        aux =  aux->next; 

    return aux->value;
}
// **************************************************************
// Metodo para obtener la posicion de un elemento de la lista
template <typename T>
int DoublyLinkedList<T>::searchIndex(T value) const
{
    return 0;
}
// **************************************************************
// Metodo para verificar si la lista esta vacia
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return size_ == 0;
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
int DoublyLinkedList<T>::size() const
{
    return size_;
}
// **************************************************************
// Metodo para vaciar la lista
template <typename T>
void DoublyLinkedList<T>::clear()
{
    while(!isEmpty()) deleteFirst();
}
// **************************************************************
// Metodo para imprimir la lista de primero a ultimo
template <typename T> void DoublyLinkedList<T>::printForward() const {
    if (isEmpty()){
        std::cout << "()" << std::endl;
        return;
    }
    Element *aux;
    aux = first;
    std::cout << "(";
    for (int i = 0; i < size(); ++i) {
        std::cout << aux->value << ", ";
        aux = aux->next;
    }
    std::cout << "\b\b)" << std::endl;
}
// **************************************************************
// Metodo para eliminar todo elemento que cumpla una condicion
template <typename T>
void DoublyLinkedList<T>::deleteCondition(bool (*func) ())
{
    Element *aux = first;
    for (int i = 0; i < size(); ++i) {
        if (func()) {
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
            delete aux;
            --size;
            break;
        }
        aux = aux->next;
    }
}
// Metodo para eliminar todo elemento que cumpla una condicion
template <typename T>
void DoublyLinkedList<T>::deleteCondition()
{
    Element *aux = first;
    Element *after = first;
    bool valueRepeat = false;
    int i = 0;
    while (i != size() - 1) {
        for (int j = 1; j < size(); ++j) {
            if (after->value == aux->next->value) {
                valueRepeat = true;
                break;
            }
            aux = aux->next;
        }
        after = after->next;
        aux = after;
        ++i;
    }
    if (valueRepeat) {
        Element *deleted = aux->next;
        aux->next = aux->next->next;
        aux->next->next->previous = aux;
        delete deleted;
    }
}
// Metodo para ordenar de forma ascendente
template <typename T> void DoublyLinkedList<T>::sort(bool (*condition) ()) {
    // Element* aux = first;
	// int aux, j;

    // for (int i = 0; i < size(); i++) {
	// 	j = i - 1;
	// 	while (j >= 0 && condition())
	// 	{
	// 		Intercambiar(vector[j + 1], vector[j]);
	// 		j--;
	// 	}
    //     vector[j + 1] = aux;
    //     aux = aux->next;
	// }
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T>& l)
{
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T> &l, int initial, int final) {
    Element *aux = l.first;

    for (int i = 0; i < initial; ++i) {
        aux = aux->next;
    }
     
    aux->previous = last;
    aux->previous->next = aux;

    for (int i = 0; i < final - initial; ++i)
        aux = aux->next;     
    last = aux;
    last->next = nullptr;
    size_ += (final - initial + 1);
    l.size_ -= (final - initial + 1);     
}
// Metodo para ordenar de forma ascendente
template <typename T>
void DoublyLinkedList<T>::transfer(DoublyLinkedList<T>& l, int index)
{
}
// **************************************************************
// Metodo para imprimir la lista de ultimo a primero
template <typename T> void DoublyLinkedList<T>::printBackwards() const {}

// Metodo para imprimir la lista de ultimo a primero
template <typename T>
T DoublyLinkedList<T>::operator[](int i) const
{
    return getValueIndicatedIndex(i);
}


/*******************************************************************/

template <typename T>
const char *DoublyLinkedList<T>::ListEmpty::what() const throw() {
  return "Empty list";
}

/*********************************************************************/

template <typename T>
const char *DoublyLinkedList<T>::OutRange::what() const throw() {
  return "Out the range";
}
