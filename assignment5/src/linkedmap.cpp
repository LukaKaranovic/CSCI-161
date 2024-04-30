/**
 * @file linkedmap.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date April 11, 2024
 * 
 * Implements Map ADT defined in 'map' header file using a linked list data structure.
 */
 


#include <iostream>
#include <cstring>

#include "dynamicarray.h"
#include "map.h"
#include "keyvalue.h"
#include "singlelinkedlistnode.h"

/** @brief Implements the map abstract data type defined in 'map.h' using a single linked list data structure.
 *  
 *  A map is a dictionary of key-value pairs. The key-value pairs are entered into a linked list in this class.
 *  The public methods allow for constructing, copying, and easily moving linked map data structures. They also
 *  allow for key-value entry insertion, removal, and easy access. The linked map can also be turned into a dynamic 
 *  array containing all of the keys or a dynamic array containing all of its values.
 *  
 */

template <typename K, typename V>
class LinkedMap: public Map<K, V> {
		
	friend class LinkedMapTest<K,V>;
	friend class MapTest<K, V>;

	private:
		SingleLinkedListNode<K,V>* _front;
		int _size;

		void deepCopy(SingleLinkedListNode<K,V>*& destinationFront, const SingleLinkedListNode<K,V>* sourceFront) {
			if (sourceFront == nullptr) {
				return;
			}
			destinationFront = new SingleLinkedListNode<K,V>(sourceFront->_data);
			SingleLinkedListNode<K,V>* copy = destinationFront;
			SingleLinkedListNode<K,V>* next = sourceFront->_next;
			while (next != nullptr) {
				copy->_next = new SingleLinkedListNode<K,V>(next->_data);
				copy = copy->_next;
				next = next->_next;
			}
		}

		void clear(SingleLinkedListNode<K,V>*& listFront) {
			while (listFront != nullptr) {
				SingleLinkedListNode<K,V>* node = listFront;
				listFront = listFront->_next;
				delete node;
			}
		}

	public:
		
		/** @brief Default Constructor
		 *  
		 */

		LinkedMap(): _front(nullptr), _size(0) {}

		/** @brief Destructor. Clears every element from the linked map.
		 *  
		 */

		~LinkedMap() {
			clear(_front);
		}

		/** @brief Copy constructor. Deep copies from another linked map.
		*
		*  Deep copies another linked map's size, front pointer, and linked list of key-value pairs.
		*
		*  @param other The source linked map containing a size, front pointer, and linked list of key-value pairs.
		*  
		*/

		LinkedMap(const LinkedMap& other): _front(nullptr), _size(other._size) {
			deepCopy(_front, other._front);
		}

		/** @brief Move constructor. Shallow copies from another linked map.
		*
		*  Shallow copies an R-value linked map's size, front pointer, and linked list of key-value pairs, assigning it a name.
		*  Ensures the R-value's front pointer is empty after assignment
		*
		*  @param temp The R-value linked map containing a size, front pointer, and linked list of key-value pairs.
		*  
		*/

		LinkedMap(LinkedMap&& temp): _front(temp._front), _size(temp._size) {
			temp._front = nullptr;
		}

		/** @brief Copy assignmnt. Deep copies the key-value pairs from another linked map.
		*
		*  Overloads the assignment (=) operator so that it does the following:
		*  Copies entry keys and values in the same order from a source linked map to the current
		*  linked map. 
		*
		*  @param other The source linked map containing a size, front pointer, and linked list of key-value pairs.
		*  @return The updated version of the linked map.
		*/

		LinkedMap& operator = (const LinkedMap& other) {
			if (this == &other) {
				return *this;
			}
			clear(_front);
			deepCopy(_front, other._front);
			_size = other._size;
			return *this;
		}

		/** @brief Move assignmnt. Shallow copies from another linked map.
		*
		*  Overloads the assignment (=) operator so that it does the following:
		*  Shallow copies an R-value linked map's size, front pointer, and linked list of key-value pairs, assigning it a name.
		*  Ensures the temporary R-value linked map's pointers are null after assignment.
		*
		*  @param temp The R-value linked map containing a size, front pointer, and linked list of key-value pairs.
		*  @return The updated version of the linked map.
		*/

		LinkedMap& operator = (LinkedMap&& temp) {
			if (this == &temp) {
				return *this;
			}
			clear(_front);
			_front = temp._front;
			_size = temp._size;
			temp._front = nullptr;
			return *this;
		}

		/** @brief Inserts a new key-value entry into the linked map.
		*
		*  Inserts a new entry into the linked map at the tail of the linked list. Will not add the
		*  key-value pair if the key already exists in the map. Increases the size by one.
		*
		*  @param key The key of the key-value pair to be inserted.
		*  @param value The value of the key-value pair to be inserted.
		*  @return True if the insertion was successful. False if the insertion was not successful.
		*/

		bool put(K key, V value) override {
			SingleLinkedListNode<K,V>* newNode = new SingleLinkedListNode<K,V>(KeyValue<K,V>(key, value));
			if (_size == 0) {
				_front = newNode;
				_size++;
				return true;
			} else if (containsKey(key) == false) {
				SingleLinkedListNode<K,V>* iterator = _front;
				while (iterator->_next != nullptr) {
					iterator = iterator->_next;
				}
				iterator->_next = newNode;
				_size++;
				return true;
			}
			return false;
		}

		/** @brief Returns the linked map's current size.
		* 
		*   @return The current size of the linked map.
		*/  

		int size() const override {
			return _size;
		}

		/** @brief Gets the value that is paired with the passed key.
		*
		*  Searches for the key passed as a parameter and returns the value associated with it.
		*  Throws an exception if unsuccessful.
		*
		*  @param key The key of the key-value pair to be retrieved.
		*  @return The value associated with the key that was passed.
		*/

		V get(K key) const override {
			SingleLinkedListNode<K,V>* iterator = _front;
			while (iterator != nullptr) {
				if (iterator->_data._key == key) {
					return iterator->_data._value;
				}
				iterator = iterator->_next;
			}
			throw("No matching entry available in map.");
		}

		/** @brief Gets the value that is paired with the passed key as an index.
		*
		*  Overloads the ([]) operator so that it does the following:
		*  Searches for the key passed as a parameter and returns the value associated with it.
		*  Throws an exception if unsuccessful.
		*
		*  @param key The key of the key-value pair to be retrieved.
		*  @return The value associated with the key that was passed.
		*/

		V operator [] (K key) const override {
			return get(key);
		}

		/** @brief Removes a specific key-value node from the linked map.
		*
		*  Searches for the target key in the linked map. If found, deletes the
		*  node of the key-value pair. Reassigns pointers to ensure there are no gaps in the array. 
		*  Decreases the size by one.
		*
		*  @param key The key of the key-value pair to be removed.
		*  @return True if the node is found and removed and false if not.
		*/

		V remove(K key) override {
			V value;
			if (_front == nullptr) {
				throw("Remove was unsuccessful.");
			} else if (containsKey(key) == false) {
				throw("Remove was unsuccessful.");
			} else if (_front->_data._key == key) {
				SingleLinkedListNode<K,V>* target = _front;
				value = target->_data._value;
				_front = _front->_next;
				delete target;
				_size--;
				return value;
			} 
			SingleLinkedListNode<K,V>* prev = _front;
			while (prev->_next != nullptr) {
				if (prev->_next->_data._key == key) {
					SingleLinkedListNode<K,V>* target = prev->_next;
					value = target->_data._value;
					prev->_next = prev->_next->_next;
					delete target;
					_size--;
					return value;
				}
				prev = prev->_next;
			}
			throw("Remove was unsuccessful.");
		}

		/** @brief Checks if the linked map contains the passed key.
		*
		*  Searches for the target key in the entire linked map. If found, returns true and terminates.
		*  If not found, returns false and terminates.
		*
		*  @param key The target key being searched for.
		*  @return True if the target key is found and false if not.
		*/

		bool containsKey(K key) const override {
			if (_front == nullptr) {
				return false;
			}
			SingleLinkedListNode<K,V>* iterator = _front;
			while (iterator->_next != nullptr) {
				if (iterator->_data._key == key || iterator->_next->_data._key == key) {
					return true;
				}
				iterator = iterator->_next;
			}
			return false;
		}

		/** @brief Checks if the linked map contains the passed value.
		*
		*  Searches for the target value in the entire linked map. If found, returns true and terminates.
		*  If not found, returns false and terminates.
		*
		*  @param value The target value being searched for.
		*  @return True if the target value is found and false if not.
		*/

		bool containsValue(V value) const override {
			if (_front == nullptr) {
				return false;
			}
			SingleLinkedListNode<K,V>* iterator = _front;
			while (iterator->_next != nullptr) {
				if (iterator->_data._value == value || iterator->_next->_data._value == value) {
					return true;
				}
				iterator = iterator->_next;
			}
			return false;
		}

		/** @brief Creates a dynamic array containing all of the keys in the linked map.
		*
		*  Dynamically allocates a new dynamic array data structure defined in the dynamicarray.h specification.
		*  Each entry has its key inserted into the array in order.
		*
		*  @return The dynamic array data structure containing all of the keys. 
		*		   Returns null if the linked map is empty.
		*/

		const DynamicArray<K>* keys() const override {
			if (size() == 0) {
				return nullptr;
			}
			DynamicArray<K>* keys = new DynamicArray<K>();
			SingleLinkedListNode<K,V>* iterator = _front;
			while (iterator->_next != nullptr) {
				keys->insert(iterator->_data._key);
				iterator = iterator->_next;
			}
			keys->insert(iterator->_data._key);
			return keys;
		}

		/** @brief Creates a dynamic array containing all of the values in the linked map.
		*
		*  Dynamically allocates a new dynamic array data structure defined in the dynamicarray.h specification.
		*  Each entry has its value inserted into the array in order.
		*
		*  @return The dynamic array data structure containing all of the values. 
		*		   Returns null if the linked map is empty.
		*/

		const DynamicArray<V>* values() const override {
			if (size() == 0) {
				return nullptr;
			}
			DynamicArray<V>* values = new DynamicArray<V>();
			SingleLinkedListNode<K,V>* iterator = _front;
			while (iterator->_next != nullptr) {
				values->insert(iterator->_data._value);
				iterator = iterator->_next;
			}
			values->insert(iterator->_data._value);
			return values;
		}

	};

 



