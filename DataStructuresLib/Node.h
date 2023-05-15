#pragma once

#include <iostream>

/*
Node.h

This class represents a basic node for a singly linked list data structure.
The node struct holds data defined by the template type and has a pointer that points to the next node in the list.
A printData method is included to debug the contents of a node if needed.
*/

// Definitions
template<typename Type>
struct Node
{
    // Store the data of the node, based on the given template type.
    Type data;

    // Store a pointer that points to the next node. 
    Node* nextNode;

    Node(const Type& value);

    void printData();
};

// Implementations

// Constructor for the node struct. We want to pass by reference and not waste memory creating a copy of the value.
template<typename Type>
Node<Type>::Node(const Type& value)
{
    data = value;
    nextNode = nullptr;
}

// Used for debugging.
template<typename Type>
void Node<Type>::printData()
{
    std::cout << "Data: " << data << "\n";
}
