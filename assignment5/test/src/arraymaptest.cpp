/**
 * @file arraymaptest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 24, 2020
 * 
 * Performs unit tests of ArrayMap implementation of Map ADT.
 *
 */
 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment5_array_map_test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "arraymap.cpp"
#include "arraymaptest.h"


using namespace std;

/*
 * Test Fixture  to test ArrayMap
 */
class TestFixture {
	public:
		/*
		 * Data to test ArrayMap<string, string>
		 */
		static const int NUMBER_OF_COUNTRIES = 5;
		string countries[NUMBER_OF_COUNTRIES] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
		string capitals[NUMBER_OF_COUNTRIES] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

		string brazil ="Brazil";
		string brazil_capital ="Brasilia";

		/*
		 * Data to test ArrayMap<int, string>
		 */
		static const int MONTHS = 12;
		int month_numbers[MONTHS] = {1,2,3,4,5,6,7,8,9,10,11,12};
		string month_names[MONTHS] = {"January", "February", "March", "April", "May", "June", 
			"July", "August", "September", "October", "November", "December"};
	
	
	
		/*
		 * Data to test ArrayMap<string, double>
	 	 */
		static const int GRADES = 11;
		string letter_grades[GRADES] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
		double grade_points[GRADES] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};

};

template<typename K, typename V>
void ArrayMapTest<K,V>::putIntoMap(const K* keys, const V* values, const int size, ArrayMap<K,V>& arrayMap) {
	for(int i=0; i<size; i++) {
		arrayMap.put(keys[i], values[i]);
	}
	
}

template<typename K, typename V>
ArrayMap<K,V> ArrayMapTest<K,V>::createArrayMap(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	putIntoMap(keys, values, size, arrayMap);
	return arrayMap;
}

template<typename K, typename V>
bool ArrayMapTest<K,V>::testDefaultConstructor() {
	ArrayMap<K,V> arrayMap;
	if( arrayMap._capacity != DEFAULT_CAPACITY ) {
		cout<<"\treason: default capcity is not correct"<<endl;
		return false;
	}

	if( arrayMap._size != 0 ) {
		cout<<"\treason: default size is not correct"<<endl;
		return false;
	}
	if( arrayMap._entries == nullptr ) {
		cout<<"\treason: default entries pointer is not correct"<<endl;
		return false;
	}
	return true;
}

template<typename K, typename V>
bool ArrayMapTest<K,V>::testConstructor() {
	int capacity = 10;
	ArrayMap<K,V> arrayMap(capacity);
	if( arrayMap._capacity != capacity ) {
		cout<<"\treason: capcity is not correct"<<endl;
		return false;
	}

	if( arrayMap._size != 0 ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}
	if( arrayMap._entries == nullptr ) {
		cout<<"\treason: entries pointer is not correct"<<endl;
		return false;
	}
	return true;
}

template<typename K, typename V>
bool ArrayMapTest<K,V>::testPut(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap._size != size ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap._entries[i]._key != keys[i]) {
			cout<<"\treason: keys put are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i]) {
			cout<<"\treason: values put are not correct"<<endl;
			return false;
		}
	}
	return true;
	
}


template<typename K, typename V>
bool ArrayMapTest<K,V>::testSize(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	if(arrayMap.size() != 0 ) {
		cout<<"\treason: initial size is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap.size() != size ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}
	return true;
	
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testCopyConstructor(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap1(size);
	putIntoMap(keys, values, size, arrayMap1);
	ArrayMap<K,V> arrayMap2 = arrayMap1;
	if(arrayMap2._capacity != size ) {
		cout<<"\treason: capacity of copy constructed array map is not correct"<<endl;
			return false;
	}
	if(arrayMap2._size != size ) {
		cout<<"\treason: size of copy constructed array map is not correct"<<endl;
			return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap2._entries[i]._key != keys[i]) {
			cout<<"\treason: keys of copy constructed array map are not correct"<<endl;
			return false;
		}
		if(arrayMap2._entries[i]._value != values[i]) {
			cout<<"\treason: values of copy constructed array map are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testMoveConstructor(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap = std::move(createArrayMap(keys, values, size));
	
	if(arrayMap._capacity != size ) {
		cout<<"\treason: capacity of move constructed array map is not correct"<<endl;
			return false;
	}
	if(arrayMap._size != size ) {
		cout<<"\treason: size of move constructed array map is not correct"<<endl;
			return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap._entries[i]._key != keys[i]) {
			cout<<"\treason: keys of move constructed array map are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i]) {
			cout<<"\treason: values of move constructed array map are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testCopyAssignment(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap1(size);
	putIntoMap(keys, values, size, arrayMap1);
	ArrayMap<K,V> arrayMap2;
	arrayMap2 = arrayMap1;
	if(arrayMap2._capacity != size ) {
		cout<<"\treason: capacity of copy assigned array map is not correct"<<endl;
			return false;
	}
	if(arrayMap2._size != size ) {
		cout<<"\treason: size of copy assigned array map is not correct"<<endl;
			return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap2._entries[i]._key != keys[i]) {
			cout<<"\treason: keys of copy assigned array map are not correct"<<endl;
			return false;
		}
		if(arrayMap2._entries[i]._value != values[i]) {
			cout<<"\treason: values of copy assigned array map are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testMoveAssignment(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap;
	arrayMap = std::move(createArrayMap(keys, values, size));
	
	if(arrayMap._capacity != size ) {
		cout<<"\treason: capacity of move assigned array map is not correct"<<endl;
			return false;
	}
	if(arrayMap._size != size ) {
		cout<<"\treason: size of move assigned array map is not correct"<<endl;
			return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap._entries[i]._key != keys[i]) {
			cout<<"\treason: keys of move assigned array map are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i]) {
			cout<<"\treason: values of move assigned array map are not correct"<<endl;
			return false;
		}
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testGet(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap.get(keys[0]) != values[0] || arrayMap.get(keys[size/2]) != values[size/2] ||
			arrayMap.get(keys[size-1]) != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testIndex(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap[keys[0]] != values[0] || arrayMap[keys[size/2]] != values[size/2] ||
			arrayMap[keys[size-1]] != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testRemove(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	putIntoMap(keys, values, size, arrayMap);

	try {
		arrayMap.remove(keys[0]+keys[size-1]);
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	if(arrayMap._size != size ) {
		cout<<"\treason: size after unsuccesful remove is not correct"<<endl;
			return false;
	}
	for(int i=0; i<size; i++) {
		if(arrayMap._entries[i]._key != keys[i] ) {
			cout<<"\treason: keys after unsuccesful remove are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i] ) {
			cout<<"\treason: values after unsuccesful remove are not correct"<<endl;
			return false;
		}
	}
	
	int removeAt = size/2;
	arrayMap.remove(keys[removeAt]);
	if(arrayMap._size != size-1 ) {
		cout<<"\treason: size after remove is not correct"<<endl;
			return false;
	}
	for(int i=0; i<removeAt; i++) {
		if(arrayMap._entries[i]._key != keys[i] ) {
			cout<<"\treason: keys before remove index are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i] ) {
			cout<<"\treason: values before remove index are not correct"<<endl;
			return false;
		}
	}
	for(int i=removeAt; i<size-1; i++) {
		if(arrayMap._entries[i]._key != keys[i+1] ) {
			cout<<"\treason: keys after remove index are not correct"<<endl;
			return false;
		}
		if(arrayMap._entries[i]._value != values[i+1] ) {
			cout<<"\treason: values after remove index are not correct"<<endl;
			return false;
		}
	}
	
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testContainsKey(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	if(arrayMap.containsKey(keys[0]) || arrayMap.containsKey(keys[size/2]) || arrayMap.containsKey(keys[size-1])) {
		cout<<"\treason: contains key in an empty array map is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap.containsKey(keys[0]) != true || arrayMap.containsKey(keys[size/2]) != true || arrayMap.containsKey(keys[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty array map is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testContainsValue(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	if(arrayMap.containsValue(values[0]) || arrayMap.containsValue(values[size/2]) || arrayMap.containsValue(values[size-1])) {
		cout<<"\treason: contains value in an empty array map is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, arrayMap);
	if(arrayMap.containsValue(values[0]) != true || arrayMap.containsValue(values[size/2]) != true || arrayMap.containsValue(values[size-1]) != true) {
		cout<<"\treason: contains value in a non-empty array map is not correct"<<endl;
		return false;
	}
	
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testKeys(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	const DynamicArray<K>* mapKeys = arrayMap.keys();
	if(mapKeys != nullptr) {
		cout<<"\treason: keys pointer from an empty map is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, arrayMap);
	mapKeys = arrayMap.keys();
	if(mapKeys == nullptr) {
		cout<<"\treason: keys pointer from a non-empty map is not correct"<<endl;
		return false;
	}
	if(mapKeys->size() != size) {
		cout<<"\treason: keys size is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapKeys)[i] != keys[i] ) {
			cout<<"\treason: keys are not correct"<<endl;
			return false;
		}
	}
	delete mapKeys;
	return true;
}


template<typename K, typename V>
bool ArrayMapTest<K,V>:: testValues(const K* keys, const V* values, const int size) {
	ArrayMap<K,V> arrayMap(size);
	const DynamicArray<V>* mapValues = arrayMap.values();
	if(mapValues != nullptr) {
		cout<<"\treason: values pointer from an empty map is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, arrayMap);
	mapValues = arrayMap.values();
	if(mapValues == nullptr) {
		cout<<"\treason: values pointer from a non-empty map is not correct"<<endl;
		return false;
	}
	if(mapValues->size() != size) {
		cout<<"\treason: values size is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapValues)[i] != values[i] ) {
			cout<<"\treason: values are not correct"<<endl;
			return false;
		}
	}
	delete mapValues;
	return true;
}



BOOST_FIXTURE_TEST_SUITE(assignment5_array_map_test_suite, TestFixture)

	BOOST_AUTO_TEST_CASE(array_map_string_string_test_case) {

		
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testDefaultConstructor()) , "TEST: ArrayMap<string, string> - default_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testConstructor()) , "TEST: ArrayMap<string, string> - constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testPut(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - put()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testSize(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - size()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testCopyConstructor(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - copy_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testMoveConstructor(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - move_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testCopyAssignment(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - copy_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testMoveAssignment(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - move_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testGet(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - get()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testIndex(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - []");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testRemove(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - remove()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testContainsKey(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - containsKey()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testContainsValue(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - containsValue()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testKeys(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - keys()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,string>::testValues(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: ArrayMap<string, string> - values()");
	
	}

	BOOST_AUTO_TEST_CASE(array_map_int_string_test_case) {

		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testDefaultConstructor()) , "TEST: ArrayMap<int,string> - default_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testConstructor()) , "TEST: ArrayMap<int,string> - constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testPut(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - put()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testSize(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - size()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testCopyConstructor(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - copy_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testMoveConstructor(month_numbers, month_names,MONTHS)) , "TEST: ArrayMap<int,string> - move_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testCopyAssignment(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - copy_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testMoveAssignment(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - move_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testGet(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - get()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testIndex(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - []");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testRemove(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - remove()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testContainsKey(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - containsKey()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testContainsValue(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - containsValue()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testKeys(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - keys()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<int,string>::testValues(month_numbers, month_names, MONTHS)) , "TEST: ArrayMap<int,string> - values()");
	}

	BOOST_AUTO_TEST_CASE(array_map_string_double_test_case) {

		
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testDefaultConstructor()) , "TEST: ArrayMap<string, double> - default_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testConstructor()) , "TEST: ArrayMap<string, double> - constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testPut(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - put()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testSize(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - size()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testCopyConstructor(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - copy_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testMoveConstructor(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - move_constructor()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testCopyAssignment(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - copy_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testMoveAssignment(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - move_assignment()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testGet(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - get()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testIndex(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - []");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testRemove(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - remove()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testContainsKey(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - containsKey()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testContainsValue(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - containsValue()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testKeys(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - keys()");
		BOOST_CHECK_MESSAGE((ArrayMapTest<string,double>::testValues(letter_grades, grade_points, GRADES)) , "TEST: ArrayMap<string, double> - values()");
	

	}

BOOST_AUTO_TEST_SUITE_END()

