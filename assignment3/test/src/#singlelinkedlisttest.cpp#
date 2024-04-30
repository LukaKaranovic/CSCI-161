/**
 * @file singlelinkedlisttest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 14, 2023
 *
 * Performs unit tests on the functions of SingleLinkedList class.
 *
 */


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment3_single_linked_list

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <assert.h>
#include "singlelinkedlist.h"
#include "singlelinkedlisttest.h"

using namespace std;


bool SingleLinkedListTest::testPreviousNode() {
    SingleLinkedList list;
    SingleLinkedListNode* nodeFifty = new SingleLinkedListNode(50, 0);
    list._front = list._back = nodeFifty;
     ++list._size;
    SingleLinkedListNode* nodeFourty = new SingleLinkedListNode(40, list._front);
    list._front = nodeFourty;
     ++list._size;
    SingleLinkedListNode* nodeThirty = new SingleLinkedListNode(30, list._front);
    list._front = nodeThirty;
     ++list._size;
    SingleLinkedListNode* nodeTweenty = new SingleLinkedListNode(20, list._front);
    list._front = nodeTweenty;
     ++list._size;
    SingleLinkedListNode* nodeTen = new SingleLinkedListNode(10, list._front);
    list._front = nodeTen;
     ++list._size;

    SingleLinkedListNode* prevTen = list.previousNode(10);
    SingleLinkedListNode* prevTweenty = list.previousNode(20);
    SingleLinkedListNode* prevThirty = list.previousNode(30);
    SingleLinkedListNode* prevFourty = list.previousNode(40);
    SingleLinkedListNode* prevFifty = list.previousNode(50);

    return (prevTen == nullptr && 
            prevTweenty == nodeTen && prevTweenty->_data == 10 &&
            prevThirty == nodeTweenty && prevThirty->_data == 20 &&
            prevFourty == nodeThirty && prevFourty->_data == 30 &&
            prevFifty == nodeFourty && prevFifty->_data == 40 &&
            list._size == 5 && list._front == nodeTen && list._back == nodeFifty);
}


bool SingleLinkedListTest::testDeepCopy() {
    SingleLinkedList list;
    SingleLinkedListNode* nodeFifty = new SingleLinkedListNode(50, 0);
    list._front = list._back = nodeFifty;
    ++list._size;
    SingleLinkedListNode* nodeFourty = new SingleLinkedListNode(40, list._front);
    list._front = nodeFourty;
     ++list._size;
    SingleLinkedListNode* nodeThirty = new SingleLinkedListNode(30, list._front);
    list._front = nodeThirty;
     ++list._size;
    SingleLinkedListNode* nodeTweenty = new SingleLinkedListNode(20, list._front);
    list._front = nodeTweenty;
     ++list._size;
    SingleLinkedListNode* nodeTen = new SingleLinkedListNode(10, list._front);
    list._front = nodeTen;
     ++list._size;

    SingleLinkedList copy;
    assert(list._size == 5 && copy._size == 0);

    copy.deepCopy(list);

    return (
            copy._size == 5 && 
            copy._front != list._front && copy._front->_data == list._front->_data && copy._front->_data == 10 &&
            copy._front->_next != list._front->_next && copy._front->_next->_data == list._front->_next->_data && copy._front->_next->_data == 20 &&
            copy._front->_next->_next != list._front->_next->_next && copy._front->_next->_next->_data == list._front->_next->_next->_data && 
            copy._front->_next->_next->_data == 30 &&
            copy._front->_next->_next->_next != list._front->_next->_next->_next && 
            copy._front->_next->_next->_next->_data == list._front->_next->_next->_next->_data && 
            copy._front->_next->_next->_next->_data == 40 &&
            copy._front->_next->_next->_next->_next != list._front->_next->_next->_next->_next && 
            copy._front->_next->_next->_next->_next->_data == list._front->_next->_next->_next->_next->_data && 
            copy._front->_next->_next->_next->_next->_data == 50 &&
            copy._front->_next->_next->_next->_next->_next == nullptr &&
            copy._back != list._back && copy._back->_data == list._back->_data && copy._back->_data == 50
            
    );
}


/**
 * @brief Compares single linked list nodes' data against the given test data.
 *
 * Helper function to be used to test copy and move constructors and copy and move assignments
 *
 * @param list Single linked list whose node's data will be compared.
 * @param testData Test data that will be compared against the list node's data.
 * @param testDataSize The size of the test data.
 *
 * @return Returns true if the list node's data matches with the test data. 
 */
bool isListDataValid(SingleLinkedList& list, const int testData[], const int testDataSize) {
	bool isDataValid = true;
	for( int i =0; i<testDataSize; i++) {
		if (list.front() != testData[i]) {
			isDataValid = false;
			break;
		}
		list.popFront();
	}
	return isDataValid;
}

/**
 * @brief Creates a single linked list and load it with data from a given file.
 *
 * @param filename The file from which data will be loaded into the list.
 *
 * @return Returns a single linked list with data loaded from the given file.
 */ 
SingleLinkedList createSingleLinkedList(const char* filename) {
	SingleLinkedList list;
	list.load(filename);
	return list;
}	


void pushBackIntoList(SingleLinkedList& list, const int* array, const int size ) {
	for (int i=0; i<size; i++) {
		list.pushBack(array[i]);
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

bool isEqualElements(const SingleLinkedList& list, const int* array, const int size) {
	if(list.size() != size) {
		return false;
	}
	const int* listArray = list.array();
	bool isEqual = isEqualElements(listArray, array, size);
	delete [] listArray;
	return isEqual;
}



/*
 * Test suite for assignment 3
 */
BOOST_AUTO_TEST_SUITE(assignment3_test_suite)

/*
 * Test case for single linked list.
 */	
BOOST_AUTO_TEST_CASE(single_linked_list) {

	/*
	 * Testing default constructor.
	 */
	SingleLinkedList list;

	BOOST_CHECK_MESSAGE(list.empty(), "TEST: SingleLinkedList - Default Constructor empty after construction");
	BOOST_CHECK_MESSAGE(list.size() == 0, "TEST: SingleLinkedList - Default Constructor size zero after construction");
	BOOST_CHECK_MESSAGE(list.front() == -1, "TEST: SingleLinkedList - Default Constructor front");
	BOOST_CHECK_MESSAGE(list.back() == -1, "TEST: SingleLinkedList - Default Constructor back");
	cout<<endl;


	/*
	 * Testing previousNode() function
	 */
	BOOST_CHECK_MESSAGE(SingleLinkedListTest::testPreviousNode(), "TEST: SingleLinkedList -  PreviousNode function");


	/*
	 * Testing pushFront() function.
	 */
	int data1 = 10;
	list.pushFront(data1);
	BOOST_CHECK_MESSAGE(list.empty() == false, "TEST: SingleLinkedList -  PushFront not empty first data.");
	BOOST_CHECK_MESSAGE(list.size() == 1, "TEST: SingleLinkedList -  PushFront size first data.");

	/*
	 * Testing front() function
	 */
	BOOST_CHECK_MESSAGE(list.front() == data1,
			"TEST: SingleLinkedList -  Front after first push front");

	/*
	 * Testing back() function
	 */
	BOOST_CHECK_MESSAGE(list.back() == data1,
			"TEST: SingleLinkedList -  Back after first push front");

	int data2 = 20;
	list.pushFront(data2);
	BOOST_CHECK_MESSAGE(list.size() == 2, "TEST: SingleLinkedList -  PushFront size second push front.");

	BOOST_CHECK_MESSAGE(list.front() == data2,
			"TEST: SingleLinkedList -  Front after second push front");
	BOOST_CHECK_MESSAGE(list.back() == data1,
			"TEST: SingleLinkedList -  Back after second push front");
	cout<<endl;


	/*
	 * Testing pushBack() function
	 */
	int data3 = 30;
	list.pushBack(data3);
	BOOST_CHECK_MESSAGE(list.size() == 3, "TEST: SingleLinkedList -  PushBack size first push back.");
	BOOST_CHECK_MESSAGE(list.front() == data2,
			"TEST: SingleLinkedList -  Front after first push back");
	BOOST_CHECK_MESSAGE(list.back() == data3,
			"TEST: SingleLinkedList -  Back after first push back");


	int data4 = 40;
	list.pushBack(data4);
	BOOST_CHECK_MESSAGE(list.size() == 4, "TEST: SingleLinkedList -  PushBack size second push back");
	BOOST_CHECK_MESSAGE(list.front() == data2,
			"TEST: SingleLinkedList -  Front after second push back");
	BOOST_CHECK_MESSAGE(list.back() == data4,
			"TEST: SingleLinkedList -  Back after second push back");

	cout<<endl;


	/*
	 * Testing deepCopy() function
	 */
	BOOST_CHECK_MESSAGE(SingleLinkedListTest::testDeepCopy(), "TEST: SingleLinkedList -  Deep Copy function");
	

	/*
	 * Testing insert() function
	 */
	int data5 = 50;
	list.insert(data5, data5);
	BOOST_CHECK_MESSAGE(list.size() == 4, "TEST: SingleLinkedList -  Insert size after failed insertion");
	list.insert(data3, data5);
	BOOST_CHECK_MESSAGE(list.size() == 5, "TEST: SingleLinkedList -  Insert size after first successful insertion");
	BOOST_CHECK_MESSAGE(list.front() == data2,
			"TEST: SingleLinkedList -  Front after first successful insertion");
	BOOST_CHECK_MESSAGE(list.back() == data4,
			"TEST: SingleLinkedList -  Back after first successful insertion");



	cout<<endl;

	/*
	 * Testing search() function
	 */
	int data6 = 60;
	const SingleLinkedListNode* const searchNode1 = list.search(data6);
	BOOST_CHECK_MESSAGE(searchNode1 == 0, "TEST: SingleLinkedList -  Search non-existing data");

	list.insert(data2, data6);
	BOOST_CHECK_MESSAGE(list.size() == 6, "TEST: SingleLinkedList -  Insert size after second successful insertion");
	BOOST_CHECK_MESSAGE(list.front() == data6,
			"TEST: SingleLinkedList -  Front after second successful insertion");
	BOOST_CHECK_MESSAGE(list.back() == data4,
			"TEST: SingleLinkedList -  Back after second successful insertion");

	const SingleLinkedListNode* const searchNode2 = list.search(data6);
	BOOST_CHECK_MESSAGE(searchNode2 != 0 && searchNode2->getData() == data6,
		"TEST: SingleLinkedList -  Search existing data");	
	cout<<endl;


	/*
	 * Testing popFront() function
	 */
	list.popFront();
	BOOST_CHECK_MESSAGE(list.size() == 5, "TEST: SingleLinkedList -  PopFront size after popping from the front");
	BOOST_CHECK_MESSAGE(list.front() != data6 && list.front() == data2 && list.back() == data4,
			"TEST: SingleLinkedList -  PopFront Front and Back after popping from the front");
	cout<<endl;

	/*
	 * Testing popBack() function
	 */
	list.popBack();
	BOOST_CHECK_MESSAGE(list.size() == 4, "TEST: SingleLinkedList -  PopBack size after popping from the back");
	BOOST_CHECK_MESSAGE(list.front() == data2 && list.back() != data4 && list.back() == data3,
			"TEST: SingleLinkedList -  PopBack Front and Back after popping from the back");
	cout<<endl;

	/*
	 * Testing remove() function
	 */
	list.remove(data6);
	BOOST_CHECK_MESSAGE(list.size() == 4, "TEST: SingleLinkedList -  Remove size after unsuccessful remove");

	const SingleLinkedListNode* const searchNode3 = list.search(data5);
	BOOST_CHECK_MESSAGE(searchNode3 != 0 && searchNode3->getData() == data5,
			"TEST: SingleLinkedList -  Remove search non NULL before remove");

	list.remove(data5);
	BOOST_CHECK_MESSAGE(list.size() == 3, "TEST: SingleLinkedList -  Remove size after successful remove");
	const SingleLinkedListNode* const searchNode4 = list.search(data5);
	BOOST_CHECK_MESSAGE(searchNode4 == 0, "TEST: SingleLinkedList -  Remove search NULL after successful remove");
       cout<<endl;	


	/*
	 * Testing clear() function
	 */
	list.clear();
	BOOST_CHECK_MESSAGE(list.empty(), "TEST: SingleLinkedList -  Clear empty after clear");
	BOOST_CHECK_MESSAGE(list.size() == 0, "TEST: SingleLinkedList -  Clear size zero after clear");
	cout<<endl;


	/*
	 * Testing array() function
	 */
	const int listTestDataSize = 28;
	const int listTestData[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 55, 60, 70, 80, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
	pushBackIntoList(list, listTestData, listTestDataSize);
	const int* listArray = list.array();
	bool isEqual = true;
	if(list.size() != listTestDataSize) {
		isEqual = false;
	} 
	isEqual = isEqualElements(listArray, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isEqual, "TEST: SingleLinkedList -  Array with the elements from list nodes");
	delete [] listArray;

	/*
	 * Testing equal() function
	 */
	SingleLinkedList equalList;
	pushBackIntoList(equalList, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(list.equal(equalList), "TEST: SingleLinkedList -  Equal lists");

	list.clear();
	BOOST_REQUIRE(list.empty());
	
	/*
	 * Testing load() function
	 */
	const char* inputFileName = "resource/listinput.txt";
	const char* outputFileName = "test/resource/singlelisttestoutput.txt";
	
	list.load(inputFileName);
	BOOST_CHECK_MESSAGE(list.empty() == false, "TEST: SingleLinkedList -  Load not empty after loading from file");
	BOOST_CHECK_MESSAGE(list.size() == listTestDataSize, "TEST: SingleLinkedList -  Load size after loading from file");
	BOOST_CHECK_MESSAGE(list.front() == 10, "TEST: SingleLinkedList -  Load front after loading from file");
	BOOST_CHECK_MESSAGE(list.back() == 99, "TEST: SingleLinkedList -  Load back after loading from file");

	bool isLoadSuccess = isEqualElements(list, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isLoadSuccess == true, "TEST: SingleLinkedList -  Load all elements successful");
	cout<<endl;


	/*
	 * Testing show() function
	 */
	list.clear();
	BOOST_REQUIRE(list.empty());
	BOOST_TEST_MESSAGE("TEST: SingleLinkedList -  Show");
	list.load(inputFileName);
	list.show();
	cout<<endl;


	/*
	 * Testing save() function
	 */

	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);
	list.load(inputFileName);
	BOOST_REQUIRE(list.empty() == false && list.size() == listTestDataSize);
	for( int i =0; i<listTestDataSize/2; i++) {
		list.popFront();
	}
	list.save(outputFileName);
	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);

	list.load(outputFileName);
	BOOST_CHECK_MESSAGE(list.empty() == false, "TEST: SingleLinkedList -  Save not empty after loading from saved file");
	BOOST_CHECK_MESSAGE(list.size() == listTestDataSize/2, "TEST: SingleLinkedList -  Save size after loading from saved file");
	BOOST_CHECK_MESSAGE(list.front() == 55, "TEST: SingleLinkedList -  Save front after loading from saved file");
	BOOST_CHECK_MESSAGE(list.back() == 99, "TEST: SingleLinkedList -  Save back after loading from saved file");
	bool isSaveSuccess = isEqualElements(list, listTestData+listTestDataSize/2, listTestDataSize/2);
	BOOST_CHECK_MESSAGE(isSaveSuccess == true, "TEST: SingleLinkedList -  Save all elements successful");
	cout<<endl;

	/*
	 * Testing copy constructor
	 */
	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);
	list.load(inputFileName);
	BOOST_REQUIRE(list.empty() == false && list.size() == listTestDataSize);

	SingleLinkedList list2(list);
	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);
	bool isCopyConstructSuccess = isEqualElements(list2, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isCopyConstructSuccess == true, "TEST: SingleLinkedList -  Copy constructor");
	cout<<endl;

	/*
	 * Testing move constructor
	 */
	SingleLinkedList list3 = createSingleLinkedList(inputFileName);
	bool isMoveConstructSuccess = isEqualElements(list3, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isMoveConstructSuccess == true, "TEST: SingleLinkedList -  Move constructor");
	cout<<endl;

	/*
	 * Testing copy assignment
	 */
	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);
	list.load(inputFileName);
	BOOST_REQUIRE(list.empty() == false && list.size() == listTestDataSize);
	SingleLinkedList list4;
	list4 = list;
	list.clear();
	BOOST_REQUIRE(list.empty() && list.size() == 0);
	bool isCopyAssignSuccess = isEqualElements(list4, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isCopyAssignSuccess == true, "TEST: SingleLinkedList -  Copy assignment");
	cout<<endl;

	/*
	 * Testing move assignment
	 */
	SingleLinkedList list5;
	list5 = createSingleLinkedList(inputFileName);
	bool isMoveAssignSuccess = isEqualElements(list5, listTestData, listTestDataSize);
	BOOST_CHECK_MESSAGE(isMoveAssignSuccess == true, "TEST: SingleLinkedList -  Move assignment");
	cout<<endl;
}



BOOST_AUTO_TEST_SUITE_END()

