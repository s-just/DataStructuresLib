#pragma once

#include <iostream>

/*
DNode.h

This class represents a basic node for a doubly linked list data structure.
The node struct holds data defined by the template type and has a pointer that points to the next node in the list and the previous node in the list.
A printData method is included to debug the contents of a node if needed.
*/

// Definitions
template<typename Type>
struct DNode
{
    // Store the data of the node, based on the given template type.
    Type data;

    // Store a pointer that points to the next and previous node.
    DNode* prevNode;
    DNode* nextNode;

    DNode(const Type& value);

    void printData();
};

// Implementations

// Constructor for the node struct. We want to pass by reference and not waste memory creating a copy of the value.
template<typename Type>
DNode<Type>::DNode(const Type& value)
{
    data = value;
    prevNode = nullptr;
    nextNode = nullptr;
    
}

// Used for debugging.
template<typename Type>
void DNode<Type>::printData()
{
    std::cout << "Data: " << data << "\n";
}
