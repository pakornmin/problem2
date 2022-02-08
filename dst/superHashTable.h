#pragma once
#include <utility>
#include <vector>

#include "superLinearDictionary.h"
#include "hashTable.h"



using std::pair;
using std::vector;

class SuperHashTable {
  public:

    SuperHashTable();

    ~SuperHashTable();

    int getSize();
    bool isEmpty();
    void insert(pair<int,int> key, HashTable* value);
    HashTable* get(pair<int,int> key);
    bool contains(pair<int,int> key);
    vector< pair< pair<int,int>, HashTable* > > getItems();
    int curCap();

  private:
    void expandCapacity();
    int size;
    int capacity;
    float maxloadfactor;
    SuperLinearDictionary* table;


};

#include "superHashTable-inl.h"
