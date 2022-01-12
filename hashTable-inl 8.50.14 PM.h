#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

HashTable::HashTable() {
    size = 0;
    capacity = 5;
    maxloadfactor = 0.5;
    table = new LinearDictionary[capacity];
}

HashTable::~HashTable() {
    delete [] table;
}

int HashTable::getSize() {
    return this->size;
}

bool HashTable::isEmpty() {
    if (this->size == 0) {
        return true;
    }
    return false;
}

void HashTable::insert(int key, int value) {

    int index = hash(key, capacity);
    table[index].insert(key, value);
    size++;

    float load = float(size)/capacity;
    if(load>=maxloadfactor){
        expandCapacity();
    }


}

int HashTable::get(int key) {
    int index  = hash(key,capacity);
    return(table[index].get(key));
}

bool HashTable::contains(int key) {
    int index  = hash(key,capacity);
    return(table[index].contains(key));
}

vector< pair< int, int > > HashTable::getItems() {
    vector < pair< int, int > > a;
    vector < pair< int, int > > b;

    for(int i = 0; i<capacity; i++){
        b = table[i].getItems();
        a.insert(a.end(),b.begin(),b.end());
    }

    return a;
}

void HashTable::expandCapacity() {

    int newcap = capacity * 2;
    LinearDictionary *newTable = new LinearDictionary[newcap];

    vector < pair< int, int > > allItems = this->getItems();
    int sizeLoop = allItems.size();

    for (int i= 0; i<sizeLoop; i++){
        int index = hash(allItems[i].first, newcap);
        newTable[index].insert(allItems[i].first,allItems[i].second);
    }

    delete[] this->table;
    this->table = newTable;

    this->capacity = newcap;


}
