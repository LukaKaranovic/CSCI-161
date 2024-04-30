/**
 * @file  maptest.h
 * @author  Humayun Kabir, Instructor, CSCI 161, VIU
 * @version  1.0.0
 * @date  March 18, 2024
 * 
 * Declares the prototype of unit test class MapTest and its functions that will be used 
 * to perform unit test on both ArrayMap and LinkedMap implementations of Map ADT using Map pointer.
 */


#ifndef __MAP_TEST_HEADER__
#define __MAP_TEST_HEADER__


template<typename K, typename V> class Map;
template<typename K, typename V> class ArrayMap;
template<typename K, typename V> class LinkedMap;

template<typename K, typename V>
class MapTest {
    public:
        static void putIntoMap(const K* keys, const V* values, const int size,  Map<K,V>* map);
        static bool isKeyValuesInMap(const K* keys, const V* values, const int size, LinkedMap<K,V>& lmap);
        static bool isKeyValuesInMap(const K* keys, const V* values, const int size, ArrayMap<K,V>& amap);
        static bool testPut(const K* keys, const V* values, const int size);
        static bool testSize(const K* keys, const V* values, const int size);
        static bool testGet(const K* keys, const V* values, const int size);
        static bool testIndex(const K* keys, const V* values, const int size);
        static bool testRemove(const K* keys, const V* values, const int size);
        static bool testContainsKey(const K* keys, const V* values, const int size);
        static bool testContainsValue(const K* keys, const V* values, const int size);
        static bool testKeys(const K* keys, const V* values, const int size);
        static bool testValues(const K* keys, const V* values, const int size);
};

#endif