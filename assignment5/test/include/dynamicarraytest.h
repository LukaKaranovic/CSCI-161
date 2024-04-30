/**
 * @file dynamicarraytest.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date March 18, 2024
 * 
 * Declares the prototype of unit test class DynamicArrayTest and its functions that will be used 
 * to perform unit test on the functions of DynamicArray class.
 *
 */

#ifndef __DYNAMIC_ARRAY_TEST_HEADER__
#define __DYNAMIC_ARRAY_TEST_HEADER__

#include "dynamicarray.h"

template<typename T>
class DynamicArrayTest {
    public:
        static void insertArray(T* array, const int size, DynamicArray<T>& darray);
        static bool isSameElements(T* array1, T* array2, const int size);
        DynamicArray<T> static createDynamicArray(T* array, const int size);
        static bool testDefaultConstructor();
        static bool testConstructor();
        static bool testCapacity();
        static bool testInsert(T* array, const int size);
        static bool testSize(T* array, const int size);
        static bool testEmpty(T* array, const int size);
        static bool testSearch(T* array, const int size);
        static bool testErase(T* array, const int size);
        static bool testEraseAt(T* array, const int size);
        static bool testClear(T* array, const int size);
        static bool testIndexValue(T* array, const int size);
        static bool testIndexReference(T* array, const int size);
        static bool testCopyConstructor(T* array, const int size);
        static bool testMoveConstructor(T* array, const int size);
        static bool testCopyAssignment(T* array, const int size);
        static bool testMoveAssignment(T* array, const int size);     

};

#endif