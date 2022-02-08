#pragma once
#include <utility>
#include <vector>

using std::pair;
using std::vector;


class LinearDictionary{
  public:
    LinearDictionary();

    ~LinearDictionary();

    int getSize();
    bool isEmpty();
    void insert(int key, int value);
    int get(int key);
    bool contains(int key);
    vector< pair< int, int > > getItems();

  private:
    vector < pair< int, int > > actualDictionary;
    int size;


};

#include "linearDictionary-inl.h"
