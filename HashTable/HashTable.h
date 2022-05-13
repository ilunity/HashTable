#include "../SList/SList.h"
#include "../Counter/Counter.h"


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

    SList *getUniqueList(int &comparisonNumber);
};
