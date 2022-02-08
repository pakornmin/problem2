#include "hashFunctions.h"
#include <utility>

using std::pair;
using std::vector;

int hash(int value, int range) {
    int result = value % range;
    return result;
}

int hash(pair<int,int> value, int range) {
    int hash_value = value.first*10 + value.second;

    int result = hash_value % range;

    return result;
}
