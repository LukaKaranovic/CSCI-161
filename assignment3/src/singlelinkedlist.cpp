/**
 * @file singlelinkedlist.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date March 9, 2024
 *
 * Implements the functions of SingleLinkedList class defined in singlelinkedlist.h header file.
 *
 */

#include <iostream>
#include <fstream>
#include "singlelinkedlist.h"

using namespace std;

/** @brief Searches for a node containing a target value and returns the node before 
 *         it.
 *
 *  Starts each search by assigning a pointer iterator to the list's front. Iterates 
 *  through the list checking if the node after iterator contains the target value 
 *  being searched for.
 *
 *  @param value The target value of the node being searched for.
 *  @return Returns the address of the node before the node with the target value if 
 *          found. Otherwise returns null.
 */

SingleLinkedListNode* SingleLinkedList::previousNode(const int value) {
    SingleLinkedListNode* node = _front;
    while (node != nullptr && node->_next != nullptr) {
        if (node->_next->_data == value) {
            return node;
        }
        node = node->_next;
    }
    return nullptr;
}

/** @brief Deep copies the values from another linked list.
 *
 *  Copies node values in the same order from a source linked list to the current 
 *  linked list. The two linked lists should be equal after the copy.
 *
 *  @param other The source linked list data structure containing the front pointer,   
 *  back pointer, and the list's size.
 *  @return Void.
 */

void SingleLinkedList::deepCopy(const SingleLinkedList& other) {
    SingleLinkedListNode* iterator = other._front;
    while (iterator != nullptr) {
        pushBack(iterator->_data);
        iterator = iterator->_next;
    }
}

/** @brief Default Constructor
 *
*/

SingleLinkedList::SingleLinkedList(): _front(0), _back(0), _size(0) {}

/** @brief Destructor. Clears every new node from the linked list.
 * 
*/

SingleLinkedList::~SingleLinkedList() {
    clear();
}

/** @brief Copy constructor. Deep copies from another linked list.
 *
 *  Clears the newly constructed linked list's pointers, ensuring it is empty before copying.
 *  Copies node values in the same order from a source linked list to the newly
 *  created linked list. The two linked lists should be equal after the copy.
 *
 *  @param other The source linked list data structure containing the front pointer,   
 *  back pointer, and the list's size.
 */

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
    this->_front = nullptr;
    this->_back = nullptr;
    this->_size = 0;
    deepCopy(other);
}

/** @brief Move constructor. Shallow copies from another linked list.
 *
 *  Copies an R-value single linked list's pointers, assigning it a new name.
 *  Ensures the temporary R-value single linked list is empty after assignment.
 *
 *  @param temp An R-value linked list data structure containing the front pointer,   
 *  back pointer, and the list's size.
 */

SingleLinkedList::SingleLinkedList(SingleLinkedList&& temp): _front(temp._front), _back(temp._back), _size(temp._size) {}

/** @brief Copy assignmnt. Deep copies the values from another linked list.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies node values in the same order from a source linked list to the newly
 *  created linked list. The two linked lists should be equal after the copy.
 *
 *  @param other The source linked list data structure containing the front pointer,   
 *  back pointer, and the list's size.
 *  @return The updated version of the single linked list.
 */

SingleLinkedList& SingleLinkedList::operator = (const SingleLinkedList& other) {
    if (this == &other) {
        return *this;
    } 
    deepCopy(other);
    return *this;
}

/** @brief Move assignmnt. Shallow copies from another linked list.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies an R-value single linked list's pointers, assigning it a new name.
 *  Ensures the temporary R-value single linked list is empty after assignment.
 *
 *  @param temp An R-value linked list data structure containing the front pointer,   
 *  back pointer, and the list's size.
 *  @return The updated version of the single linked list.
 */

SingleLinkedList& SingleLinkedList::operator = (SingleLinkedList&& temp) {
    if (this == &temp) {
        return *this;
    }
    _front = temp._front;
    _back = temp._back;
    _size = temp._size;
    temp._front = nullptr;
    temp._back = nullptr;
    temp._size = 0;
    return *this;
}

/** @brief Returns the size of the list.
 *
 *  @return The size of the list.
 */

int SingleLinkedList::size() const {
    return _size;
}

/** @brief Checks if the single linked list is empty or not. Returns true if empty
 *         and false if not empty.
 *
 *  If the front pointer of the list is null, the back pointer of the list is null
 *  and the list's size is 0, then the list is empty. If one of these three conditions
 *  is false, then the list must not be empty and the return value will be false.
 *
 *  @return The boolean value stating whether the list is empty or not.
 */

bool SingleLinkedList::empty() const {
    return (_front == nullptr) && (_back == nullptr) && (_size == 0);
}

/** @brief Prints every node's value in the single linked list.
 *
 *  Creates an iterator that iterates from start to finish, outputting values separated
 *  by a space. Will leave the function once list is empty.
 *
 *  @return Void.
 */

void SingleLinkedList::show() const {
    SingleLinkedListNode* iterator = _front;
    if (!empty()) {
        while (iterator != nullptr) {
            cout << iterator->_data << " ";
            iterator = iterator->_next;
        }
    }
}

/** @brief Creates a new node and adds it to the front of the linked list.
 *
 *  Dynamically creates a new node and assigns the list's front pointer to the 
 *  new node. If the list is empty, this new node will also be the back.
 *
 *  @param data The value assigned to the node being added.
 *  @return Void.
 */

void SingleLinkedList::pushFront(const int data) {
    SingleLinkedListNode* newNode = new SingleLinkedListNode(data, nullptr);
    if (empty()) {
        _front = newNode;
        _back = newNode;
    } else {
        newNode->_next = _front;
        _front = newNode;
    }
    _size++;
}

/** @brief Creates a new node and adds it to the end of the linked list.
 *
 *  Dynamically creates a new node and assigns the list's back pointer to the 
 *  new node. If the list is empty, this new node will also be the front. This function 
 *  also alters the previous node's next value to ensure the list is not broken.
 *
 *  @param data The value assigned to the node being added.
 *  @return Void.
 */

void SingleLinkedList::pushBack(const int data) {
    SingleLinkedListNode* newNode = new SingleLinkedListNode(data, nullptr);
        if (empty()) {
            _front = newNode;
            _back = newNode;
        } else {
            _back->_next = newNode;
            _back = newNode;
        }
        _size++;
}

/** @brief Inserts a new node with a given value into the linked list.
 *
 *  Dynamically creates a new node and assigns it's value to the value passed.
 *  Searches for the node containing the value before and inserts the new node before 
 *  the found node. 
 *
 *  @param before The target value of the node being searched for.
 *  @param data The value assigned to the node being added.
 *  @return If a node is able to be inserted (meaning a node with the value 
 *          'before' was found), returns true. If a node isn't able to be inserted, 
 *          returns false.
 */

bool SingleLinkedList::insert(const int before, const int data) {
    SingleLinkedListNode* node = search(before);
    if (_front->_data == before) {
        pushFront(data);
        return true;
    } else if (node != nullptr) {
        SingleLinkedListNode* newNode = new SingleLinkedListNode(data, node);
        SingleLinkedListNode* prev = previousNode(before);
        prev->_next = newNode;
        _size++;
        return true;
    }
    return false;
}

/** @brief Searches for a node containing a target value and returns the node.
 *
 *  Starts each search by assigning a pointer iterator to the list's front. Iterates 
 *  through the list checking if iterator's value is the target value being searched 
 *  for. 
 *
 *  @param data The target value of the node being searched for.
 *  @return Returns the address of the node with the target value if found. Otherwise 
 *          returns null.
 */

SingleLinkedListNode* SingleLinkedList::search(const int data) const {
    SingleLinkedListNode* iterator = _front;
    if (empty()) {
        return nullptr;
    }
    while (iterator != nullptr) {
        if (iterator->_data == data) {
            return iterator;
        }
        iterator = iterator->_next;
    }
    return nullptr;
}

/** @brief Finds and returns the value of the first node in the single linked list.
 *
 *  If the list is empty it will return 0, otherwise the value at the list's front will 
 *  be returned.
 *
 *  @return The value of the first node in the single linked list.
 */

const int SingleLinkedList::front() const {
    if (empty()) {
        return -1;
    } else {
        return _front->_data;
    }
}

/** @brief Finds and returns the value of the last node in the single linked list.
 *
 *  If the list is empty it will return 0, otherwise the value at the list's back will 
 *  be returned.
 *
 *  @return The value of the last node in the single linked list.
 */

const int SingleLinkedList::back() const {
    if (empty()) {
        return -1;
    } else {
        return _back->_data;
    }
}

/** @brief Deletes the first node of the linked list.
 *
 *  Returns if list is empty, otherwise removes the list's front and reassigns it to 
 *  point to the new first node of the linked list.
 *
 *  @return Void.
 */

void SingleLinkedList::popFront() {
    if (empty()) {
        return;
    } else if (_size == 1) {
        _back = nullptr;
    }
    SingleLinkedListNode* node = _front;
    _front = _front->_next;
    delete node;   
    _size--;
}

/** @brief Deletes the last node of the linked list.
 *
 *  Returns if list is empty, otherwise removes the list's back and reassigns it to 
 *  point to the new last node of the linked list (which is found by calling 
 *  previousNode()).
 *
 *  @return Void.
 */

void SingleLinkedList::popBack() {
    if (empty()) {
        return;
    } else if (_size == 1) {
        _front = nullptr;
        SingleLinkedListNode* node = _back;
        _back = nullptr;
        delete node;
    } else {
        SingleLinkedListNode* prev = previousNode(_back->_data);
        SingleLinkedListNode* node = _back;
        prev->_next = nullptr;
        _back = prev;
        delete node;
    }
    _size--;
}

/** @brief Deletes an existing node with a given value into the linked list.
 *
 *  Searches for a node with the passed target value and deletes it. Can be used to 
 *  delete the front and back of a list as well. The list will return true if a node 
 *  containing the value is found and deleted.
 * 
 *  @param data The value of the node to be deleted.
 *  @return Void.
 */

void SingleLinkedList::remove(const int data) {
    if (empty()) {
        return ;
    } else if (data == _front->_data) {
        popFront();
    } else if (data == _back->_data) {
        popBack();
    } else if (search(data) != nullptr) {
        SingleLinkedListNode* prev = previousNode(data);
        SingleLinkedListNode* node = search(data);
        prev->_next = node->_next;
        delete node;
        _size--;
    }
}

/** @brief Clears the linked list of all of it's values.
 * 
 *  @return Void.
 */

void SingleLinkedList::clear() {
    while(!empty()) {
        popFront();
    }
}

/** @brief Copies the values of the linked list to an array, in order.
 *
 *  Dynamically allocates an array of the list's size and copies the node values to an 
 *  array. Useful if you want to use arrays to manipulate your data after inserting 
 *  and deleting nodes.
 *
 *  @return The address of the array that was created within the function.
 */

const int* SingleLinkedList::array() const {
    int* array = new int[_size];
    SingleLinkedListNode* iterator = _front;
    for (int i = 0; i < _size; i++) {
        array[i] = iterator->_data;
        iterator = iterator->_next;
    }
    return array;
}

/** @brief Checks if two different single linked lists are equal.
 *
 *  Two linked lists are equal if they are the same size, and contain the same node 
 *  values in the same order. If any values are different or are in a different order,
 *  the linked lists are not equal.
 *
 *  @param other Another single linked list data structure containing the front 
 *  pointer, back pointer, and the list's size.
 *  @return True if the linked lists are equal. False if they are not equal.
 */

bool SingleLinkedList::equal(const SingleLinkedList& other) const {
    if (_size != other._size) {
        return false;
    }
    SingleLinkedListNode* iterator1 = _front;
    SingleLinkedListNode* iterator2 = other._front;
    while (iterator1 != nullptr && iterator2 != nullptr) {
        if (iterator1->_data != iterator2->_data) {
            return false;
        }
        iterator1 = iterator1->_next;
        iterator2 = iterator2->_next;
    }
    return true;
}

/** @brief Copies the values from an input text file to the current single linked 
 *         list.
 *
 *  Copies node values in the same order from a source input file to the single linked 
 *  list. Takes the input file given in the command line argument when executing the 
 *  main file.
 *
 *  @param filename The name of the input text file.
 *  @return Void.
 */

void SingleLinkedList::load(const char* filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Can't open the file " << filename << endl;
    }
    int data;
    while (inputFile >> data) {
        pushBack(data);
    }
    inputFile.close();
}

/** @brief Copies the values from the single linked list to an output text file.
 *
 *  Copies node values in the same order from the single linked list to an output text
 *  file. Takes the output file given in the command line argument when executing the 
 *  main file.
 *
 *  @param filename The name of the output text file.
 *  @return Void.
 */

void SingleLinkedList::save(const char* filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Can't open the file " << filename << endl;
    }
    SingleLinkedListNode* iterator = _front;
    while (iterator != nullptr) {
        outputFile << iterator->_data << " ";
        iterator = iterator->_next;
    }
    cout << endl;
    outputFile.close();
}
