#pragma once
#include <utility>
#include <vector>
#include "hashFunctions.h"
#include "hashTable.h"


using std::pair;
using std::vector;


class SuperLinearDictionary{
  public:
    SuperLinearDictionary();

    ~SuperLinearDictionary();

    int getSize();
    bool isEmpty();
    void insert(pair<int,int> key, HashTable* value);
    HashTable* get(pair<int,int> key);
    bool contains(pair<int,int> key);
    vector< pair< pair<int,int>, HashTable* > > getItems();
    void nullptrAllElement();

  private:
    vector < pair< pair<int,int>, HashTable* > > actualDictionary;
    int size;


};

#include "superLinearDictionary-inl.h"
