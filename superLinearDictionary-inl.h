#include <stdexcept>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include "hashFunctions.h"
#include "hashTable.h"

using std::pair;
using std::runtime_error;
using std::vector;
using std::cout;
using std::string;
using std::endl;

SuperLinearDictionary::SuperLinearDictionary() {
    this->size = 0;
}

SuperLinearDictionary::~SuperLinearDictionary() {
    for(int i=0; i<size; i++) {
        delete actualDictionary[i].second;
    }
}

void SuperLinearDictionary::nullptrAllElement() {
    for(int i=0; i<size; i++) {
        actualDictionary[i].second = nullptr;
    }
}

int SuperLinearDictionary::getSize() {
    return this->size;
}

bool SuperLinearDictionary::isEmpty() {
    if(this->size==0){
        return true;
    }else{
        return false;
    }
}


void SuperLinearDictionary::insert(pair<int,int> key, HashTable* value) {
    if(contains(key)) {
        throw runtime_error("Key Already Existed: insert failed");
    }
    pair< pair<int,int>,HashTable* > temp;
    temp.first=key;
    temp.second = value;
    actualDictionary.push_back(temp);
    this->size++;
}


HashTable* SuperLinearDictionary::get(pair<int,int> key) {
    for(int i = 0; i<actualDictionary.size(); i++){
        if(actualDictionary[i].first==key){
            return (actualDictionary[i].second);
        }
    }
    throw runtime_error("Key Not Found in get method");
}

bool SuperLinearDictionary::contains(pair<int,int> key) {
    for(int i = 0; i<actualDictionary.size(); i++){
        if(actualDictionary[i].first==key){
            return true;
        }
    }
    return false;
}


vector< pair< pair<int,int>, HashTable* > > SuperLinearDictionary::getItems() {
    vector< pair< pair<int,int>, HashTable* > > temp;
    for(int i = 0; i<actualDictionary.size(); i++){
        pair<pair<int,int>, HashTable*> element;
        element.first = actualDictionary[i].first;
        element.second = actualDictionary[i].second;
        temp.push_back(element);
    }
    return temp;
}
