/**
 * @file dynamicarraymain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Uses DynamicArray class.
 * Instantiates DynamicArray object that starts with a fixed capacity but 
 * that is expanded when the array becomes full.
 * Performs test usages of all the constructors of DynamicArray objects.
 * Performs test usages of all the overloaded operators on DynamicArray objects.	
 * Loads double data from a file into a DynamicArray object. 
 * Saves double data from a DynamicArray object into a file.
 *
 */
 

#include <cassert>
#include <iostream>
#include <fstream>

#include "dynamicarray.h"
#include "utility.h"


using namespace std;


/**
 * The main function that accepts input and ouput file names as the command line
 * arguments.
 */
int main(int argc, char** argv) {

	/*
	 * Retrieve the file names from the command line arguments.
	 */
	const char* arrayInputFile = "resource/fibonacci.txt";
	const char* arrayOutputFile = "resource/arrayoutput.txt";

	/*
	 * Using DynamicArray default constructor
	 */
	cout<<"Using DynamicArray default constructor and insert up to capacity................"<<endl;
	DynamicArray darray1;
	cout<<"Capacity: "<< darray1.capacity() << ", size: " << darray1.size()<< " before inserting elements" << endl;

	for(int i=1; i<=DEFAULT_CAPACITY; i++) {
		darray1.insert(i);
		cout<<"Capacity: "<< darray1.capacity() << ", size: " << darray1.size() << " after inserting "<< i << endl;
	}
	cout<<endl;


	/**
	 * Using DynamicArray << operator (overloaed)
	 */
	cout<<"Using DynamicArray << operator to show array elements..........................."<<endl;
	cout<<darray1<<endl;
	cout<<endl;
	
	/**
	 * Using DynamicArray insert() after dynamic array is full, i.e., exceeds the capacity
	 */
	int element = 300;
	cout<<"Using DynamicArray insert() function after the array is full...................."<<endl;
	darray1.insert(element);
	cout<<"Capacity: "<< darray1.capacity() << ", size: " << darray1.size()<< " after inserting "<<element<<"  into the full array" << endl;
	cout<<darray1<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray search() function
	 */
	cout<<"Using DynamicArray search() function............................................"<<endl;
	cout<<"Succesful: Index of "<<element<<"  in the dynamic array is: "<< darray1.search(element) <<endl;
	element *= 2;
	cout<<"Unsuccessful: Index of "<<element<<"  in the dynamic array is: "<< darray1.search(element) <<endl;
	cout<<endl;


	/*
	 * Using DynamicArray regular constructor
	 */
	cout<<"Using DynamicArray regular constrcutor and insert up to capacity and beyond....."<<endl;
	DynamicArray darray2(5);
	for (int i=1; i<=7; i++) {
		darray2.insert(i*10);
		cout<<"Capacity: "<< darray2.capacity() << ", size: " << darray2.size() << " after inserting "<< i*10 <<  endl;
	}
	cout<<darray2<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray overloaded regular constructor
	 */
	cout<<"Using DynamicArray overloaded regular constructor..............................."<<endl; 
	int testElements[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int testSize = 10;
	DynamicArray darray3(testElements, testSize);
	cout<<"Capacity: "<<darray3.capacity()<<" size: "<<darray3.size()<<endl;
	cout<<darray3<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray copy constructor
	 */
	cout<<"Using DynamicArray copy constructor............................................."<<endl;
	DynamicArray darray4(darray2);
	cout<<"Capacity: "<<darray4.capacity()<<" size: "<<darray4.size()<<endl;
	cout<<darray4<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray copy assignment
	 */
	cout<<"Using DynamicArray copy assignment.............................................."<<endl;
	DynamicArray darray5;
	darray5 = darray2;
	cout<<"Capacity: "<<darray5.capacity()<<" size: "<<darray5.size()<<endl;
	cout<<darray5<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray move constructor
	 */
	cout<<"Using DynamicArray move constructor............................................."<<endl;
	DynamicArray darray6 = DynamicArray(testElements, testSize);
	cout<<"Capacity: "<<darray6.capacity()<<" size: "<<darray6.size()<<endl;
	cout<<darray6<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray move assignment
	 */
	cout<<"Using DynamicArray move assignment.............................................."<<endl;
	DynamicArray darray7;
	darray7 = DynamicArray(testElements, testSize);
	cout<<"Capacity: "<<darray7.capacity()<<" size: "<<darray7.size()<<endl;
	cout<<darray7<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray clear function
	 */
	cout<<"Using DynamicArray clear function..............................................."<<endl;
	darray3.clear();
	cout<<"Capacity: "<<darray3.capacity()<<", size: "<<darray3.size()<<", empty: "<<darray3.empty()<<", Elements:"<<endl;
	cout<<darray3<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray overloaded insert function
	 */
	cout<<"Using DynamicArray overloaded insert function..................................."<<endl;
	DynamicArray darray8(5);
	cout<<"Capacity: "<<darray8.capacity()<<", size: "<<darray8.size()<<", empty: "<<darray8.empty()<<", before insertion"<<endl;
	darray8.insert(testElements, testSize);
	cout<<"Capacity: "<<darray8.capacity()<<", size: "<<darray8.size()<<", empty: "<<darray8.empty()<<", after insertion:"<<endl;
	cout<<darray8<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray elements function.
	 */
	cout<<"Using DynamicArray elements function.............................................."<<endl;
	int* elements = darray8.elements();
	assert(elements != nullptr);
	cout<<endl;
	for(int i = 0; i<darray8.size(); i++) {
		cout<<elements[i]<<" ";
	}
	cout<<endl;
	delete [] elements;

	/*
	 * Using DynamicArray erase function
	 */
	int eraseMe = 50;
	cout<<"Using DynamicArray erase() function............................................."<<endl;
	cout<<"Capacity: "<< darray7.capacity() << ", size: " << darray7.size()<<" before erasing "<<eraseMe<< endl;
	cout<<darray7<<endl;
	darray7.erase(eraseMe);
	cout<<"Capacity: "<< darray7.capacity() << ", size: " << darray7.size() <<" after erasing "<<eraseMe<< endl;
	cout<<darray7<<endl;
	darray7.erase(eraseMe);
	cout<<"Capacity: "<< darray7.capacity() << ", size: " << darray7.size()<< " after erasing a non-exisitng element "<<eraseMe<< endl;
	cout<<darray7<<endl;
	cout<<endl;

	
	/*
	 * Using DynamicArray post increment operator
	 */
	cout<<"Using DynamicArray post increment operator......................................"<<endl;
	darray2++;
	cout<<darray2<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray pre increment operator
	 */
	cout<<"Using DynamicArray pre increment operator......................................."<<endl;
	++darray2;
	cout<<darray2<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray post decrement operator
	 */
	cout<<"Using DynamicArray post decrement operator......................................"<<endl;
	darray2--;
	cout<<darray2<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray pre decrement operator
	 */
	cout<<"Using DynamicArray pre decrement operator......................................."<<endl;
	--darray2;
	cout<<darray2<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray array index [i] operator
	 */
	cout<<"Using DynamicArray array index operator........................................."<<endl;
	try {
		cout<<"array[3]: "<<darray1[3]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	try {
		cout<<"array[5]: "<<darray1[5]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	try {
		cout<<"array[-1]: "<<darray1[-1]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	try {
		cout<<"array[25]: "<<darray1[25]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	try {	
		cout<<"Before update array[5]: "<<darray1[5]<<endl;
		darray1[5] = 2*darray1[5];
		cout<<"After update array[5]: "<<darray1[5]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	cout<<endl;


	/*
	 * Using DynamicArray + operator
	 */
	cout<<"Using DynamicArray + operator..................................................."<<endl;
	DynamicArray darray9 = darray2 + darray4;
	cout<<darray9<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray - operator
	 */
	cout<<"Using DynamicArray - operator..................................................."<<endl;
	DynamicArray darray10 = darray2 - darray4;
	cout<<darray10<<endl;
	cout<<endl;

	/*
	 * Using DynamicArray * operator
	 */
	cout<<"Using DynamicArray * operator..................................................."<<endl;
	DynamicArray darray11 = darray2 *  darray4;
	cout<<darray11<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray == operator
	 */
	cout<<"Using DynamicArray == operator.................................................."<<endl;
	DynamicArray darray12(testElements, testSize);
	darray3.insert(testElements, testSize);
	if(darray3 == darray12) {
		cout<<"DynamicArrays darray3 and darray12 are equal"<<endl;
	}
	else {
		cout<<"DynamicArrays darray3 and darray12 are not equal"<<endl;
	}
	cout<<"DynamicArray darray3:"<<endl;
	cout<<darray3<<endl;
	cout<<"DynamicArray darray12:"<<endl;
	cout<<darray12<<endl;
	cout<<endl;


	darray12.insert(110);
	if(darray3 == darray12) {
		cout<<"DynamicArrays darray3 and darray12 are equal"<<endl;
	}
	else {
		cout<<"DynamicArrays darray3 and darray12 are not equal"<<endl;
	}
	cout<<"DynamicArray darray3:"<<endl;
	cout<<darray3<<endl;
	cout<<"DynamicArray darray12:"<<endl;
	cout<<darray12<<endl;


	testElements[5] = 55;
	DynamicArray darray13(testElements, testSize);


	if(darray3 == darray13) {
		cout<<"DynamicArrays darray3 and darray13 are equal"<<endl;
	}
	else {
		cout<<"DynamicArrays darray3 and darray13 are not equal"<<endl;
	}
	cout<<"DynamicArray darray3:"<<endl;
	cout<<darray3<<endl;
	cout<<"DynamicArray darray13:"<<endl;
	cout<<darray13<<endl;
	cout<<endl;


	/*
	 * Using DynamicArray >> operator
	 */
	cout<<"Using DynamicArray >> operator.................................................."<<endl;
	ifstream in(arrayInputFile);
	if(!in) {
		cout<<"Cannot open input file: "<<arrayInputFile<<endl;
		return -1;
	}
	DynamicArray darray14(5);

	in>>darray14;
	
	cout<<"Capacity: "<< darray14.capacity()<<", size: "<<darray14.size()<<endl;
	cout<<darray14<<endl;
	in>>darray14;
	cout<<"Capacity: "<< darray14.capacity()<<", size: "<<darray14.size()<<endl;
	cout<<darray14<<endl;
	cout<<endl;
	in.close();

	/**
	 * Using DynamicArray load() function
	 */
	cout<<"Using DynamicArray load() function.............................................."<<endl;
	DynamicArray darray15(15);
	load(arrayInputFile, darray15);
	cout<<"Capacity: "<< darray15.capacity()<<", size: "<<darray15.size()<<" after loading from file"<<endl;
	cout<<darray15<<endl;
	cout<<endl;

	/**
	 * Using DynamicArray save() function
	 */
	cout<<"Using DynamicArray save() function.............................................."<<endl;
	save(darray15, arrayOutputFile);
	darray15.clear();
	cout<<"Capacity: "<< darray15.capacity()<<", size: "<<darray15.size()<<" after clearing the array"<<endl;
	load(arrayOutputFile, darray15);
	cout<<"Capacity: "<< darray15.capacity()<<", size: "<<darray15.size()<<" after loading from saved file"<<endl;
	cout<<darray15<<endl;
	cout<<endl;



	return 0;
}
