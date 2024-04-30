/**
 * @file simpleset.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Defines a SimpleSet class.
 * SimpleSet class uses DynamicArray class as its base class.
 * All the elements in a SimpleSet class must be unique.
 * A SimpleSet object starts with a fixed capacity but that can be expanded when the
 * set grows beyond the capacity.	
 * 
 */
 



#ifndef __SIMPLESET_HEADER__
#define __SIMPLESET_HEADER__

#include "dynamicarray.h"

class SimpleSet: public DynamicArray {

	public:
	
		/*
		 * Allow using overloaded insert function from the base class
		 */	
		using DynamicArray::insert;

		/**
		 * Default constructor
		 */
		SimpleSet();


		/**
		 * Regular constructor
		 */
		SimpleSet(int capacity);

		/**
		 * Overloaded Regular constructor
		 */
		SimpleSet(const int* array, const int array_size);
		//Create a DynamicArray of capacity equal to array_size.
		//Copy all the unique elements from the array into your SimpleSet elements.
		//Remember SimpleSet must not contain duplicate elements and the size of your SimpleSet
		//should reflect the actual number of elements copied into it. 



		/**
		 * Copy constructor
		 */
		SimpleSet(const SimpleSet&);


		/**
		 * Move constructor.
		 */
		SimpleSet(SimpleSet&&);


		/**
		 * Destructor
		 */
		~SimpleSet();


		/*
		 * Overriding insert(const int element) function
		 */
		void insert(const int element) override;
		//Check whether there is an exisiting element in the set with the same value.
		//Insert the new element at the end of set if there is no other element in the set with
		//the same value.
		//Increase the capacity to the twice of its current value if the number of elements in the
		//set exceeds the current capacity. 
		//Reallocate memory for increased capacity. 
		//Copy the old elements to the newly allocated memory locations. 
		//Add the new element at the end of the old elements in the newly allocated memory.
		//Free previously allocated memory. 
		//Assign the address of the newly allocated memory to the appropriate pointer of the set.


		/*
		 * Overriding insert(const int array[], const int size)
		 */
		void insert(const int array[], const int size);
		//Insert all the elements from the array into your simple set except the duplicates.
		//At any point of insertion, if the capacity is full, double 
		//the capacity and continue the insertion until all array elements have been inserted.
		//Increment the size of the dynamic array after each insertion.


		/**
		 * Copy assignment of the set.
		 */
		SimpleSet& operator = (const SimpleSet&);


		/**
		 * Move assignment.
		 */
		SimpleSet& operator = (SimpleSet&&);

		
		/*
		 * Overloading prefix increment (++) operator
		 */
		SimpleSet& operator++();
		//Increment each element of this simpleset by 1.
		//Return the reference of this simpleset.


		/*
		 * Overloading postfix increment (++) operator
		 */
		SimpleSet operator++(int);
		//Create a copy simpleset from this simpleset.
		//Increment each element of this simpleset by 1.
		//Return the copy simpleset.
		
		
		/*
		 * Overloading prefix decrement(--) operator
		 */
		SimpleSet& operator--();
		//Decrement each element of this simpleset by 1.
		//Return the reference on this simpleset.
		
		
		/*
		 * Overloading postfix decrement operator
		 */
		SimpleSet operator--(int);
		//Create a copy simpleset from this simpleset.
		//Decrement each element of this simpleset by 1.
		//Return the copy simpleset.

		
		/**
		 * Overloading + operator to perform set union operation.
		 */
		SimpleSet operator + (const SimpleSet&) const;
		//Create a SimpleSet taking the elements from the both SimpleSet objects, 
		//make sure the resultant SimpleSet does not have any duplicate.
		//Return the resultant SimpleSet.
		

		
		/**
		 * Overloading - operator to perform set difference operation
		 */
		SimpleSet operator - (const SimpleSet&) const;
		//Create a SimpleSet taking the elements from this SimpleSet object, only if
		//that element does not exist in the other SimpleSet object.
		//Return the resultant SimpleSet.


		/**
		 * Overloading * operator to perform set intersection operation.
		 */
		SimpleSet operator * (const SimpleSet&) const;
		//Create a SimpleSet taking only those elements that exist in both SimpleSet
		//objects.
		//Return the resultant SimpleSet.


		/**
		 * Overloading == operator to perform set equality operation.
		 */
		bool operator == (const SimpleSet&) const;
		//Return true if both SimpleSet operands have the same size and same elements, not
		//necessarily at the same position.
		//Return false otherwise.


		
		
		/**
		 * Stream extract operation.
		 * Although SimpleSet class is not inheriting DynamicArray's 'operator >> ()'
		 * friend function SimpleSet does not need its own friend function to
		 * have this extraction functionality.
		 * This functionality on SimpleSet class will be achieved through 
		 * runtime polymorphism by passing a SimpleSet class object
		 * through DynamicArray class reference in DynamicArray's 'operator >>()'
		 * friend function.
		 * This will only work if DynamicArray's 'operator >> ()' friend function
		 * uses its virtual function 'insert()' to insert a new element into a
		 * DynamicArray object.
		 */
		//friend std::istream& operator >> (std::istream&, SimpleSet&);
		//Extract all the elements from the input stream and insert the extracted elements into 
		//the set only if there is no duplicate in the set.
		


		/**
		 * Stream insert operation.
		 * Same comments as 'operator >>()' function except the use of virtual function
		 * 'insert()'.
		 */
		//friend std::ostream& operator << (std::ostream&, const SimpleSet&);
		//Insert all elements of the simple set into the output stream.
		//Separate the elements by a space during this insertion.
		
		friend class SimpleSetTest;
};


#endif
