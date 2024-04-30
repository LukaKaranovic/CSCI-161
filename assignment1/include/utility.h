/**
 * @file utility.h
 * @author Humayun Kabir, Instrcutor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Defines utility functions related to an array of integers.
 */



#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__

using namespace std;


void load (const char* filename, int*& array, int &size);
//Open the file specified by 'filename' in read only mode.
//The first number in the file represents the data size.
//The rest of the numbers in the file are actual data.
//The first number is not included in the actual data.
//Each line in the file has one number.
//Read the data size from the file and allocate memory dynamically based on the read size.
//Assign the address of the allocated memory to the passed 'array' reference of pointer parameter.
//Read all the data elements into the array one after another.
//Close the file when all data elements have been read and placed into the array.



void save(const int *data, const int size, const char* filename);
//If the size of the data array is zero, do nothing, return.
//Open the file specified by 'filename' in write only mode.
//Write the size of the array into the file first and separate the data from the size by a space.
//Write each element of the array one after another separated spaces.
//Close the file when all elements have written into it.


void show(const int *array, const int size);
//Loop through the array and print all elements from the array.
//Separate two elements by a space.


int* duplicate(const int* data, const int size);
//Create a new array of size parameter 'size' by alloacting memory dynamically
//Copy each element from the original 'array' into the new array.
//Return the new array.


void sortOriginal(int *array, const int size);
//Sort the original array in ascending order using any one sorting
//algorithm from the followings:
//	1. Bubble
//	2. Selection
//	3. Insertion
//	4. Merge
//	5. Quick
//Don't pick the sorting algorithm in your code, i.e., during compile time.
//The sorting algorithm is picked during the linking time.	



int* sortCopy(const int *array, const int size);
//Make a copy of the original array into another array.
//Sort the copied array in ascending order using any one sorting
//algorithm from the followings:
//	1. Bubble
//	2. Selection
//	3. Insertion
//	4. Merge
//	5. Quick
//Don't pick the sorting algorithm in your code, i.e., during compile time.
//The sorting algorithm is picked during the linking time.
//Return the sorted copy of the array.	



#endif
