cmake_minimum_required(VERSION 3.27)
project(ListasDoblementeEnlazadas)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListasDoblementeEnlazadas main.cpp
        DoublyLinkedList.tpp
        DoublyLinkedList.h)
