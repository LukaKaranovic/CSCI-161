/**
 * @file map.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 16, 2020
 *
 * Specifies a Map Abstract Data Type (ADT).
 * This specification specifies only the expected behaviours or operations of Map ADT. 
 * This specification does not tell what data or data structure should be used.
 * The choice of data structure is left to the implementor of the ADT.
 * Map ADT can be implemented using either an Array or a Linked List.
 * If Map ADT is implemented using an Array data structure, it might impose a maximum capacity on the ADT.
 * A dynamic array data structure can also be used to implement Map ADT to avoid maximum capacity limitation.
 * If Map ADT is implemented using Linked List, there will be no maximum limitation on ADT capacity.
 * To encapsulate an entry or key-value pair of Map ADT its implementation should use KeyValue<K,V> template class from 'keyvalue.h'.
 * To encapsulate a node for a single linked list of Map ADT linked list implementationn it should use SingleLinkedListNode<K,V> 
 * template class from 'singlelinkedlistnode.h'.
 * Both keys() and values() methods of Map ADT return a pointer to an object of type DynamicArray<T> defined in 
 * 'dynamicarray.h'.
 *
 */ 



#ifndef __MAP_HEADER__
#define __MAP_HEADER__

#include <iostream>
#include "dynamicarray.h"

using namespace std;


template <typename K, typename V>
class Map {
	
	public:
		/*
		 * Default constructor
		 */
		Map() {
			cout<<"Map::constructor......"<<endl;
		}

		/*
		 * Destructor
		 */
		virtual ~Map() {
			cout<<"Map::destructor....."<<endl;
		}


		/*
		 * Puts an entry with a key of type K and a value of type V into the map.
		 */
		virtual bool put(K key, V value) = 0;
		//Put an entry with a key of type K and a value of type V into the map
		//only if no other entry with the same key exists in the map.
		//Returns true if the put is successful.
		//Returns false, otherwise.


				
		/*
		 * Returns the number of entries that have been put into the map.
		 */
		virtual int size() const = 0;

				

		/*
		 * Returns the value of a matching entry from the map.
		 */
		virtual V get(K key) const = 0;
		//Return the value of an entry of the matching key from the map.
		//Throw exception, if there is no matching entry available in the map.
		 
	
		/*
		 * Returns the value of a matching entry from the map.
		 */
		virtual V operator [] (K key)  const = 0;
       	//Return the value of an entry of the matching key from the map.
		//Throw exception, if there is no matching entry available in the map.
		

		/*
		 * Removes an entry from the map.
		 */
		virtual V remove(K key) = 0;
		//Remove a matching entry from the map.
		//Return the value of the removed entry, if the remove is successful.
		//Throw exception, if the remove fails.
		


		/*
		 * Checking for the existance of a key in the map.
		 */
		virtual bool containsKey(K key) const = 0;
		//Return true, if there is an entry in the map whose key matches with a given key.
		//Return false, otherwise.
		


		/*
		 * Checking for the existance of a value in the map.
		 */ 
		virtual bool containsValue(V value) const = 0;
		//Return true, if there is at least one entry in the map whose value matches with a given value.
		//Return false, otherwise.
		 

		/*
		 * Returns all the keys of the map.
		 */
		virtual const DynamicArray<K>* keys() const = 0;
		//If map size is zero return a NULL pointer
		//Return all the keys of the map in a  DynamicArray pointer.
		//Use DynamicArray class from 'dynamicarray.h' header file.
		

		
		/*
		 * Returns all the values of the map.
		 */
		virtual const DynamicArray<V>* values() const = 0;
		//If map size is zero return a NULL pointer
		//Return all the values of the map in a DynamicArray pointer.
		//Use DynamicArray class from 'dynamicarray.h' header file.

};

#endif

