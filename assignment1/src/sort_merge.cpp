/**
 * @file sort_merge.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date January 24, 2024
 *
 * Implement sort() function defined in sort.h header file using merge sort algorithm for an array of integers.
 */

#include "sort.h"


//You are allowed to add more helper functions to call from your sort() function in this file.

// Merges two subarrays together into a sorted array.
void merge(int* array, int first, int mid, int last) {
    // Assigns appropriate variables to split array into two subarrays.
    int tempArray[last + 1];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    
    // Compares the first element of both subarrays, copies the smaller first element to sorted array.
    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (array[first1] < array[first2]) {
            tempArray[index] = array[first1];
            ++first1;
        } else {
            tempArray[index] = array[first2];
            ++first2;
        }
    }
    
    // Finishes off the first subarray if there are remaining elements.
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = array[first1];
    }
    
    // Finishes off the second subarray if there are remaining elements.
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = array[first2];
    }
    
    // Copies the sorted result back to the original array.
    for (index = first; index <= last; ++index) {
        array[index] = tempArray[index];   
    }

}

// Contains the merge sort algorithm.
void mergesort(int* array, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        // Calls recursively, splitting the array into subarrays.
        mergesort(array, first, mid);
        mergesort(array, mid+1, last);
        // Merges the subarrays together.
        merge(array, first, mid, last);
    }
}


// Calls the merge sort algorithm.
void sort(int* array, const int size) {
    int first = 0;
    int last = size - 1;
    mergesort(array, first, last);
}


