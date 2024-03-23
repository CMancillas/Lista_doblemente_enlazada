#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> l;

    list.insertBeginning(1);
    list.insertBeginning(2);
    //list.printForward();

    list.insertBeginning(3);
    list.insertBeginning(4);
    list.printForward();


    l.insertBeginning(5);
    l.insertBeginning(6);
    //l.printForward();
 
    l.insertBeginning(7);
    l.insertBeginning(8);
    l.printForward();


    list.transfer(l, 1, 2); 
     //listclear( );       
    list.printForward(); 
    return 0;
}
      
