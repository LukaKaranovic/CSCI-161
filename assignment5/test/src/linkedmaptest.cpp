/**
 * @file - linkedmaptest.cpp
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.0
 * @date - July 24, 2020
 * 
 * Performs unit tests of LinkedMap implementation of Map ADT.
 *
 */
 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment5_linked_map_test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "linkedmap.cpp"
#include "linkedmaptest.h"
#include "singlelinkedlistnode.h"


using namespace std;

/*
 * Test Fixture  to test LinkedMap
 */
class TestFixture {
	public:
		/*
		 * Data to test LinkedMap<string, string>
		 */
		static const int NUMBER_OF_COUNTRIES = 5;
		string countries[NUMBER_OF_COUNTRIES] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
		string capitals[NUMBER_OF_COUNTRIES] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

		string brazil ="Brazil";
		string brazil_capital ="Brasilia";

		/*
		 * Data to test LinkedMap<int, string>
		 */
		static const int MONTHS = 12;
		int month_numbers[MONTHS] = {1,2,3,4,5,6,7,8,9,10,11,12};
		string month_names[MONTHS] = {"January", "February", "March", "April", "May", "June", 
			"July", "August", "September", "October", "November", "December"};
	
	
	
		/*
		 * Data to test LinkedMap<string, double>
	 	 */
		static const int GRADES = 11;
		string letter_grades[GRADES] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
		double grade_points[GRADES] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};

};


template<typename K, typename V>
void LinkedMapTest<K,V>::putIntoMap(const K* keys, const V* values, const int size, LinkedMap<K,V>& LinkedMap) {
	for(int i=0; i<size; i++) {
		LinkedMap.put(keys[i], values[i]);
	}
	
}


template<typename K, typename V>
LinkedMap<K,V> LinkedMapTest<K,V>::createLinkedMap(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	putIntoMap(keys, values, size, linkedMap);
	return linkedMap;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>::isKeyValuesInMap(const K* keys, const V* values, const int size, LinkedMap<K,V>& linkedMap) {
	if(linkedMap._front == nullptr || linkedMap._size != size ) {
		cout<<"\treason: front pointer and size are not correct"<<endl;
		return false;
	}

	SingleLinkedListNode<K,V>* iterator = linkedMap._front;
	int i = 0;
	while(iterator != nullptr && i<size ) {
		if(iterator->_data._key != keys[i]) {
			cout<<"\treason: keys are not correct"<<endl;
			return false;
		}
		if(iterator->_data._value != values[i]) {
			cout<<"\treason: keys are not correct"<<endl;
			return false;
		}
		iterator = iterator->_next;
		i++;
	}

	if(iterator != nullptr || i<size) {
		cout<<"\treason: number of entries are not correct"<<endl;
		return false;
	}

	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>::isDeepCopy(const LinkedMap<K,V>& linkedMap1, const LinkedMap<K,V>& linkedMap2) {
	if(linkedMap1._size != linkedMap2._size ) {
		cout<<"\treason: sizes are diffrent"<<endl;
		return false;
	}
	SingleLinkedListNode<K,V>* iterator1 = linkedMap1._front; 
	SingleLinkedListNode<K,V>* iterator2 = linkedMap2._front; 
	
	while(iterator1 != nullptr && iterator2 != nullptr ) {
		if(iterator1 == iterator2 ) {
			cout<<"\treason: nodes are shallow copy"<<endl;
			return false;
		}
		if(iterator1->_data._key != iterator2->_data._key ) {
			cout<<"\treason: keys are not correct"<<endl;
			return false;
		}
		if(iterator1->_data._value != iterator2->_data._value ) {
			cout<<"\treason: keys are not correct"<<endl;
			return false;
		}
		iterator1 = iterator1->_next;
		iterator2 = iterator2->_next;
	}
	if (iterator1 != nullptr || iterator2 != nullptr ) {
		cout<<"\treason: nodes are diffrent"<<endl;
		return false;
	}

	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>::testDefaultConstructor() {
	LinkedMap<K,V> linkedMap;
	
	if( linkedMap._size != 0 ) {
		cout<<"\treason: default size is not correct"<<endl;
		return false;
	}
	if( linkedMap._front != nullptr ) {
		cout<<"\treason: default front pointer is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>::testPut(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	putIntoMap(keys, values, size, linkedMap);
	return isKeyValuesInMap(keys, values, size, linkedMap);
	
}


template<typename K, typename V>
bool LinkedMapTest<K,V>::testSize(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	if(linkedMap.size() != 0 ) {
		cout<<"\treason: initial size is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, linkedMap);
	if(linkedMap.size() != size ) {
		cout<<"\treason: size is not correct"<<endl;
		return false;
	}
	return true;
	
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testCopyConstructor(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap1;
	putIntoMap(keys, values, size, linkedMap1);
	LinkedMap<K,V> linkedMap2 = linkedMap1;
	
	if(linkedMap2._size != size ) {
		cout<<"\treason: size of copy constructed linked map is not correct"<<endl;
			return false;
	}
	return isDeepCopy(linkedMap1, linkedMap2);
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testMoveConstructor(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap = std::move(createLinkedMap(keys, values, size));
	
	
	if(linkedMap._size != size ) {
		cout<<"\treason: size of move constructed linked map is not correct"<<endl;
			return false;
	}

	return isKeyValuesInMap(keys, values, size, linkedMap);
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testCopyAssignment(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap1;
	putIntoMap(keys, values, size, linkedMap1);
	LinkedMap<K,V> linkedMap2;
	linkedMap2 = linkedMap1;
	
	if(linkedMap2._size != size ) {
		cout<<"\treason: size of copy assigned linked map is not correct"<<endl;
			return false;
	}
	return isDeepCopy(linkedMap1, linkedMap2);
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testMoveAssignment(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	linkedMap = std::move(createLinkedMap(keys, values, size));
	
	
	if(linkedMap._size != size ) {
		cout<<"\treason: size of move assigned linked map is not correct"<<endl;
			return false;
	}
	
	return isKeyValuesInMap(keys, values, size, linkedMap);
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testGet(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	putIntoMap(keys, values, size, linkedMap);
	if(linkedMap.get(keys[0]) != values[0] || linkedMap.get(keys[size/2]) != values[size/2] ||
			linkedMap.get(keys[size-1]) != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testIndex(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	putIntoMap(keys, values, size, linkedMap);
	if(linkedMap[keys[0]] != values[0] || linkedMap[keys[size/2]] != values[size/2] ||
			linkedMap[keys[size-1]] != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testRemove(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	putIntoMap(keys, values, size, linkedMap);

	try {
		linkedMap.remove(keys[0]+keys[size-1]);
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	if(linkedMap._size != size ) {
		cout<<"\treason: size after unsuccesful remove is not correct"<<endl;
			return false;
	}
	if(isKeyValuesInMap(keys, values, size, linkedMap) != true ) {
		return false;
	}
	
	int removeAt = size/2;
	linkedMap.remove(keys[removeAt]);
	if(linkedMap._size != size-1 ) {
		cout<<"\treason: size after remove is not correct"<<endl;
		return false;
	}
	SingleLinkedListNode<K,V>* iterator = linkedMap._front;
	int i = 0;
	while(iterator != nullptr && i<removeAt ) {
		if(iterator->_data._key != keys[i] ) {
			cout<<"\treason: keys before removed entry are not correct"<<endl;
			return false;
		}
		if(iterator->_data._value != values[i] ) {
			cout<<"\treason: values before removed entry are not correct"<<endl;
			return false;
		}
		iterator = iterator->_next;
		i++;
	}

	while(iterator != nullptr && i<size-1 ) {
		if(iterator->_data._key != keys[i+1] ) {
			cout<<"\treason: keys after removed entry are not correct"<<endl;
			return false;
		}
		if(iterator->_data._value != values[i+1] ) {
			cout<<"\treason: values after removed entry are not correct"<<endl;
			return false;
		}
		iterator = iterator->_next;
		i++;
	}

	if(iterator != nullptr || i<size-1) {
		cout<<"\treason: number of entries after remove is not correct"<<endl;
		return false;
	}
		
	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testContainsKey(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	if(linkedMap.containsKey(keys[0]) || linkedMap.containsKey(keys[size/2]) || linkedMap.containsKey(keys[size-1])) {
		cout<<"\treason: contains key in an empty linked map is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, linkedMap);
	if(linkedMap.containsKey(keys[0]) != true || linkedMap.containsKey(keys[size/2]) != true || linkedMap.containsKey(keys[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty linked map is not correct"<<endl;
		return false;
	}

	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testContainsValue(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	if(linkedMap.containsValue(values[0]) || linkedMap.containsValue(values[size/2]) || linkedMap.containsValue(values[size-1])) {
		cout<<"\treason: contains value in an empty linked map is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, linkedMap);
	if(linkedMap.containsValue(values[0]) != true || linkedMap.containsValue(values[size/2]) != true || linkedMap.containsValue(values[size-1]) != true) {
		cout<<"\treason: contains value in a non-empty linked map is not correct"<<endl;
		return false;
	}
	
	return true;
}


template<typename K, typename V>
bool LinkedMapTest<K,V>:: testKeys(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	const DynamicArray<K>* mapKeys = linkedMap.keys();
	if(mapKeys != nullptr) {
		cout<<"\treason: keys pointer from an empty map is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, linkedMap);
	mapKeys = linkedMap.keys();
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
bool LinkedMapTest<K,V>:: testValues(const K* keys, const V* values, const int size) {
	LinkedMap<K,V> linkedMap;
	const DynamicArray<V>* mapValues = linkedMap.values();
	if(mapValues != nullptr) {
		cout<<"\treason: values pointer from an empty map is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, linkedMap);
	mapValues = linkedMap.values();
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



BOOST_FIXTURE_TEST_SUITE(assignment5_linked_map_test_suite, TestFixture)

	BOOST_AUTO_TEST_CASE(linked_map_string_string_test_case) {
		
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testDefaultConstructor()) , "TEST: LinkedMap<string, string> - default_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testPut(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - put()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testSize(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - size()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testCopyConstructor(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - copy_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testMoveConstructor(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - move_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testCopyAssignment(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - copy_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testMoveAssignment(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - move_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testGet(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - get()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testIndex(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - []");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testRemove(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - remove()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testContainsKey(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - containsKey()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testContainsValue(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - containsValue()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testKeys(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - keys()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,string>::testValues(countries, capitals, NUMBER_OF_COUNTRIES)) , "TEST: LinkedMap<string, string> - values()");
	
	}

	BOOST_AUTO_TEST_CASE(linked_map_int_string_test_case) {
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testDefaultConstructor()) , "TEST: LinkedMap<int,string> - default_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testPut(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - put()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testSize(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - size()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testCopyConstructor(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - copy_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testMoveConstructor(month_numbers, month_names,MONTHS)) , "TEST: LinkedMap<int,string> - move_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testCopyAssignment(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - copy_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testMoveAssignment(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - move_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testGet(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - get()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testIndex(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - []");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testRemove(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - remove()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testContainsKey(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - containsKey()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testContainsValue(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - containsValue()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testKeys(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - keys()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<int,string>::testValues(month_numbers, month_names, MONTHS)) , "TEST: LinkedMap<int,string> - values()");
	}

	BOOST_AUTO_TEST_CASE(linked_map_string_double_test_case) {
			
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testDefaultConstructor()) , "TEST: LinkedMap<string, double> - default_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testPut(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - put()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testSize(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - size()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testCopyConstructor(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - copy_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testMoveConstructor(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - move_constructor()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testCopyAssignment(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - copy_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testMoveAssignment(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - move_assignment()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testGet(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - get()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testIndex(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - []");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testRemove(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - remove()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testContainsKey(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - containsKey()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testContainsValue(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - containsValue()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testKeys(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - keys()");
		BOOST_CHECK_MESSAGE((LinkedMapTest<string,double>::testValues(letter_grades, grade_points, GRADES)) , "TEST: LinkedMap<string, double> - values()");

	}

BOOST_AUTO_TEST_SUITE_END()

