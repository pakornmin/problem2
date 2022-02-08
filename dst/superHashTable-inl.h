#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

SuperHashTable::SuperHashTable() {
    size = 0;
    capacity = 5;
    maxloadfactor = 0.5;
    table = new SuperLinearDictionary[capacity];
}

SuperHashTable::~SuperHashTable() {

    delete[] table;
}

int SuperHashTable::getSize() {
    return this->size;
}

bool SuperHashTable::isEmpty() {
    if (this->size == 0) {
        return true;
    }
    return false;
}

void SuperHashTable::insert(pair<int,int> key, HashTable* value) {

    int index = hash(key, capacity);
    table[index].insert(key, value);
    size++;

    float load = float(size)/capacity;
    if(load>=maxloadfactor){
        expandCapacity();
    }


}

HashTable* SuperHashTable::get(pair<int,int> key) {
    int index  = hash(key,capacity);
    return(table[index].get(key));
}

bool SuperHashTable::contains(pair<int,int> key) {
    int index  = hash(key,capacity);
    return(table[index].contains(key));
}

vector< pair< pair<int,int>, HashTable* > > SuperHashTable::getItems() {
    vector < pair< pair<int,int>, HashTable* > > a;
    vector < pair< pair<int,int>, HashTable* > > b;

    for(int i = 0; i<capacity; i++){
        b = table[i].getItems();
        a.insert(a.end(),b.begin(),b.end());
    }

    return a;
}

void SuperHashTable::expandCapacity() {

    int newcap = capacity * 2;
    SuperLinearDictionary *newTable = new SuperLinearDictionary[newcap];

    vector < pair< pair<int,int>, HashTable* > > allItems = this->getItems();
    int sizeLoop = allItems.size();

    for (int i= 0; i<sizeLoop; i++){
        int index = hash(allItems[i].first, newcap);
        newTable[index].insert(allItems[i].first,allItems[i].second);
    }

    this->table = newTable;

    this->capacity = newcap;


}

int SuperHashTable::curCap() {
    return capacity;
}
