/**
 * @file sort_bubble.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date Januaryy 24, 2024
 *
 * Implement sort() function defined in sort.h header file using bubble sort algorithm for an array of integers.
 */

#include "sort.h"

//You are allowed to add more helper functions to call from your sort() function in this file.

// Swaps two elements to move smallest element to the left of array.
void swap(int &left, int &right) { 
    int temp = left;
    left = right;
    right = temp;
}

// Implements bubble sort algorithm.
void sort(int* array, const int size) { 
	int last = size - 1;
	bool sorted = false; // Further optimization.
	for (int i = 0; (i < last) && !sorted; i++) { // Moves the sorted 'wall' over with each pass.
        sorted = true; 
	    // Starting from the right end of array, compares each element to the next element to the left.
	    for (int j = last; j > i; j--) { 
	        if (array[j-1] > array[j]) { // Swaps the two elements if left element is larger.
	            swap(array[j], array[j-1]);
	            sorted = false; 
	        }
	    }
	}
}




