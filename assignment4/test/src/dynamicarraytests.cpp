/**
 * @file - dynamicarraytests.cpp
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.1
 * @date - March 09, 2024
 *
 * Performs unit test on the functions of DynamicArray class.
 *
 */



#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignnment4_dynamic_array

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <fstream>
#include "dynamicarray.h"
#include "dynamicarraytest.h"
#include "utility.h"


using namespace std;


bool DynamicArrayTest::testDefaultConstructor(){
	DynamicArray darray;
	if(darray._capacity != DEFAULT_CAPACITY ) {
		cout<<"\treason: capacity is not initialized properly"<<endl;
		return false;
	} 
	if(darray._size != 0 ) {
		cout<<"\treason: size is not initialized properly"<<endl;
		return false;
	}
	if(darray._elements == nullptr ) {
		cout<<"\treason: elements pointer is not initialized properly"<<endl;
		return false;
	}

	return true;
}


bool DynamicArrayTest::testRegularConstructor(){
	int testCapacity = 5;
	DynamicArray darray(testCapacity);
	if(darray._capacity != testCapacity ) {
		cout<<"\treason: capacity is not initialized properly"<<endl;
		return false;
	} 
	if(darray._size != 0 ) {
		cout<<"\treason: size is not initialized properly"<<endl;
		return false;
	}
	if(darray._elements == nullptr ) {
		cout<<"\treason: elements pointer is not initialized properly"<<endl;
		return false;
	}

	return true;
}


bool DynamicArrayTest::testOverloadedRegularConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray(array, size);

	if (darray._capacity != size || darray._size != size || darray._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer are not initialized properly"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(darray._elements[i]  != array[i]) {
			cout<<"\treason: elements of the dynamic array are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testCopyConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray(array, size);

	DynamicArray copy(darray);

	if (copy._capacity != size || copy._size != size || copy._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer are not initialized properly in the copy constructed dynamic array"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(copy._elements[i]  != array[i]) {
			cout<<"\treason: elements of the copy constructed dynamic array are not correct"<<endl;
			return false;
		}
	}
	return true;

}


bool DynamicArrayTest::testMoveConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	
	DynamicArray darray = std::move(DynamicArray(array, size));
	if (darray._capacity != size || darray._size != size || darray._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer of the move constructed dynamic array are not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(darray._elements[i]  != array[i]) {
			cout<<"\treason: elements of the move constructed dynamic array are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testSize() {
	DynamicArray darray1;
	
	if (darray1.size() != 0) {
		cout<<"\treason: deafult size is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	DynamicArray darray2(array, size);
	
	if (darray2.size() != size) {
		cout<<"\treason: custom size is not correct"<<endl;
		return false;
	}

	return true;
}


bool DynamicArrayTest::testCapacity() {
	DynamicArray darray1;
	
	if (darray1.capacity() != DEFAULT_CAPACITY) {
		cout<<"\treason: deafult capacity is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	DynamicArray darray2(array, size);
	
	if (darray2.capacity() != size) {
		cout<<"\treason: custom capacity is not correct"<<endl;
		return false;
	}

	return true;
}


bool DynamicArrayTest::testEmpty() {
	DynamicArray darray1;
	
	if (darray1.empty() != true) {
		cout<<"\treason: empty true is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	DynamicArray darray2(array, size);
	
	if (darray2.empty() != false) {
		cout<<"\treason: empty false is not correct"<<endl;
		return false;
	}

	return true;
}


bool DynamicArrayTest::testInsert() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	int capacity = 5;

	DynamicArray darray(capacity);

	for ( int i = 0 ; i<size; i++) {
		darray.insert(array[i]);
		if(i < capacity -1 && darray._capacity != capacity ) {
			cout<<"\treason: capacity after inserting within the capacity is not correct"<<endl;
			return false;
		}
		if(i > capacity -1 && darray._capacity != 2*capacity ) {
			cout<<"\treason: capacity after inserting beyond the capacity is not correct"<<endl;
			return false;
		}
		if(darray._size != i+1) {
			cout<<"\treason: size after insertion is not correct"<<endl;
			return false;
		}
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: element after insertion is not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testOverloadedInsert() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	int capacity = 5;
	DynamicArray darray(capacity);
	darray.insert(array, size);
	if (darray._capacity != 2*capacity || darray._size != size || darray._elements == 0) {
		cout<<"\treason: capacity, size or elements pointer are not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(darray._elements[i]  != array[i]) {
			cout<<"\treason: elements inserted are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool DynamicArrayTest::testSearch() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray(array, size);
	if(darray.search(200) != -1) {
		cout<<"\treason: searching a non-existing element is not correct"<<endl;
		return false;
	}
	if(darray.search(array[3]) != 3) {
		cout<<"\treason: searching an existing element is not correct"<<endl;
		return false;
	}
	return true;
}


bool DynamicArrayTest::testElements() {
	int* elements = nullptr;
	DynamicArray darray;
	elements = darray.elements();
	if(elements != nullptr ) {
		cout<<"\treason: pointer from an empty dynamic array is not correct"<<endl;
		return false;
	}
	elements = nullptr;
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray1(array, size);
	elements = darray1.elements();
	if(elements == nullptr) {
		cout<<"\treason: pointer from a non-empty dynamic array is not correct"<<endl;
		return false;
	}
	for(int i = 0; i<size; i++) {
		if(elements[i] != array[i]) {
			cout<<"\treason: elements from a non-empty dynamic array are not correct"<<endl;
			return false;
		}
	}
	if( elements != nullptr) {
		delete [] elements;
	}
	return true;
}


bool DynamicArrayTest::testErase() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	int erased = 2;
	DynamicArray darray(array, size);
	darray.erase(array[erased]);
	if(darray._size != size-1 || darray._capacity != size) {
		cout<<"\treason: size or capacity after erase is not correct"<<endl;
		return false;
	}
	for(int i = 0; i<erased; i++) {
		if( darray._elements[i] != array[i] ) {
			cout<<"\treason: elements before the erased element are not correct"<<endl;
			return false;
		}
	}

	for (int i = erased; i<size-1; i++) {
		if(darray._elements[i] != array[i+1] ){
			cout<<"\treason: elements after the erased element are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testClear() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray(array, size);
	
	if(darray._size != size || darray._capacity != size || darray._elements == nullptr) {
		cout<<"\treason: size or capacity or elements pointer before clear is not correct"<<endl;
		return false;
	}
	darray.clear();
	if(darray._size != 0 || darray._capacity != size || darray._elements == nullptr) {
		cout<<"\treason: size or capacity or elements pointer after clear is not correct"<<endl;
		return false;
	}
	return true;
}


bool DynamicArrayTest::testCopyAssignment() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	DynamicArray darray(array, size);
	DynamicArray copy;
	
	copy = darray;

	if (copy._capacity != size || copy._size != size || copy._elements == 0) {
		cout<<"\treason: size or capacity or elements pointer of the copy assigned dynamic array is not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(copy._elements[i]  != array[i]) {
			cout<<"\treason: elements of the copy assigned dynamic array are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool DynamicArrayTest::testMoveAssignment() {
	DynamicArray darray;
		
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	
	darray = std::move(DynamicArray(array, size));
	if (darray._capacity != size || darray._size != size || darray._elements == 0) {
		cout<<"\treason: size or capacity or elements pointer of the move assigned dynamic array is not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(darray._elements[i]  != array[i]) {
			cout<<"\treason: elements of the move assigned dynamic array are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool DynamicArrayTest::testPrefixIncrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray1(array, size);
	DynamicArray darray2 = ++darray1;
	for( int i = 0; i<size; i++) {
		if(darray1._elements[i]  != array[i] +1) {
			cout<<"\treason: elements of the calling dynamic array are not incremented"<<endl;
			return false;
		}
	}
	for( int i = 0; i<size; i++) {
		if(darray2._elements[i]  != array[i] +1) {
			cout<<"\treason: elements of the assigned dynamic array are not incremented"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testPostfixIncrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray1(array, size);
	DynamicArray darray2 = darray1++;
	for( int i = 0; i<size; i++) {
		if(darray1._elements[i]  != array[i] + 1) {
			cout<<"\treason: elements of the calling dynamic array are not incremented"<<endl;
			return false;
		}
	}

	for( int i = 0; i<size; i++) {
		if(darray2._elements[i]  != array[i]) {
			cout<<"\treason: elements of the assigned dynamic array are not equal to the elements before the increment"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testPrefixDecrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray1(array, size);
	DynamicArray darray2 = --darray1;
	for( int i = 0; i<size; i++) {
		if(darray1._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the calling dynamic array are not decremented"<<endl;
			return false;
		}
	}
	for( int i = 0; i<size; i++) {
		if(darray2._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the assigned dynamic array are not decremented"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testPostfixDecrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray1(array, size);
	DynamicArray darray2 = darray1--;
	for( int i = 0; i<size; i++) {
		if(darray1._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the calling dynamic array are not decremented"<<endl;
			return false;
		}
	}

	for( int i = 0; i<size; i++) {
		if(darray2._elements[i]  != array[i]) {
			cout<<"\treason: elements of the assigned dynamic array are not equal to the elements before the decrement"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testAddOperator() {
	int size1 = 5;
	int array1[size1] = {10, 20, 30, 40, 50};
	int array2[size1] = {10, 20, 30, 40, 50};
	DynamicArray darray1(array1, size1);
	DynamicArray darray2(array2, size1);
	DynamicArray darray = darray1 + darray2;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size, or the elements pointer of the returned dynamic array is not correct with same size operands"<<endl;
		return false;
	}
	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array1[i] + array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the summation of the elemnts of the operands with same size operands"<<endl;
			return false;
		}
	}

	int size3 = 10;
	int array3[size3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	DynamicArray darray3(array3, size3);
	darray = darray3 + darray2;
	if(darray._capacity != size3 || darray._size != size3 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size left operand"<<endl;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array3[i] + array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the summation of the elements of the operands with larger size left operand"<<endl;
			return false;
		}
	}

	for(int i = size1; i < size3; i++) {
		if(darray._elements[i] != array3[i]) {
			cout<<"\treason: elements of the returned dynamic array are not equal to the elements of left operand with larger size left operand"<<endl;
			return false;
		}
	}

	darray = darray2 + darray3;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size right operand"<<endl;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array2[i] + array3[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the summation of the elements of the operands with larger size right operand"<<endl;
			return false;
		}
	}

	return true;
}


bool DynamicArrayTest::testSubtractOperator() {
	int size1 = 5;
	int array1[size1] = {20, 40, 60, 80, 100};
	int array2[size1] = {10, 20, 30, 40, 50};
	DynamicArray darray1(array1, size1);
	DynamicArray darray2(array2, size1);
	DynamicArray darray = darray1 - darray2;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with same size operands"<<endl;
		return false;
	}
	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array1[i] - array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the subtraction of the elemnts of the operands with same size operands"<<endl;
			return false;
		}
	}

	int size3 = 10;
	int array3[size3] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
	DynamicArray darray3(array3, size3);
	darray = darray3 - darray2;
	if(darray._capacity != size3 || darray._size != size3 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size left operand"<<endl;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array3[i] - array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the subtraction of the elements of the operands with larger size left operand"<<endl;
			return false;
		}
	}

	for(int i = size1; i < size3; i++) {
		if(darray._elements[i] != array3[i]) {
			cout<<"\treason: elements of the returned dynamic array are not equal to the elements of left operand with larger size left operand"<<endl;
			return false;
		}
	}

	darray = darray2 - darray3;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size right operand"<<endl;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array2[i] - array3[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the subtraction of the elements of the operands with larger size right operand"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testMultiplyOperator() {
	int size1 = 5;
	int array1[size1] = {10, 20, 30, 40, 50};
	int array2[size1] = {10, 20, 30, 40, 50};
	DynamicArray darray1(array1, size1);
	DynamicArray darray2(array2, size1);
	DynamicArray darray = darray1 * darray2;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with same size operands"<<endl;
		return false;
	}
	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array1[i] * array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the multiplication of the elemnts of the operands with same size operands"<<endl;
			return false;
		}
	}

	int size3 = 10;
	int array3[size3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	DynamicArray darray3(array3, size3);
	darray = darray3 * darray2;
	if(darray._capacity != size3 || darray._size != size3 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size left operand"<<endl;
		return false;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array3[i] * array2[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the multiplication of the elements of the operands with larger size left operand"<<endl;
			return false;
		}
	}

	for(int i = size1; i < size3; i++) {
		if(darray._elements[i] != array3[i]) {
			cout<<"\treason: elements of the returned dynamic array are not equal to the elements of left operand with larger size left operand"<<endl;
			return false;
		}
	}

	darray = darray2 * darray3;
	if(darray._capacity != size1 || darray._size != size1 || darray._elements == nullptr) {
		cout<<"\treason: capacity, size or the elements pointer of the returned dynamic array is not correct with larger size right operand"<<endl;
		return false;
	}

	for(int i = 0; i < size1; i++) {
		if(darray._elements[i] != (array2[i] * array3[i])) {
			cout<<"\treason: elements of the returned dynamic array are not the multiplication of the elements of the operands with larger size right operand"<<endl;
			return false;
		}
	}
	return true;
}


bool DynamicArrayTest::testEqualOperator() {
	int size1 = 5;
	int array1[size1] = {10, 20, 30, 40, 50};
	int array2[size1] = {10, 20, 30, 40, 50};
	DynamicArray darray1(array1, size1);
	DynamicArray darray2(array2, size1);
	if(!(darray1==darray2)) {
		cout<<"\treason: returns false when two operands have same size and same elements in the same order"<<endl;
		return false;
	}
	int array3[size1] = {50, 40, 30, 20, 10};
	DynamicArray darray3(array3, size1);
	if(darray1==darray3) {
		cout<<"\treason: returns true when two operands have same size and same elements but in different order"<<endl;
		return false;
	}
	int size4 = 10;
	int array4[size4] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	DynamicArray darray4(array4, size4);
	if(darray4==darray1) {
		cout<<"\treason: returns true when two operands have different size and some same elements but many different elements"<<endl;
		return false;
	}
	return true;
}


bool DynamicArrayTest::testIndexOperator() {
	int size = 5;
	int array[size] = {10, 20, 30, 40, 50};
	DynamicArray darray(array, size);
	if(darray[3] != array[3]) {
		cout<<"\treason: does not return the correct element value from the index"<<endl;
		return false;
	}
	return true;
}


bool DynamicArrayTest::testIndexReferenceOperator() {
	int size = 5;
	int array[size] = {10, 20, 30, 40, 50};
	DynamicArray darray(array, size);
	darray[3] = 100;
	if(darray[3] != 100) {
		cout<<"\treason: does not assign the correct element value at the index"<<endl;
		return false;
	}
	return true;
}


bool DynamicArrayTest::testExtractorOperator() {
	const char* inputFile = "test/resource/input.txt";
	ifstream input(inputFile);
	if(input) {
		DynamicArray darray;
		int size = 26;
		int array[] = {10, 10, 20, 20, 30, 40, 40, 50, 60, 60, 70, 80, 
			80, 90, 100, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
		
		input>>darray;
		input.close();

		if(darray._capacity != 4*DEFAULT_CAPACITY || darray._size != size || darray._elements == nullptr) {
			cout<<"\treason: capcity, size, or elements pointer after the extraction is not correct"<<endl;
			return false;
		}

		for(int i = 0; i<size; i++) {
			if(darray._elements[i] != array[i]) {
				cout<<"\treason: elements extracted from the file are not correct"<<endl;
				return false;
			}
		}
	}

	return true;
}


bool DynamicArrayTest::testInserterOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	DynamicArray darray(array, size);
	cout<<endl;
	cout<<darray;
	cout<<endl;
	return true;
}


bool DynamicArrayTest::testLoad() {
	DynamicArray darray;
	int size = 26;
	int array[] = {10, 10, 20, 20, 30, 40, 40, 50, 60, 60, 70, 80, 
		80, 90, 100, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
	
	load("test/resource/input.txt", darray);
	
	if(darray._capacity != 4*DEFAULT_CAPACITY || darray._size != size || darray._elements == nullptr) {
		cout<<"\treason: capcity, size, or elements pointer after the load is not correct"<<endl;
		return false;
	}

	for(int i = 0; i<size; i++) {
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: elements loaded from the file are not correct"<<endl;
			return false;
		}
	}
	
	return true;
}


bool isArrayInFile(const int* array, const int size, const char* file) {
	std::ifstream in(file);
	if(!file) {
		return false;
	}
	int count = 0;
	int element;
	while (in>>element) {
		if(count > (size-1) || array[count] != element) {
			cout<<"\treason: elements saved in the file are not correct"<<endl;
			return false;
		}
		count++;
	}
	in.close();
	return true;
}


bool DynamicArrayTest::testSave() {
	int size = 26;
	int array[] = {10, 10, 20, 20, 30, 40, 40, 50, 60, 60, 70, 80, 
		80, 90, 100, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
	DynamicArray darray(array, size);
	save(darray, "test/resource/arrayoutput.txt");
	return isArrayInFile(darray._elements, size, "test/resource/arrayoutput.txt");
}





BOOST_AUTO_TEST_SUITE(dynamic_array_int_test_suite)

BOOST_AUTO_TEST_CASE(dynamic_array_int_test_case) {

	/*
	 * Default constructor
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testDefaultConstructor(), "TEST: DynamicArray - default_constructor()");
	

	/*
	 * Regular constructor
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testRegularConstructor(), "TEST: DynamicArray - regular_constructor()");
	

	/*
	 * Overloaded regular constructor
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testOverloadedRegularConstructor(), "TEST: DynamicArray - overloaded_constructor()");
	

	/*
	 * Copy constructor
	 */
	
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testCopyConstructor(), "TEST: DynamicArray - copy_constructor()");
	
	/*
	 * Move constructor
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testMoveConstructor(), "TEST: DynamicArray - move_constructor()");

	/*
	 * Size function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testSize(), "TEST: DynamicArray - size()");

	/*
	 * Capacity function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testCapacity(), "TEST: DynamicArray - capacity()");

	/*
	 * Emoty function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testEmpty(), "TEST: DynamicArray - empty()");


	/*
	 * Insert function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testInsert(), "TEST: DynamicArray - insert()");
	
	/*
	 * Overloaded Insert function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testOverloadedInsert(), "TEST: DynamicArray - overloaded_insert()");

	/*
	 * Search function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testSearch(), "TEST: DynamicArray - search()");
	
	/*
	 * Elements function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testElements(), "TEST: DynamicArray - elements()");

	/*
	 * Erase function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testErase(), "TEST: DynamicArray - erase()");

	/*
	 * Clear function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testClear(), "TEST: DynamicArray - clear()");
	
	/*
	 * Copy assignment operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testCopyAssignment(), "TEST: DynamicArray - copy_assignment() or operator = lvalue");
	
	/*
	 * Move assignment operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testMoveAssignment(), "TEST: DynamicArray - move_assignment() or operator = rvalue");
	
	/*
	 * Prefix Increment operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testPrefixIncrementOperator(), "TEST: DynamicArray - operator ++ prefix ");
	
	/*
	 * Postfix Increment operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testPostfixIncrementOperator(), "TEST: DynamicArray - operator ++ postfix");

	/*
	 * Prefix Decrement operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testPrefixDecrementOperator(), "TEST: DynamicArray - operator -- prefix");

	/*
	 * Postfix Decrement operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testPostfixDecrementOperator(), "TEST: DynamicArray - operator -- postfix");
	
	/*
	 * Add operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testAddOperator(), "TEST: DynamicArray - operator + ");
	
	/*
	 * Subtract operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testSubtractOperator(), "TEST: DynamicArray - operator - ");
	
	/*
	 * Multiply operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testMultiplyOperator(), "TEST: DynamicArray - operator * ");
	
	/*
	 * Equal operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testEqualOperator(), "TEST: DynamicArray - operator == ");
	

	/*
	 * Index Operators
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testIndexOperator(), "TEST: DynamicArray - operator [] ");
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testIndexReferenceOperator(), "TEST: DynamicArray - operator [] reference");
	
	
	/*
	 * Extractor operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testExtractorOperator(), "TEST: DynamicArray - operator >> ");
	
	/*
	 * Inseter operator
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testInserterOperator(), "TEST: DynamicArray - operator << ");
	

}


BOOST_AUTO_TEST_CASE(dynamic_array_int_utility_test_case) {
	
	/*
	 * Load function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testLoad(), "TEST: Utility - load()");
	
	/*
	 * Save function
	 */
	BOOST_CHECK_MESSAGE(DynamicArrayTest::testSave(), "TEST: Utility - save()");
	
}


BOOST_AUTO_TEST_SUITE_END()

	

	
