
/**
 * @file doublelinkedlisttest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April, 2023
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

#include "doublelinkedlist.h"
#include "arraytest.h"


void arrayIntoTestList(const int* array, const int size, DoubleLinkedList& list) {
    
    for (int i = 0; i < size; i++) {
        DoubleLinkedListNode* node = new DoubleLinkedListNode;
        node->value = array[i];
        node->prev = nullptr;
        node->next = nullptr;
        if(list.head == nullptr && list.tail == nullptr) {
            list.head = list.tail = node;
        }
        else {
            node->prev = list.tail;
            list.tail->next = node;
            list.tail = list.tail->next;
        }
        list.size++;
    }
}


void clearTestList(DoubleLinkedList& list) {
    if(list.head == nullptr || list.tail == nullptr || list.size ==0) {
        return;
    }
    DoubleLinkedListNode* node = list.head;
    DoubleLinkedListNode* next = node->next;
    delete node;
    while( next != nullptr) {
        node = next;
        next = next->next;
        delete node;
    }
    list.head = list.tail = nullptr;
    list.size = 0;

}


bool isArrayInTestList(const int* array, const int size, DoubleLinkedList& list) {
    if(list.size != size) {
        return false;
    }

    DoubleLinkedListNode* node = list.head;
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



bool isTestListsInSeparateMemory(const DoubleLinkedList& list1, const DoubleLinkedList& list2) {
	DoubleLinkedListNode* node1 = list1.head;
	DoubleLinkedListNode* node2 = list2.head;
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
 * Test case to test functions of double linked list
 */
BOOST_AUTO_TEST_CASE(double_linked_list) {
	
	/*
	 * Testing createNewNode() function
	 * 
	 */

	DoubleLinkedListNode* node = createNewNode(10, nullptr, nullptr);
	BOOST_CHECK_MESSAGE(node->value == 10 && node->prev == nullptr && node->next == nullptr, "TESTL DoubleLinkedList - Create New Node");
	
	
	
	DoubleLinkedList list0;
	
	/*
	 * Testing empty() function
	 */
	BOOST_CHECK_MESSAGE(empty(list0), "TEST: DoubleLinkedList - List Is Empty");
	


/*
	 * Testing size() function
	 */
	BOOST_CHECK_MESSAGE(size(list0) == 0, "TEST: DoubleLinkedList - Size zero");
	
	int listTestArraySize = 11;
	int listTestArray[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	arrayIntoTestList(listTestArray, listTestArraySize, list0);
	BOOST_CHECK_MESSAGE(empty(list0) == false, "TEST: DoubleLinkedList - Empty false");
	BOOST_CHECK_MESSAGE(size(list0) == listTestArraySize, "TEST: DoubleLinkedList - Size non-zero");
	

	/*
	 * Testing front() function
	 */
	int frontElement = front(list0);
	BOOST_CHECK_MESSAGE(frontElement == listTestArray[0], "TEST: DoubleLinkedList - front() function");
	
	/*
	 * Testing back() function
	 */
	int backElement = back(list0);
	BOOST_CHECK_MESSAGE(backElement == listTestArray[listTestArraySize -1], "TEST: DoubleLinkedList - back() function");


	/*
	 * Testing showForward() function
	 */
	BOOST_TEST_MESSAGE("TEST: DoubleLinkedList - showForward() function");
	showForward(list0);

	/*
	 * Testing showBackward() function
	 */
	BOOST_TEST_MESSAGE("TEST: DoubleLinkedList - showBackward() function");
	showBackward(list0);


	/*
	 * Testing search() function
	 */
	const DoubleLinkedListNode* const foundNode1 = search(list0, -10);
	BOOST_CHECK_MESSAGE( foundNode1 == nullptr,
			"TEST: DoubleLinkedList - Search a non-existing element");

	const DoubleLinkedListNode* const foundNode2 = search(list0, listTestArray[listTestArraySize/2]);
	BOOST_CHECK_MESSAGE(foundNode2 != nullptr && 
						foundNode2->value == listTestArray[listTestArraySize/2], "TEST: DoubleLinkedList - Search an existing element");

	clearTestList(list0);
	

	DoubleLinkedList list;
	
	/*
	 * Testing pushFront() function
	 */
	int element1 = 10;
	pushFront(list, element1);
	BOOST_CHECK_MESSAGE(list.head != 0 && list.tail != 0 && empty(list) == false && list.head->value == element1
			&& list.tail->value == element1, 
	"TEST: DoubleLinkedList - Push Front First");
	
	int element2 = 20;
	pushFront(list, element2);
	BOOST_CHECK_MESSAGE(
		list.head != nullptr && 
		list.tail != nullptr &&
		list.head->value == element2 && 
		list.tail->value == element1 &&
		list.head->next != nullptr && 
		list.head->next->value == element1 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element2 &&
		empty(list) == false &&
		size(list) == 2, 
		"TEST: DoubleLinkedList - Push Front Second");
	
	int element3 = 30;
	pushFront(list, element3);
	BOOST_CHECK_MESSAGE(list.head != nullptr && 
		list.tail != nullptr &&
		list.head->value == element3 && 
		list.head->next != nullptr && 
		list.head->next->value == element2 &&
		list.head->next->next != nullptr && 
		list.head->next->next->value == element1 && 
		list.head->next->next->next == nullptr &&
		list.head->next->next == list.tail &&
		list.tail->value == element1 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element2 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element3 &&
		list.tail->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 3,
		"TEST: DoubleLinkedList - Push Front Third");

	
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
			list.tail->prev != nullptr &&
			list.tail->prev->value == element1 &&
			list.tail->prev->prev != nullptr &&
			list.tail->prev->prev->value == element2 &&
			list.tail->prev->prev->prev != nullptr &&
			list.tail->prev->prev->prev->value == element3 &&
			list.tail->prev->prev->prev->prev == nullptr &&
			empty(list) == false &&
			size(list) == 4, 
			"TEST: DoubleLinkedList - Push Back First");
	
	
	

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
			list.tail->prev != nullptr &&
			list.tail->prev->value == element4 &&
			list.tail->prev->prev != nullptr &&
			list.tail->prev->prev->value == element1 &&
			list.tail->prev->prev->prev != nullptr &&
			list.tail->prev->prev->prev->value == element2 &&
			list.tail->prev->prev->prev->prev != nullptr &&
			list.tail->prev->prev->prev->prev->value == element3 &&
			list.tail->prev->prev->prev->prev->prev == nullptr &&
			empty(list) == false &&
			size(list) == 5, 
			"TEST: DoubleLinkedList - Push Back Second");
	
	
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
		list.tail->prev != nullptr &&
		list.tail->prev->value == element4 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element1 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element2 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 5,  
		"TEST: DoubleLinkedList - Insert before a non-existing element");




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
		list.head->next->next->next->next->next->value ==element5 &&
		list.head->next->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next->next == list.tail &&
		list.tail->value == element5 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element4 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element1 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element2 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element6 &&
		list.tail->prev->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 6, 
		"TEST: DoubleLinkedList - Insert before an existing element");

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
		list.head->next->next->next->next->next->value ==element4 &&
		list.head->next->next->next->next->next->next != nullptr &&
		list.head->next->next->next->next->next->next->value == element5 &&
		list.head->next->next->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next->next->next == list.tail &&
		list.tail->value == element5 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element4 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element1 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element2 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element6 &&
		list.tail->prev->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->prev->prev->value == element7 &&
		list.tail->prev->prev->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 7, 	
		"TEST: DoubleLinkedList - Insert before front element");
	
	
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
		list.head->next->next->next->next->next->value ==element5 &&
		list.head->next->next->next->next->next->next == nullptr &&
		list.head->next->next->next->next->next == list.tail &&
		list.tail->value == element5 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element4 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element1 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element2 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element6 &&
		list.tail->prev->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 6, 	
		"TEST: DoubleLinkedList - Pop front");

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
		list.tail->prev != nullptr &&
		list.tail->prev->value == element1 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element2 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element6 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 5, 	
		"TEST: DoubleLinkedList - Pop back");

	

	

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
		list.tail->prev != nullptr &&
		list.tail->prev->value == element1 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element2 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element6 &&
		list.tail->prev->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 5, 	
		"TEST: DoubleLinkedList - Remove a non-existing element");
	
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
		list.tail->prev != nullptr &&
		list.tail->prev->value == element1 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element2 &&
		list.tail->prev->prev->prev != nullptr &&
		list.tail->prev->prev->prev->value == element3 &&
		list.tail->prev->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 4, 
		"TEST: DoubleLinkedList - Remove an existing element");


	removed = false;
	removed = remove(list, front(list));
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
		list.tail->prev != nullptr &&
		list.tail->prev->value == element1 &&
		list.tail->prev->prev != nullptr &&
		list.tail->prev->prev->value == element2 &&
		list.tail->prev->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 3, 		
		"TEST: DoubleLinkedList - Remove front element");

	

	removed = false;
	removed = remove(list, back(list));
	BOOST_CHECK_MESSAGE(
		removed == true &&
		list.head != nullptr &&
		list.head->value == element2 && 
		list.head->next != nullptr &&
		list.head->next->value == element1 &&
		list.head->next->next == nullptr &&
		list.head->next == list.tail &&
		list.tail->value == element1 &&
		list.tail->prev != nullptr &&
		list.tail->prev->value == element2 &&
		list.tail->prev->prev == nullptr &&
		empty(list) == false &&
		size(list) == 2, 		
		"TEST: DoubleLinkedList - Remove back element");

	clearTestList(list);
	


	/*
	 * Testing clear() function
	 */
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	clear(list);
	BOOST_CHECK_MESSAGE(empty(list) == true  && list.head == 0 && list.tail == 0 , "TEST: DoubleLinkedList - Clear");
		
	
	
	
	/*
	 * Testing asArray() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	const int* listArray = asArray(list);
	BOOST_CHECK_MESSAGE(isSameElements(listArray, listTestArray, listTestArraySize), "TEST: DoubleLinkedList - As Array");
	delete [] listArray;
	clearTestList(list);
	
	/*
	 * Testing equal() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);	
	DoubleLinkedList equalList;
	arrayIntoTestList(listTestArray, listTestArraySize, equalList);	
	BOOST_CHECK_MESSAGE(equal(list, equalList), "TEST: DoubleLinkedList - Equal");
	clearTestList(list);
	clearTestList(equalList);
	

	/*
	 * Testing copy() function
	 */
	clearTestList(list);
	arrayIntoTestList(listTestArray, listTestArraySize, list);
	DoubleLinkedList copyList;
	copy(copyList, list);
	BOOST_CHECK_MESSAGE(equal(list, copyList) && isTestListsInSeparateMemory(list, copyList), 
				"TEST: DoubleLinkedList - Copy");

	clearTestList(list);
	clearTestList(copyList);



	/*
	 * Testing DoubleLinkedList load() function
	 */

	int testElements[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 55, 60, 70, 80, 90,
	       	91, 92, 93, 94, 95, 96, 97, 98, 99};
	int testElementsSize = 28;
	const char* inputFilename = "test/resource/input.txt";

	DoubleLinkedList doubleLinkedList;
	load(inputFilename, doubleLinkedList);

	const int* doubleListArray1 = asArray(doubleLinkedList);

	BOOST_CHECK_MESSAGE(	
		empty(doubleLinkedList) == false && 
		size(doubleLinkedList) == testElementsSize &&
		isSameElements(doubleListArray1, testElements, testElementsSize), 
		"TEST: DoubleLinkedList - Load");

	delete [] doubleListArray1;
	/*
	 * Testing Double Linked List save() function
	 */
	for (int i=0; i<testElementsSize/2; i++) {
		popBack(doubleLinkedList);
	}
	const char* outputFilename = "test/resource/output_double.txt";
	save(doubleLinkedList,outputFilename);
	clearTestList(doubleLinkedList);
	load(outputFilename, doubleLinkedList);
	const int* doubleListArray2 = asArray(doubleLinkedList);

	BOOST_CHECK_MESSAGE(
		empty(doubleLinkedList) == false && 
		size(doubleLinkedList) == testElementsSize/2 &&
		isSameElements(doubleListArray2, testElements, testElementsSize/2), 
			"TEST: DoubleLinkedList - Save");
	delete [] doubleListArray2;
	clearTestList(doubleLinkedList);
	
}



BOOST_AUTO_TEST_SUITE_END()