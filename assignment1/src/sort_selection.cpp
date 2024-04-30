/**
 * @file sort_selection.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date January 24, 2024
 *
 * Implement sort() function defined in sort.h header file using selection sort algorithm for an array of integers.
 */


#include "sort.h"

//You are allowed to add more helper functions to call from your sort() function in this file.

// Function that swaps two elements.
void swap (int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
}

// Implements selection sort algorithm.
void sort(int* array, const int size) {
    
    // Moves the sorted 'wall' forward one element with each pass.
    for (int i = 0; i < size-1; i++) { 
        int min = i; // Sets smallest value element to the first element.
        
        // Looks for an unsorted element smaller than min.
        for (int j = i+1; j < size; j++) { 
            if (array[j] < array[min]) { // If element is smaller than current min, assigns it to min.
                min = j;
            }
        }
        // Swaps first element of unsorted half with min of unsorted half.
        swap(array[i], array[min]);
    }
}


