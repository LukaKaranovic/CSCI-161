/**
 * @file dynamicarray.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Defines a DynamicArray class. A DynamicArray object starts with a fixed capacity but 
 * that capacity is expanded when the array is growing out of capacity.	
 * 
 */
 


#ifndef __DYNAMIC_ARRAY_HEADER__
#define __DYNAMIC_ARRAY_HEADER__

#include <iostream>

const int DEFAULT_CAPACITY = 10;

class DynamicArray {
	protected:
		int _capacity;  //Defines the maximum number of elements that this DynamicArray can hold 
		int _size;	//Keeps track of the current number of elements inserted in this DynamicArray
		int* _elements;	//Pointer to the array where the elements are inserted.


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
		 * Overloaded Regular constructor
		 */
		DynamicArray(const int* array, const int array_size);
		//Create a DynamicArray of capacity equal to array_size and size equal to array_size
		//Copy all the elements from the array into your DynamicArray elements. 


		/**
		 * Copy constructor
		 */
		DynamicArray(const DynamicArray&);


		/**
		 * Move constructor.
		 */
		DynamicArray(DynamicArray&&);


		/**
		 * Destructor
		 */
		virtual ~DynamicArray();

		
		int size() const;
		//Returns the number of elements that have been inserted into the array.


		int capacity() const;
		//Returns the capacity of this dynamic array.


		bool empty() const;
		//Returns true if the array does not contain any element.

		
		virtual	void insert(const int element);
		//Check whether the array is full or not.
		//If array is full, create a new array with double capacity.
		//	Copy the elements from the old array to the new array.
		//	Release memory from the old array.
		//	Assign new array pointer to the old array pointer.
		//Insert the new element at the end of the array and increment the size.

		
		virtual void insert(const int array[], const int size);
		//Insert all the elements from the array into your dynamic array.
		//At any point of insertion, if the dynamic array capacity is full, double 
		//the capacity and continue the insertion until all array elements have been inserted.
		//Increment the size of the dynamic array after each insertion.


		int search(const int element) const;
		//Searche the element in the dynamic array.
		//Return the index of the element if found.
		//Returns -1 otherwise

		int* elements() const;
		//Retrun a copy of _elements array
		//Return a NULL pointer if the dynamic array is empty


		void erase(const int element);
		//Search the element to be erased.
		//If found move all other elements on the right of this element 1 position left.
		//Decrement the size.


		void clear();
		//Remove all the elements from the array but keep the memory allocated to it.



		/**
		 * Copy assignment of the array.
		 */
		DynamicArray& operator = (const DynamicArray&);


		/**
		 * Move assignment.
		 */
		DynamicArray& operator = (DynamicArray&&);


		/**
		 * Prefix incerment operation. 		 
		 */
		DynamicArray& operator ++ ();
		//Increment each element by 1.
		//Return its own reference  after the increment.


		/**
		 * Postfix increment operation.
		*/
		DynamicArray operator ++ (int dummy);
		 //Create a copy of this DynamicArray with the current state of the elements.
		 //Increment each element of this dynamic array by 1.
		 //Return the copy dynamic array with the old values.


		/**
		 * Prefix decrement operation.		
		 */
		DynamicArray& operator -- ();
		//Decrement each element by 1.
		//Return its own reference after the decrement.


		/**
		 * Postfix decrement operation. 
		 */
		DynamicArray operator -- (int dummy);
		//Create a copy of this DynamicArray with the current state of the elements.
		//Decrement each element of this dynamic array by 1.
		//Return the copy dynamic array with the old values.

		
		/**
		 * Add operation
		 */
		DynamicArray operator + (const DynamicArray&) const;
 		//Return a new DynamicArray object where each element is the summation
		//of the corresponding elements of the two operand DynamicArray objects.
		//Add nothing if the second oparand does not have the correspong element
		//of the first operand, i.e., the second operand has less number of elemnts
		//compared to the first oparand.
		//Ignore the extra elements if the second operand has more elements than
		//the first operand.

		
		
		/**
		 * Subtract operation
		 */
		DynamicArray operator - (const DynamicArray&) const;
		//Return a new DynamicArray object where each element is the differnce
		//between the corresponding elements of the two operating DynamicArray objects.
		//Subract nothing if the second oparand does not have the correspong element
		//of the first operand, i.e., the second operand has less number of elemnts
		//compared to the first oparand.
		//Ignore the extra elements if the second operand has more elements than
		//the first operand.
		


		/**
		 * Multiply opertation
		 */
		DynamicArray operator * (const DynamicArray&) const;
		//Return a new DynamicArray object where each element is the multiplication
		//of the corresponding elements of the two operating DynamicArray objects.
		//Multiplies nothing if the second oparand does not have the correspong element
		//of the first operand, i.e., the second operand has less number of elemnts
		//compared to the first oparand.
		//Ignores the extra elements if the second operand has more elements than
 		//the first operand.
		

		/*
		 * Equal operation
		 */
		bool operator == (const DynamicArray&) const;
		//Compare this dynamic array with another dynamic array.
		//Return true if the compared dynamic arrays have the same capacity, same number
		//of elements, and the elements at the same indices in both dynamic arrays are
		//same.


		/**
		 * Constant Index operation.
		 */
		int operator [] (int) const;
		//Return the nth element of the dynamic array.
		//Throw an error message (c-string) if the index n is beyond current
		//size of this dynamic array.
			


		/**
		 * Index operation.
		 */
		int& operator [] (int);
		//Return the address of nth element of the dynamic array.
		//Throw an error message (c-string) if the index n is beyond current
		//size of this dynamic array. Use throw statement, e.g., throw "Index out of bound!";
		


		/**
		 * Stream extract operation.
		 */
		friend std::istream& operator >> (std::istream&, DynamicArray&);
		//Extract all elements from the input stream and insert them into the dynamic array 
		//one after another. 
		

		/**
		 * Stream insert operation.
		 */
		friend std::ostream& operator << (std::ostream&, const DynamicArray&);
		//Insert all elements of the dynamic array into the output stream.
		//Separate the elements by a space during this insertion.
		
		friend class DynamicArrayTest;
};



#endif
