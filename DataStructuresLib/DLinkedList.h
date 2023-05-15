#pragma once

#include "DNode.h"

/*
DLinkedList.h

This class represents a basic doubly linked list data structure.
It allows these operations: appending elements, removing elements, determining the size of the list, and clearing the list.

*/

// Definitions
template<typename Type>
class DLinkedList
{
private:
    DNode<Type>* head;
    DNode<Type>* tail;

public:
    DLinkedList();

    void printList();

    void append(const Type& value);

    void removeValue(const Type& value);

    int size() const;

    void clear();
};



// Implementations
template<typename Type>
DLinkedList<Type>::DLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Used for testing. (Remove this later and rebuild it)
template<typename Type>
void DLinkedList<Type>::printList()
{
    DNode<Type>* currentNode = head;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->nextNode;
    }
    std::cout << "\n";
}

// Append the reference of the passed value to the list. We declare the value as const since we do not intend to modify the value of it.
template<typename Type>
void DLinkedList<Type>::append(const Type& value)
{
    // Assign the pointer for the new node to a dynamically allocated pointer using the new keyword.
    DNode<Type>* newNodePtr = new DNode<Type>(value);

    // If there is no memory address assigned to the head pointer yet... 
    // The list is empty and we need to add the new node using it's pointer.
    if (head == nullptr)
    {
        head = newNodePtr;
        tail = newNodePtr;
    }
    // Otherwise, we see the list is not empty, and we need to update the tail node and both it's pointers.
    else
    {

        // Sets the prevNode of the current tail node (which will soon be changed) in the linked list to the newly created node.
        newNodePtr->prevNode = tail;
        // Sets the nextNode of the current tail node (which will soon be changed) in the linked list to the newly created node.
        tail->nextNode = newNodePtr;
        
        // Updates the linked list's tail to point to the new last node in the list rather than the node that was previously considered last.
        tail = newNodePtr;
    }
}

// Removes the first found node from the list of the given value that is passed by reference.
template<typename Type>
void DLinkedList<Type>::removeValue(const Type& value)
{
    // Create two pointers used for navigation. Navigation begins at the head node of the list.
    DNode<Type>* currentNode = head;

    // Until we are the end of the list or have found the desired value, traverse by changing the current node to the next node.
    while ((currentNode != nullptr) && (currentNode->data != value))
    {
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

    // Update the links of the adjacent nodes.
    // If the current node is the head node, update the head pointer to be the next node in the list before deletion.
    if (currentNode == head)
    {
        head = currentNode->nextNode;
        if (head != nullptr)
            head->prevNode = nullptr;
    }
    // If the current node is the tail node, update the tail pointer to be the previous node in the list before deletion.
    else if (currentNode == tail)
    {
        tail = currentNode->prevNode;
        if (tail != nullptr)
            tail->nextNode = nullptr;
    }
    // In this case, the current node is neither the head nor the tail, thus we need to update the links to work around the current node before deletion.
    else
    {
        currentNode->prevNode->nextNode = currentNode->nextNode;
        currentNode->nextNode->prevNode = currentNode->prevNode;
    }

    // We can safely delete the found node.
    delete currentNode;
}

template<typename Type>
int DLinkedList<Type>::size() const
{
    // Setup a variable to increment when determining the size.
    int sizeCounter = 0;

    // Initialize a pointer to the current node used for traversal at the head of the list.
    DNode<Type>* currentNode = head;

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
void DLinkedList<Type>::clear()
{
    // Setup two pointers for traversal.
    DNode<Type>* currentNode = head;
    DNode<Type>* previousNode = nullptr;

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
