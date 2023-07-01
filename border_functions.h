#ifndef BORDER_FUNCTIONS_H
#define BORDER_FUNCTIONS_H

#include "node.h"

struct BorderElement{
    Node* ptrData;
    int iLevel;
    BorderElement* ptrNext;
};

struct Border{
    BorderElement* ptrTop;
    BorderElement* ptrLast;
};

Border* newBorder();
void insertBorder(Border*, Node*, int);
void popBorder(Border*);

#endif