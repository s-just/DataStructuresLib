#pragma once

#include "Node.h"

/*
LinkedList.h

This class represents a basic singly linked list data structure.
It allows these operations: appending elements, removing elements, determining the size of the list, and clearing the list.

*/

// Definitions
template<typename Type>
class LinkedList
{
private:
    Node<Type>* head;
    Node<Type>* tail;

public:
    LinkedList();

    void printList();

    void append(const Type& value);

    void removeValue(const Type& value);

    int size() const;

    void clear();
};



// Implementations
template<typename Type>
LinkedList<Type>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Used for testing. (Remove this later and rebuild it)
template<typename Type>
void LinkedList<Type>::printList()
{
    Node<Type>* currentNode = head;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->nextNode;
    }
    std::cout << "\n";
}

// Append the reference of the passed value to the list. We declare the value as const since we do not intend to modify the value of it.
template<typename Type>
void LinkedList<Type>::append(const Type& value)
{
    // Assign the pointer for the new node to a dynamically allocated pointer using the new keyword.
    Node<Type>* newNode = new Node<Type>(value);

    // If there is no memory address assigned to the head pointer yet... 
    // The list is empty and we need to add the new node using it's pointer.
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    // Otherwise we can see the list is not empty and need to setup a new pointer for the previous tail node and change the tail of the list to point at that new node.
    else
    {
        // Sets the nextNode of the current tail node (which will soon be changed) in the linked list to the newly created node.
        tail->nextNode = newNode;

        // Updates the linked list's tail to point to the new last node in the list rather than the node that was previously considered last.
        tail = newNode;
    }
}

// Removes the first found node from the list of the given value that is passed by reference.
template<typename Type>
void LinkedList<Type>::removeValue(const Type& value)
{
    // Create two pointers used for navigation. Navigation begins at the head node of the list.
    Node<Type>* currentNode = head;
    Node<Type>* previousNode = nullptr;

    // Until we are the end of the list or have found the desired value, traverse by changing the current node to the next node.
    while ((currentNode != nullptr) && (currentNode->data != value))
    {
        // Adjust the previous node.
        previousNode = currentNode;
        // Adjust the current node pointer to be the pointer for the next node of the current node.
        currentNode = currentNode->nextNode;
    }

    // At this point we have traversed the whole list and did not find the value or we have stopped traversing because we found the value...

    // If the value was not found, we need to exit the function and let the user know that it was not found.
    if (currentNode == nullptr)
    {
        std::cout << "The given value of: " << value << "to be removed was not found.";
        return;
    }

    // If we have not returned out of the function yet, then we have found the given value in our list.

    // If the first element (the head) of the list is the node we are trying to delete, make sure to reassign the head node.
    if (currentNode == head)
        head = currentNode->nextNode;
    // Otherwise we can shift the next node pointer of the previous node to point at the node that is after the current node (since we are deleting the current node).
    else
        previousNode->nextNode = currentNode->nextNode;
    // In the case that the the node we are trying to delete is the tail, we want to make sure to reassign the pointer for the tail one over.
    if (currentNode == tail)
        tail = previousNode;

    // We can safely delete the found node.
    delete currentNode;
}

template<typename Type>
int LinkedList<Type>::size() const
{
    // Setup a variable to increment when determining the size.
    int sizeCounter = 0;

    // Initialize a pointer to the current node used for traversal at the head of the list.
    Node<Type>* currentNode = head;

    while (currentNode != nullptr)
    {
        // Increment counter
        sizeCounter++;

        // Set the current node to the next node (for traversal) of the list.
        currentNode = currentNode->nextNode;
    }

    return sizeCounter;
}

// Clears the list and it's nodes.
template<typename Type>
void LinkedList<Type>::clear()
{
    // Setup two pointers for traversal.
    Node<Type>* currentNode = head;
    Node<Type>* previousNode = nullptr;

    // Continue traversing until the list is empty
    while (currentNode != nullptr)
    {
        // Shift the traversal pointers and delete the node that was previously traversed.
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
        delete previousNode;

    }

    // Ensure that we clear the head and tail pointers.
    head = nullptr;
    tail = nullptr;
}
