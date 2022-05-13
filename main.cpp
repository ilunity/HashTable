#include <iostream>
#include "HashTable/HashTable.h"
#include <time.h>
#include <cmath>

using namespace std;


void init() {
    srand(time(0));
    system("chcp 65001");
}

char **generateStringArray(int count, int minLength, int spread, float coincidentProbability) {
    char **stringArray = new char *[count];
    coincidentProbability = round(coincidentProbability * 10);

    for (int i = 0; i < count; ++i) {
        if (rand() % 10 < coincidentProbability && i != 0) {
            stringArray[i] = stringArray[rand() % i];
            continue;
        }

        int length = rand() % spread + minLength;

        char *str = new char[length + 1];
        for (int j = 0; j < length; ++j) {
            str[j] = (rand() % 25 + 65);
        }
        str[length] = '\0';

        stringArray[i] = str;
    }

    return stringArray;
}

int main() {
    init();

    int stringCount = 2000;
    HashTable hashTable(2333);
    char **initialArray = generateStringArray(stringCount, 3, 1, 0.3);

    for (int i = 0; i < stringCount; ++i) {
        hashTable.push(initialArray[i]);
    }

    cout << hashTable << endl;

    SList *fullList = hashTable.getFullList();
    cout << "Полный список строк: " << *fullList << endl;

    int comparisonNumber = hashTable.calculateComparisons();
    cout << "Количество сравнений: " << comparisonNumber << endl;
    cout << "Количество уникальных строк: " << (*fullList).getLength() << endl;
}