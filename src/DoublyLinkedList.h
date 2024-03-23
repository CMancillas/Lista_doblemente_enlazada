#ifndef LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
#define LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H

#define NO_ENCONTRADO (-1)

#include <exception>

template <typename T>
class DoublyLinkedList{
public:

    // Constructor
    DoublyLinkedList();
    // Destructor
    ~DoublyLinkedList();
    // Construtor de copias
    DoublyLinkedList(const DoublyLinkedList<T> & list);
    // Operador de asignacion
    DoublyLinkedList<T> & operator=(const DoublyLinkedList<T> & list);

    void insertBeginning(T value);
    void insertLast(T value);
    void insertIndicatedIndex(T value, int index);
    void deleteFirst();
    void deleteLast();
    void deleteIndicatedIndex(int index);
    T searchValue(int index) const;
    int searchIndex(T value) const;
    bool isEmpty() const;
    T getFirstValue() const;
    T getLastValue() const;
    T getValueIndicatedIndex(int index) const;
    void modifyValueIndicatedIndex(int index,T value);
    int size() const;
    void clear();
    void printForward() const;
    void printBackwards() const;

    void deleteCondition();
    void deleteCondition(bool (*func) ());
    void sort(bool (*condition) ());
    void transfer(DoublyLinkedList<T>& l);
    void transfer(DoublyLinkedList<T> &l, int initial, int final);
    void transfer(DoublyLinkedList<T>& l, int index);
    T operator[](int i) const;

    class ListEmpty : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class OutRange : public std::exception {
  public:
    virtual const char *what() const throw();
  };
private:
    // Tamaño de la lista doblemente enlazada
    int size_;

    // Doubly linked list
    struct Element{
        // Constructor por default del struct
        Element(T value, Element *next = nullptr, Element *previous = nullptr) ;
        T value;
        Element *next;
        Element *previous;
    };

    Element *first;
    Element *last;
};

#include "DoublyLinkedList.tpp"
#endif //LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
