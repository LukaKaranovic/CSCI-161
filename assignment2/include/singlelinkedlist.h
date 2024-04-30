/**
 * @file singlelinkedlist.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.1
 * @date February 17, 2023
 *
 * Defines the data structure and the functions related to singly linked list of integers.
 *
 */



#ifndef __SINGLE_LINKED_LIST_HEADER__
#define __SINGLE_LINKED_LIST_HEADER__

/*
 * Data structure for single linked list node.
 */
struct SingleLinkedListNode {
	int value;						//Integer value of the node
	SingleLinkedListNode* next = 0; //Pointer to the next node in the list
									//Next pointer is initialized to NULL
};


/*
 * Data structure for a singly linked list that maintains two pointers
 * to point both the beginning and the end of the list and a counter
 * to count how many nodes are in the list.
 */
struct SingleLinkedList {
	SingleLinkedListNode* head = 0;	//Pointer to the beginning of the list
	SingleLinkedListNode* tail = 0; //Pointer to the end of the list
	int size = 0;					//Counts the number of nodes in the list
};


SingleLinkedListNode* createNewNode(const int value, SingleLinkedListNode* next);
//Dynamically allocate memory for a new SingleLinkedListNode
//Assign 'value' to new node's value.
//Assign 'next' to new node's next.
//Return the pointer of the new node.



int size(const SingleLinkedList& list);
//Return the size of the list.



bool empty(const SingleLinkedList& list);
//Return true if the list is empty.
//Return false, otherwise



const int front(const SingleLinkedList& list);
//If the list is not empty, return the value from the first node of the list.
//Return 0, otherwise.



const int back(const SingleLinkedList& list);
//If the list is not empty, return the value from the last node of the list.
//Return 0, otherwise.



void show(const SingleLinkedList& list);
//Starting from the head prints the values from the linked list separated by spaces.



SingleLinkedListNode* search(const SingleLinkedList& list, const int value);
//Loop through the single linked list from the beginning to the end.
//Campare the value of each node with 'value'.
//If they are equal return the node.
//If no such node is found return NULL.



void pushFront(SingleLinkedList& list, const int value);
//Create a new single linked list node with the integer 'value'
//Place the new node at the begining of the single linked list specified as 'list'
//Increment the size of the list.


SingleLinkedListNode* previousNode(SingleLinkedList& list, const int value);
//Iterate through the list starting from list head.
//Return the pointer of a node from the list whose next node has the value equal to 'value'.
//Return NULL if the front node value is equal to 'value' or
//no node in the list has value equal to 'value'.


void pushBack(SingleLinkedList& list, const int value);
//Create a new single linked list node with the integer 'value'
//Locate the last node of the single linked list specified as 'list'.
//Place the new node after the last node of the list.
//Increment the size of the list.


bool insert(SingleLinkedList& list, const int before, const int value);
//Find the node in the 'list' whose 'value' is equal to 'before'.
//If no such node is found, return false.
//Otherwise, create a new node with the 'value', place the new node 
//before the found node, and return true.
//Increment the size of the list and return true.  


void popFront(SingleLinkedList& list);
//Remove the first node from the linked list and relesse its memory. 
//Decrement the size of the list.



void popBack(SingleLinkedList& list);
//Remove the last node from the linked list and relesse its memory. 
//Decrement the size of the list.

	


bool remove(SingleLinkedList& list, const int value);
//Find the node with the 'value' from the linked list.
//If no such node is found, do nothing, return false.
//Otherwise, remove the node from the list and release its memory
//and decrement the size of the list.



void clear(SingleLinkedList& list);
//Remove all the nodes from the linked list until it is empty



const int* asArray(const SingleLinkedList& list);
//Dynamically allocate memory for an array of integers using list size as your arrray size.
//Starting from the head of the list copy the values from all the nodes of the list into the
//array and return the pointer of the array.



bool equal(const SingleLinkedList& list1, const SingleLinkedList& list2);
//Return true if 'list1' and 'list2' linked lists have the same size
//and node values. Return false, otherwise.



void copy(SingleLinkedList& dest, const SingleLinkedList& source);
//Copy all the nodes from the source linked list into dest linked list.
//All the nodes in the dest linked list must have newly allocated memory and 
//appropriately linked.


void load(const char* filename, SingleLinkedList& list);
//Open the file in read only mode.
//Read the values from the file and push them at the end of the list one after another.
//Close the file before return.


void save(const SingleLinkedList& list, const char* filename);
//Open the file in write only mode.
//Go through the list and write the vlaues from the list into the file on
//the same line separated by spaces.
//Close the file before return.


#endif

