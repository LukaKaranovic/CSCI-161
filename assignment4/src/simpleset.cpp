/**
 * @file simpleset.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date March 30, 2024
 *
 * Implements SimpleSet class functions defined in simpleset.h header file.
 * 
 */
 
#include <iostream>
#include <fstream>

#include "utility.h"
#include "dynamicarray.h"
#include "simpleset.h"

using namespace std;

/** @brief Default Constructor
 *
*/

SimpleSet::SimpleSet(): DynamicArray() {}

/** @brief Constructor
 *
*/

SimpleSet::SimpleSet(int capacity): DynamicArray(capacity) {}

/** @brief Overloaded Constructor. For creating a simpleset off of an existing array.
 *
*/

SimpleSet::SimpleSet(const int* array, const int array_size): DynamicArray(array, array_size) {
    for (int i = 0; i < array_size; i++) {
        insert(array[i]);
    }
}

/** @brief Copy constructor. Deep copies from another simple set.
 *
 *  Deep copies another simple set's capacity, size, and elements.
 *
 *  @param other The source simple set containing the capacity, size, 
 *  and elements.   
 *  
 */

SimpleSet::SimpleSet(const SimpleSet& other): DynamicArray(other) {}

/** @brief Move constructor. Shallow copies from another simple set.
 *
 *  Shallow copies an R-value simple set's capacity, size, and elements pointer.
 *  Ensures the R-value's elements pointer is empty after assignment
 *
 *  @param other The source simple set containing the capacity, size, 
 *  and elements.   
 *  
 */

SimpleSet::SimpleSet(SimpleSet&& temp): DynamicArray(temp) {}

/** @brief Destructor. Clears every element from the simple set.
 * 
*/

SimpleSet::~SimpleSet() {}

/** @brief Inserts a new unique element into the simple set.
 *
 *  Inserts a new unique element into the simple set at the rightmost index. If the
 *  size exceeds the capacity, a new set with double the capacity is created
 *  and everything is copied into that set. The new array replaced the current set.
 *  If the element already exists in the set, it will not be inserted. Increases the size by one.
 *
 *  @param element The element value to be inserted into the simple set.
 *  @return Void.
*/

void SimpleSet::insert(const int element) {
    if (search(element) == -1) {
        DynamicArray::insert(element);
    }
}

/** @brief Inserts all of the elements from an array into the simple set.
 *
 *  For each element of the parameter array, the original insert function is called on
 *  it. Every element from the array will be inserted into the simple set if it is unique. 
 *  Every element value from the array already in the simple set will not be added. 
 *
 *  @param array The array containing all of the elements to be inserted.
 *  @param size The size of the passed array.
 *  @return Void.
*/

void SimpleSet::insert(const int array[], const int size) {
    for (int i = 0; i < size; i++) {
        insert(array[i]);
    }
}

/** @brief Copy assignmnt. Deep copies the values from another simple set.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies element values in the same order from a source simplr set to the current
 *  simple set. The two sets should be equal after the copy.
 *
 *  @param other The source simple set containing the capacity, size,   
 *  elements pointer, and elements.
 *  @return The updated version of the simple set.
 */

SimpleSet& SimpleSet::operator = (const SimpleSet& other) {
    DynamicArray::operator = (other);
    return *this;
}

/** @brief Move assignmnt. Shallow copies from another simple set.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies an R-value simple set's capacity, size, and elements, assigning it a new name.
 *  Ensures the temporary R-value simple set's pointers are null after assignment.
 *
 *  @param temp An R-value simple set containing the capacity, size,   
 *  elements pointer, and elements.
 *  @return The updated version of the simple set.
 */

SimpleSet& SimpleSet::operator = (SimpleSet&& temp) {
    DynamicArray::operator = (temp);
    return *this;
}

/** @brief Pre-Increment. Pre-increments every element in the set by 1.
 *
 *  Overloads the pre-increment (++) operator so that it does the following:
 *  Increments the value of every element in the set by 1.
 *
 *  @return The updated version of the simple set.
 */

SimpleSet& SimpleSet::operator ++ () {
    for (int i = 0; i < _size; i++) {
        ++_elements[i];
    }
    return *this;
}

/** @brief Post-Increment. Post-increments every element in the set by 1.
 *
 *  Overloads the post-increment (++) operator so that it does the following:
 *  Creates a temporary copy of the simple set. Increments the value of every element 
 *  in the set by 1. Returns the un-incremented copy of the set first.
 *
 *  @param dummy The int dummy to tell the compiler it is a post-inrement operation.
 *  @return The temporary un-incremented version of the simple set.
 */

SimpleSet SimpleSet::operator ++ (int dummy) {
    SimpleSet temp(*this);
    ++(*this);
    return temp;
}

/** @brief Pre-Decrement. Pre-decrements every element in the set by 1.
 *
 *  Overloads the pre-decrement (--) operator so that it does the following:
 *  Decrements the value of every element in the set by 1.
 *
 *  @return The updated version of the simple set.
 */

SimpleSet& SimpleSet::operator -- () {
    for (int i = 0; i < _size; i++) {
        --_elements[i];
    }
    return *this;
}

/** @brief Post-Decrement. Post-decrements every element in the set by 1.
 *
 *  Overloads the post-decrement (--) operator so that it does the following:
 *  Creates a temporary copy of the simple set. Decrements the value of every element 
 *  in the array by 1. Returns the un-decremented copy of the set first.
 *
 *  @param dummy The int dummy to tell the compiler it is a post-decrement operation.
 *  @return The temporary un-decremented version of the simple set.
 */

SimpleSet SimpleSet::operator -- (int dummy) {
    SimpleSet temp(*this);
    --(*this);
    return temp;
}

/** @brief Forms the union of two sets.
 *
 *  Overloads the addition (+) operator so that it does the following:
 *  Forms a union of all of the unique elements from the current simple set
 *  and the other simple set.
 *
 *  @param rhs The other simple set containing a capacity, size,
 *             and array of elements.
 *  @return A new simple set that is the union of the two sets.
 */

SimpleSet SimpleSet::operator + (const SimpleSet& rhs) const {
    SimpleSet set(*this);
    for (int i = 0; i < rhs._size; i++) {
        set.insert(rhs._elements[i]);
    }
    return set;
}

/** @brief Forms the difference of two sets.
 *
 *  Overloads the subtraction (-) operator so that it does the following:
 *  Removes all of the elements from the current simple set that are
 *  present in the other simple set.
 *
 *  @param rhs The other simple set containing a capacity, size,
 *             and array of elements.
 *  @return A new simple set that is the difference of the two sets.
 */

SimpleSet SimpleSet::operator - (const SimpleSet& rhs) const {
    SimpleSet set(_size); 
    for (int i = 0; i < _size; i++) {
        if (rhs.search(_elements[i]) == -1) {
            set.insert(_elements[i]);
        }
    }
    return set;
}

/** @brief Forms the intersection of two sets.
 *
 *  Overloads the multiplication (*) operator so that it does the following:
 *  Forms a new simple set of all of the elements present in both the current
 *  simple set and the other simple set.
 *
 *  @param rhs The other simple set containing a capacity, size,
 *             and array of elements.
 *  @return A new simple set that is the intersection of the two sets.
 */

SimpleSet SimpleSet::operator * (const SimpleSet& rhs) const {
    SimpleSet set(_size);
    for (int i = 0; i < _size; i++) {
        if (rhs.search(_elements[i]) != -1) {
            set.insert(_elements[i]);
        }
    }
    return set;
}

/** @brief Compares the values of two simple sets to see if they are equal.
 *
 *  Overloads the equality (==) operator so that it does the following: Checks if the two simple sets (current and other)
 *  have the same size and element values. The elements do not have to be in the same order to be equal.
 *
 *  @param other The other dynamic array data structure containing a capacity, size,
 *               and array of elements.
 *  @return True if both of the dynamic arrays are equal and false if they are not.
 */

bool SimpleSet::operator == (const SimpleSet& rhs) const {
    if (_size != rhs._size) {
        return false;
    } 
    for (int i = 0; i < _size; i++) {
        if (rhs.search(_elements[i]) == -1) {
            return false;
        }
    }
    return true;
}

