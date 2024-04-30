/**
 * @file singlelinkedlistmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 12, 2023
 *
 * The main module for single linked list of CSCI 161 assignment2.
 * 
 * Tests the functions related to single linked list of integers.
 * Loads integers values from a file into a signle linked list.
 * Performs various operations on the list.
 * Saves the integer values from a linked list to a file.
 * Clears the linked list.
 * 
 *
 */



#include <iostream>
#include "singlelinkedlist.h"


using namespace std;

void pushBackIntoList(SingleLinkedList& list, const int* data, const int size) {
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
	 * Testing Single Linked List
	 */
	
	cout<<"Testing Single Linked List.............."<<endl;

	SingleLinkedList singleLinkedList;

	cout<<"Single Linked Lkst before no push"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	
	popFront(singleLinkedList);
	popBack(singleLinkedList);

	int element = 10;
	pushFront(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	element =20;
	pushFront(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	element = 30;
	pushFront(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	element = 20;
	insert(singleLinkedList, element, element);
	cout<<"Single Linked List after inserting "<<element<<" before "<<element<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	element = 40;
	pushFront(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	
	cout<<"Single Linked List front: "<<front(singleLinkedList)<<endl;
	cout<<"Single Linked List back: "<<back(singleLinkedList)<<endl;
	cout<<endl;

	element = 20;
	remove(singleLinkedList, element);
	cout<<"Single Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);


	cout<<"Single Linked List front: "<<front(singleLinkedList)<<endl;
	cout<<"Single Linked List back: "<<back(singleLinkedList)<<endl;
	cout<<endl;
	
	remove(singleLinkedList, element);
	cout<<"Single Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<"Single Linked List front: "<<front(singleLinkedList)<<endl;
	cout<<"Single Linked List back: "<<back(singleLinkedList)<<endl;
	cout<<endl;
	
	insert(singleLinkedList, element, element);
	cout<<"Single Linked List after failed insertion of "<<element<<" before "<<element<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);

	cout<<"Single Linked List front: "<<front(singleLinkedList)<<endl;
	cout<<"Single Linked List back: "<<back(singleLinkedList)<<endl;
	cout<<endl;
	
	element = 50;
	pushFront(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<"Single Linked List front: "<<front(singleLinkedList)<<endl;
	cout<<"Single Linked List back: "<<back(singleLinkedList)<<endl;
	cout<<endl;
	
	popFront(singleLinkedList);
	cout<<"Single Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popFront(singleLinkedList);
	cout<<"Single Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popFront(singleLinkedList);
	cout<<"Single Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popFront(singleLinkedList);
	cout<<"Single Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popFront(singleLinkedList);
	cout<<"Single Linked List after pop front"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	popFront(singleLinkedList);
	popBack(singleLinkedList);
	

	element = 10;
	pushBack(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	element = 20;
	pushBack(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	element = 30;
	pushBack(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	element = 40;
	pushBack(singleLinkedList, element);
	cout<<"Single Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	element = 50;
	pushBack(singleLinkedList, 50);
	cout<<"Single Linked List after pushing "<<element<<" at  back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	popBack(singleLinkedList);
	cout<<"Single Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popBack(singleLinkedList);
	cout<<"Single Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popBack(singleLinkedList);
	cout<<"Single Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popBack(singleLinkedList);
	cout<<"Single Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	popBack(singleLinkedList);
	cout<<"Single Linked List after pop back"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;

	popFront(singleLinkedList);
	popBack(singleLinkedList);

	clear(singleLinkedList);


	

	/*
	 * Testing remove from an empty single linked list
	 */
	element = 15;
	cout<<"Testing remove from an empty single linked list"<<endl;
	remove(singleLinkedList, element);
	cout<<endl;

	/*${TEST}/${INCLUDE}/doublelinkedlisttest.h
	 * Testing remove from a non-empty single linked list
	 */
	cout<<"List after pushing "<<listTestArraySize<<" elements at bck of the list"<<endl;
	pushBackIntoList(singleLinkedList, listTestArray, listTestArraySize);
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<"Testing remove from an non-empty single linked list by removing "<<element<<endl;
    remove(singleLinkedList, element);
	cout<<"Single Linked List after removing "<<element<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;


	/*
	 * Testing search a non existing element in single linked list
	 */ 
	cout<<"Testing search of a non-existing element in a single linked list"<<endl;
	const SingleLinkedListNode* const resultNode1 = search(singleLinkedList, element);
	if(resultNode1 != NULL && resultNode1->value == element) {
		cout<<"Found "<<resultNode1->value<<" in the single linked  list"<<endl;
	}
	else {
		cout<<"Didn't find "<<element<<" in the single linked list"<<endl;
	}
	cout<<endl;


	/*
	 * Testing search an existing element in single linked list
	 */ 
	cout<<"Testing search of an existing element in a single linked list"<<endl;
	element = 16;
	const SingleLinkedListNode* const resultNode2 = search(singleLinkedList, element);
	if(resultNode2 != NULL && resultNode2->value == element) {
		cout<<"Found "<<resultNode2->value<<" in the single linked  list"<<endl;
	}
	else {
		cout<<"Didn't find "<<element<<" in the single linked list"<<endl;
	}
	cout<<endl;


	
	/*
	 * Testing insert before non-existing value
	 */
	element = 25;
	int beforeValue = 35;
	insert(singleLinkedList, beforeValue, element);
	cout<<"Single Linked List after failing to insert "<<element<<" before node with value "<<beforeValue<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;


	/*
	 * Testing insert before an existing value
	 */
	element = 25;
	beforeValue = 20;
	insert(singleLinkedList, beforeValue, element);
	cout<<"Single Linked List after inserting "<<element<<" before node with value "<<beforeValue<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;



	/*
	 * Using SingleLinkedList asArray() function
	 */
	cout<<"Using SingleLinkedList asArray() function"<<endl;
	clear(singleLinkedList);
	pushBackIntoList(singleLinkedList, listTestArray, listTestArraySize);
	const int* listArray = asArray(singleLinkedList);
	if(isEqualElements(listArray, listTestArray, listTestArraySize)) {
		cout<<"SingleLinkedList.asArray() returned the array with the elements from list nodes"<<endl;
	}
	cout<<endl;
	
	/*
	 * Using SingleLinkedList equal() function
	 */
	cout<<"Using SingleLinkedList equal() function"<<endl;
	SingleLinkedList equalLinkedList;
	pushBackIntoList(equalLinkedList, listTestArray, listTestArraySize);
	const int* equalListArray = asArray(equalLinkedList);
	if(isEqualElements(listArray, equalListArray, listTestArraySize)) {
		cout<<"Two lists are equal according to SingleLinkedList.asArray() function"<<endl;
	}

	if(equal(singleLinkedList, equalLinkedList)) {
		cout<<"Two lists are equal according to SingleLinkedList.equal() function"<<endl;
	}
	
	delete [] listArray;
	delete [] equalListArray;
	clear(singleLinkedList);
	clear(equalLinkedList);
	cout<<endl;



	/*
	 * Using copy() function
	 */
	cout<<"Using copy() function"<<endl;
	pushBackIntoList(singleLinkedList, listTestArray, listTestArraySize);
	SingleLinkedList copySingleLinkedList;
	copy(copySingleLinkedList, singleLinkedList);
	cout<<"Original List"<<endl;
	show(singleLinkedList);
	cout<<"Copy List"<<endl;
	show(copySingleLinkedList);
	clear(singleLinkedList);
	clear(copySingleLinkedList);
	cout<<endl;



	/*
	 * Testing Utility functions and Single Linked List
	 */


	cout<<"Single Linked List before loading any element"<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	/*
	 * Testing loading value into a single linked list from a file
	 */ 
	load(argv[1], singleLinkedList);
	cout<<"Single Linked List after loading elements from input file: "<<argv[1]<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	cout<<endl;
	
	
	/*
	 * Testing save from a single linked list
	 */
	cout<<"Saving value from a single linked list into a file: "<<argv[2]<<endl;
	save(singleLinkedList, argv[2]);

	/*
	 * Clear all elements from the single linked list to release memory
	 */
	clear(singleLinkedList);
	cout<<"Single Linked List after removing all elements"<<endl; 
	show(singleLinkedList);
	cout<<endl;


	/*
	 * Testing loading value into a single linked list from the saved file
	 */ 
	load(argv[2], singleLinkedList);
	cout<<"Single Linked List after loading elements from saved file: "<<argv[2]<<endl;
	cout<<"Size of the list: "<<size(singleLinkedList)<<endl;
	show(singleLinkedList);
	clear(singleLinkedList);
	cout<<endl<<endl;

	return 0;
}
