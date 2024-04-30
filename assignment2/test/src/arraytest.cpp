/**
 * @file arraytest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 11, 2023
 * 
 * Implements functions defined in 'arraytest.h'.
 *
 */


#include "arraytest.h"

bool isSameElements(const int* array1, const int* array2, const int size) {
	for(int i=0; i<size; i++) {
		if(array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}
