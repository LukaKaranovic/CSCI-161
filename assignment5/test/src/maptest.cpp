/**
 * @file - maptests.cpp
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.0
 * @modified - July 24, 2020
 * 
 * Performs unit tests of ArrayMap and Map implementations of Map ADT
 * through Map ADT reference to test dynamic polymorphism.
 *
 */
 
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment5_map_test

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "dynamicarray.cpp"
#include "map.h"
#include "arraymap.cpp"
#include "linkedmap.cpp"
#include "maptest.h"


using namespace std;

/*
 * Test Fixture  to test ArrayMap
 */
class TestFixture {
	public:
		/*
		 * Data to test ArrayMap<string, string> and Map<string, string>
		 */
		static const int NUMBER_OF_COUNTRIES = 5;
		string countries[NUMBER_OF_COUNTRIES] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
		string capitals[NUMBER_OF_COUNTRIES] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

		string brazil ="Brazil";
		string brazil_capital ="Brasilia";

		/*
		 * Data to test ArrayMap<int, string> and Map<int, string>
		 */
		static const int MONTHS = 12;
		int month_numbers[MONTHS] = {1,2,3,4,5,6,7,8,9,10,11,12};
		string month_names[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	
		/*
		 * Data to test ArrayMap<string, double> and Map<string, double>
	 	 */
		static const int GRADES = 11;
		string letter_grades[GRADES] = {"A+", "A","A-","B+","B", "B-", "C+", "C", "C-", "D", "F"};
		double grade_points[GRADES] = {4.33, 4.00, 3.67, 3.33, 3.00, 2.67, 2.33, 2.00, 1.67, 1.00, 0.00};

};



template<typename K, typename V>
void MapTest<K,V>::putIntoMap(const K* keys, const V* values, const int size, Map<K,V>* map) {
	for(int i=0; i<size; i++) {
		map->put(keys[i], values[i]);
	}
	
}


template<typename K, typename V>
bool MapTest<K,V>::isKeyValuesInMap(const K* keys, const V* values, const int size, LinkedMap<K,V>& lmap) {
	if(lmap._front == nullptr || lmap._size != size ) {
		cout<<"\treason: front pointer and size are not correct"<<endl;
		return false;
	}

	SingleLinkedListNode<K,V>* iterator = lmap._front;
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
bool MapTest<K,V>::isKeyValuesInMap(const K* keys, const V* values, const int size, ArrayMap<K,V>& amap) {
	if(amap._entries == nullptr || amap._size != size ) {
		cout<<"\treason: front pointer and size are not correct"<<endl;
		return false;
	}

	for(int i=0; i<size; i++) {
		if(amap._entries[i]._key != keys[i]) {
			cout<<"\treason: keys put are not correct"<<endl;
			return false;
		}
		if(amap._entries[i]._value != values[i]) {
			cout<<"\treason: values put are not correct"<<endl;
			return false;
		}
	}

	return true;
}


template<typename K, typename V>
bool MapTest<K,V>::testPut(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	putIntoMap(keys, values, size, map);
	if (isKeyValuesInMap(keys, values, size, dynamic_cast<ArrayMap<K,V>&>(*map)) != true) {
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	putIntoMap(keys, values, size, map);
	if (isKeyValuesInMap(keys, values, size, dynamic_cast<LinkedMap<K,V>&>(*map)) != true) {
		return false;
	}
	delete map;
	return true;
}


template<typename K, typename V>
bool MapTest<K,V>::testSize(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	if(map->size() != 0 ) {
		cout<<"\treason: size on an empty array map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);
	if(map->size() != size ) {
		cout<<"\treason: size on a non-empty array map object is not correct"<<endl;
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	if(map->size() != 0 ) {
		cout<<"\treason: size on an empty linked map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);
	if(map->size() != size ) {
		cout<<"\treason: size on a non-empty linked map object is not correct"<<endl;
		return false;
	}
	delete map;
	return true;
	
}


template<typename K, typename V>
bool MapTest<K,V>:: testGet(const K* keys, const V* values, const int size) {
	
	Map<K,V>* map = new ArrayMap<K,V>(size);
	putIntoMap(keys, values, size, map);
	if(map->get(keys[0]) != values[0] || map->get(keys[size/2]) != values[size/2] ||
			map->get(keys[size-1]) != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	putIntoMap(keys, values, size, map);
	if(map->get(keys[0]) != values[0] || map->get(keys[size/2]) != values[size/2] ||
			map->get(keys[size-1]) != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	delete map;
	return true;
}


template<typename K, typename V>
bool MapTest<K,V>:: testIndex(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	putIntoMap(keys, values, size, map);
	if((*map)[keys[0]] != values[0] || (*map)[keys[size/2]] != values[size/2] ||
			(*map)[keys[size-1]] != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	putIntoMap(keys, values, size, map);
	if((*map)[keys[0]] != values[0] || (*map)[keys[size/2]] != values[size/2] ||
			(*map)[keys[size-1]] != values[size-1]) {
		cout<<"\treason: values gey by keys are not correct"<<endl;
		return false;
	}
	delete map;
	return true;
}


template<typename K, typename V>
bool MapTest<K,V>:: testRemove(const K* keys, const V* values, const int size) {
	
	Map<K,V>* map = new ArrayMap<K,V>(size);
	putIntoMap(keys, values, size, map);

	try {
		map->remove(keys[0]+keys[size-1]);
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	if(dynamic_cast<ArrayMap<K,V>*>(map)->_size != size ) {
		cout<<"\treason: size after unsuccesful remove is not correct"<<endl;
		return false;
	}
	if(isKeyValuesInMap(keys, values, size, dynamic_cast<ArrayMap<K,V>&>(*map)) != true ) {
		return false;
	}

	int removeAt = size/2;
	map->remove(keys[removeAt]);

	if(dynamic_cast<ArrayMap<K,V>*>(map)->_size != size -1) {
		cout<<"\treason: size after succesful remove from array map object is not correct"<<endl;
		return false;
	}

	for(int i=0; i<removeAt; i++) {
		if(dynamic_cast<ArrayMap<K,V>*>(map)->_entries[i]._key != keys[i]) {
			cout<<"\treason: keys before removed element from array map object  are not correct"<<endl;
			return false;
		}
	}

	for(int i=0; i<removeAt; i++) {
		if(dynamic_cast<ArrayMap<K,V>*>(map)->_entries[i]._value != values[i]) {
			cout<<"\treason: values before removed element from array map object are not correct"<<endl;
			return false;
		}
	}

	for(int i=removeAt; i<size-1; i++) {
		if(dynamic_cast<ArrayMap<K,V>*>(map)->_entries[i]._key != keys[i+1]) {
			cout<<"\treason: keys after removed element from array map object are not correct"<<endl;
			return false;
		}
	}

	for(int i=removeAt; i<size-1; i++) {
		if(dynamic_cast<ArrayMap<K,V>*>(map)->_entries[i]._value != values[i+1]) {
			cout<<"\treason: values after removed element are not correct"<<endl;
			return false;
		}
	}

	delete map;
	map = new LinkedMap<K,V>();
	putIntoMap(keys, values, size, map);

	try {
		map->remove(keys[0]+keys[size-1]);
	}
	catch(const char* error) {
		cout<<error<<endl;
	}

	if(dynamic_cast<LinkedMap<K,V>*>(map)->_size != size ) {
		cout<<"\treason: size after unsuccesful remove is not correct"<<endl;
		return false;
	}
	if(isKeyValuesInMap(keys, values, size, dynamic_cast<LinkedMap<K,V>&>(*map)) != true ) {
		return false;
	}


	map->remove(keys[removeAt]);

	if(dynamic_cast<LinkedMap<K,V>*>(map)->_size != size -1) {
		cout<<"\treason: size after succesful remove from array map object is not correct"<<endl;
		return false;
	}


	SingleLinkedListNode<K,V>* iterator = dynamic_cast<LinkedMap<K,V>*>(map)->_front;
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
	
	delete map;

	return true;
}


template<typename K, typename V>
bool MapTest<K,V>:: testContainsKey(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	if(map->containsKey(keys[0]) != false || map->containsKey(keys[size/2]) != false || map->containsKey(keys[size-1]) != false) {
		cout<<"\treason: contains key in an empty array map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);
	if(map->containsKey(keys[0]) != true || map->containsKey(keys[size/2]) != true || map->containsKey(keys[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty array map object is not correct"<<endl;
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	if(map->containsKey(keys[0]) != false || map->containsKey(keys[size/2]) != false || map->containsKey(keys[size-1]) != false) {
		cout<<"\treason: contains key in an empty linked map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);

	if(map->containsKey(keys[0]) != true || map->containsKey(keys[size/2]) != true || map->containsKey(keys[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty linked map object is not correct"<<endl;
		return false;
	}
	delete map;
	return true;
}


template<typename K, typename V>
bool MapTest<K,V>:: testContainsValue(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	if(map->containsValue(values[0]) != false || map->containsValue(values[size/2]) != false|| map->containsValue(values[size-1]) != false) {
		cout<<"\treason: contains key in an empty array map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);
	if(map->containsValue(values[0]) != true || map->containsValue(values[size/2]) != true|| map->containsValue(values[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty array map object is not correct"<<endl;
		return false;
	}
	delete map;
	map = new LinkedMap<K,V>();
	if(map->containsValue(values[0]) != false || map->containsValue(values[size/2]) != false || map->containsValue(values[size-1]) != false) {
		cout<<"\treason: contains key in an empty linked map object is not correct"<<endl;
		return false;
	}
	putIntoMap(keys, values, size, map);
	if(map->containsValue(values[0]) != true || map->containsValue(values[size/2]) !=true || map->containsValue(values[size-1]) != true) {
		cout<<"\treason: contains key in a non-empty linked map object is not correct"<<endl;
		return false;
	}
	delete map;
	return true;
}



template<typename K, typename V>
bool MapTest<K,V>:: testKeys(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	const DynamicArray<K>* mapKeys = map->keys();
	if(mapKeys != nullptr) {
		cout<<"\treason: keys pointer from an empty array map object is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, map);

	mapKeys = map->keys();
	if(mapKeys == nullptr) {
		cout<<"\treason: keys pointer from a non-empty array map object  is not correct"<<endl;
		return false;
	}
	if(mapKeys->size() != size) {
		cout<<"\treason: keys size from an non-empty array map object is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapKeys)[i] != keys[i] ) {
			cout<<"\treason: keys from an non-empty array map object are not correct"<<endl;
			return false;
		}
	}

	delete map;
	delete mapKeys;
	map = nullptr;
	mapKeys = nullptr;

	map = new LinkedMap<K,V>();
	mapKeys = map->keys();
	if(mapKeys != nullptr) {
		cout<<"\treason: keys pointer from an empty linked map object is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, map);

	mapKeys = map->keys();
	if(mapKeys == nullptr) {
		cout<<"\treason: keys pointer from a non-empty linked map object is not correct"<<endl;
		return false;
	}
	if(mapKeys->size() != size) {
		cout<<"\treason: keys size from a non-empty linked map object is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapKeys)[i] != keys[i] ) {
			cout<<"\treason: keys from a non-empty linked map object are not correct"<<endl;
			return false;
		}
	}
	delete map;
	delete mapKeys;
	return true;
}


template<typename K, typename V>
bool MapTest<K,V>:: testValues(const K* keys, const V* values, const int size) {
	Map<K,V>* map = new ArrayMap<K,V>(size);
	const DynamicArray<V>* mapValues = map->values();
	if(mapValues != nullptr) {
		cout<<"\treason: values pointer from an empty array map object is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, map);

	mapValues = map->values();
	if(mapValues == nullptr) {
		cout<<"\treason: values pointer from a non-empty array map object  is not correct"<<endl;
		return false;
	}
	if(mapValues->size() != size) {
		cout<<"\treason: values size from an non-empty array map object is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapValues)[i] != values[i] ) {
			cout<<"\treason: values from an non-empty array map object are not correct"<<endl;
			return false;
		}
	}

	delete map;
	delete mapValues;
	map = nullptr;
	mapValues = nullptr;

	map = new LinkedMap<K,V>();
	mapValues = map->values();
	if(mapValues != nullptr) {
		cout<<"\treason: values pointer from an empty linked map object is not correct"<<endl;
		return false;
	}

	putIntoMap(keys, values, size, map);

	mapValues = map->values();
	if(mapValues == nullptr) {
		cout<<"\treason: values pointer from a non-empty linked map object is not correct"<<endl;
		return false;
	}
	if(mapValues->size() != size) {
		cout<<"\treason: values size from a non-empty linked map object is not correct"<<endl;
		return false;
	}
	for(int i=0; i<size; i++) {
		if((*mapValues)[i] != values[i] ) {
			cout<<"\treason: values from a non-empty linked map object are not correct"<<endl;
			return false;
		}
	}
	delete map;
	delete mapValues;
	return true;
	
}





BOOST_FIXTURE_TEST_SUITE(assignment5_map_test_suite, TestFixture)

	BOOST_AUTO_TEST_CASE(map_string_string_test_case) {

		BOOST_CHECK_MESSAGE((MapTest<string, string>::testPut(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - put()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testSize(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - size()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testGet(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - get()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testIndex(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - []"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testRemove(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - remove()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testContainsKey(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - containsKey()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testContainsValue(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - containsValue()");
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testKeys(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - keys()");  
		BOOST_CHECK_MESSAGE((MapTest<string, string>::testValues(countries, capitals, NUMBER_OF_COUNTRIES)), "TEST: Map<string, string> - values()");  
	}


	BOOST_AUTO_TEST_CASE(map_int_string_test_case) {

		BOOST_CHECK_MESSAGE((MapTest<int, string>::testPut(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - put()"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testSize(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - size()"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testGet(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - get()"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testIndex(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - []"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testRemove(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - remove()"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testContainsKey(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - containsKey()"); 
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testContainsValue(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - containsValue()");
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testKeys(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - keys()");  
		BOOST_CHECK_MESSAGE((MapTest<int, string>::testValues(month_numbers, month_names, MONTHS)), "TEST: Map<int, string> - values()");  
	}


	BOOST_AUTO_TEST_CASE(map_string_double_test_case) {

		BOOST_CHECK_MESSAGE((MapTest<string, double>::testPut(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - put()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testSize(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - size()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testGet(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - get()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testIndex(letter_grades, grade_points, GRADES)), "TEST: Map<string, double - []"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testRemove(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - remove()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testContainsKey(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - containsKey()"); 
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testContainsValue(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - containsValue()");
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testKeys(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - keys()");  
		BOOST_CHECK_MESSAGE((MapTest<string, double>::testValues(letter_grades, grade_points, GRADES)), "TEST: Map<string, double> - values()");  
	}




BOOST_AUTO_TEST_SUITE_END()





