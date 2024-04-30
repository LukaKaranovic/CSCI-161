/**
 * @file simplesetmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Uses SimpleSet class.
 * Instantiates SimpleSetobject that starts with a fixed capacity but 
 * that is expanded when the array becomes full.
 * All elements in SimpleSet must be unique.
 * Performs test usages of all the constructors of SimpleSet objects.
 * Performs test usages of all the overloaded operators on SimpleSet objects.	
 * Loads double data from a file into a SimpleSet object. 
 * Saves double data from a SimpleSet object into a file.
 */
 

#include <cassert>
#include <iostream>
#include <fstream>

#include "utility.h"
#include "simpleset.h"



using namespace std;


/**
 * The main function that accepts input and output file names as the command line arguments.
 */
int main(int argc, char** argv) {

	/*
	 * Initialize file names.
	 */
	const char* setInputFile1 = "resource/primes.txt";
	const char* setInputFile2 = "resource/fibonacci.txt";
	const char* setOutputFile = "resource/setoutput.txt";

	/*
	 * Using SimpleSet Default constructor and insert function
	 */
	cout<<"Using SimpleSet default constructor and insert function........................."<<endl;
	SimpleSet sset0;
	cout<<"Capacity: "<< sset0.capacity() << ", size: " << sset0.size() << endl;
		
	int element = 0;
	for(int i=1; i<6; i++) {
		element = i*10;
		sset0.insert(element);
		cout<<"............. simple set size: "<<sset0.size()<<", after inserting: " << element << endl;
	}
	

	/*
	 * Using operator << - runtime polymorphism in action.
	 * Passing SimpleSet object through DynamicArray reference into operator<<() function.
	 */
	cout<<"Using insertion << operator to show elements...................................."<<endl;
	cout<<sset0<<endl;
	cout<<endl;

	


	/*
	 * Using SimpleSet Regular constructor and insert function
	 */
	cout<<"Using SimpleSet regular constructor and insert function........................."<<endl;
	SimpleSet sset1(5);

	cout<<"Capacity: "<< sset1.capacity() << ", size: " << sset1.size() << endl;
	
	element = 0;
	for(int i=1; i<6; i++) {
		element = i*10;
		sset1.insert(element);
		cout<<"............. simple set size: "<<sset1.size()<<", after inserting: " << element << endl;
	}
	cout<<sset1<<endl;
	cout<<endl;
	


	/*
	 * Using Overloaded Regular Constructor
	 */
	cout<<"Using Overloaded Regular Constructor..........................................."<<endl;
	int uniqueElements[] = {10,20, 30, 40, 50, 60, 70, 80,90, 100};
	int uniqueElementSize = 10;
	SimpleSet sset2(uniqueElements, uniqueElementSize);
	cout<<"Capacity: "<<sset2.capacity()<<" size: "<<sset2.size() << " with no duplicate data"<<endl;
	cout<<sset2<<endl;

	int duplicateElements[] = {10,20, 20, 40, 40, 60, 70, 80, 80, 100};
	int duplicateElementSize = 10;
	SimpleSet sset3(duplicateElements, duplicateElementSize);
	cout<<"Capacity: "<<sset3.capacity()<<" size: "<<sset3.size()<<" with duplicate data"<<endl;
	cout<<sset3<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet Copy constructor
	 */
	cout<<"Using SimpleSet copy constructor................................................"<<endl;
	SimpleSet sset4(sset1);
	cout<<"Capacity: "<<sset4.capacity()<<" size: "<<sset4.size()<<" copy constructed"<<endl;
	cout<<sset4<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet Move constructor
	 */
	cout<<"Using SimpleSet move constructor................................................"<<endl;
	SimpleSet sset5 = SimpleSet(uniqueElements, uniqueElementSize);
	cout<<"Capacity: "<<sset5.capacity()<<" size: "<<sset5.size()<<" move constructed"<<endl;
	cout<<sset5<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet copy assignment
	 */
	cout<<"Using SimpleSet copy assignment................................................."<<endl;
	SimpleSet sset6;
	sset6 = sset1;
	cout<<"Capacity: "<<sset6.capacity()<<" size: "<<sset6.size()<<" copy assigned"<<endl;
	cout<<sset6<<endl;
	cout<<endl;

	/*
	 * Using SimpleSet Move assignment
	 */
	cout<<"Using SimpleSet move assignment................................................."<<endl;
	SimpleSet sset7;
	sset7 = SimpleSet(uniqueElements, uniqueElementSize);
	cout<<"Capacity: "<< sset7.capacity() << ", size: " << sset7.size() << " move assigned"<< endl;
	cout<<sset7<<endl;
	cout<<endl;	


	/*
	 * Using SimpleSet overriden insert function
	 */
	cout<<"Using SimpleSet insert function................................................."<<endl;
	element = 30;
	sset1.insert(element);
	cout<<"Capacity: "<< sset1.capacity() << ", size: " << sset1.size() << " after attempting to insert a duplicate element "<<element<< endl;
	cout<<sset1<<endl;

	element = 60;
	sset1.insert(60);
	cout<<"Capacity: "<< sset1.capacity() << ", size: " << sset1.size() << " after insert a unique element "<<element<< endl;
	cout<<sset1<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet inherited erase function
	 */
	element = 30;
	cout<<"Using SimpleSet erase function.................................................."<<endl;
	sset7.erase(element);
	cout<<"Size " << sset7.size()<<" after erasing "<<element<< endl;
	cout<<sset7<<endl;
	cout<<"Using SimpleSet erasing a non-existing element "<<element<<endl;
	sset7.erase(element);
	cout<<"Size: " << sset7.size()<<" after erasing a non-exisitng element "<< element << endl;
	cout<<sset7<<endl;
	cout<<endl;



	/*
	 * Using SimpleSet inherited clear function
	 */
	cout<<"Using SimpleSet clear function.................................................."<<endl;
	sset7.clear();
	cout<<"Capacity: "<< sset7.capacity() << ", size: " << sset7.size() << endl;
	cout<<sset7<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet overriden insert function
	 */
	cout<<"Using SimpleSet insert function......................................"<<endl;
	sset7.insert(uniqueElements, uniqueElementSize);
	cout<<"Capacity: "<< sset7.capacity() << ", size: " << sset7.size() << " with unique data set"<< endl;
	cout<<sset7<<endl;
	sset7.clear();
	sset7.insert(duplicateElements, duplicateElementSize);
	cout<<"Capacity: "<< sset7.capacity() << ", size: " << sset7.size() << " with duplicate data set"<< endl;
	cout<<sset7<<endl;
	cout<<endl;


	/*
	 *	Using SimpleSet inherited elements function
	 */
	cout<<"Using SimpleSet inherited elements function......................................"<<endl;
	int* elements = sset7.elements();
	assert(elements != nullptr);
	cout<<endl;
	for(int i = 0; i<sset7.size(); i++) {
		cout<<elements[i]<<" ";
	}
	cout<<endl;
	delete [] elements;



	/*
	 * Using extraction >> operator: runtime polymorphism in action
	 * Passing SimpleSet object through DynamicArray reference into operator>>() function.
	 */
	cout<<"Using extraction >> operator ..................................................."<<endl;
	ifstream primeStream(setInputFile1);
	SimpleSet sset8(10);
	if(!primeStream) {
		cout<<"Caanot open prime input file!"<<endl;
	}
	else {
		primeStream>>sset8;
		primeStream.close();
	}
	
	cout<<".......prime set: ";
	cout<<sset8<<endl;
	
	ifstream fibonacciStream(setInputFile2);
	SimpleSet sset9(10);
	if(!fibonacciStream) {
		cout<<"Connot open fibonacci input file"<<endl;
	}
	else {
		fibonacciStream>>sset9;
		fibonacciStream.close();
	}

	cout<<"......fobonacci set: ";
	cout<<sset9<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet set union operator
	 */
	cout<<"Using SimpleSet set union (operator+)......................................"<<endl;
	SimpleSet primeUnionFibo = sset8 + sset9;
	cout<<"Prime UNION Fibonacci: "<<primeUnionFibo<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet set difference operator
	 */
	cout<<"Using SimpleSet set difference using (operator-)................................."<<endl;
	SimpleSet primeDiffFibo = sset8 - sset9;
	cout<<"Prime DIFERENCE Fibonacci: "<<primeDiffFibo<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet set intersection operator
	 */
	cout<<"Using SimpleSet set intersection using (operator*)..............................."<<endl;
	SimpleSet primeInterFibo = sset8 * sset9;
	cout<<"Prime INTERSECTION Fibonacci: "<<primeInterFibo<<endl;
	cout<<endl;



	/*
	 * Using inherited index operator
	 */
	cout<<"Using SimpleSet index [] operator .............................................."<<endl;
	
	try{
		cout<<"sset8[3]: "<<sset8[3]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	try{
		cout<<"sset8[5]: "<<sset8[5]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	try {
		cout<<"sset8[11]: "<<sset8[11]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	try{
		cout<<"sset8[-1]: "<<sset8[-1]<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	cout<<endl;


	/*
	 * Using SimpleSet post increment operator
	 */
	cout<<"Using SimpleSet post increment operator........................................."<<endl;
	cout<<"... prime set before increment "<<sset8<<endl;
	sset8++;
	cout<<"... prime set after increment "<<sset8<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet pre increment operator
	 */
	cout<<"Using SimpleSet pre increment operator.........................................."<<endl;
	cout<<"... prime set before increment "<<sset8<<endl;
	++sset8;
	cout<<"... prime set after increment "<<sset8<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet post decrement operator
	 */
	cout<<"Using SimpleSet post deccrement operator........................................"<<endl;
	cout<<"... prime set before deccrement "<<sset8<<endl;
	sset8--;
	cout<<"... prime set after deccrement "<<sset8<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet pre decrement operator
	 */
	cout<<"Using SimpleSet pre deccrement operator........................................."<<endl;
	cout<<"... prime set before deccrement "<<sset8<<endl;
	--sset8;
	cout<<"... prime set after deccrement "<<sset8<<endl;
	cout<<endl;


	/*
	 * Using load() function - runtime polymorphism in action
	 * Passing SimpleSet object through DynamicArray reference into load() function.
	 */
	cout<<"Using SimpleSet load() function................................................."<<endl;
	SimpleSet sset10;
	load(setInputFile1, sset10);
	cout<<sset10<<endl;
	cout<<endl;


	/*
	 * Using SimpleSet == operator
	 */
	cout<<"Using SimpleSet == operator....................................................."<<endl;
	if(sset2 == sset3) {
		cout<<"SimpleSets sset2 and sset3 are equal"<<endl;
	}
	else {
		cout<<"SimpleSets sset2 and sset3 are not equal"<<endl;
	}

	if(sset8 == sset10) {
		cout<<"SimpleSets sset8 and sset10 are equal"<<endl;
	}
	else {
		cout<<"SimpleSets sset8 and sset10 are not equal"<<endl;
	}
	cout<<endl;



	/*
	 * Using save() function - runtime polymorphism in action.
	 * Passing SimpleSet object through DynamicArray reference into save() function
	 */
	cout<<"Using SimpleSet save() function................................................."<<endl;
	save(sset10, setOutputFile);
	sset10.clear();
	load(setOutputFile, sset10);
	cout<<sset10<<endl;
	cout<<endl;


	return 0;
}
