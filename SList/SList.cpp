#include "SList.h"
#include "cstring"

SList::SList() {
    beginPointer = endPointer = nullptr;
    comparisonNumber = length = 0;
}

SList::~SList() {
    SListElem *ptr;

    while (beginPointer != nullptr) {
        ptr = beginPointer;
        beginPointer = beginPointer->next;
        delete ptr;
    }
}


void SList::push(char *str) {
    length++;
    SListElem *ptr = new SListElem;

    ptr->string = str;
    ptr->next = nullptr;

    if (beginPointer == nullptr) {
        beginPointer = endPointer = ptr;
        return;
    };

    endPointer->next = ptr;
    endPointer = ptr;
}

char *SList::pop() {
    length--;
    if (!beginPointer) return "\0";

    if (beginPointer == endPointer) {
        char *str = endPointer->string;
        delete endPointer;
        return str;
    }

    char *str = endPointer->string;
    SListElem *ptr = beginPointer;
    while (ptr->next != endPointer) {
        ptr = ptr->next;
    }

    delete endPointer;
    endPointer = ptr;

    return str;
}

void SList::connect(SList &list) {
    length += list.length;
    if (list.beginPointer == nullptr) return;

    if (beginPointer == nullptr) {
        beginPointer = list.beginPointer;
        endPointer = list.endPointer;
        return;
    }

    endPointer->next = list.beginPointer;
    endPointer = list.endPointer;
}

bool SList::include(char *str, SListElem *initPointer) {
    SListElem *ptr;
    if (initPointer == nullptr) {
        ptr = beginPointer;
        if (beginPointer == nullptr) return false;
    } else {
        ptr = initPointer;
    }

    while (ptr != endPointer) {
        comparisonNumber++;
        if (strcmp(ptr->string, str) == 0) return true;

        ptr = ptr->next;
    }

    comparisonNumber++;
    if (strcmp(ptr->string, str) == 0) return true;

    return false;
}

int SList::getComparisonNumber() const {
    return comparisonNumber;
}

int SList::countOf(char *str) {
    SListElem *ptr = beginPointer;
    int counter = 0;

    while (ptr != endPointer) {
        if (strcmp(ptr->string, str) == 0) counter++;
        ptr = ptr->next;
    }
    if (strcmp(ptr->string, str) == 0) counter++;
    ptr = ptr->next;

    return counter;
}

bool SList::isEmpty() {
    return beginPointer == nullptr;
}

int SList::getLength() {
    return length;
}

ostream &operator<<(ostream &stream, SList &list) {
    SListElem *ptr = list.beginPointer;
    if (ptr == nullptr) {
        stream << "Список пуст";
        return stream;
    }

    stream << "(";
    while (ptr->next != nullptr) {
        stream << ptr->string << ", ";
        ptr = ptr->next;
    }
    stream << ptr->string << ")";

    return stream;
}

void SList::normalize() {
    SListElem *currentPointer, *previousPointer;
    currentPointer = previousPointer = beginPointer;

    char *currentString;
    while (currentPointer != endPointer) {
        currentString = currentPointer->string;

        if (include(currentString, currentPointer->next)) {
            if (currentPointer == beginPointer) {
                beginPointer = currentPointer->next;
            } else {
                previousPointer->next = currentPointer->next;
            }
            length--;
        }

        previousPointer = currentPointer;
        currentPointer = currentPointer->next;
    }
}

SList *SList::normalizeCopy() {
    SList *copyList = new SList;
    if (beginPointer == nullptr) return copyList;

    SListElem *pointer = beginPointer;
    char *currentString;
    while (pointer != endPointer) {
        currentString = pointer->string;

        if (!include(currentString, pointer->next)) {
            (*copyList).push(currentString);
        }

        pointer = pointer->next;
    }
    (*copyList).push(pointer->string);

    return copyList;
}
