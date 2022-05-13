#include "HashTable.h"
#include "cstring"

HashTable::HashTable(int length) {
    arrayLength = length;
    stringListArray = new SList[length];
}

HashTable::~HashTable() {
    delete[] stringListArray;
}

int HashTable::hashFunction(char *string) const {
    int stringLength = strlen(string);
    if (!stringLength) return -1;

    int result = 0;
    for (int i = 0; i < stringLength - 1; ++i) {
        result = (result + string[i]) % arrayLength * 31;
    }
    result = (result + string[stringLength - 1]) % arrayLength;

    return result;
}

void HashTable::push(char *string) {
    int index = hashFunction(string);

    if (!stringListArray[index].include(string)) {
        stringListArray[index].push(string);
    }
}

SList *HashTable::getFullList() {
    SList *fullList = new SList;

    for (int i = 0; i < arrayLength; ++i) {
        (*fullList).connect(stringListArray[i]);
    }

    return fullList;
}

ostream &operator<<(ostream &stream, HashTable &obj) {
    for (int i = 0; i < obj.arrayLength; ++i) {
        stream << i << ": " << obj.stringListArray[i] << endl;
    }

    return stream;
}

int HashTable::calculateComparisons() {
    int comparisonNumber = 0;
    for (int i = 0; i < arrayLength; ++i) {
        comparisonNumber += stringListArray[i].getComparisonNumber();
    }

    return comparisonNumber;
}
