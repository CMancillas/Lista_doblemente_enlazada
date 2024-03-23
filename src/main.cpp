#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> l;

    list.insertLast(1);
    list.insertBeginning(2);
    //list.printForward();

    list.insertLast(3);
    list.insertBeginning(4);
    list.printBackwards();


    l.insertBeginning(5);
    l.insertBeginning(6);
    //l.printForward();
 
    l.insertBeginning(7);
    l.insertBeginning(8);
    l.printForward(); 
  

    //list.transfer(l, 0, 3);
    list.intercambiar(l);
    list.printForward();
    l.printForward();
    l.modifyValueIndicatedIndex(3, 7);
    l.printForward();
   //lis tclear( );  
    
   return 0; 
}
      
