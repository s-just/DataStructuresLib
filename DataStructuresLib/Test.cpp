/*
Test.cpp

A file for testing the implementation of the data structures.
*/

#include "LinkedList.h"
#include "DLinkedList.h"
int main()
{
    std::cout << "Testing append...\n";

    LinkedList<int> myLinkedList = LinkedList<int>();

    std::cout << "List after creation: ";
    myLinkedList.printList();

    std::cout << "List after appending the first value: ";
    myLinkedList.append(3);
    myLinkedList.printList();

    std::cout << "List after appending the second value: ";
    myLinkedList.append(7);
    myLinkedList.printList();

    std::cout << "List after appending the third value: ";
    myLinkedList.append(1);
    myLinkedList.printList();

    std::cout << "\nTesting size method...\n";

    std::cout << "Size: " << myLinkedList.size() << "\n";

    std::cout << "\nTesting delete...\n";

    std::cout << "List after removing first value: ";
    myLinkedList.removeValue(3);
    myLinkedList.printList();

    std::cout << "List after removing last value: ";
    myLinkedList.removeValue(1);
    myLinkedList.printList();

    std::cout << "List after removing all values: ";
    myLinkedList.removeValue(7);
    myLinkedList.printList();

    std::cout << "\nTesting clear method...\n";

    std::cout << "List after appending multiple values: ";
    myLinkedList.append(3);
    myLinkedList.append(2);
    myLinkedList.append(8);
    myLinkedList.printList();

    std::cout << "List after clearing all values: ";
    myLinkedList.clear();
    myLinkedList.printList();


    DLinkedList<int> myDLinkedList = DLinkedList<int>();

    myDLinkedList.append(3);
    myDLinkedList.append(1);
    myDLinkedList.append(5);

    myDLinkedList.insertAfterIndex(0, 2);
    myDLinkedList.insertBeforeIndex(0, 2);

    myDLinkedList.insertBeforeIndex(3, 8);
    myDLinkedList.insertAfterIndex(2, 7);

    myDLinkedList.printList();

    myDLinkedList.reverse();

    myDLinkedList.printList();

}