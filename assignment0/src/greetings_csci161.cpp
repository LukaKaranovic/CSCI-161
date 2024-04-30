/**
 * @file greetings_csci161.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 03, 2020
 *
 * Implements functions to greet 'Hello!' and 'Goodbye!' to 'CSCI 161'
 *
 */


#include <iostream>
#include "greetings.h"

/**
 * Defines greetings target to CSCI 161
 */
#define GREET_TO "CSCI 161"		


using namespace std;


/**
 * Greets 'Hello! CSCI 161'
 */
void sayHello() {
	cout<< "Hello! "<<GREET_TO<<endl;
}



/**
 * Greets 'Goodbye! CSCI 161'
 */
void sayGoodbye() {
	cout<< "Goodbye! "<<GREET_TO<<endl;
}
