/**
 * \file Bank.hpp
 * \brief Implementacion de la clase DoublyLinkedList.
 * \author Braulio Alessandro Sánchez Bermúdez
 * \author Carlos Enrique Mancillas Duran
 * \date 22/03/2024
 * */

#ifndef LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
#define LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H

/** \class DoublyLinkedList
 *
 * Esta clase template ofrece una implementaci&oacute;n de lista doble con operaciones
para agregar,
 * eliminar elementos, y consultar el ultimo de la lista, entre otras.
 *
 * \tparam T Tipo de elementos almacenados en la lista doble.
 */
template <typename T>
class DoublyLinkedList{
public:
    /**
   * \brief Constructor por defecto que inicializa una lista doble vac&iacute;a.
   */
    // Constructor
    DoublyLinkedList();
    /**
    * \brief Destructor que libera la memoria de la lista doble.
    */
    // Destructor
    ~DoublyLinkedList();
    /**
   * \brief Constructor de copia.
   * \param list Otra lista de la cual se copiar&aacute;n los elementos.
   */
    // Construtor de copias
    DoublyLinkedList(const DoublyLinkedList<T> & list);
    /**
  * \brief Sobrecarga del operador de asignaci&oacute;n.
  * \param list Otra lista doble de la cual se copiar&aacute;n los elementos.
  * \exception const <b>char *</b> La lista doble copia no puede ser creado.
  *
  * \return Referencia a la lista actual.
  */
    // Operador de asignacion
    DoublyLinkedList<T> & operator=(const DoublyLinkedList<T> & list);

    /**
    * \brief Agrega un nuevo elemento al principio de la lista doble.
    * \param value El valor a agregar.
    */
    void insertBeginning(T value);
    /**
    * \brief Agrega un nuevo elemento al final de la lista doble.
    * \param value El valor a agregar.
    */
    void insertLast(T value);
    /**
    * \brief Agrega un nuevo elemento en el indice indicado de la lista doble.
    * \param value El valor a agregar.
     * \param index El indice en donde se agregara.
    */
    void insertIndicatedIndex(T value, int index);
    /**
    * \brief Elimina el primer elemento de la lista doble.
    */
    void deleteFirst();
    /**
    * \brief Elimina el ultimo elemento de la lista doble.
    */
    void deleteLast();
    /**
    * \brief Elimina el elemento en el indice indicado de la lista doble.
    * \param index indice el cual sera eliminado.
    */
    void deleteIndicatedIndex(int index);
    /**
    * \brief Busca elemento en la lista doble.
    * \param value Valor a verificar si esta en la lista.
    */
    bool searchValue(T value) const;
    /**
    * \brief Regresa inciso del valor a buscar.
    * \param value valor que buscaremos en la lista.
    */
    int searchIndex(T value) const;
    /**
    * \brief Verifica si la lista esta vacia.
    *
    */
    bool isEmpty() const;
    /**
    *\brief Regresa primer valor de la lista.
    *
    */
    T getFirstValue() const;
    /**
    *\brief Regresa ultimo valor de la lista.
    *
    */
    T getLastValue() const;
    /**
    *\brief Regresa valor indicado de la lista.
    * \param index inciso de la lista a regresar.
    */
    T getValueIndicatedIndex(int index) const;
    /**
    *\brief Modifica valor indicado de la lista.
    * \param index inciso de la lista a modificar.
    * \param value valor que se insertara en la lista.
    */
    void modifyValueIndicatedIndex(int index,T value);
    /**
    *\brief Regresa tamaño de la lista.
    */
    int sizeList() const;
    /**
    *\brief Vacia la lista.
    */
    void clear();
    /**
    *\brief Imprime lista de primero a ultimo.
    */
    void printForward() const;
    /**
    *\brief Imprime lista de ultimo a primero.
    */
    void printBackwards() const;

private:
    // Tamaño de la lista doblemente enlazada
    int size;

    // Doubly linked list
    struct Element{
        // Constructor por default del struct
        Element(int value, Element *next = nullptr, Element *previous = nullptr) ;
        T value;
        Element *next;
        Element *previous;
    };

    Element *first;
    Element *last;
};

#endif //LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
