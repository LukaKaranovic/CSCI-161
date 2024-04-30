/**
 * @file - simplesettests.cpp
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.1
 * @date - March 09, 2024
 *
 * Performs unit test on the functions of SimpleSet class.
 *
 */


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment4_simple_set

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <fstream>

#include "dynamicarray.h"
#include "simpleset.h"
#include "simplesettest.h"
#include "utility.h"


using namespace std;


bool SimpleSetTest::testDefaultConstructor(){
	SimpleSet simpleset;
	if(simpleset._capacity != DEFAULT_CAPACITY ) {
		cout<<"\treason: capacity is not initialized properly"<<endl;
		return false;
	} 
	if(simpleset._size != 0 ) {
		cout<<"\treason: size is not initialized properly"<<endl;
		return false;
	}
	if(simpleset._elements == nullptr ) {
		cout<<"\treason: elements pointer is not initialized properly"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testRegularConstructor(){
	int testCapacity = 5;
	SimpleSet simpleset(testCapacity);
	if(simpleset._capacity != testCapacity ) {
		cout<<"\treason: capacity is not initialized properly"<<endl;
		return false;
	} 
	if(simpleset._size != 0 ) {
		cout<<"\treason: size is not initialized properly"<<endl;
		return false;
	}
	if(simpleset._elements == nullptr ) {
		cout<<"\treason: elements pointer is not initialized properly"<<endl;
		return false;
	}

	return true;
}


bool SimpleSetTest::testOverloadedRegularConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset(array, size);

	if (simpleset._capacity != size || simpleset._size != size || simpleset._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer are not initialized properly"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(simpleset._elements[i]  != array[i]) {
			cout<<"\treason: elements of simple set are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testCopyConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset(array, size);

	SimpleSet copy(simpleset);

	if (copy._capacity != size || copy._size != size || copy._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer are not initialized properly in the copy constructed simple set"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(copy._elements[i]  != array[i]) {
			cout<<"\treason: elements of the copy constructed simple set are not correct"<<endl;
			return false;
		}
	}
	return true;

}


bool SimpleSetTest::testMoveConstructor() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	
	SimpleSet simpleset = std::move(SimpleSet(array, size));
	if (simpleset._capacity != size || simpleset._size != size || simpleset._elements == 0) {
		cout<<"\treason: capacity, size and elements pointer of the move constructed simple set are not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(simpleset._elements[i]  != array[i]) {
			cout<<"\treason: elements of the move constructed simple set are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testSize() {
	SimpleSet simpleset1;
	
	if (simpleset1.size() != 0) {
		cout<<"\treason: deafult size is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	SimpleSet simpleset2(array, size);
	
	if (simpleset2.size() != size) {
		cout<<"\treason: custom size is not correct"<<endl;
		return false;
	}

	return true;
}


bool SimpleSetTest::testCapacity() {
	SimpleSet simpleset1;
	
	if (simpleset1.capacity() != DEFAULT_CAPACITY) {
		cout<<"\treason: deafult capacity is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	SimpleSet simpleset2(array, size);
	
	if (simpleset2.capacity() != size) {
		cout<<"\treason: custom capacity is not correct"<<endl;
		return false;
	}

	return true;
}


bool SimpleSetTest::testEmpty() {
	SimpleSet simpleset1;
	
	if (simpleset1.empty() != true) {
		cout<<"\treason: empty true is not correct"<<endl;
		return false;
	}
	
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	SimpleSet simpleset2(array, size);
	
	if (simpleset2.empty() != false) {
		cout<<"\treason: empty false is not correct"<<endl;
		return false;
	}

	return true;
}


bool SimpleSetTest::testInsert() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	int capacity = 5;

	SimpleSet simpleset(capacity);

	for ( int i = 0 ; i<size; i++) {
		simpleset.insert(array[i]);
		if(i < capacity -1 && simpleset._capacity != capacity ) {
			cout<<"\treason: capacity after inserting within the capacity is not correct"<<endl;
			return false;
		}
		if(i > capacity -1 && simpleset._capacity != 2*capacity ) {
			cout<<"\treason: capacity after inserting beyond the capacity is not correct"<<endl;
			return false;
		}
		if(simpleset._size != i+1) {
			cout<<"\treason: size after insertion is not correct"<<endl;
			return false;
		}
		if(simpleset._elements[i] != array[i]) {
			cout<<"\treason: element after insertion is not correct"<<endl;
			return false;
		}
	}

	simpleset.insert(array[1]);

	if(simpleset._size != size) {
		cout<<"\treason: duplicate insertion did happen"<<endl;
		return false;
	}

	simpleset.insert(array[1]+1);

	if(simpleset._size != size+1 || simpleset._elements[size] != array[1]+1) {
		cout<<"\treason: non-duplicate insertion did not happen"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testOverloadedInsert() {
	int array[] = {100, 105, 110, 115, 120, 125, 130, 130};
	int size = 8;
	int capacity = 5;
	SimpleSet simpleset(capacity);
	simpleset.insert(array, size);
	if (simpleset._capacity != 2*capacity || simpleset._size != size-1 || simpleset._elements == 0) {
		cout<<"\treason: capacity, size or elements pointer are not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size-1; i++) {
		if(simpleset._elements[i]  != array[i]) {
			cout<<"\treason: elements inserted are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool SimpleSetTest::testSearch() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset(array, size);
	if(simpleset.search(200) != -1) {
		cout<<"\treason: searching a non-existing element is not correct"<<endl;
		return false;
	}
	if(simpleset.search(array[3]) != 3) {
		cout<<"\treason: searching an existing element is not correct"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testElements() {
	SimpleSet simpleset;
	int* elements = nullptr;
	elements = simpleset.elements();
	if(elements != nullptr ) {
		cout<<"\treason: pointer from an empty simple set is not correct"<<endl;
		return false;
	}
	elements = nullptr;

	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset1(array, size);
	elements = simpleset1.elements();
	if(elements == nullptr) {
		cout<<"\treason: pointer from a non-empty simple set is not correct"<<endl;
		return false;
	}
	for(int i = 0; i<size; i++) {
		if(elements[i] != array[i]) {
			cout<<"\treason: elements from a non-empty simple set are not correct"<<endl;
			return false;
		}
	}
	if( elements != nullptr) {
		delete [] elements;
	}
	return true;
}


bool SimpleSetTest::testErase() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	int erased = 2;
	SimpleSet simpleset(array, size);
	simpleset.erase(array[erased]);
	if(simpleset._size != size-1 || simpleset._capacity != size) {
		cout<<"\treason: size or capacity after erase is not correct"<<endl;
		return false;
	}
	for(int i = 0; i<erased; i++) {
		if( simpleset._elements[i] != array[i] ) {
			cout<<"\treason: elements before the erased element are not correct"<<endl;
			return false;
		}
	}

	for (int i = erased; i<size-1; i++) {
		if(simpleset._elements[i] != array[i+1] ){
			cout<<"\treason: elements after the erased element are not correct"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testClear() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset(array, size);
	
	if(simpleset._size != size || simpleset._capacity != size || simpleset._elements == nullptr) {
		cout<<"\treason: size or capacity or elements pointer before clear is not correct"<<endl;
		return false;
	}
	simpleset.clear();
	if(simpleset._size != 0 || simpleset._capacity != size || simpleset._elements == nullptr) {
		cout<<"\treason: size or capacity or elements pointer after clear is not correct"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testCopyAssignment() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;

	SimpleSet simpleset(array, size);
	SimpleSet copy;

	copy = simpleset;

	if (copy._capacity != size || copy._size != size || copy._elements == 0) {
		cout<<"\treason: size or capacity or elements pointer of the copy assigned simple set is not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(copy._elements[i]  != array[i]) {
			cout<<"\treason: elements of the copy assigned simple set are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool SimpleSetTest::testMoveAssignment() {
	SimpleSet simpleset;
		
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	
	simpleset = std::move(SimpleSet(array, size));
	if (simpleset._capacity != size || simpleset._size != size || simpleset._elements == 0) {
		cout<<"\treason: size or capacity or elements pointer of the move assigned simple set is not correct"<<endl;
		return false;
	}
	for( int i = 0; i<size; i++) {
		if(simpleset._elements[i]  != array[i]) {
			cout<<"\treason: elements of the move assigned simple set are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool SimpleSetTest::testPrefixIncrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset1(array, size);
	SimpleSet simpleset2 = ++simpleset1;
	for( int i = 0; i<size; i++) {
		if(simpleset1._elements[i]  != array[i] +1) {
			cout<<"\treason: elements of the calling simple set are not incremented"<<endl;
			return false;
		}
	}
	for( int i = 0; i<size; i++) {
		if(simpleset2._elements[i]  != array[i] +1) {
			cout<<"\treason: elements of the assigned simple set are not incremented"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testPostfixIncrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset1(array, size);
	SimpleSet simpleset2 = simpleset1++;
	for( int i = 0; i<size; i++) {
		if(simpleset1._elements[i]  != array[i] + 1) {
			cout<<"\treason: elements of the calling simple set are not incremented"<<endl;
			return false;
		}
	}

	for( int i = 0; i<size; i++) {
		if(simpleset2._elements[i]  != array[i]) {
			cout<<"\treason: elements of the assigned simple set are not equal to the elements before the increment"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testPrefixDecrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset1(array, size);
	SimpleSet simpleset2 = --simpleset1;
	for( int i = 0; i<size; i++) {
		if(simpleset1._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the calling simple set are not decremented"<<endl;
			return false;
		}
	}
	for( int i = 0; i<size; i++) {
		if(simpleset2._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the assigned simple set are not decremented"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testPostfixDecrementOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset1(array, size);
	SimpleSet simpleset2 = simpleset1--;
	for( int i = 0; i<size; i++) {
		if(simpleset1._elements[i]  != array[i] - 1) {
			cout<<"\treason: elements of the calling simple set are not decremented"<<endl;
			return false;
		}
	}

	for( int i = 0; i<size; i++) {
		if(simpleset2._elements[i]  != array[i]) {
			cout<<"\treason: elements of the assigned simple set are not equal to the elements before the decrement"<<endl;
			return false;
		}
	}
	return true;
}


bool SimpleSetTest::testAddOperator() {
	int size1 = 5;
	int array1[size1] = {10, 20, 30, 40, 50};
	SimpleSet simpleset1(array1, size1);
	SimpleSet simpleset2(array1, size1);
	SimpleSet simpleset = simpleset1 + simpleset2;
	if(simpleset._capacity != size1 || simpleset._size != size1 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set union operation with same set operands are not correct"<<endl;
		return false;
	}
	for(int i = 0; i < size1; i++) {
		if(simpleset._elements[i] != array1[i]) {
			cout<<"\treason: elements of returned simple set after set union operation with same set operands are not correct"<<endl;
			return false;
		}
	}

	int size2 = 5;
	int array2[size2] = {60, 70, 80, 90, 100};
	SimpleSet simpleset3(array2, size2);
	simpleset = simpleset2 + simpleset3;
	if(simpleset._capacity != size1 + size2 || simpleset._size != size1 + size2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set union operation with mutually exclusive set operands are not correct"<<endl;
		return false;
	}
	
	for(int i = 0; i < size1; i++) {
		if(simpleset._elements[i] != array1[i]) {
			cout<<"\treason: elements of returned simple set after set union operation with mutually exclusive set operands are not correct"<<endl;
			return false;
		}
	}

	for(int i = size1; i < size1+size2; i++) {
		if(simpleset._elements[i] != array2[i-size1]) {
			cout<<"\treason: elements of returned simple set after set union operation with mutually exclusive set operands are not correct"<<endl;
			return false;
		}
	}

	int size3 = 10;
	int array3[size3] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	SimpleSet simpleset4(array3, size3);
	simpleset = simpleset1 + simpleset4;
	if(simpleset._capacity != size3 || simpleset._size != size3 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set union operation with set operands, where the first one is subset of the second one, are not correct"<<endl;
		return false;
	}

	for(int i = 0; i < size3; i++) {
		if(simpleset._elements[i] != array3[i]) {
			cout<<"\treason: elements of returned simple set after set union operation with set operands, where the first one is subset of the second one, elements are not correct"<<endl;
			return false;
		}
	}

	simpleset = simpleset4 + simpleset1;
	if(simpleset._capacity != size3 || simpleset._size != size3 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set union operation with set operands, where the second one is subset of the first one, are not correct"<<endl;
		return false;
	}

	for(int i = 0; i < size3; i++) {
		if(simpleset._elements[i] != array3[i]) {
			cout<<"\treason: elements of returned simple set after set union operation with set operands, where the second one is subset of the first one, elements are not correct"<<endl;
			return false;
		}
	}


	return true;
}


bool SimpleSetTest::testSubtractOperator() {
	int size1 = 10;
	int array1[size1] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size2 = 5;
	int array2[size2] = {10, 20, 30, 40, 50};
	SimpleSet simpleset1(array1, size1);
	SimpleSet simpleset2(array2, size2);
	SimpleSet simpleset = simpleset1 - simpleset2;
	if(simpleset._capacity != size1 || simpleset._size != size2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set difference operation with set operands, where the second one is subset of the first one, are not correct"<<endl;
		return false;
	}
	for(int i = 0; i < size2; i++) {
		if(simpleset._elements[i] != array1[i+size2]) {
			cout<<"\treason: elements of returned simple set after set difference operation with set operands, where the second one is subset of the first one, elements are not correct"<<endl;
			return false;
		}
	}

	simpleset = simpleset2 - simpleset1;
	if(simpleset._capacity != size2 || simpleset._size != 0 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set difference operation with set operands, where the first one is subset of the second one, are not correct"<<endl;
		return false;
	}

	int size3 = 10;
	int array3[size3] = {60, 70, 80, 90, 100};
	SimpleSet simpleset3(array3, size3);
	simpleset = simpleset2 - simpleset3;
	if(simpleset._capacity != size2 || simpleset._size != size2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set difference operation with mutually exclusive set operands are not correct"<<endl;
		return false;
	}

	for(int i = 0; i < size2; i++) {
		if(simpleset._elements[i] != array2[i]) {
			cout<<"\treason: elements of returned simple set after set difference operation with mutually exclusive set operands are not correct"<<endl;
			return false;
		}
	}

	int size4 = 5;
	int array4[size4] = {-10, -20, 30, 40, -50,};
	SimpleSet simpleset4(array4, size4);
	simpleset = simpleset1 - simpleset4;
	if(simpleset._capacity != size1 || simpleset._size != size1-2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set difference operation with mutually non-exclusive set operands are not correct"<<endl;
		return false;
	}


	for(int i = 0; i < 2; i++) {
		if(simpleset._elements[i] != array1[i]) {
			cout<<"\treason: elements of returned simple set after set difference operation with mutually non-exclusive set operands are not correct"<<endl;
			return false;
		}
	}

	for(int i = 2; i < size1-2; i++) {
		if(simpleset._elements[i] != array1[i+2]) {
			cout<<"\treason: elements of returned simple set after set difference operation with mutually non-exclusive set operands are not correct"<<endl;
			return false;
		}
	}

	return true;
}


bool SimpleSetTest::testMultiplyOperator() {
	int size1 = 10;
	int array1[size1] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size2 = 5;
	int array2[size2] = {10, 20, 30, 40, 50};
	SimpleSet simpleset1(array1, size1);
	SimpleSet simpleset2(array2, size2);
	SimpleSet simpleset = simpleset1 * simpleset2;
	if(simpleset._capacity != size1 || simpleset._size != size2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set intersection operation with set operands, where the second one is subset of the first one, are not correct"<<endl;
		return false;
	}
	for(int i = 0; i < size2; i++) {
		if(simpleset._elements[i] != array1[i]) {
			cout<<"\treason: elements of returned simple set after set intersection operation with set operands, where the second one is subset of the first one, are not correct"<<endl;
			return false;
		}
	}

	simpleset = simpleset2 * simpleset1;
	if(simpleset._capacity != size2 || simpleset._size != size2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set intersection operation with set operands, where the first one is subset of the second one, are not correct"<<endl;
		return false;
	}

	for(int i = 0; i < size2; i++) {
		if(simpleset._elements[i] != array2[i]) {
			cout<<"\treason: elements of returned simple set after set intersection operation with set operands, where the first one is subset of the second one, are not correct"<<endl;
			return false;
		}
	}

	int size3 = 10;
	int array3[size3] = {60, 70, 80, 90, 100};
	SimpleSet simpleset3(array3, size3);
	simpleset = simpleset2 * simpleset3;
	if(simpleset._capacity != size2 || simpleset._size != 0 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set intersection operation with mutually exclusive set operands are not correct"<<endl;
		return false;
	}

	
	int size4 = 5;
	int array4[size4] = {-10, -20, 30, 40, -50,};
	SimpleSet simpleset4(array4, size4);
	simpleset = simpleset1 * simpleset4;
	if(simpleset._capacity != size1 || simpleset._size != 2 || simpleset._elements == nullptr) {
		cout<<"\treason: capacity, size, and elements pointer of returned simple set after set intersection operation with mutually non-exclusive set operands are not correct"<<endl;
		return false;
	}

	for(int i = 0; i < 2; i++) {
		if(simpleset._elements[i] != array1[i+2]) {
			cout<<"\treason: elements of returned simple set after set intersection operation with mutually non-exclusive set operands are not correct"<<endl;
			return false;
		}
	}
	
	return true;
}


bool SimpleSetTest::testEqualOperator() {
	int size1 = 5;
	int array1[size1] = {10, 20, 30, 40, 50};
	int array2[size1] = {10, 20, 30, 40, 50};
	SimpleSet simpleset1(array1, size1);
	SimpleSet simpleset2(array2, size1);
	if(!(simpleset1==simpleset2)) {
		cout<<"\treason: returns false when two operands have same size and same elements in the same order"<<endl;
		return false;
	}
	int array3[size1] = {50, 40, 30, 20, 10};
	SimpleSet simpleset3(array3, size1);
	if(!(simpleset1==simpleset3)) {
		cout<<"\treason: returns false when two operands have same size and same elements but in different order"<<endl;
		return false;
	}
	int size4 = 10;
	int array4[size1] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	SimpleSet simpleset4(array4, size4);
	if(simpleset4==simpleset1) {
		cout<<"\treason: returns true when two operands have different size and some same elements but many different elements"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testIndexOperator() {
	int size = 5;
	int array[size] = {10, 20, 30, 40, 50};
	SimpleSet simpleset(array, size);
	if(simpleset[3] != array[3]) {
		cout<<"\treason: does not return the correct element value from the index"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testIndexReferenceOperator() {
	int size = 5;
	int array[size] = {10, 20, 30, 40, 50};
	SimpleSet simpleset(array, size);
	simpleset[3] = 100;
	if(simpleset[3] != 100) {
		cout<<"\treason: does not assign the correct element value at the index"<<endl;
		return false;
	}
	return true;
}


bool SimpleSetTest::testExtractorOperator() {
	const char* inputFile = "test/resource/input.txt";
	ifstream input(inputFile);
	if(input) {
		SimpleSet simpleset;
		int size = 20;
		int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
		
		input>>simpleset;
		input.close();

		if(simpleset._capacity != 2*DEFAULT_CAPACITY || simpleset._size != size || simpleset._elements == nullptr) {
			cout<<"\treason: capcity, size, or elements pointer after the extraction is not correct"<<endl;
			return false;
		}

		for(int i = 0; i<size; i++) {
			if(simpleset._elements[i] != array[i]) {
				cout<<"\treason: elements extracted from the file are not correct"<<endl;
				return false;
			}
		}
	}

	return true;
}


bool SimpleSetTest::testInserterOperator() {
	int array[] = {100, 105, 110, 115, 120, 125, 130};
	int size = 7;
	SimpleSet simpleset(array, size);
	cout<<endl;
	cout<<simpleset;
	cout<<endl;
	return true;
}


bool SimpleSetTest::testLoad() {
	SimpleSet simpleset;
	int size = 20;
	int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
		
	load("test/resource/input.txt", simpleset);
	
	if(simpleset._capacity != 2*DEFAULT_CAPACITY || simpleset._size != size || simpleset._elements == nullptr) {
		cout<<"\treason: capcity, size, or elements pointer after the load is not correct"<<endl;
		return false;
	}

	for(int i = 0; i<size; i++) {
		if(simpleset._elements[i] != array[i]) {
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


bool SimpleSetTest::testSave() {
	int size = 20;
	int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200 };
	SimpleSet simpleset(array, size);
	save(simpleset, "test/resource/setoutput.txt");
	return isArrayInFile(simpleset._elements, size, "test/resource/setoutput.txt");
}





BOOST_AUTO_TEST_SUITE(simpleset_test_suite)

BOOST_AUTO_TEST_CASE(simpleset_test_case) {

	/*
	 * Default constructor
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testDefaultConstructor(), "TEST: SimpleSet - default_constructor()");
	

	/*
	 * Regular constructor
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testRegularConstructor(), "TEST: SimpleSet - regular_constructor()");
	

	/*
	 * Overloaded regular constructor
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testOverloadedRegularConstructor(), "TEST: SimpleSet - overloaded_constructor()");
	

	/*
	 * Copy constructor
	 */
	
	BOOST_CHECK_MESSAGE(SimpleSetTest::testCopyConstructor(), "TEST: SimpleSet - copy_constructor()");
	
	/*
	 * Move constructor
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testMoveConstructor(), "TEST: SimpleSet - move_constructor()");

	/*
	 * Size function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testSize(), "TEST: SimpleSet - size()");

	/*
	 * Capacity function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testCapacity(), "TEST: SimpleSet - capacity()");

	/*
	 * Emoty function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testEmpty(), "TEST: SimpleSet - empty()");


	/*
	 * Insert function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testInsert(), "TEST: SimpleSet - insert()");
	
	/*
	 * Overloaded Insert function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testOverloadedInsert(), "TEST: SimpleSet - overloaded_insert()");

	/*
	 * Search function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testSearch(), "TEST: SimpleSet - search()");
	
	/*
	 * Elements function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testElements(), "TEST: SimpleSet - elements()");

	/*
	 * Erase function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testErase(), "TEST: SimpleSet - erase()");

	/*
	 * Clear function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testClear(), "TEST: SimpleSet - clear()");
	
	/*
	 * Copy assignment operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testCopyAssignment(), "TEST: SimpleSet - copy_assignment() or operator = lvalue");
	
	/*
	 * Move assignment operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testMoveAssignment(), "TEST: SimpleSet - move_assignment() or operator = rvalue");
	
	/*
	 * Prefix Increment operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testPrefixIncrementOperator(), "TEST: SimpleSet - operator ++ prefix ");
	
	/*
	 * Postfix Increment operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testPostfixIncrementOperator(), "TEST: SimpleSet - operator ++ postfix");

	/*
	 * Prefix Decrement operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testPrefixDecrementOperator(), "TEST: SimpleSet - operator -- prefix");

	/*
	 * Postfix Decrement operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testPostfixDecrementOperator(), "TEST: SimpleSet - operator -- postfix");
	
	/*
	 * Add operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testAddOperator(), "TEST: SimpleSet - operator + ");
	
	/*
	 * Subtract operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testSubtractOperator(), "TEST: SimpleSet - operator - ");
	
	/*
	 * Multiply operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testMultiplyOperator(), "TEST: SimpleSet - operator * ");
	
	/*
	 * Equal operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testEqualOperator(), "TEST: SimpleSet - operator == ");
	

	/*
	 * Index Operators
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testIndexOperator(), "TEST: SimpleSet - operator [] ");
	BOOST_CHECK_MESSAGE(SimpleSetTest::testIndexReferenceOperator(), "TEST: SimpleSet - operator [] reference");
	
	
	/*
	 * Extractor operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testExtractorOperator(), "TEST: SimpleSet - operator >> ");
	
	/*
	 * Inseter operator
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testInserterOperator(), "TEST: SimpleSet - operator << ");
	

}


BOOST_AUTO_TEST_CASE(simpleset_utility_test_case) {
	
	/*
	 * Load function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testLoad(), "TEST: Utility - load()");
	
	/*
	 * Save function
	 */
	BOOST_CHECK_MESSAGE(SimpleSetTest::testSave(), "TEST: Utility - save()");
	
}


BOOST_AUTO_TEST_SUITE_END()

	





	

	
