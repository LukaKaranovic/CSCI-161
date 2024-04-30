/**
 * @file dynamicarray.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Defines a DynamicArray template class.
 * DynamicArray template class can be used with any data type.
 * In order to instantiate a DynamicArray for a particular data type in the client
 * code the implementation source code of DynamicArray template class must be included
 * in the client code. This is due to the reason that type binding in a template
 * class happens during compile time not during linking time. In other words, client code 
 * must include the implementation code not this header file. The implementation code,
 * however, needs to include this header file.
 * A DynamicArray object starts with a fixed capacity but that can be expanded when the
 * array grows beyond the capacity.	
 * 
 */
 


#ifndef __DYNAMIC_ARRAY_HEADER__
#define __DYNAMIC_ARRAY_HEADER__

const int DEFAULT_CAPACITY = 10;

template<typename T> class DynamicArrayTest;

template <typename T>
class DynamicArray {
	
	friend class DynamicArrayTest<T>;

	protected:
		int _capacity; 		//The capacity of the array
		int _size;		//Counts the number of elements in the array
		T* _elements;		//Actual array that contains the elements.

	public:
		/**
		 * Default constructor
		 */
		DynamicArray();


		/**
		 * Regular constructor
		 */
		DynamicArray(const int capacity);


		/**
		 * Copy constructor
		 */
		DynamicArray(const DynamicArray& other);


		/**
		 * Move constructor.
		 */
		DynamicArray(DynamicArray&& temp);


		/**
		 *Destructor
		 */
		~DynamicArray();

		/**
		 * Returns maxumum number of elements that this dynamic array can hold.
		 */
		int capacity() const;
		

		/**
		 * Inserts an element into the array.
		 */
		void insert(const T element);
		//Check whether the array is full or not.
		//If array is full, create a new array with double capacity.
		//	Copy the elements from the old array to the new array.
		//	Release memory from the old array.
		//	Assign new array pointer to the old array pointer.
		//Insert the new element at the end of the array and increment the size.


		/**
		 * Returns the current number of elements in the dynamic array.
		 */
		int size() const;

		/**
		 * Returns true if the dynamic array does not contain any element.
		 */
		bool empty() const;
		

		/**
		 * Searches the element in the dynamic array.
		 */
		int search(const T element) const;
		//Loop through  the elements in the dynamic array.
		//Returns the index of the element if found.
		//Returns -1 otherwise


		/**
		 * Erase the element at the index from the dynamic array.
		 */
		void eraseAt(const int index);
		//If the index is not within the range, throw exception saying 'Inavlid Index'.
		//Remove the element at the index by moving all other elements right to it one
		//position left and decrementing the size.


		/**
		 * Erase the element if it exists, return true.
		 * Return, false otherwise
		 */
		bool erase(const T element);
		//Remove the element by moving all other elements right to it one
		//position left and decrementing the size.


		/**
		 * Removes all the elements from the dynamic array.
		 */
		void clear();


		/**
		 * Copy assignment of the dynamic array.
		 */
		DynamicArray& operator = (const DynamicArray& other);


		/**
		 * Move assignment.
		 */
		DynamicArray& operator = (DynamicArray&& temp);


		/**
		 * Returns the element at the specified index from the collection
		 */
		 T operator [] (const int index) const;
		

		 /**
		 * Returns the address of the element at the specified index 
		 * from the collection
		 */
		 T& operator [] (const int index);	
	
};


#endif
