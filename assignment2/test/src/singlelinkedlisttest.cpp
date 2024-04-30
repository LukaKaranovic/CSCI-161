/**
 * @file singlelinkedlisttest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 12, 2023
 *
 * The main module for CSCI 161 lab2.
 * 
 * Tests the functions related to single linked list of integers.
 * Loads integers values from a file into a signle linked list.
 * Performs various operations on the list.
 * Saves the integer values from a linked list to a file.
 * Clears the linked list.
 *
 * Tests the functions related to binary search tree of integer key.
 * Inserts test integer keys into a binary search tree.
 * Performs various operations on the binary search tree.
 * Clears binary search tree.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE lab2

#include <boost/test/unit_test.hpp>
#include <iostream>

#include "singlelinkedlist.h"
#include "arraytest.h"



void arrayIntoTestList(const int* array, const int size, SingleLinkedList& list) {
    
    for (int i = 0; i < size; i++) {
        SingleLinkedListNode* node = new SingleLinkedListNode;
        node->value = array[i];
        node->next = nullptr;
        if(list.head == nullptr && list.tail == nullptr) {
            list.head = list.tail = node;
        }
        else {
            list.tail->next = node;
            list.tail = list.tail->next;
        }
        list.size++;
    }
}

void clearTestList(SingleLinkedList& list) {
    if(list.head == nullptr || list.tail == nullptr || list.size ==0) {
        return;
    }
    SingleLinkedListNode* node = list.head;
    SingleLinkedListNode* next = node->next;
    delete node;
    while( next != nullptr) {
        node = next;
        next = next->next;
        delete node;
    }
    list.head = list.tail = nullptr;
    list.size = 0;

}

bool isArrayInTestList(const int* array, const int size, SingleLinkedList& list) {
    if(list.size != size) {
        return false;
    }

    SingleLinkedListNode* node = list.head;
    for (int i = 0; i < size-1; i++) {
        if(node->value != array[i] ){
            return false;
        }
        node = node->next;
    }
    if(node != list.tail || node->value != array[size-1]) {
        return false;
    }
    return true;
}



bool isTestListsInSeparateMemory(const SingleLinkedList& list1, const SingleLinkedList& list2) {
	SingleLinkedListNode* node1 = list1.head;
	SingleLinkedListNode* node2 = list2.head;
	while(node1 != nullptr && node2 != nullptr) {
		if(node1 == node2) {
			return false;
		}
		node1 = node1->next;
		node2 = node2->next;
	}
    
    if(node1 != nullptr || node2 != nullptr) {
        return false;
    }
	
    return true;
}



using namespace std;

BOOST_AUTO_TEST_SUITE(assignment2test)



/**
 * Test case to test functions of single linked list
 */
BOOST_AUTO_TEST_CASE(single_linked_list) {

	/*
	 * Testing createNewNode() function
	 * 
	 */

	SingleLinkedListNode* node = createNewNode(10, nullptr);
	BOOST_CHECK_MESSAGE(node->value == 10 && node->next == nullptr, "TESTL SingleLinkedList - Create New Node");
	
	
	SingleLinkedList list0;
	
	/*
	 * Testing empty() function
	 */
	BOOST_CHECK_MESSAGE(empty(list0) == true, "TEST: SingleLinkedList - Empty true");
	
	
	/*
	 * Testing size() function
	 */
	BOOST_CHECK_MESSAGE(size(list0) == 0, "TEST: SingleLinkedList - Size zero");
	
	int listTestArraySize = 11;
	int listTestArray[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	arrayIntoTestList(listTestArray, listTestArraySize, list0);
	BOOST_CHECK_MESSAGE(empty(list0) == false, "TEST: SingleLinkedList - Empty false");
	BOOST_CHECK_MESSAGE(size(list0) == listTestArraySize, "TEST: SingleLinkedList - Size non-zero");


	/*
	 * Testing front() function
	 */
	int frontElement = front(list0);
	BOOST_CHECK_MESSAGE(frontElement == listTestArray[0], "TEST: SingleLinkedList - front() function");
	
	/*
	 * Testing back() function
	 */
	int backElement = back(list0);
	BOOST_CHECK_MESSAGE(backElement == listTestArray[listTestArraySize -1], "TEST: SingleLinkedList - back() function");

	
	/*
	 * Testing show() function
	 */
	BOOST_TEST_MESSAGE("TEST: SingleLinkedList - Show");
	show(list0);

	/*
	 * Testing search() function
	 */
	const SingleLinkedListNode* const foundNode1 = search(list0, listTestArray[listTestArraySize/2]);
	BOOST_CHECK_MESSAGE( foundNode1 != 0 && foundNode1->value == listTestArray[listTestArraySize/2],
			"TEST: SingleLinkedList - Search an existing element");


	const SingleLinkedListNode* const foundNode2 = search(list0, -10);
	BOOST_CHECK_MESSAGE(foundNode2 == 0, "TEST: SingleLinkedList - Search a non-existing element");

	clearTestList(list0);
	

	SingleLinkedList list;
	/*
	 * Testing pushFront() function
	 */
	int element1 = 10;
	pushFront(list, element1);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr && 
			list.tail != nullptr &&
			list.head->value == element1 && 
			list.tail->value == element1 &&
			list.head->next == nullptr && 
			list.tail->next == nullptr && 
			empty(list) == false &&
		    size(list) == 1,
			"TEST: SingleLinkedList - Push Front First");
	
	int element2 = 20;
	pushFront(list, element2);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr && 
			list.tail != nullptr &&
			list.head->value == element2 && 
			list.tail->value == element1 &&
			list.head->next != nullptr && 
			list.head->next->value == element1 &&
			list.head->next->next == nullptr &&
			empty(list) == false &&
			size(list) == 2,
			"TEST: SingleLinkedList - Push Front Second");
	

	int element3 = 30;
	pushFront(list, element3);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr && 
			list.tail != nullptr &&
			list.head->value == element3 && 
			list.head->next != nullptr && 
			list.head->next->value == element2 &&
			list.head->next->next != nullptr && 
			list.head->next->next->value == element1 && 
			list.head->next->next->next == nullptr &&
			list.head->next->next == list.tail &&
			list.tail->value == element1 &&
			empty(list) == false &&
			size(list) == 3, 
			"TEST: SingleLinkedList - Push Front Third");

	
	

	/*
	 * Testing previousNode() function
	 */
	SingleLinkedListNode* prevNode0 = previousNode(list, element3);
	SingleLinkedListNode* prevNode1 = previousNode(list, element2);
	SingleLinkedListNode* prevNode2 = previousNode(list, element1);
	BOOST_CHECK_MESSAGE(prevNode0 == 0 && prevNode1 != 0 && prevNode1->value == element3 &&
			prevNode2 != 0 && prevNode2->value == element2,
			"TEST: SingleLinkedList - Previous Node");


	/*
	 * Test pushBack() function
	 */
	int element4 = 40;
	pushBack(list, element4);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr &&
			list.head->value == element3 && 
			list.head->next != nullptr &&
			list.head->next->value == element2 &&
			list.head->next->next != nullptr &&
			list.head->next->next->value == element1 &&
			list.head->next->next->next != nullptr &&
			list.head->next->next->next->value == element4 &&
			list.head->next->next->next->next == nullptr &&
			list.head->next->next->next == list.tail &&
			list.tail->value == element4 &&
			empty(list) == false &&
			size(list) == 4, 
			"TEST: SingleLinkedList - Push Back First");

	
	int element5 = 50;
	pushBack(list, element5);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr &&
			list.head->value == element3 && 
			list.head->next != nullptr &&
			list.head->next->value == element2 &&
			list.head->next->next != nullptr &&
			list.head->next->next->value == element1 &&
			list.head->next->next->next != nullptr &&
			list.head->next->next->next->value == element4 &&
			list.head->next->next->next->next != nullptr &&
			list.head->next->next->next->next->value == element5 &&
			list.head->next->next->next->next->next == nullptr &&
			list.head->next->next->next->next == list.tail &&
			list.tail->value == element5 &&
			empty(list) == false &&
			size(list) == 5, 
			"TEST: SingleLinkedList - Push Back Second");


	/*
	 * Testing insert() function
	 */
	
	int element6 = 60;
	insert(list, element6, element6);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr &&
			list.head->value == element3 && 
			list.head->next != nullptr &&
			list.head->next->value == element2 &&
			list.head->next->next != nullptr &&
			list.head->next->next->value == element1 &&
			list.head->next->next->next != nullptr &&
			list.head->next->next->next->value == element4 &&
			list.head->next->next->next->next != nullptr &&
			list.head->next->next->next->next->value == element5 &&
			list.head->next->next->next->next->next == nullptr &&
			list.head->next->next->next->next == list.tail &&
			list.tail->value == element5 &&
			empty(list) == false &&
			size(list) == 5,  
		"TEST: SingleLinkedList - Insert before a non-existing element");




	insert(list, element2, element6);
       	BOOST_CHECK_MESSAGE(
			list.head != nullptr &&
			list.head->value == element3 && 
			list.head->next != nullptr &&
			list.head->next->value == element6 &&
			list.head->next->next != nullptr &&
			list.head->next->next->value == element2 &&
			list.head->next->next->next != nullptr &&
			list.head->next->next->next->value == element1 &&
			list.head->next->next->next->next != nullptr &&
			list.head->next->next->next->next->value == element4 &&
			list.head->next->next->next->next->next != nullptr &&
			list.head->next->next->next->next->next->value == element5 &&
			list.head->next->next->next->next->next->next == nullptr &&
			list.head->next->next->next->next->next == list.tail &&
			list.tail->value == element5 &&
			empty(list) == false &&
			size(list) == 6, 
		"TEST: SingleLinkedList - Insert before an existing element");
		

	int element7 = 70;
	insert(list, front(list), element7);
	BOOST_CHECK_MESSAGE(
			list.head != nullptr &&
			list.head->value == element7 &&
			list.head->next != nullptr &&
			list.head->next->value == element3 && 
			list.head->next->next != nullptr &&
			list.head->next->next->value == element6 &&
			list.head->next->next->next != nullptr &&
			list.head->next->next->next->value == element2 &&
			list.head->next->next->next->next != nullptr &&
			list.head->next->next->next->next->value == element1 &&
			list.head->next->next->next->next->next != nullptr &&
			list.head->next->next->next->next->next->value == element4 &&
			list.head->next->next->next->next->next->next != nullptr &&
			list.head->next->next->next->next->next->next->value == element5 &&
			list.head->next->next->next->next->next->next->next == nullptr &&
			list.head->next->next->next->next->next->next == list.tail &&
			list.tail->value == element5 &&
			empty(list) == false &&
			size(list) == 7, 
		"TEST: SingleLinkedList - Insert before front element");

	
	
	/*
	 * Testing popFront() function
	 */
	popFront(list);
	BOOST_CHECK_MESSAGE(
		list.head != nullptr &&
		list.head->value == element3 &&
		list.head->next != nullptr &&
		list.head->next->value == element6 && 
		list.head->next->next != nullptr &&
		list.head->next->next->value == element2 &&
		list.head->next->next->next != nullptr &&
		list.head->next->next->next->value == element1 &&
		list.head->next->next->next->next != nullptr &&
		list.head->next->next->next->next->value == element4 &&
		list.head->next->next->next->next->next != nullptr &&
		list.head->next->next->next->next->next->value == element5 &&
		list.head->next->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next->next == list.tail &&
		list.tail->value == element5 &&
		empty(list) == false &&
		size(list) == 6, 
		"TEST: SingleLinkedList - Pop front");

	
	
	/*
	 * Testing popBack() function
	 */
	popBack(list);
	BOOST_CHECK_MESSAGE(
		list.head != nullptr &&
		list.head->value == element3 &&
		list.head->next != nullptr &&
		list.head->next->value == element6 && 
		list.head->next->next != nullptr &&
		list.head->next->next->value == element2 &&
		list.head->next->next->next != nullptr &&
		list.head->next->next->next->value == element1 &&
		list.head->next->next->next->next != nullptr &&
		list.head->next->next->next->next->value == element4 &&
		list.head->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next == list.tail &&
		list.tail->value == element4 &&
		empty(list) == false &&
		size(list) == 5, 
		"TEST: SingleLinkedList - Pop back");

	


	/*
	 * Testing remove() function
	 */
	bool removed = false;
	removed = remove(list, -10);
	BOOST_CHECK_MESSAGE(
		removed == false &&
		list.head != nullptr &&
		list.head->value == element3 &&
		list.head->next != nullptr &&
		list.head->next->value == element6 && 
		list.head->next->next != nullptr &&
		list.head->next->next->value == element2 &&
		list.head->next->next->next != nullptr &&
		list.head->next->next->next->value == element1 &&
		list.head->next->next->next->next != nullptr &&
		list.head->next->next->next->next->value == element4 &&
		list.head->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next == list.tail &&
		list.tail->value == element4 &&
		empty(list) == false &&
		size(list) == 5,  
		"TEST: SingleLinkedList - Remove a non-existing element");
	
	
	
	removed = false;
	removed = remove(list, element6);
	BOOST_CHECK_MESSAGE(
		removed == true &&
		list.head != nullptr &&
		list.head->value == element3 &&
		list.head->next != nullptr &&
		list.head->next->value == element2 && 
		list.head->next->next != nullptr &&
		list.head->next->next->value == element1 &&
		list.head->next->next->next != nullptr &&
		list.head->next->next->next->value == element4 &&
		list.head->next->next->next->next == nullptr &&
		list.head->next->next->next == list.tail &&
		list.tail->value == element4 &&
		empty(list) == false &&
		size(list) == 4,  
		"TEST: SingleLinkedList - Remove an existing element");
	

	remove(list, front(list));
	BOOST_CHECK_MESSAGE(
		removed == true &&
		list.head != nullptr &&
		list.head->value == element2 &&
		list.head->next != nullptr &&
		list.head->next->value == element1 && 
		list.head->next->next != nullptr &&
		list.head->next->next->value == element4 &&
		list.head->next->next->next == nullptr &&
		list.head->next->next == list.tail &&
		list.tail->value == element4 &&
		empty(list) == false &&
		size(list) == 3,  
		"TEST: SingleLinkedList - Remove front element");


	remove(list, back(list));
	BOOST_CHECK_MESSAGE(
		removed == true &&
		list.head != nullptr &&
		list.head->value == element2 &&
		list.head->next != nullptr &&
		list.head->next->value == element1 && 
		list.head->next->next == nullptr &&
		list.head->next == list.tail &&
		list.tail->value == element1 &&
		empty(list) == false &&
		size(list) == 2,  
		"TEST: SingleLinkedList - Remove back element");

	clearTestList(list);
	

	/*
	 * Testing clear() function
	 */
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	clear(list);
	BOOST_CHECK_MESSAGE(empty(list) &&  size(list) == 0 && list.head == 0 && list.tail == 0 , 
			"TEST: SingleLinkedList - Clear");
	
	
	/*
	 * Testing asArray() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	const int* listArray = asArray(list);
	BOOST_CHECK_MESSAGE(isSameElements(listArray, listTestArray, listTestArraySize), "TEST: SignleLinkedList - As Array");
	delete [] listArray;
	
	
	/*
	 * Testing equal() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	SingleLinkedList equalList;
	arrayIntoTestList(listTestArray, listTestArraySize, equalList);
	BOOST_CHECK_MESSAGE(equal(list, equalList), "TEST: SingleLinkedList - Equal");
	clearTestList(list);
	clearTestList(equalList);


	/*
	 * Testing copy() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	SingleLinkedList copyList;
	copy(copyList, list);
	BOOST_CHECK_MESSAGE(equal(list, copyList) && isTestListsInSeparateMemory(list, copyList), 
				"TEST: SingleLinkedList - Copy");

	clearTestList(list);
	clearTestList(copyList);



	/*
	 * Testing SingleLinkedList load() function
	 */
	int testElements[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 55, 60, 70, 80, 90,
	       	91, 92, 93, 94, 95, 96, 97, 98, 99};
	int testElementsSize = 28;

	SingleLinkedList singleLinkedList;
	const char* inputFilename = "test/resource/input.txt";
	load(inputFilename, singleLinkedList);

	const int* singleListArray1 = asArray(singleLinkedList);

	BOOST_CHECK_MESSAGE( 
		       	empty(singleLinkedList) == false && 
				size(singleLinkedList) == testElementsSize &&
				isSameElements(singleListArray1, testElements, testElementsSize),
				"TEST: SingleLinkedList - Load");

	delete [] singleListArray1;

	/*
	 * Testing SingleLinkedList save() function
	 */
	for (int i=0; i<testElementsSize/2; i++) {
		popBack(singleLinkedList);
	}
	const char* outputFilename = "test/resource/output_single.txt";
	save(singleLinkedList, outputFilename);
	clearTestList(singleLinkedList);
	load(outputFilename, singleLinkedList);
	const int* singleListArray2 = asArray(singleLinkedList);
	BOOST_CHECK_MESSAGE(
		empty(singleLinkedList) == false && 
		size(singleLinkedList) == testElementsSize/2 &&
		isSameElements(singleListArray2, testElements, testElementsSize/2),
		 "TEST: SingleLinkedList - Save");
	
	delete [] singleListArray2;
	clearTestList(singleLinkedList);

		
}

BOOST_AUTO_TEST_SUITE_END()

