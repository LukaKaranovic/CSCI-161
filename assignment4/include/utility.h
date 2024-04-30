/**
 * @file utility.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 15, 2020
 *
 * Defines utility functions relates to DynamicArray.
 *
 */ 



#ifndef __UTILITY_HEADER__
#define __UTILITY_HEADER__

#include "dynamicarray.h"


void load(const char* filename, DynamicArray& darray);
//Open the file specified by 'filename' in read only mode.
//Read each data item from the file and add the data item into the dynamic array 
//calling 'input>>darray' overloaded operator from 'dynamicarray.cpp'
//assuming 'input' refers to your input file stream.



void save(const DynamicArray& darray, const char* filename);
//Open the file specified by 'filename' in write only mode.
//Save the data items from the dynamic array into the file calling
//'output<<darray', overloaded operator function from 'dynamicarray.cpp',
//assuming 'output' refers to  your output file stream.




#endif
