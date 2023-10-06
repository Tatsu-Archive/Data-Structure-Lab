/*Implement a hash table with linear probing using array with the following operations :
INSERT(key), DELETE(key), SEARCH(key). */

#include<iostream>
using namespace std;

class HashTable{
    int *arr;
    int size;
public:

    