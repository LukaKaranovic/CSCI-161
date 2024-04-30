/**
 * @file sort_insertion.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date January 24, 2024
 *
 * Implement sort() function defined in sort.h header file using insertion sort algorithm for an array of integers.
 */

#include "sort.h"

//You are allowed to add more helper functions to call from your sort() function in this file.

// Implements insertion sort algorithm.
void sort(int* array, const int size) {
	
	// Moves the sorted 'wall' forward one element with each pass.
	for (int i = 1; i < size; i++) {
	    int temp = array[i]; // Saves data of new element. 
	    int j = i; 
	    
	    // Checks if element being added to sorted part of array is smaller than any elements already sorted.
	    for (; (j > 0) && (temp < array[j-1]); j--) {
	        // Replaces new element with the greater value element (shifting greater values right). 
	        array[j] = array[j-1];
	    }
	    array[j] = temp; // Data of new element is applied in the correct index.
	}
}

