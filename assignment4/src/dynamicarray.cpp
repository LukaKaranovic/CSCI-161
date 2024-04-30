/**
 * @file dynamicarray.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date March 29, 2024
 *
 * Implements DynamicArray class functions defined in dynamicarray.h header file.
 * 
 */

#include <iostream>
#include <fstream>

#include "dynamicarray.h"
#include "utility.h"

using namespace std;

/** @brief Default Constructor
 *
*/

DynamicArray::DynamicArray(): _capacity(DEFAULT_CAPACITY), _size(0), _elements(new int[DEFAULT_CAPACITY]) {}

/** @brief Constructor
 *
*/

DynamicArray::DynamicArray(const int capacity): _capacity(capacity), _size(0), _elements(new int[capacity]) {}

/** @brief Overloaded Constructor. For creating a dynamicarray off of an existing array.
 *
*/

DynamicArray::DynamicArray(const int* array, const int array_size): _capacity(array_size), _size(array_size), _elements(new int[array_size]) {
    for (int i = 0; i < array_size; i++) {
        _elements[i] = array[i];
    }
}

/** @brief Copy constructor. Deep copies from another dynamic array.
 *
 *  Deep copies another dynamic array's capacity, size, and elements.
 *
 *  @param other The source dynamic array containing the capacity, size, 
 *  and elements. 
 *  
 */

DynamicArray::DynamicArray(const DynamicArray& other): _capacity(other._capacity), _size(other._size), _elements(new int[_capacity]) {
    for (int i = 0; i < _size; i++) {
        _elements[i] = other._elements[i];
    }
}

/** @brief Move constructor. Shallow copies from another dynamic array.
 *
 *  Shallow copies an R-value dynamic array's capacity, size, and elements pointer.
 *  Ensures the R-value's elements pointer is empty after assignment
 *
 *  @param other The source dynamic array containing the capacity, size, 
 *  and elements.
 *  
 */

DynamicArray::DynamicArray(DynamicArray&& temp): _capacity(temp._capacity), _size(temp._size), _elements(temp._elements) {
    temp._elements = nullptr;
}

/** @brief Destructor. Clears every element from the dynamic array.
 * 
*/

DynamicArray::~DynamicArray() {
    delete[] _elements;
}

/** @brief Returns the dynamic array's current size.
 * 
 *  @return The current size of the dynamic array.
*/  

int DynamicArray::size() const {
    return _size;
}

/** @brief Returns the dynamic array's capacity.
 *
 *  @return The capacity of the dynamic array. 
*/

int DynamicArray::capacity() const {
    return _capacity;
}

/** @brief Checks if the dynamic array is empty or not. Returns true if 
 *         it is empty, and false if it is not empty.
 *
 *  A dynamic array is empty if its current size is 0.
 *
 *  @return The boolean value stating whether the dynamic array is empty or not.
*/

bool DynamicArray::empty() const {
    return _size == 0;
}

/** @brief Inserts a new element into the dynamic array.
 *
 *  Inserts a new element into the dynamic array at the rightmost index. If the
 *  size exceeds the capacity, a new array with double the capacity is created
 *  and everything is copied into that array. The new array replaced the current array.
 *  Increases the size by one.
 *
 *  @param element The element value to be inserted into the dynamic array.
 *  @return Void.
*/

void DynamicArray::insert(const int element) {
    if (_size == _capacity) {
        int* tempArray = new int[_capacity * 2];
        for (int i = 0; i < _size; i++) {
            tempArray[i] = _elements[i];
        }
        _elements = tempArray;
        _capacity = _capacity * 2;
    }
    _elements[_size] = element;
    _size++;
}

/** @brief Inserts all of the elements from an array into the dynamic array.
 *
 *  For each element of the parameter array, the original insert function is called on
 *  it. Every element from the array will be inserted into the dynamic array. 
 *
 *  @param array The array containing all of the elements to be inserted.
 *  @param size The size of the passed array.
 *  @return Void.
*/

void DynamicArray::insert(const int array[], const int size) {
    for (int i = 0; i < size; i++) {
        insert(array[i]);    
    }
}

/** @brief Searches for a specific element in the dynamic array.
 *
 *  Iteratively searches for the passed element value within the array.
 *  Returns an invalid index if the element is not found in the array.
 *
 *  @param element The element value being searched for.
 *  @return The index of the element being searched for. 
 *          Returns -1 if the element is not found.
*/

int DynamicArray::search(const int element) const {
    for (int i = 0; i < _size; i++) {
        if (element == _elements[i]) {
            return i;
        }
    }
    return -1;
}

/** @brief Returns an array copy of the dynamic array.
 *
 *  Dynamicallly allocates a temporary array where each element in elements
 *  is copied into the temporary array in the same order.
 *
 *  @return The address of the temporary array copy.
*/

int* DynamicArray::elements() const {
    if (empty()) {
        return nullptr;
    } else {
        int* tempArray = new int[_size];
        for (int i = 0; i < _size; i++) {
            tempArray[i] = _elements[i];
        }
        return tempArray;
    }
}

/** @brief Removes a specific element from the dynamic array.
 *
 *  Searches for the target element in the dynamic array. If found, deletes the
 *  index of the element and shifts everything to the right of that element one
 *  index to the left, ensuring there are no gaps in the array. Decreases the size
 *  by one.
 *
 *  @param element The element being deleted from the dynamic array.
 *  @return Void.
*/

void DynamicArray::erase(const int element) {
    int i = search(element);
    if (i != -1) {
        for (; i < _size; i++) {
            _elements[i] = _elements[i+1];
        }
        _size--;
    }
}

/** @brief Clears the dynamic array by setting the size to 0.
 *
 *  @return Void.
*/

void DynamicArray::clear() {
    _size = 0;
} 

/** @brief Copy assignmnt. Deep copies the values from another dynamic array.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies element values in the same order from a source dynamic array to the current
 *  dynamic array. The two arrays should be equal after the copy.
 *
 *  @param other The source dynamic array containing the capacity, size,   
 *  elements pointer, and elements.
 *  @return The updated version of the dynamic array.
 */

DynamicArray& DynamicArray::operator = (const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    _size = other._size;
    _capacity = other._capacity;
    _elements = new int[_capacity];
    for (int i = 0; i < _size; i++) {
        _elements[i] = other._elements[i];
    }
    return *this;
}

/** @brief Move assignmnt. Shallow copies from another dynamic array.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies an R-value dynamic array's capacity, size, and elements, assigning it a new name.
 *  Ensures the temporary R-value dynamic array's pointers are null after assignment.
 *
 *  @param temp An R-value dynamic array containing the capacity, size,   
 *  elements pointer, and elements.
 *  @return The updated version of the dynamic array.
 */

DynamicArray& DynamicArray::operator = (DynamicArray&& temp) {
    if (this == &temp) {
        return *this;
    }
    _size = temp._size;
    _capacity = temp._capacity;
    _elements = temp._elements;
    temp._elements = nullptr;
    return *this;
}

/** @brief Pre-Increment. Pre-increments every element in the array by 1.
 *
 *  Overloads the pre-increment (++) operator so that it does the following:
 *  Increments the value of every element in the array by 1.
 *
 *  @return The updated version of the dynamic array.
 */

DynamicArray& DynamicArray::operator ++ () {
    for (int i = 0; i < _size; i++) {
        _elements[i]++;
    }
    return *this;
}

/** @brief Post-Increment. Post-increments every element in the array by 1.
 *
 *  Overloads the post-increment (++) operator so that it does the following:
 *  Creates a temporary copy of the dynamic array. Increments the value of every element 
 *  in the array by 1. Returns the un-incremented copy of the array first.
 *
 *  @param dummy The int dummy to tell the compiler it is a post-inrement operation.
 *  @return The temporary un-incremented version of the dynamic array.
 */

DynamicArray DynamicArray::operator ++ (int dummy) {
    DynamicArray temp(*this);
    ++(*this);
    return temp;
}

/** @brief Pre-Decrement. Pre-decrements every element in the array by 1.
 *
 *  Overloads the pre-decrement (--) operator so that it does the following:
 *  Decrements the value of every element in the array by 1.
 *
 *  @return The updated version of the dynamic array.
 */

DynamicArray& DynamicArray::operator -- () {
    for (int i = 0; i < _size; i++) {
        _elements[i]--;
    }
    return *this;
}

/** @brief Post-Decrement. Post-decrements every element in the array by 1.
 *
 *  Overloads the post-decrement (--) operator so that it does the following:
 *  Creates a temporary copy of the dynamic array. Decrements the value of every element 
 *  in the array by 1. Returns the un-decremented copy of the array first.
 *
 *  @param dummy The int dummy to tell the compiler it is a post-decrement operation.
 *  @return The temporary un-decremented version of the dynamic array.
 */

DynamicArray DynamicArray::operator -- (int dummy) {
    DynamicArray temp(*this);
    --(*this);
    return temp;
}

/** @brief Adds the values of an input array to the existing array's element values.
 *
 *  Overloads the addition (+) operator so that it does the following:
 *  For every element in the current array, adds the value from the same index of 
 *  the input array. If the input array is bigger than the current array, the values
 *  from the input array will be ignored.
 *
 *  @param rhs The input dynamic array data structure containing a capacity, size,
 *             and array of elements.
 *  @return An updated copy of the dynamic array with the values added.
 */

DynamicArray DynamicArray::operator + (const DynamicArray& rhs) const {
    DynamicArray array(*this);
    for (int i = 0; (i < rhs._size && i < _size); i++) {
        array._elements[i] += rhs._elements[i];
    }
    return array;
}

/** @brief Subtracts the values of an input array to the existing array's element values.
 *
 *  Overloads the subtraction (-) operator so that it does the following:
 *  For every element in the current array, subtracts the value from the same index of 
 *  the input array. If the input array is bigger than the current array, the values
 *  from the input array will be ignored.
 *
 *  @param rhs The input dynamic array data structure containing a capacity, size,
 *             and array of elements.
 *  @return An updated copy of the dynamic array with the values subtracted.
 */

DynamicArray DynamicArray::operator - (const DynamicArray& rhs) const {
    DynamicArray array(*this);
    for (int i = 0; (i < rhs._size && i < _size); i++) {
        array._elements[i] -= rhs._elements[i];
    }
    return array;
}

/** @brief Multiplies the values of an input array to the existing array's element values.
 *
 *  Overloads the multiplication (*) operator so that it does the following:
 *  For every element in the current array, multiplies the value from the same index of 
 *  the input array. If the input array is bigger than the current array, the values
 *  from the input array will be ignored.
 *
 *  @param rhs The input dynamic array data structure containing a capacity, size,
 *             and array of elements.
 *  @return An updated copy of the dynamic array with the values multiplied.
 */

DynamicArray DynamicArray::operator * (const DynamicArray& rhs) const {
    DynamicArray array(*this);
    for (int i = 0; (i < rhs._size && i < _size); i++) {
        array._elements[i] *= rhs._elements[i];
    }
    return array;
}

/** @brief Compares the values and structure of two dynamic arrays to see if they are equal.
 *
 *  Overloads the equality (==) operator so that it does the following: Checks if the two arrays (current and other)
 *  have the same size, capacity, and element values in the same order. If one element is out of order or the 
 *  capacity is different, the dynamic arrays are not equal. 
 *
 *  @param other The other dynamic array data structure containing a capacity, size,
 *               and array of elements.
 *  @return True if both of the dynamic arrays are equal and false if they are not.
 */

bool DynamicArray::operator == (const DynamicArray& other) const {
    if (_size != other._size) {
        return false;
    } else if (_capacity != other._capacity) {
        return false;
    }

    for (int i = 0; i < _size; i++) {
        if (_elements[i] != other._elements[i]) {
            return false;
        }
    }
    return true;
}

/** @brief Returns the element in the dynamic array at the passed index value.
 *
 *  Overloads the index ([]) operator so that it does the following:
 *  Returns the appropriate element in the array based on the passed index parameter.
 *  If the passed index is out-of-bounds (e.g. a negative index or an index greater than size),
 *  then an error is given to the user. This function is able to be used on constant dynamic arrays.
 *
 *  @param index The index of the element the user wishes to access.
 *  @return The element in the dynamic array at the passed index.
 */

int DynamicArray::operator [] (int index) const {
    if (index < 0 || index > _size) {
        cerr << "Index " << index << " is out of bounds!" << endl;
    } else {
        return *(_elements + index);
    }
}

/** @brief Returns the address of the element in the dynamic array at the passed index value.
 *
 *  Overloads the index ([]) operator so that it does the following:
 *  Returns the appropriate address of the element in the array based on the passed index parameter.
 *  If the passed index is out-of-bounds (e.g. a negative index or an index greater than size),
 *  then an error is given to the user. 
 *
 *  @param index The index of the element the user wishes to access.
 *  @return The memeory address of the element in the dynamic array at the passed index.
 */

int& DynamicArray::operator [] (int index) {
    if (index < 0 || index > _size) {
        cerr << "Index " << index << " is out of bounds!" << endl;
    } else {
        return *(_elements + index);
    }
}

/** @brief Stream extraction operator. Extracts elements from an input stream and puts them into the dynamic array.
 *
 *  While there is an integer value available in the input stream, it will be inserted into the dynamic array
 *  at the next available index.
 *
 *  @param in The address of the input stream.
 *  @param arr The dynamic array reference taking the data from the input stream.
 *  @return The input stream is returned after all of the information has been extracted.
 */

istream& operator >> (std::istream& in, DynamicArray& arr) {
    int number;
    while(in >> number) {
        arr.insert(number);
    }
    return in;
}

/** @brief Stream insertion operator. Takes elements from a dynamic array and puts them into the output stream.
 *
 *  Iteratively goes through the dynamic array from start to finish, inserting every element in order separated by a space.
 *
 *  @param out The address of the output stream.
 *  @param arr The dynamic array reference taking the data from the input stream.
 *  @return The output stream is returned after all of the information has been inserted.
 */

ostream& operator << (std::ostream& out, const DynamicArray& arr) {
    for (int i = 0; i < arr._size; i++) {
        out << arr._elements[i] << " ";
    }
    return out;
}
