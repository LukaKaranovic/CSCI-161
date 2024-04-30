/**
 * @file doublelinkedlist.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.1
 * @date February 17, 2023
 *
 * Defines the data structures and functions related to double linked list of integers.
 *
 */



#ifndef __DOUBLE_LINKED_LIST_HEADER__
#define __DOUBLE_LINKED_LIST_HEADER__

/*
 * Data structure for double linked list node.
 */
struct DoubleLinkedListNode {
	int value;						//Integer value of the node
	DoubleLinkedListNode* prev = 0; //Pointer to the previous node in the list. Initialized to NULL
	DoubleLinkedListNode* next = 0; //Pointer to the next node in the list. Initialized to NULL
};

/*
 * Data structure for double linked list that maintains two pointers
 * to point both the beginning and the end of the list and a counter
 * to count how many nodes are in the list.
 */
struct DoubleLinkedList {
	DoubleLinkedListNode* head = 0; //Pointer to the beginning of the list. Initialized to NULL
	DoubleLinkedListNode* tail = 0; //Pointer to the beginning of the list. Initialized to NULL
	int size = 0;					//Counts number of nodes in the list
};


DoubleLinkedListNode* createNewNode(const int value, DoubleLinkedListNode* prev, DoubleLinkedListNode* next);
//Dynamically allocate memory for a new DoubleLinkedListNode
//Assign 'value' to new node's value.
//Assign 'prev' to new node's prev.
//Assign 'next' to new node's next.
//Return the pointer of the new node.



int size(const DoubleLinkedList& list);
//Returns the size of the list.



bool empty(const DoubleLinkedList& list);
//Return true if the list is empty.
//Return false, otherwise



const int front(const DoubleLinkedList& list);
//If the list is not empty, return the value from the first node of the list.
//Return 0, otherwise.



const int back(const DoubleLinkedList& list);
//If the list is not empty, return the value from the last node of the list.
//Return 0, otherwise.



void showForward(const DoubleLinkedList& list);
//Prints the values of the linked list from head to tail separated by spaces.



void showBackward(const DoubleLinkedList& list);
//Prints the values of the linked list from tail to head separated by spaces.



DoubleLinkedListNode* search(DoubleLinkedList& list, const int value);
//Loop through the double linked list from the beginning to the end.
//Campare the value of each node with 'value'.
//If they are equal return the node.
//If no such node is found return NULL.



void pushFront(DoubleLinkedList& list, const int value);
//Create a new double linked list node with the integer 'value'
//Place the new node at the begining of the double linked list.
//Increment the size of the list.



void pushBack(DoubleLinkedList& list, const int value);
//Create a new double linked list node with the integer 'value'
//Place the new node after the last node of the list.
//Increment the size of the list.



bool insert(DoubleLinkedList& list, const int before, const int value);
//Find the node in the 'list' whose 'value' is equal to 'before'.
//If no such node is found, return false.
//Otherwise, create a new node with the 'value', place the new node 
//before the found node, increment the size of the list and return true.  		



void popFront(DoubleLinkedList& list);
//Remove the first node from the linked list and relesse its memory. 
//Decrement the size of the list.



void popBack(DoubleLinkedList& list);
//Remove the last node from the linked list, and release memory from the
//removed node. Decrement the size of the list.
	


bool remove(DoubleLinkedList& list, const int value);
//Find the node with the 'value' from the linked list.
//If no such node is found, do nothing, return false.
//Otherwise, remove the node from the list and release its memory,
//decrement the size of the list and return true.



void clear(DoubleLinkedList& list);
//Remove all the nodes from the linked list until it is empty



const int* asArray(const DoubleLinkedList& list);
//Dynamically allocate memory for an array of integers using list size as your arrray size.
//Starting from the head of the list copy the values from all the nodes of the list into the
//array and return the pointer of the array.



bool equal(const DoubleLinkedList& list1, const DoubleLinkedList& list2);
//Return true if 'list1' and 'list2' linked lists have the same size
//and node values. Return false, otherwise.



void copy(DoubleLinkedList& dest, const DoubleLinkedList& source);
//Copy all the nodes from the source linked list into dest linked list.
//All the nodes in the dest linked list must have newly allocated memory and 
//appropriately linked.


void load(const char* filename, DoubleLinkedList& list);
//Open the file named 'filename' in read only mode.
//Read data from the file.
//Push data at back of the list.
//Close the file before return.


void save(const DoubleLinkedList& list, const char* filename);
//Open the file named 'filename' in write only mode
//Write data from the list into the file.
//Close the file before return.


#endif

