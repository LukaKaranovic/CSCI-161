/**
 * @file linkedmaptest.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date March 18, 2024
 * 
 * Declares the prototype of unit test class LinkedMapTest and its functions that will be used 
 * to perform unit test on LinkedMap implementation of Map ADT.
 *
 */


#ifndef __LINKED_MAP_TEST_HEADER__
#define __LINKED_MAP_TEST_HEADER__

template<typename K, typename V>
class LinkedMapTest {
    public:
        static void putIntoMap(const K* keys, const V* values, const int size,  LinkedMap<K,V>& LinkedMap);
        static LinkedMap<K,V> createLinkedMap(const K* keys, const V* values, const int size);
        static bool isKeyValuesInMap(const K* keys, const V* values, const int size, LinkedMap<K,V>& linkedMap);
        static bool isDeepCopy(const LinkedMap<K,V>& linkedMap1, const LinkedMap<K,V>& linkedMap2);
        static bool testDefaultConstructor();
        static bool testPut(const K* keys, const V* values, const int size);
        static bool testSize(const K* keys, const V* values, const int size);
        static bool testCopyConstructor(const K* keys, const V* values, const int size);
        static bool testMoveConstructor(const K* keys, const V* values, const int size);
        static bool testCopyAssignment(const K* keys, const V* values, const int size);
        static bool testMoveAssignment(const K* keys, const V* values, const int size);
        static bool testGet(const K* keys, const V* values, const int size);
        static bool testIndex(const K* keys, const V* values, const int size);
        static bool testRemove(const K* keys, const V* values, const int size);
        static bool testContainsKey(const K* keys, const V* values, const int size);
        static bool testContainsValue(const K* keys, const V* values, const int size);
        static bool testKeys(const K* keys, const V* values, const int size);
        static bool testValues(const K* keys, const V* values, const int size);
};

#endif