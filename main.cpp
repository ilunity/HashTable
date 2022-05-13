#include <iostream>
#include "HashTable/HashTable.h"
#include <time.h>

using namespace std;


void init() {
    srand(time(0));
    system("chcp 65001");
}

char **generateStringArray(int count, int minLength, int spread) {
    char **stringArray = new char *[count];

    for (int i = 0; i < count; ++i) {
        if (rand() % 10 < 1 && i != 0) {
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

    int stringCount = 6500;
    HashTable hashTable(6113);
    char **initialArray = generateStringArray(stringCount, 4, 3);

    for (int i = 0; i < stringCount; ++i) {
        hashTable.push(initialArray[i]);
    }

    cout << hashTable << endl;

    SList *fullList = hashTable.getFullList();
    cout << "Полный список строк: " << *fullList << endl;

    int comparisonNumber = 0;
    SList *uniqueList = hashTable.getUniqueList(comparisonNumber);
    cout << "Только уникальные строки: " << *uniqueList << endl;
    cout << "Количество сравнений: " << comparisonNumber << endl;
    cout << "Количество уникальных строк: " << (*uniqueList).getLength() << endl;
}