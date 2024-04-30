/**
 * @file doublelinkedlist.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date February 16, 2024
 *
 * Implement the functions specified in 'doublelinkedlist.h'.
 *
 */

/*
 * Include necessary standard library header files.
 */


#include "doublelinkedlist.h"
#include <fstream>
#include <iostream>
using namespace std;

/** @brief Creates a new double linked list node. Assigns a value and
 *         gives it the address the previous and next nodes.
 *
 *  Creates a new double linked list node through dynamic memory allocation.
 *  Gives the node a value and the address of the previous node, and the address of 
 *  the next node passed by parameters. This function is useful for insertion and 
 *  copying functions.
 *
 *  @param value The value assigned to the node.
 *  @param prev The address of the previous node in the linked list.
 *  @param next The address of the next node in the linked list.
 *  @return The newly created node's address.
 */
 
DoubleLinkedListNode* createNewNode(const int value, DoubleLinkedListNode* prev, DoubleLinkedListNode* next) {
    DoubleLinkedListNode* newNode = new DoubleLinkedListNode;
    newNode->value = value;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

/** @brief Returns the size of the list.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return The size of the list passed as a parameter.
 */

int size(const DoubleLinkedList& list) {
    return list.size;
}

/** @brief Checks if the double linked list is empty or not. Returns true if empty
 *         and false if not empty.
 *
 *  If the head pointer of the list is null, the tail pointer of the list is null
 *  and the list's size is 0, then the list is empty. If one of these three conditions
 *  is false, then the list must not be empty and the return value will be false.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return The boolean value stating whether the list is empty or not.
 */
 
bool empty(const DoubleLinkedList& list) {
    return list.head == 0 && list.tail == 0 && list.size == 0;
}

/** @brief Finds and returns the value of the first node in the double linked list.
 *
 *  If the list is empty it will return 0, otherwise the value at the list's head will 
 *  be returned.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return The value of the first node in the double linked list.
 */
 
const int front(const DoubleLinkedList& list) {
    if (empty(list)) {
        return 0;
    }
    return list.head->value;
}

/** @brief Finds and returns the value of the last node in the double linked list.
 *
 *  If the list is empty it will return 0, otherwise the value at the list's tail will 
 *  be returned.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return The value of the last node in the double linked list.
 */
 
const int back(const DoubleLinkedList& list) {
    if (empty(list)) {
        return 0;
    }    
    return list.tail->value;
}

/** @brief Prints every node's value in the double linked list, going from first to 
 *         last.
 *
 *  Creates an iterator that iterates from the head to tail, outputting values 
 *  separated by a space. Will leave the function once list is empty.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */

void showForward(const DoubleLinkedList& list) {
    DoubleLinkedListNode* iterator = list.head;
    if (!empty(list)) {      
        while (iterator != 0) {
            cout << iterator->value << " ";
            iterator = iterator->next;
        } 
    }
}

/** @brief Prints every node's value in the double linked list, going from last to 
 *         first.
 *
 *  Creates an iterator that iterates from the tail to head, outputting values 
 *  separated by a space. Will leave the function once list is empty.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */
 
void showBackward(const DoubleLinkedList& list) {
    DoubleLinkedListNode* iterator = list.tail;
    if (!empty(list)) {  
        while (iterator != 0) {
            cout << iterator->value << " ";
            iterator = iterator->prev;
        } 
    }
}

/** @brief Searches for a node containing a target value and returns the node.
 *
 *  Starts each search by assigning a pointer iterator to the list's head. Iterates 
 *  through the list checking if iterator's value is the target value being searched 
 *  for. 
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param value The target value of the node being searched for.
 *  @return Returns the address of the node with the target value if found. Otherwise 
 *          returns null.
 */
 
DoubleLinkedListNode* search(DoubleLinkedList& list, const int value) {
    DoubleLinkedListNode* iterator = list.head;
    while (iterator != 0) {
        if (iterator->value == value) {
            return iterator;
        }
        iterator = iterator->next;
    }
    return 0;
}

/** @brief Creates a new node and adds it to the front of the linked list.
 *
 *  Creates a new node with createNewNode() and assigns the list's head pointer to the 
 *  new node. If the list is empty, this new node will also be the tail.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param value The value assigned to the node being added.
 *  @return Void.
 */

void pushFront(DoubleLinkedList& list, const int value) {
    DoubleLinkedListNode* newNode = createNewNode(value, 0, list.head);
    if (empty(list)) {
        list.tail = newNode;
        list.head = newNode;
    }
    list.head->prev = newNode;
    list.head = newNode;
    list.size++;
}

/** @brief Creates a new node and adds it to the end of the linked list.
 *
 *  Creates a new node with createNewNode() and assigns the list's tail pointer to the 
 *  new node. If the list is empty, this new node will also be the head. This function 
 *  also alters the previous node's next value to ensure the list is not broken.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param value The value assigned to the node being added.
 *  @return Void.
 */
 
void pushBack(DoubleLinkedList& list, const int value) {
    DoubleLinkedListNode* newNode = createNewNode(value, list.tail, 0);
    if (empty(list)) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
    list.size++;
}

/** @brief Inserts a new node with a given value into the linked list.
 *
 *  Creates a new node with createNewNode() and assigns it's value to the value passed.
 *  Searches for the node containing the value before and inserts the new node before 
 *  the found node. 
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param before The target value of the node being searched for.
 *  @param value The value assigned to the node being added.
 *  @return If a node is able to be inserted (meaning a node with the value 
 *          'before' was found), returns true. If a node isn't able to be inserted, 
 *          returns false.
 */
 
bool insert(DoubleLinkedList& list, const int before, const int value) {
    if (list.head->value == before) {
        pushFront(list, value);
        return true;
    } else if (search(list, before) != 0) {
        DoubleLinkedListNode* node = search(list, before);
        DoubleLinkedListNode* prev = node->prev;
        DoubleLinkedListNode* newNode = createNewNode(value, prev, node);
        prev->next = newNode;
        node->prev = newNode;
        list.size++;
        return true;
    }
    
    return false;
}

/** @brief Deletes the first node of the linked list.
 *
 *  Returns if list is empty, otherwise removes the list's head and reassigns head to 
 *  point to the new first node of the linked list.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */
 
void popFront(DoubleLinkedList& list) {
    if (empty(list)) {
        return;
    } else if (list.head == list.tail) {
        DoubleLinkedListNode* node = list.head;
        list.tail = 0;
        list.head = 0;
        delete node;
        list.size--;
    } else {
        DoubleLinkedListNode* node = list.head;
        list.head = list.head->next;
        list.head->prev = 0;
        node->next = 0;
        delete node;
        list.size--;
    }
   
}

/** @brief Deletes the last node of the linked list.
 *
 *  Returns if list is empty, otherwise removes the list's tail and reassigns tail to 
 *  point to the new last node of the linked list (which is found by calling 
 *  previousNode()).
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */
 
void popBack(DoubleLinkedList& list) {
    if (empty(list)) {
        return;
    } else if (list.head == list.tail) {
        list.head = 0;
        DoubleLinkedListNode* node = list.tail;
        list.tail = 0;
        delete node;
    } else {
        DoubleLinkedListNode* node = list.tail;
        list.tail = list.tail->prev;;
        list.tail->next = 0;
        delete node;
    }
    list.size--;
}

/** @brief Deletes an existing node with a given value into the linked list.
 *
 *  Searches for a node with the passed target value and deletes it. Can be used to 
 *  delete the head and tail of a list as well. The list will return true if a node 
 *  containing the value is found and deleted.
 * 
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param value The value of the node to be deleted.
 *  @return If a node with the target value is found and deleted, returns true. 
 *          Otherwise, returns false.
 */
 
bool remove(DoubleLinkedList& list, const int value) {
    if (empty(list)) {
        return false;
    } else if (value == list.head->value) {
        popFront(list);
        return true;
    } else if (value == list.tail->value) {
        popBack(list);
        return true;
    } else if (search(list, value) != 0) {
        DoubleLinkedListNode* node = search(list, value);
        DoubleLinkedListNode* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        delete node;
        list.size--;
        return true;
    }
    
    return false;
}

/** @brief Clears the linked list of all of it's values.
 * 
 *  @param list The single linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */

void clear(DoubleLinkedList& list) {
    while(!empty(list)) {
        popFront(list);
    }
}

/** @brief Copies the values of the linked list to an array, in order.
 *
 *  Dynamically allocates an array of the list's size and copies the node values to an 
 *  array. Useful if you want to use arrays to manipulate your data after inserting 
 *  and deleting nodes.
 *
 *  @param list The double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return The address of the array that was created within the function.
 */

const int* asArray(const DoubleLinkedList& list) {
    int* array = new int[list.size];
    DoubleLinkedListNode* iterator = list.head;
    for (int i = 0; i < list.size; i++) {
        array[i] = iterator->value;
        iterator = iterator->next;
    }
    return array;
}

/** @brief Checks if two different double linked lists are equal.
 *
 *  Two linked lists are equal if they are the same size, and contain the same node 
 *  values in the same order. If any values are different or are in a different order,
 *  the linked lists are not equal.
 *
 *  @param list1 A double linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param list2 Another double linked list data structure containing the head 
 *  pointer, tail pointer, and the list's size.
 *  @return True if the linked lists are equal. False if they are not equal.
 */
 
bool equal(const DoubleLinkedList& list1, const DoubleLinkedList& list2) {
    if (list1.size != list2.size) {
        return false;
    }
    DoubleLinkedListNode* iterator1 = list1.head;
    DoubleLinkedListNode* iterator2 = list2.head;
    while(iterator1 != 0 && iterator2 != 0) {
        if (iterator1->value != iterator2->value) {
            return false;
        }
        iterator1 = iterator1->next;
        iterator2 = iterator2->next;
    }
    return true;
}

/** @brief Copies the values from one linked list to another linked list.
 *
 *  Copies node values in the same order from a source linked list to a destination 
 *  linked list. The two linked lists should be equal after the copy.
 *
 *  @param dest The newly created linked list data structure containing the head 
 *  pointer, tail pointer, and the list's size.
 *  @param source The source linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */
 
void copy(DoubleLinkedList& dest, const DoubleLinkedList& source) {
    DoubleLinkedListNode* iterator = source.head;

    while (iterator != 0) {
        pushBack(dest, iterator->value);
        iterator = iterator->next;
    }
}

/** @brief Copies the values from an input text file to a newly created single linked 
 *         list.
 *
 *  Copies node values in the same order from a source input file to a single linked 
 *  list. Takes the input file given in the command line argument when executing the 
 *  main file.
 *
 *  @param filename The name of the input text file.
 *  @param source The source linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @return Void.
 */
 
void load(const char* filename, DoubleLinkedList& list) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Can't open the file " << filename << endl;
    }
    int value;
    while (inputFile >> value) {
        pushBack(list, value);
    }
    inputFile.close();
}

/** @brief Copies the values from a double linked list to an output text file.
 *
 *  Copies node values in the same order from a double linked list to an output text
 *  file. Takes the output file given in the command line argument when executing the 
 *  main file.
 *
 *  @param source The source linked list data structure containing the head pointer,   
 *  tail pointer, and the list's size.
 *  @param filename The name of the output text file.
 *  @return Void.
 */
 
void save(const DoubleLinkedList& list, const char* filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Can't open the file " << filename << endl;
    }
    DoubleLinkedListNode* iterator = list.head;
    while (iterator != 0) {
        outputFile << iterator->value << " ";
        iterator = iterator->next;
    }
    cout << endl;
    outputFile.close();
}