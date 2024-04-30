/**
 * @file doublelinkedlistmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 12, 2023
 *
 * The main module for double linked list of CSCI 161 assignment2.
 * 
 * Tests the functions related to double linked list of integers.
 * Loads integers values from a file into a double linked list.
 * Performs various operations on the list.
 * Saves the integer values from a linked list to a file.
 * Clears the linked list.
 *
 */



#include <iostream>
#include "doublelinkedlist.h"


using namespace std;


void pushBackIntoList(DoubleLinkedList& list, const int* data, const int size) {
	for(int i=0; i<size; i++) {
		pushBack(list, data[i]);
	}
}

bool isEqualElements(const int* array1, const int* array2, const int size) {
	for(int i=0; i<size; i++) {
		if(array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}


/*
 * 
 * @brief Accepts input and output file names as the command line arguments.
 * Performs the test usages of the functions from 'singlelinkedlits.cpp',
 * 'doublelinkedlist.cpp', and 'utility.cpp'.
 *
 * @param argc The number of command line arguments passed to run the program.
 * 	       The number includes the command.
 * @param argv The array of command and command line arguments, the command is in argv[0],
 * 	       input file path is in argv[1], and output file path is in argv[2].
 * 	       
 */
int main(int argc, char** argv) {
	
	/*
	 * Check whether the names of the input and output files have been passed
	 * as the command line argument or not.
	 */
	if(argc<3) {
		cerr<<"Usage: lab3 <input-file-path> <output-file-path>"<<endl;
		return -1;
	}


	int listTestArraySize = 11;
	int listTestArray[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};


	

	/*
	 * Testing Double Linked List
	 */
	
	cout<<"Testing Double Linked List.............."<<endl;

	DoubleLinkedList doubleLinkedList;

	cout<<"Double Linked List before no push"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	
	popFront(doubleLinkedList);
	popBack(doubleLinkedList);
	cout<<endl;


	int element = 10;
	pushFront(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	element =20;
	pushFront(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 30;
	pushFront(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	element = 20;
	insert(doubleLinkedList, element, element);
	cout<<"Double Linked List after inserting "<<element<<" before "<<element<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 40;
	pushFront(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 20;
	remove(doubleLinkedList, element);
	cout<<"Double Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	remove(doubleLinkedList, element);
	cout<<"Double Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	insert(doubleLinkedList, element, element);
	cout<<"Double Linked List after failed insertion of "<<element<<" before "<<element<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	element = 50;
	pushFront(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<"Double Linked List front: "<<front(doubleLinkedList)<<endl;
	cout<<"Double Linked List back: "<<back(doubleLinkedList)<<endl;
	cout<<endl;
	
	cout<<"Double Linked List backward after pushing "<<element<<" at front"<<endl;
	showBackward(doubleLinkedList);
	cout<<endl;

	popFront(doubleLinkedList);
	cout<<"Double Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	popFront(doubleLinkedList);
	cout<<"Double Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	popFront(doubleLinkedList);
	cout<<"Double Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	popFront(doubleLinkedList);
	cout<<"Double Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	popFront(doubleLinkedList);
	cout<<"Double Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popFront(doubleLinkedList);
	popBack(doubleLinkedList);
	

	element = 10;
	pushBack(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	element = 20;
	pushBack(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 30;
	pushBack(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 40;
	pushBack(doubleLinkedList, element);
	cout<<"Double Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;
	
	element = 50;
	pushBack(doubleLinkedList, 50);
	cout<<"Double Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<"Double Linked List backword after pushing "<<element<<" at  back"<<endl;
	showBackward(doubleLinkedList);
	cout<<endl;


	popBack(doubleLinkedList);
	cout<<"Double Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popBack(doubleLinkedList);
	cout<<"Double Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popBack(doubleLinkedList);
	cout<<"Double Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popBack(doubleLinkedList);
	cout<<"Double Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popBack(doubleLinkedList);
	cout<<"Double Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	popFront(doubleLinkedList);
	popBack(doubleLinkedList);

	clear(doubleLinkedList);


	cout<<"Double Linked List before loading any element"<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	/*
	 * Testing remove from an empty double linked list
	 */
	element = 15;
	cout<<"Testing remove from an empty single linked list"<<endl;
	remove(doubleLinkedList, element);
	cout<<endl;

	

	/*
	 * Testing remove from a non-empty double linked list
	 */
	cout<<"List after pushing "<<listTestArraySize<<" elements at back of the list"<<endl;
	pushBackIntoList(doubleLinkedList, listTestArray, listTestArraySize);
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<"Testing remove from an non-empty double linked list by removing "<<element<<endl;
	remove(doubleLinkedList, element);
	cout<<"Double Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;


	/*
	 * Testing search a non existing element in double linked list
	 */ 
	cout<<"Testing search of a non-existing element in a double linked list"<<endl;
	const DoubleLinkedListNode* const resultDoubleNode1 = search(doubleLinkedList, element);
	if(resultDoubleNode1 != NULL && resultDoubleNode1->value == element) {
		cout<<"Found "<<resultDoubleNode1->value<<" in the double linked  list"<<endl;
	}
	else {
		cout<<"Didn't find "<<element<<" in the double linked list"<<endl;
	}
	cout<<endl;


	/*
	 * Testing search an existing element in double linked list
	 */ 
	cout<<"Testing search of an existing element in a double linked list"<<endl;
	element = 16;
	const DoubleLinkedListNode* const resultDoubleNode2 = search(doubleLinkedList, element);
	if(resultDoubleNode2 != NULL && resultDoubleNode2->value == element) {
		cout<<"Found "<<resultDoubleNode2->value<<" in the double linked  list"<<endl;
	}
	else {
		cout<<"Didn't find "<<element<<" in the double linked list"<<endl;
	}
	cout<<endl;


	/*
	 * Testing insert before node
	 */
	element = 15;
	int beforeValue = resultDoubleNode2->value;
	insert(doubleLinkedList, beforeValue, element);
	cout<<"Double Linked List after inserting "<<element<<" before node with value "<<beforeValue<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;


	/*
	 * Testing insert before non-existing value
	 */
	element = 25;
	beforeValue = 35;
	insert(doubleLinkedList, beforeValue, element);
	cout<<"Double Linked List after failing to insert "<<element<<" before node with value "<<beforeValue<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;


	/*
	 * Testing insert before an existing value
	 */
	element = 25;
	beforeValue = 20;
	insert(doubleLinkedList, beforeValue, element);
	cout<<"Double Linked List after inserting "<<element<<" before node with value "<<beforeValue<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;

	


	/*
	 * Using DoubleLinkedList asArray() function
	 */
	cout<<"Using DoubleLinkedList asArray() function"<<endl;
	clear(doubleLinkedList);
	pushBackIntoList(doubleLinkedList, listTestArray, listTestArraySize);
	const int* listArray = asArray(doubleLinkedList);
	if(isEqualElements(listArray, listTestArray, listTestArraySize)) {
		cout<<"DoubleLinkedList.asArray() returned the array with the elements from list nodes"<<endl;
	}
	cout<<endl;
	
	/*
	 * Using DoubleLinkedList equal() function
	 */
	cout<<"Using DoubleLinkedList equal() function"<<endl;
	DoubleLinkedList equalList;
	pushBackIntoList(equalList, listTestArray, listTestArraySize);
	const int* equalListArray = asArray(equalList);
	if(isEqualElements(listArray, equalListArray, listTestArraySize)) {
		cout<<"Two lists are equal according to DoubleLinkedList.asArray() function"<<endl;
	}

	if(equal(doubleLinkedList, equalList)) {
		cout<<"Two lists are equal according to DoubleLinkedList.equal() function"<<endl;
	}
	
	delete [] listArray;
	delete [] equalListArray;
	clear(doubleLinkedList);
	clear(equalList);
	cout<<endl;

 

	/*
	 * Using copy() function
	 */
	cout<<"Using copy() function"<<endl;
	pushBackIntoList(doubleLinkedList, listTestArray, listTestArraySize);
	DoubleLinkedList copyDoubleLinkedList;
	copy(copyDoubleLinkedList, doubleLinkedList);
	cout<<"Original List"<<endl;
	cout<<"Size of the original list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<"Copy List"<<endl;
	cout<<"Size of the copy list: "<<size(copyDoubleLinkedList)<<endl;
	showForward(copyDoubleLinkedList);
	clear(doubleLinkedList);
	clear(copyDoubleLinkedList);
	cout<<endl;




	
	/*
	 * Testing loading value into a double linked list from a file
	 */ 
	clear(doubleLinkedList);
	load(argv[1], doubleLinkedList);
	cout<<"Double Linked List after loading elements from an input file: "<<argv[1]<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<"Double Linked List backword after loading elements from an input file: "<<argv[1]<<endl;
	showBackward(doubleLinkedList);
	cout<<endl;
	
	

	/*
	 * Testing save double linked list
	 */
	cout<<"Saving from a double linked list into a file: "<<argv[2]<<endl;
	save(doubleLinkedList, argv[2]);
	clear(doubleLinkedList);
	cout<<"Double Linked List after removing all elements"<<endl; 
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	load(argv[2], doubleLinkedList);
	cout<<"Double Linked List after loading elements from the saved file: "<<argv[2]<<endl;
	cout<<"Size of the list: "<<size(doubleLinkedList)<<endl;
	showForward(doubleLinkedList);
	cout<<endl;




	return 0;
}
