/**
 * @file: test.cpp
 * @author: Humayun Kabir, Instrcutor, CSCI 161, VIU
 * @version: 1.0.0
 * @modified: July 21, 2020
 *
 * The test module for assignment1.
 * Performs unit test on the fucntions from 'utility.cpp', and 'sort_xxx.cpp'.
 *
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment1

#include <boost/test/unit_test.hpp>


#include <iostream>
#include <string>

#include "utility.h"
#include "sort.h"

using namespace std;

bool hasSameElements (const int* array1, const int* array2, const int size) {
	for(int i=0; i<size; i++) {
		if(array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

BOOST_AUTO_TEST_SUITE(assignment1_test_sort) 

	BOOST_AUTO_TEST_CASE(sort_test_case) {
		int testSorted[] = {9, 12, 23, 34, 44, 67, 67, 73, 87, 99};
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		sort(testArray, testSize);
		BOOST_CHECK_MESSAGE(hasSameElements(testSorted, testArray, testSize), "TEST: Sort array");
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(assignment1_test_utility) 

	BOOST_AUTO_TEST_CASE(utility_load_test_case) {
	
		int* array = NULL;
		int size = 0;
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		const char* inputFile = "test/resource/testinput.txt";
		load(inputFile, array, size);
		BOOST_CHECK_MESSAGE(size == testSize && 
							hasSameElements(array, testArray, testSize), 
							"TEST: Load Array");
		
		delete [] array;
	}

	BOOST_AUTO_TEST_CASE(utility_save_test_case) {
		int* array = NULL;
		int size = 0;
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		const char* outputFile = "test/resource/testoutput.txt";
		save(testArray, testSize, outputFile);
		load(outputFile, array, size);
		BOOST_CHECK_MESSAGE(size == testSize &&
							hasSameElements(array, testArray, testSize), 
							"TEST: Saved Array");
		
		delete [] array;

	}

	BOOST_AUTO_TEST_CASE(utility_duplicate_test_case) {
		int* array = NULL;
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		array = duplicate(testArray, testSize);
		BOOST_CHECK_MESSAGE(hasSameElements(array, testArray, testSize), "TEST: Duplicate elements");
		delete [] array;
	}

	BOOST_AUTO_TEST_CASE(utility_sort_original_test_case) {
		int testSorted[] = {9, 12, 23, 34, 44, 67, 67, 73, 87, 99};
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		sortOriginal(testArray, testSize);
		BOOST_CHECK_MESSAGE(hasSameElements(testSorted, testArray, testSize), "TEST: Sort orginal array");
	}

	BOOST_AUTO_TEST_CASE(utility_sort_copy_test_case) {
		
		int testSorted[] = {9, 12, 23, 34, 44, 67, 67, 73, 87, 99};
		int testArray[] = {99, 23, 87, 67, 34, 12, 9, 44, 67, 73 };
		int testSize = 10;
		int* copy = duplicate(testArray, testSize);
		int* sortedCopy =sortCopy(testArray, testSize);
		BOOST_CHECK_MESSAGE(hasSameElements(testSorted, sortedCopy, testSize) &&
				hasSameElements(testArray, copy, testSize), "TEST: Sort array copy");
		delete [] copy;
		delete [] sortedCopy;
	}


BOOST_AUTO_TEST_SUITE_END()




