/**
 * @file: testgreetcsci.cpp
 * @author: Humayun Kabir, Instructor, CSCI 161, VIU
 * @version: 1.0.0
 * @modified: July 03, 2020
 *
 * Tests 'Hello!' and 'Goodbye' greeting.
 */

//#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE greetcsci160
#include <boost/test/included/unit_test.hpp>

//#include <boost/test/unit_test.hpp>

#include "greetings.h"


BOOST_AUTO_TEST_SUITE(greet_csci)

BOOST_AUTO_TEST_CASE(hello_goodby) {
	sayHello();
	BOOST_CHECK_MESSAGE(true, "TEST: Say Hello");
	sayGoodbye();
	BOOST_CHECK_MESSAGE(true, "TEST: Say Goodbye");
}

BOOST_AUTO_TEST_SUITE_END()
