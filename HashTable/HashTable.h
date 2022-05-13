#include "../SList/SList.h"


class HashTable {
    int arrayLength;
    SList *stringListArray;
public:
    HashTable(int length);

    ~HashTable();

    int hashFunction(char *string) const;

    void push(char *string);

    SList *getFullList();

    friend ostream &operator<<(ostream &stream, HashTable &obj);

    int calculateComparisons();
};
