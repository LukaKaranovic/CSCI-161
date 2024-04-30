/**
 * @file keyvalue.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 16, 2020
 *
 * Defines KeyValue class that encapsulates a key and a value pair
 * into one object and is used in Map ADT as its entries.
 *
 */ 

#ifndef __KEY_VALUE_HEADER__
#define __KEY_VALUE_HEADER__


template <typename K, typename V> class ArrayMap;
template <typename K, typename V> class ArrayMapTest;
template <typename K, typename V> class LinkedMap;
template <typename K, typename V> class LinkedMapTest;
template <typename K, typename V> class MapTest;


/*
 * Defination of KeyValue class.
 * KeyValue class will be used by both ArrayMap and LinkedMap classes
 */
template <typename K, typename V>
class KeyValue {

	friend class ArrayMap<K,V>;
	friend class ArrayMapTest<K,V>;
	friend class LinkedMap<K,V>;
	friend class LinkedMapTest<K,V>;
	friend class MapTest<K,V>;
	
	private:
		K _key;
		V _value;

	public:
		/*
		 * Default constructor
		 */
		KeyValue(){};
		
		
		/*
		 * Regular constructor
		 */
		KeyValue(K key, V value): _key(key), _value(value) {}
		
		/*
		 * Copy constructor
		 */
		KeyValue(const KeyValue& copy): _key(copy._key), _value(copy._value) {}
		
		/*
		 * Move constructor
		 */
		KeyValue(KeyValue&& temp): _key(temp._key), _value(temp._value) {}

		/*
		 * Copy assingment
		 */
		KeyValue& operator = (const KeyValue& rhs) {
			if(this == &rhs) {
				return *this;
			}
			_key = rhs._key;
			_value = rhs._value;
			return *this;
		}

		/*
		 * Move assignment
		 */
		KeyValue& operator = (KeyValue&& temp) {
			if(this == &temp) {
				return *this;
			}
			_key = temp._key;
			_value = temp._value;
			return *this;
		}
		
		/*
		 * Equal operator
		 */
		bool operator == (const KeyValue& other) {
			return (_key == other._key && _value == other._value);
		}

		/*
		 * Not equal operator
		 */
		bool operator != (const KeyValue& other) {
			return (_key != other._key || _value != other._value);
		}

};

#endif
