#include "iostream"

using namespace std;

struct SListElem {
    char *string;
    SListElem *next;
};

class SList {
    SListElem *beginPointer;
    SListElem *endPointer;
    int comparisonNumber;
    int length;

public:
    SList();

    ~SList();

    void push(char *str);

    char *pop();

    void connect(SList &list);

    bool include(char *str, SListElem *initPointer = nullptr);

    int getComparisonNumber() const;

    int countOf(char *str);

    bool isEmpty();

    int getLength();

    void normalize();

    SList *normalizeCopy();

    friend ostream &operator<<(ostream &stream, SList &obj);
};