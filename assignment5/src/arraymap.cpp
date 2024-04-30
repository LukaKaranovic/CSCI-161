/**
 * @file arraymap.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date April 11, 2024
 * 
 * Implements Map ADT defined in 'map' header file using an array data structure.
 */
 

#include <iostream>
#include <cstring>
#include "dynamicarray.h"
#include "map.h"
#include "keyvalue.h"

/** @brief Implements the map abstract data type defined in 'map.h' using an array data structure.
 *  
 *  A map is a dictionary of key-value pairs. The key-value pairs are entered into an array in this class.
 *  The public methods allow for constructing, copying, and easily moving array map data structures. They also
 *  allow for key-value entry insertion, removal, and easy access. The array map can also be turned into a dynamic 
 *  array containing all of the keys or a dynamic array containing all of its values.
 *  
 */

template <typename K, typename V>
class ArrayMap: public Map<K, V> {

	friend class ArrayMapTest<K,V>;
	friend class MapTest<K, V>;
			
	private:
		int _capacity;
		int _size;
		KeyValue<K,V>* _entries;
				
	public:
		
		/** @brief Default Constructor
		 *  
		 */

		ArrayMap(): _capacity(DEFAULT_CAPACITY), _size(0), _entries(new KeyValue<K, V>[DEFAULT_CAPACITY]) {}

		/** @brief Regular Constructor
		 *  
		 */

		ArrayMap(const int capacity): _capacity(capacity), _size(0), _entries(new KeyValue<K, V>[capacity]) {}

		/** @brief Destructor. Clears every element from the array map.
		 *  
		 */

		~ArrayMap() {
			delete[] _entries;
		}

		/** @brief Copy constructor. Deep copies from another array map.
		*
		*  Deep copies another array map's capacity, size, and array of key-value pairs.
		*
		*  @param other The source array map containing a capacity, size, and array of key-value pairs.
		*  
		*/

		ArrayMap(const ArrayMap<K, V>& other): _capacity(other._capacity), _size(other._size), _entries(new KeyValue<K, V>[_capacity]) {
			for (int i = 0; i < _size; i++) {
				_entries[i] = other._entries[i];
			}
		}
			
		/** @brief Move constructor. Shallow copies from another array map.
		*
		*  Shallow copies an R-value array map's capacity, size, and array of key-value pairs, assigning it a name.
		*  Ensures the R-value's entries pointer is empty after assignment
		*
		*  @param temp The R-value array map containing a capacity, size, and array of key-value pairs.
		*  
		*/

		ArrayMap(ArrayMap<K, V>&& temp): _capacity(temp._capacity), _size(temp._size), _entries(temp._entries) {
			temp._entries = nullptr;
		}

		/** @brief Copy assignmnt. Deep copies the key-value pairs from another array map.
		*
		*  Overloads the assignment (=) operator so that it does the following:
		*  Copies entry keys and values in the same order from a source array map to the current
		*  array map. 
		*
		*  @param other The source array map containing a capacity, size, and array of key-value pairs.
		*  @return The updated version of the array map.
		*/

		ArrayMap& operator = (const ArrayMap<K, V>& other) {
			if (this == &other) {
				return *this;
			}
			_capacity = other._capacity;
			_size = other._size;
			_entries = new KeyValue<K, V>[_capacity];
			for (int i = 0; i < _size; i++) {
				_entries[i] = other._entries[i];
			}
			return *this;
		}

		/** @brief Move assignmnt. Shallow copies from another array map.
		*
		*  Overloads the assignment (=) operator so that it does the following:
		*  Copies an R-value array map's capacity, size, and array of key-value pairs, assigning it a new name.
		*  Ensures the temporary R-value array map's pointers are null after assignment.
		*
		*  @param temp The R-value array map containing a capacity, size, and array of key-value pairs.
		*  @return The updated version of the array map.
		*/

		ArrayMap& operator = (ArrayMap<K, V>&& temp) {
			if (this == &temp) {
				return *this;
			}
			_size = temp._size;
			_capacity = temp._capacity;
			_entries = temp._entries;
			temp._entries = nullptr;
			return *this;
		}

		/** @brief Inserts a new key-value entry into the array map.
		*
		*  Inserts a new entry into the array map at the rightmost index. Will not add the
		*  key-value pair if the key already exists in the map. Increases the size by one.
		*
		*  @param key The key of the key-value pair to be inserted.
		*  @param value The value of the key-value pair to be inserted.
		*  @return True if the insertion was successful. False if the insertion was not successful.
		*/

		bool put (K key, V value) override {
			for (int i = 0; i < _size; i++) {
				if (key == _entries[i]._key) {
					return false;
				}
			}
			_entries[_size]._key = key;
			_entries[_size]._value = value;
			_size++;
			return true;
		}

		/** @brief Returns the array map's current size.
		* 
		*   @return The current size of the array map.
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
			for (int i = 0; i < _size; i++) {
				if (key == _entries[i]._key) {
					return _entries[i]._value;
				}
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

		/** @brief Removes a specific key-value entry from the array map.
		*
		*  Searches for the target key in the array map. If found, deletes the
		*  entry of the key-value pair and shifts everything to the right of that entry one
		*  index to the left, ensuring there are no gaps in the array. Decreases the size
		*  by one.
		*
		*  @param key The key of the key-value pair to be removed.
		*  @return True if the element is found and removed and false if not.
		*/

		V remove (K key) override {
			for (int i = 0; i < _size; i++) {
				if (_entries[i]._key == key) {
					V target = _entries[i]._value;
					for (; i < _size - 1; i++) {
						_entries[i] = _entries[i+1];
					}
					_size--;
					return target;
				}
			}
			throw("Remove was unsuccessful.");
		}

		/** @brief Checks if the array map contains the passed key.
		*
		*  Searches for the target key in the entire array map. If found, returns true and terminates.
		*  If not found, returns false and terminates.
		*
		*  @param key The target key being searched for.
		*  @return True if the target key is found and false if not.
		*/

		bool containsKey (K key) const override {
			for (int i = 0; i < _size; i++) {
				if (key == _entries[i]._key) {
					return true;
				}
			}
			return false;
		}

		/** @brief Checks if the array map contains the passed value.
		*
		*  Searches for the target value in the entire array map. If found, returns true and terminates.
		*  If not found, returns false and terminates.
		*
		*  @param value The target value being searched for.
		*  @return True if the target value is found and false if not.
		*/

		bool containsValue (V value) const override {
			for (int i = 0; i < _size; i++) {
				if (_entries[i]._value == value) {
					return true;
				}
			}
			return false;
		}

		/** @brief Creates a dynamic array containing all of the keys in the array map.
		*
		*  Dynamically allocates a new dynamic array data structure defined in the dynamicarray.h specification.
		*  Each entry has its key inserted into the array in order.
		*
		*  @return The dynamic array data structure containing all of the keys. 
		*		   Returns null if the array map is empty.
		*/

		const DynamicArray<K>* keys() const override {
			if (size() == 0) {
				return nullptr;
			}
			DynamicArray<K>* keys = new DynamicArray<K>();
			for (int i = 0; i < _size; i++) {
				keys->insert(_entries[i]._key);
			}
			return keys;
		}

		/** @brief Creates a dynamic array containing all of the values in the array map.
		*
		*  Dynamically allocates a new dynamic array data structure defined in the dynamicarray.h specification.
		*  Each entry has its value inserted into the array in order.
		*
		*  @return The dynamic array data structure containing all of the values. 
		*		   Returns null if the array map is empty.
		*/

		const DynamicArray<V>* values() const override {
			if (size() == 0) {
				return nullptr;
			}
			DynamicArray<V>* values = new DynamicArray<V>();
			for (int i = 0; i < _size; i++) {
				values->insert(_entries[i]._value);
			}
			return values;
		}

};

