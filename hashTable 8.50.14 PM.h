#pragma once
#include <utility>
#include <vector>

#include "linearDictionary.h"

using std::pair;
using std::vector;

class HashTable {
  public:

    HashTable();

    ~HashTable();

    int getSize();
    bool isEmpty();
    void insert(int key, int value);
    int get(int key);
    bool contains(int key);
    vector< pair< int, int > > getItems();

  private:
    void expandCapacity();
    int size;
    int capacity;
    float maxloadfactor;
    LinearDictionary* table;


};

#include "hashTable-inl.h"
