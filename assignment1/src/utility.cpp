/**
 * @file utility.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date January 24, 2024
 *
 * Implement utility functions defined in utility.h header file.
 */


#include "sort.h"
#include "utility.h"
#include <fstream>
#include <iostream>


// Gathers input file data and copies it to an array.
void load (const char* filename, int*& array, int &size) {
	ifstream inputArray(filename);
	if (!inputArray) {
		std::cout << "Can't open " << filename << " file to read." << std::endl;
	}
	// Assigns first number to array size and allocates memory for array.
	int number;
	inputArray >> number;
	size = number;
	array = new int[size];
    
    // Copies file data to array.
	for (int i = 0; i < size; i++) {
		inputArray >> number;
		array[i] = number;
	}
	inputArray.close();
}

// Outputs array data to an output file.
void save(const int *data, const int size, const char* filename) {
	if (size == 0) {
		std::cout << "Array size is 0. Terminating." << std::endl;
	}
	ofstream outputArray(filename);
	// First number in the file, the size value, is copied.
	outputArray << size << " ";
	
	// Copies the entire array into the output file.
	for (int i = 0; i < size; i++) {
		outputArray << data[i] << " ";
	}
	outputArray.close();
}

// Duplicates a given array into a copy array.
int* duplicate(const int* data, const int size) {
    int* arrayCopy = new int[size];
    
    for (int i = 0; i < size; i++) {
        arrayCopy[i] = data[i];
    }
    return arrayCopy;
}

// Prints the current state of the array to the console.
void show(const int *array, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// Calls the sort function for whatever sorting algorithm is linked and sorts the array.
void sortOriginal(int *array, const int size) {
    sort(array, size);
}


// Creates a copy of a given array with the duplicate function and sorts it.
int* sortCopy(const int *array, const int size) {
	int* arrayCopy = duplicate(array, size);
	sort(arrayCopy, size);
	return arrayCopy;
}


