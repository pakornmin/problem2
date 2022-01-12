#include <stdexcept>
#include <utility>
#include <vector>
#include <iostream>
#include <string>

using std::pair;
using std::runtime_error;
using std::vector;
using std::cout;
using std::string;
using std::endl;

LinearDictionary::LinearDictionary() {
    this->size = 0;
}

LinearDictionary::~LinearDictionary() {
}

int LinearDictionary::getSize() {
    return this->size;
}

bool LinearDictionary::isEmpty() {
    if(this->size==0){
        return true;
    }else{
        return false;
    }
}


void LinearDictionary::insert(int key, int value) {
    if(contains(key)) {
        throw runtime_error("Key Already Existed: insert failed");
    }
    pair< int, int > temp;
    temp.first = key;
    temp.second = value;
    actualDictionary.push_back(temp);
    this->size++;
}


int LinearDictionary::get(int key) {
    for(int i = 0; i<actualDictionary.size(); i++){
        if(actualDictionary[i].first==key){
            return (actualDictionary[i].second);
        }
    }
    throw runtime_error("Key Not Found in get method");
}

bool LinearDictionary::contains(int key) {
    for(int i = 0; i<actualDictionary.size(); i++){
        if(actualDictionary[i].first==key){
            return true;
        }
    }
    return false;
}


vector< pair< int, int > > LinearDictionary::getItems() {
    vector< pair< int, int > > temp;
    for(int i = 0; i<actualDictionary.size(); i++){
        pair<int, int> element;
        element.first = actualDictionary[i].first;
        element.second = actualDictionary[i].second;
        temp.push_back(element);
    }
    return temp;
}
