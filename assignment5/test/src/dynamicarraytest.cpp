/**
 * @file - dynamicarraytests.cpp
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.0
 * @date - July 22, 2020
 *
 * Performs unit test on the functions of DynamicArray template class with integer and double data type.
 *
 */


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment5_dynamic_array

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <fstream>
#include <string>

#include "dynamicarray.cpp"
#include "dynamicarraytest.h"

#define TEST_SIZE 7
#define TEST_CAPACITY 5


using namespace std;
template<typename T>
void DynamicArrayTest<T>::insertArray(T* array, const int size, DynamicArray<T>& darray) {
	for(int i=0; i<size; i++) {
		darray.insert(array[i]);
	}
}


template<typename T>
bool DynamicArrayTest<T>::isSameElements(T* array1, T* array2, const int size) {
	for(int i=0; i<size; i++ ) {
		if( array1[i] != array2[i] ) {
			return false;
		}
	}
	return true;
}


template<typename T>
DynamicArray<T> DynamicArrayTest<T>::createDynamicArray(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);
	return darray;
}


template<typename T>
bool DynamicArrayTest<T>::testDefaultConstructor() {
	DynamicArray<T> darray;
	if(darray._capacity != DEFAULT_CAPACITY ) {
		cout<<"\treason: default capacity is not correct"<<endl;
		return false;
	}

	if(darray._size != 0 ) {
		cout<<"\treason: default size is not correct"<<endl;
		return false;
	}

	if(darray._elements == nullptr ) {
		cout<<"\treason: default elements pointer is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testConstructor() {
	int capacity = 50;
	DynamicArray<T> darray(capacity);
	if(darray._capacity != capacity ) {
		cout<<"\treason: capacity is not correct"<<endl;
		return false;
	}

	if(darray._size != 0 ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}

	if(darray._elements == nullptr ) {
		cout<<"\treason: elements pointer is not correct"<<endl;
		return false;
	}

	return true;

}


template<typename T>
bool DynamicArrayTest<T>::testCapacity() {
	DynamicArray<T> darray1;
	if(darray1.capacity() != DEFAULT_CAPACITY ) {
		cout<<"\treason: default capacity is not correct"<<endl;
		return false;
	}
	const int capacity = 10;
	DynamicArray<T> darray2(capacity);
	if(darray2.capacity() != capacity ) {
		cout<<"\treason: capacity is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testInsert(T* array, const int size) {
	int capacity = size/2;
	DynamicArray<T> darray(capacity);

	int i = 0;
	while(i<capacity) {
		darray.insert(array[i++]);
		if(darray._capacity != capacity) {
			cout<<"\treason: capacity after inserting within the capcity is not correct"<<endl;
			return false;
		}
		if(darray._size != i) {
			cout<<"\treason: size after inserting within the capcity is not correct"<<endl;
			return false;
		}

		if(darray._elements[i-1] != array[i-1]) {
			cout<<"\treason: elements after inserting within the capcity is not correct"<<endl;
			return false;
		}
		
	}

	darray.insert(array[i++]);
	if(darray._capacity != 2*capacity) {
		cout<<"\treason: capacity after inserting beyond the capcity is not correct"<<endl;
		return false;
	}
	if(darray._size != i) {
		cout<<"\treason: size after inserting beyond the capcity is not correct"<<endl;
		return false;
	}
	if(darray._elements[i-1] != array[i-1]) {
			cout<<"\treason: elements after inserting within the capcity is not correct"<<endl;
			return false;
		}

	darray.insert(array[i++]);
	if(darray._capacity != 2*capacity) {
		cout<<"\treason: capacity after inserting beyond the capcity is not correct"<<endl;
		return false;
	}
	if(darray._size != i) {
		cout<<"\treason: size after inserting beyond the capcity is not correct"<<endl;
		return false;
	}
	if(darray._elements[i-1] != array[i-1]) {
			cout<<"\treason: elements after inserting within the capcity is not correct"<<endl;
			return false;
		}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testSize(T* array, const int size) {
	DynamicArray<T> darray(size);
	if(darray.size() != 0 ) {
		cout<<"\treason: default size is not correct"<<endl;
		return false;
	}
	insertArray(array, size, darray);
	if(darray.size() != size ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testEmpty(T* array, const int size) {
	DynamicArray<T> darray;
	if(darray.empty() != true ) {
		cout<<"\treason: empty true is not correct"<<endl;
		return false;
	}
	insertArray(array, size, darray);
	if(darray.empty() != false ) {
		cout<<"\treason: empty false is not correct"<<endl;
		return false;
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testSearch(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);
	if(darray.search(array[0]+array[size-1]) != -1) {
		cout<<"\treason: search non-existing element is not correct"<<endl;
		return false;
	}
	
	if(darray.search(array[0]) != 0 || darray.search(array[size/2]) != size/2 || darray.search(array[size-2]) != size-2) {
		cout<<"\treason: search existing element is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testErase(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);

	darray.erase(array[0]+array[size-1]);
	if(darray._capacity != size || darray._size != size) {
		cout<<"\treason: capacity or size of dynamic array after unsuccesfull erase is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: elements of dynamic array after unsuccessful are not correct"<<endl;
			return false;
		}
	}

	int eraseAt = size/2;
	darray.erase(array[eraseAt]);
	if(darray._capacity != size || darray._size != size-1) {
		cout<<"\treason: capacity or size of dynamic array after erase is not correct"<<endl;
		return false;
	}
	for(int i=0; i<eraseAt; i++) {
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: elements of dynamic array before the erased element are not correct"<<endl;
			return false;
		}
	}
	for(int i=eraseAt; i<size-1; i++) {
		if(darray._elements[i] != array[i+1]) {
			cout<<"\treason: elements of dynamic array after the erased element are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testEraseAt(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);

	try{
		darray.eraseAt(-1);
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	
	if(darray._capacity != size || darray._size != size) {
		cout<<"\treason: capacity or size of dynamic array after unsuccesfull erase is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: elements of dynamic array after unsuccessful are not correct"<<endl;
			return false;
		}
	}
	int eraseAt = size/2;
	darray.eraseAt(eraseAt);
	if(darray._capacity != size || darray._size != size-1) {
		cout<<"\treason: capacity or size of dynamic array after erase is not correct"<<endl;
		return false;
	}
	for(int i=0; i<eraseAt; i++) {
		if(darray._elements[i] != array[i]) {
			cout<<"\treason: elements of dynamic array before the erased element are not correct"<<endl;
			return false;
		}
	}
	for(int i=eraseAt; i<size-1; i++) {
		if(darray._elements[i] != array[i+1]) {
			cout<<"\treason: elements of dynamic array after the erased element are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testClear(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);
	darray.clear();
	if(darray._capacity != size ) {
		cout<<"\treason: capacity after clear is not correct"<<endl;
		return false;
	}
	if(darray._size != 0 ) {
		cout<<"\treason: size after clear is not correct"<<endl;
		return false;
	}
	if(darray._elements == nullptr ) {
		cout<<"\treason: size after clear is not correct"<<endl;
		return false;
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testIndexValue(T* array, const int size) {
	DynamicArray<T> darray(size);
	insertArray(array, size, darray);
	try{
		T value = darray[-1];
		cout<<"value: "<<value<<endl;
	}
	catch(const char* error) {
		cout<<error<<endl;
	}
	if(darray[0] != array[0] || darray[size/2] != array[size/2] || darray[size-1] != array[size-1] ) {
		cout<<"\treason: value at index is not correct"<<endl;
		return false;
	}
	
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testIndexReference(T* array, const int size) {
	DynamicArray<T> darray;
	insertArray(array, size, darray);
	try{
		darray[-1] = array[0] + array[size-1];
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	darray[size/2] = array[0] + array[size-1];
	if(darray[size/2]!= (array[0] + array[size-1]) ) {
		cout<<"\treason: value assigned at index reference is not correct"<<endl;
		return false;
	}
	
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testCopyConstructor(T* array, const int size) {
	DynamicArray<T> darray1(size);
	insertArray(array, size, darray1);
	DynamicArray<T> darray2 = darray1;
	if(darray1._capacity != darray2._capacity) {
		cout<<"\treason: capacity of copy constructed dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._size != darray2._size) {
		cout<<"\treason: size of copy constructed dynamic array is not correct"<<endl;
		return false;
	}
	if(darray2._elements == nullptr || darray2._elements == darray1._elements) {
		cout<<"\treason: elements pointer of copy constructed dynamic array is not correct"<<endl;
		return false;
	}

	if(isSameElements(darray2._elements, array, size) != true ) {
		cout<<"\treason: elements of copy constructed dynamic array are not correct"<<endl;
		return false;
	}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testMoveConstructor(T* array, const int size) {
	DynamicArray<T> darray1 = std::move(createDynamicArray(array, size));
		
	if(darray1._capacity != size) {
		cout<<"\treason: capacity of move constructed dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._size != size) {
		cout<<"\treason: size of move constructed dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._elements == nullptr) {
		cout<<"\treason: elements pointer of move constructed dynamic array is not correct"<<endl;
		return false;
	}

	if(isSameElements(darray1._elements, array, size) != true ) {
		cout<<"\treason: elements of move constructed dynamic array are not correct"<<endl;
		return false;
	}
	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testCopyAssignment(T* array, const int size) {
	DynamicArray<T> darray1(size);
	insertArray(array, size, darray1);
	DynamicArray<T> darray2;
	darray2 = darray1;
	if(darray1._capacity != darray2._capacity) {
		cout<<"\treason: capacity of copy assigned dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._size != darray2._size) {
		cout<<"\treason: size of copy assigned dynamic array is not correct"<<endl;
		return false;
	}
	if(darray2._elements == nullptr || darray2._elements == darray1._elements) {
		cout<<"\treason: elements pointer of copy assigned dynamic array is not correct"<<endl;
		return false;
	}

	if(isSameElements(darray2._elements, array, size) != true ) {
		cout<<"\treason: elements of copy assigned dynamic array are not correct"<<endl;
		return false;
	}

	return true;
}


template<typename T>
bool DynamicArrayTest<T>::testMoveAssignment(T* array, const int size) {
	DynamicArray<T> darray1;
	darray1 = std::move(createDynamicArray(array, size));
		
	if(darray1._capacity != size) {
		cout<<"\treason: capacity of move assigned dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._size != size) {
		cout<<"\treason: size of move assigned dynamic array is not correct"<<endl;
		return false;
	}
	if(darray1._elements == nullptr) {
		cout<<"\treason: elements pointer of move assigned dynamic array is not correct"<<endl;
		return false;
	}

	if(isSameElements(darray1._elements, array, size) != true ) {
		cout<<"\treason: elements of move assigned dynamic array are not correct"<<endl;
		return false;
	}
	return true;
}



BOOST_AUTO_TEST_SUITE(dynamic_array_int_test_suite)

BOOST_AUTO_TEST_CASE(dynamic_array_int_test_case) {
	int size = 7;
	int array[size] = {100, 105, 110, 115, 120, 125, 130};

	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testDefaultConstructor(), "TEST: DynamicArray<int> - default_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testConstructor(), "TEST: DynamicArray<int> - constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testCapacity(), "TEST: DynamicArray<int> - capacity()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testInsert(array, size), "Test: DynamicArray<int> - insert()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testSize(array, size), "Test: DynamicArray<int> - size()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testEmpty(array, size), "Test: DynamicArray<int> - empty()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testSearch(array, size), "Test: DynamicArray<int> - search()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testErase(array, size), "TEST: DynamicArray<int> - erase()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testEraseAt(array, size), "TEST: DynamicArray<int> - eraseAt()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testClear(array, size), "TEST: DynamicArray<int> - clear()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testIndexValue(array, size), "TEST: DynamicArray<int> - index_value()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testIndexReference(array, size), "TEST: DynamicArray<int> - index_reference()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testCopyConstructor(array, size), "Test: DynamicArray<int> - copy_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testMoveConstructor(array, size), "Test: DynamicArray<int> - move_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testCopyAssignment(array, size), "Test: DynamicArray<int> - copy_assignment()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<int>::testMoveAssignment(array, size), "Test: DynamicArray<int> - move_assignment()");
	
}



BOOST_AUTO_TEST_SUITE_END()
	
class WeekDays {
	public:
		WeekDays() {
			days = new string[TEST_SIZE];
			days[0] = "Saturday";
			days[1] = "Sunday";
		    days[2] = "Monday";
		    days[3] = "Tuesday";
		    days[4] = "Wednesday";
		    days[5] = "Thursday";
			days[6] = "Friday";
		}

		~WeekDays() {
			delete [] days;
		} 
		
		string* days;
		const int number_of_days = 7; 
};


	
BOOST_FIXTURE_TEST_SUITE(dynamic_array_string_test_suite, WeekDays)

BOOST_AUTO_TEST_CASE(dynamic_array_string_test_case) {
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testDefaultConstructor(), "TEST: DynamicArray<string> - default_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testConstructor(), "TEST: DynamicArray<string> - constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testCapacity(), "TEST: DynamicArray<string> - capacity()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testInsert(days, number_of_days), "Test: DynamicArray<string> - insert()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testSize(days, number_of_days), "Test: DynamicArray<string> - size()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testEmpty(days, number_of_days), "Test: DynamicArray<string> - empty()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testSearch(days, number_of_days), "Test: DynamicArray<string> - search()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testErase(days, number_of_days), "TEST: DynamicArray<string> - erase()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testEraseAt(days, number_of_days), "TEST: DynamicArray<string> - eraseAt()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testClear(days, number_of_days), "TEST: DynamicArray<string> - clear()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testIndexValue(days, number_of_days), "TEST: DynamicArray<string> - index_value()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testIndexReference(days, number_of_days), "TEST: DynamicArray<string> - index_reference()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testCopyConstructor(days, number_of_days), "Test: DynamicArray<string> - copy_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testMoveConstructor(days, number_of_days), "Test: DynamicArray<string> - move_constructor()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testCopyAssignment(days, number_of_days), "Test: DynamicArray<string> - copy_assignment()");
	BOOST_CHECK_MESSAGE(DynamicArrayTest<string>::testMoveAssignment(days, number_of_days), "Test: DynamicArray<string> - move_assignment()");
	
		
}


BOOST_AUTO_TEST_SUITE_END()

	
