

#ifndef LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
#define LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H

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
    bool searchValue(T value) const;
    int searchIndex(T value) const;
    bool isEmpty() const;
    T getFirstValue() const;
    T getLastValue() const;
    T getValueIndicatedIndex(int index) const;
    void modifyValueIndicatedIndex(int index,T value);
    int sizeList() const;
    void clear();
    void printForward() const;
    void printBackwards() const;

private:
    // Tamaño de la lista doblemente enlazada
    int size;

    // Doubly linked list
    struct Element{
        // Constructor por default del struct
        Element(int value, Element *next = nullptr, Element *previous = nullptr) ;
        int value;
        Element *next;
        Element *previous;
    };

    Element *first;
    Element *last;
};

#endif //LISTASDOBLEMENTEENLAZADAS_DOUBLYLINKEDLIST_H
