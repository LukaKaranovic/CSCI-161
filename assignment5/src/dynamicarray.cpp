/**
 * @file dynamicarray.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date April 8, 2024
 *
 * Implements a DynamicArray template class defined in 'dynamicarray.h' header file.
 * 
 */
 
#include <iostream>
#include <cstring>

#include "dynamicarray.h"
#include "keyvalue.h"

using namespace std;
/*
 * Implement all the functions of DynamicArray template class.
 */

/** @brief Default Constructor
 *
*/

template <typename T>
DynamicArray<T>::DynamicArray(): _capacity(DEFAULT_CAPACITY), _size(0), _elements(new T[DEFAULT_CAPACITY]) {}

/** @brief Regular Constructor
 *
*/

template <typename T>
DynamicArray<T>::DynamicArray(const int capacity): _capacity(capacity), _size(0), _elements(new T[capacity]) {}

/** @brief Copy constructor. Deep copies from another dynamic array.
 *
 *  Deep copies another dynamic array's capacity, size, and elements.
 *
 *  @param other The source dynamic array containing the capacity, size, 
 *  and elements. 
 *  
 */

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other): _capacity(other._capacity), _size(other._size), _elements(new T[_capacity]) {
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

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& temp): _capacity(temp._capacity), _size(temp._size), _elements(temp._elements) {
    temp._elements = nullptr;
}

/** @brief Destructor. Clears every element from the dynamic array.
 * 
*/

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] _elements;
}

/** @brief Returns the dynamic array's capacity.
 *
 *  @return The capacity of the dynamic array. 
*/

template <typename T>
int DynamicArray<T>::capacity() const {
    return _capacity;
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

template <typename T>
void DynamicArray<T>::insert(const T element) {
    if (_size == _capacity) {
        T* tempArray = new T[_capacity * 2];
        for (int i = 0; i < _size; i++) {
            tempArray[i] = _elements[i];
        }
        _elements = tempArray;
        _capacity = _capacity * 2;
    }
    _elements[_size] = element;
    _size++;
}

/** @brief Returns the dynamic array's current size.
 * 
 *  @return The current size of the dynamic array.
*/  

template <typename T>
int DynamicArray<T>::size() const {
    return _size;
}

/** @brief Checks if the dynamic array is empty or not. Returns true if 
 *         it is empty, and false if it is not empty.
 *
 *  A dynamic array is empty if its current size is 0.
 *
 *  @return The boolean value stating whether the dynamic array is empty or not.
*/

template <typename T>
bool DynamicArray<T>::empty() const {
    return _size == 0;
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

template <typename T>
int DynamicArray<T>::search(const T element) const {
    for (int i = 0; i < _size; i++) {
        if (element == _elements[i]) {
            return i;
        }
    }
    return -1;
}

/** @brief Removes an element at a specific index from the dynamic array.
 *
 *  Removes the element at the passed index. Shifts everything to the right of that element
 *  one index to the left, ensuring there are no gaps in the array. Decreases the size
 *  by one.
 *
 *  @param index The index of the element being removed from the dynamic array.
 *  @return Void.
*/

template <typename T>
void DynamicArray<T>::eraseAt(const int index) {
    if (index < 0 || index >= _size) {
        throw("Index is out of bounds!");
    } 
    for (int i = index; i < _size - 1; i++) {
        _elements[i] = _elements[i+1];
    }
    _size--;

}

/** @brief Removes a specific element from the dynamic array.
 *
 *  Searches for the target element in the dynamic array. If found, deletes the
 *  index of the element and shifts everything to the right of that element one
 *  index to the left, ensuring there are no gaps in the array. Decreases the size
 *  by one.
 *
 *  @param element The element being deleted from the dynamic array.
 *  @return True if the element is found and removed and false if not.
*/

template <typename T>
bool DynamicArray<T>::erase(const T element) {
    int i = search(element);
    if (i != -1) {
        for (; i < _size - 1; i++) {
            _elements[i] = _elements[i+1];
        }
        _size--;
        return true;
    }
    return false;
}

/** @brief Clears the dynamic array by setting the size to 0.
 *
 *  @return Void.
*/

template <typename T>
void DynamicArray<T>::clear() {
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

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    _size = other._size;
    _capacity = other._capacity;
    _elements = new T[_capacity];
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

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator = (DynamicArray&& temp) {
    if (this == &temp) {
        return *this;
    }
    _size = temp._size;
    _capacity = temp._capacity;
    _elements = temp._elements;
    temp._elements = nullptr;
    return *this;
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

template <typename T>
T DynamicArray<T>::operator [] (const int index) const {
    if (index < 0 || index > _size) {
        throw("Index is out of bounds!");
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

template <typename T>
T& DynamicArray<T>::operator [] (const int index) {
    if (index < 0 || index > _size) {
        throw("Index is out of bounds!");
    } else {
        return *(_elements + index);
    }

}