/**
 * @file utility.cpp
 * @author Luka Karanovic, 665778833, S24N02 CSCI 161, VIU
 * @version 1.0.0
 * @date March 29, 2024
 *
 * Implements the functions defined in utility.h header file.
 * 
 */
 

#include <fstream>
#include <iostream>
#include "utility.h"
using namespace std;

void load(const char* filename, DynamicArray& darray) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file" << filename << endl;
    }
    inputFile >> darray;
    inputFile.close();
}

void save(const DynamicArray& darray, const char* filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Error opening file" << filename << endl;
    }
    outputFile << darray;
    outputFile.close();
}




