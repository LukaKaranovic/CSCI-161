/**
 * @file sort_quick.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date January 24, 2024
 *
 * Implement sort() function defined in sort.h header file using quick sort algorithm for an array of integers.
 */


#include "sort.h"

//You are allowed to add more helper functions to call from your sort() function in this file.

// Swaps two elements if called.
void swap(int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
}

// Partitions the array around a pivot.
void partition(int* array, int first, int last, int &pivotIndex) {
    int pivot = array[first];
    int lastS1 = first;
    int firstUnknown = first + 1;
    // Iterates through every unknown value.
    for (; firstUnknown <= last; ++firstUnknown) {
        // If value is less than pivot, the element is put in S1.
        if (array[firstUnknown] < pivot) {
            ++lastS1;
            swap(array[firstUnknown], array[lastS1]);
        }
    // Else: Increments firstUnknown (moves S2 wall), putting element in S2.
    }
    
    // Moves pivot in between S1 and S2, and assigns appropriate pivotIndex value.
    swap(array[first], array[lastS1]);
    pivotIndex = lastS1;

}

// Contains the quick sort algorithm.
void quicksort(int* array, int first, int last) {
    int pivotIndex;
    if (first < last) {
        // Creates the partition (division between S1, pivot, and S2).
        partition(array, first, last, pivotIndex);
        
        // Splits and sorts regions of S1 and S2.
        quicksort(array, first, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, last);
    }
}


// Calls the quick sort algorithm
void sort(int* array, const int size) { 
    int first = 0;
    int last = size - 1;
    quicksort(array, first, last);
}


