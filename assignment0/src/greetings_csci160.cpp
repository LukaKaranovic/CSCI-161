/**
 * @file greetings_csci160.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 03, 2020
 *
 * Implements functions to greet 'Hello!' and 'Goodbye!' to 'CSCI 160'
 *
 */

#include <iostream>
#include "greetings.h"

/**
 * Define greetings target to CSCI 160
 */
#define GREET_TO "CSCI 160" 		

using namespace std;


/**
 * Greets 'Hello! CSCI 160'
 */
void sayHello() {
	cout<< "Hello! "<<GREET_TO<<endl;
}


/**
 * Greets 'Goodbye! CSCI 160'
 */
void sayGoodbye() {
	cout<< "Goodbye! "<<GREET_TO<<endl;
}
