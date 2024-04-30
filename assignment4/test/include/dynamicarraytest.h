/**
 * @file - dynamicarraytest.h
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 1.0.0
 * @date - March 09, 2024
 *
 * Declares the prototype of DynamicArrayTest class and its functions.
 *
 */

#ifndef __DYNAMIC_ARRAY_TEST_HEADER__
#define __DYNAMIC_ARRAY_TEST_HEADER__

class DynamicArrayTest {
    public: 
        
        static bool testDefaultConstructor();
        static bool testRegularConstructor();
        static bool testOverloadedRegularConstructor();
        static bool testCopyConstructor();
        static bool testMoveConstructor();
        static bool testSize();
        static bool testCapacity();
        static bool testEmpty();
        static bool testInsert();
        static bool testOverloadedInsert();
        static bool testSearch();
        static bool testElements();
        static bool testErase();
        static bool testClear();
        static bool testCopyAssignment();
        static bool testMoveAssignment();
        static bool testPrefixIncrementOperator();
        static bool testPostfixIncrementOperator();
        static bool testPrefixDecrementOperator();
        static bool testPostfixDecrementOperator();
        static bool testAddOperator();
        static bool testSubtractOperator();
        static bool testMultiplyOperator();
        static bool testEqualOperator();
        static bool testIndexOperator();
        static bool testIndexReferenceOperator();
        static bool testExtractorOperator();
        static bool testInserterOperator();
        static bool testLoad();
        static bool testSave();
       
};

#endif
