/**
 * @file singlelinkedlistnode.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 16, 2020
 *
 * Defines SingleLinkedListNode class that is used to implement a Map ADT
 * using a single linked list data structure.
 *
 */ 


#ifndef __SINGLE_LINKED_LIST_NODE_HEADER__
#define __SINGLE_LINKED_LIST_NODE_HEADER__

#include "keyvalue.h"


template <typename K, typename V> class LinkedMap;
template <typename K, typename V> class LinkedMapTest;
template <typename K, typename V> class MapTest;

/*
 * Definition of SingleLinkedListNode class.
 * SingleLinkedListNode class will be used by LinkedMap class
 */
template <typename K, typename V>
class SingleLinkedListNode {

	friend class LinkedMap<K,V>;
	friend class LinkedMapTest<K,V>;
	friend class MapTest<K, V>;

	private:
		KeyValue<K,V> _data;
		SingleLinkedListNode* _next;

	public:
		/*
		 * Default constrcustor
		 */
		SingleLinkedListNode(): _next(NULL) {}
		
		/*
		 * Regular constructor
		 */
		SingleLinkedListNode(KeyValue<K,V> data): _data(data), _next(NULL) {}	

};

#endif
