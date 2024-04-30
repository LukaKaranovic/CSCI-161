/**
 * @file main.cpp
 * @author Humayun Kabir, Instrcutor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * The main module for assignment1.
 * Performs test usages of the fucntions from 'utility.cpp', and 'sort_xxx.cpp'.
 * Loads integer data from a file into a dynamically memory alocated  array.
 * Sorts the original and a copy of the array using a selected sorting algorithm.
 * Sorting algorithm is selected by linking this module's object file with a selected
 * implementation onbject file. For example in order to use bubble sort algorithm the
 * object file from this module is linked with the object file of a module which
 * has implemented bubble sort algorithm.
 *
 */



#include <iostream>
#include <string>

#include "utility.h"


using namespace std;

/** 
 * The main function that accepts the paths of the input and output files as a command line argument.
 */
int main(int argc, char** argv) {

	int *originalArray = NULL;
	int size;

	/*
	 * Check whether file names have been passed as the command line arguments or not
	 */
	if(argc<3) {
		cout<<"Usage: "<<argv[0]<<"  <input-file> <output-file>"<<endl;
		exit(1);
	}
	
	/*
	 * Filenames are in command line arguments
	 */	
	//Input file name is in argv[1]
	//Output file name is in argv[2]

	/*
	 * Loading data into an array from the file.
	 */
	cout<<"Loading array size and array elements from the input file: "<<argv[1]<<endl;
	load(argv[1], originalArray,  size);

	cout<<"Array size is: "<<size<<endl;

	cout<<"Array elements are below:"<<endl; 
	show(originalArray, size);


	/*
	 * Sorting a copy of the array
	 */
	int *sortedCopy = sortCopy(originalArray, size);
	
	cout<<"Sorted copy of the array:"<<endl;
	show(sortedCopy, size);
	
	cout<<"Unsorted original array: "<<endl;
	show(originalArray, size);
	
	/*
	 * Soring the original array
	 */
	sortOriginal(originalArray, size);

	cout<<"Sorted original array: "<<endl;
	show(originalArray, size);

	
	/*
	 * Saving the sorted array into a file
	 */
	cout<<"Saving sorted original array into the output file: "<<argv[2]<<endl;
	save(originalArray, size, argv[2]);


	/*
	 * Releasing memory from the arrays
	 */

        if(sortedCopy !=NULL) {
		cout<<"Freeing memory from the array copy"<<endl;
		delete [] sortedCopy;
	}

	if(originalArray != NULL){
		cout<<"Freeing memory from the original array"<<endl;
		delete [] originalArray;
	}

	return 0;
}
