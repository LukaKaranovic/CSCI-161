/**
 * @file singlelinkedlistmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 14, 2020
 *
 * Performs test usages of test functions of SingleLinkedList class.
 *
 */



#include <iostream>
#include "singlelinkedlist.h"

using namespace std;

SingleLinkedList createSingleLinkedList(const char* file) {
	SingleLinkedList list;
	list.load(file);
	return list;
}


void pushBackIntoList(SingleLinkedList& list, const int* data, const int size) {
	for(int i=0; i<size; i++) {
		list.pushBack(data[i]);
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

void showArray(const int* array, const int size) {
	for(int i=0; i<size; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}



int main(int argc, char** argv) {

	
	const char* listInputFile = "resource/listinput.txt";
	const char* singleListOutputFile = "resource/singlelinkedlistoutput.txt";
	

	cout<<"\n.................................SingleLinkedList ........................."<<endl;
	/*
	 * Using SingleLinkedList Constructor
	 */
	cout<<"Using SingleLinkedList Constructor"<<endl;
	SingleLinkedList singleLinkedList;

	/*
	 * Using SingleLinkedList empty
	 */
	cout<<"Using SingleLinkedList.empty()"<<endl;
	bool isEmpty = singleLinkedList.empty();
	if(isEmpty) {
		cout<<"The single linked list is empty"<<endl;
	}
	else {
		cout<<"The single linked list is not empty"<<endl;
	}
	cout<<endl;

	/*
	 * Using SingleLinkedList.size
	 */
	cout<<"Using SingleLinkedList.size()"<<endl;
	cout<<"The single linked list size before loading: "<<singleLinkedList.size()<<endl;
	cout<<endl;

	/*
	 * Using LinkList.load() function
	 */
	cout<<"Using SingleLinkedList.load() and SingleLinkedList.show() functions"<<endl;
	singleLinkedList.load(listInputFile);
	cout<<"SingleLinkedList size after loading: "<<singleLinkedList.size()<<endl;
	cout<<endl;

	/*
	 * Using SingleLinkedList.show() function
	 */
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.front() function
	 */
	cout<<"Using SingleLinkedList.front()"<<endl;
	cout<<"The single linked list front: "<<singleLinkedList.front()<<endl;
	cout<<endl;

	/*
	 * Using SingleLinkedList.back() function
	 */
	cout<<"Using SingleLinkedList.back()"<<endl;
	cout<<"The single linked list back: "<<singleLinkedList.back()<<endl;
	cout<<endl;

	/*
	 * Using SingleLinkedList.search() function
	 */
	cout<<"Using SingleLinkedList.search() function"<<endl;
	int searchData = 100;
	cout<<"Searching "<< searchData <<" in the single linked list"<<endl;
	SingleLinkedListNode* searchResult1 = singleLinkedList.search(searchData);
       	if (searchResult1 != NULL ) {
		cout<<"Found the data "<<searchResult1->getData()<<" in the single linked list"<<endl;
	}
	else {
		cout<<"Did not find the data "<<searchData<<" in the single linked list"<<endl;
	}
	cout<<endl;
	
	/*
	 * Using SingleLinkedList.pushFront() function
	 */
	cout<<"Using SingleLinkedList.pushFront() function by pushing "<< searchData<<endl;
	singleLinkedList.pushFront(searchData);
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.search() again
	 */
	cout<<"Using SingleLinkedList.search() again after pushing "<<searchData<<endl;
	SingleLinkedListNode* searchResult2 = singleLinkedList.search(searchData);
       	if (searchResult2 != NULL ) {
		cout<<"Found the data "<<searchResult2->getData()<<" in the single linked list"<<endl;
	}
	else {
		cout<<"Did not find the data "<<searchData<<" in the single linked list"<<endl;
	}
	cout<<endl;

	/*
	 * Using SingleLinkedList.pushBack() function
	 */
	int data = 999;
	cout<<"Using SingleLinkedList.pushBack() function by pushing "<<data<<endl;
	singleLinkedList.pushBack( data);
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.insert() function
	 */
	int before = 55;
	data = 555;
	cout<<"Using SingleLinkedList.insert() function by inserting "<<data<<" before "<<before<<endl;

	singleLinkedList.insert(before, 555);
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.save() function
	 */

	cout<<"Using SingleLinkedList.save() function, saving list data into a file: "<<singleListOutputFile<<endl;
	singleLinkedList.save(singleListOutputFile);
	cout<<endl;

	/*
	 * Using SingleLinkedList.popFront() function
	 */
	cout<<"Using SingleLinkedList.popFront() function"<<endl;
	singleLinkedList.popFront();
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.popBack() function
	 */
	cout<<"Using SingleLinkedList.popBack() function"<<endl;
	singleLinkedList.popBack();
	singleLinkedList.show();
	cout<<endl;
	
	/*
	 * Using SingleLinkedList.remove() function
	 */
	cout<<"Using SingleLinkedList.remove() function by removing "<<data<<endl;
	singleLinkedList.remove(data);
	singleLinkedList.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList.clear() function
	 */
	cout<<"Using SingleLinkedList.clear() function"<<endl;
	singleLinkedList.clear();
	if(singleLinkedList.empty()) {
		cout<<"The single linked list is empty after clear"<<endl;
	}
	cout<<"SingleLinkedList size after clear: "<<singleLinkedList.size()<<endl;
	cout<<endl;
	
	/*
	 * Using SingleLinkedList.array() function
	 */
	cout<<"Using SingleLinkedList.array() function"<<endl;
	int listTestArraySize = 11;
	int listTestArray[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	pushBackIntoList(singleLinkedList, listTestArray, listTestArraySize);
	cout<<"List elements"<<endl;
	singleLinkedList.show();
	const int* listArray = singleLinkedList.array();
	if(isEqualElements(listArray, listTestArray, listTestArraySize)) {
		cout<<"SingleLinkedList.array() returned the array with the elements from list nodes"<<endl;
	}
	showArray(listArray, listTestArraySize);
	cout<<endl;
	
	/*
	 * Using SingleLinkedList.equal() function
	 */
	cout<<"Using SingleLinkedList.equal() function"<<endl;
	SingleLinkedList equalLinkedList;
	pushBackIntoList(equalLinkedList, listTestArray, listTestArraySize);
	cout<<"Equal List elements"<<endl;
	equalLinkedList.show();
	const int* equalListArray = equalLinkedList.array();
	if(isEqualElements(listArray, equalListArray, listTestArraySize)) {
		cout<<"Two lists are equal according to SingleLinkedList.array() function"<<endl;
	}

	if(singleLinkedList.equal(equalLinkedList)) {
		cout<<"Two lists are equal according to SingleLinkedList.equal() function"<<endl;
	}
	showArray(listArray, listTestArraySize);
	showArray(equalListArray, listTestArraySize);

	singleLinkedList.clear();
	equalLinkedList.clear();
	delete [] listArray;
	delete [] equalListArray;
	cout<<endl;

	/*
	 * Using SingleLinkedList copy constructor
	 */

	singleLinkedList.load(listInputFile);
	singleLinkedList.show();

	SingleLinkedList singleLinkedList2(singleLinkedList);
	cout<<"Copy constructed SingleLinkedList:"<<endl;
	singleLinkedList2.show();
	cout<<endl;
	
	/*
	 * Using SingleLinkedList move constructor
	 */
	SingleLinkedList singleLinkedList3= createSingleLinkedList (listInputFile);
	cout<<"Move constructed SingleLinkedList:"<<endl;
	singleLinkedList3.show();
	cout<<endl;



	/*
	 * Using SingleLinkedList copy assignment
	 */
	SingleLinkedList singleLinkedList4;
	singleLinkedList4 = singleLinkedList;
	cout<<"Copy assigned  SingleLinkedList:"<<endl;
	singleLinkedList4.show();
	cout<<endl;

	/*
	 * Using SingleLinkedList move assignment
	 */
	SingleLinkedList singleLinkedList5;
	singleLinkedList5 = createSingleLinkedList (listInputFile);
	cout<<"Move assigned SingleLinkedList:"<<endl;
	singleLinkedList5.show();
	cout<<endl;
	cout<<endl<<endl;

	return 0;
}

