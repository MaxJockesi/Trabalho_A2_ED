#ifndef TREE_OPERATIONS_H
#define TREE_OPERATIONS_H

#include "node.h"
#include "border_functions.h"

int heightTree(Node* ptrRoot);
int sizeTree(Node* ptrRoot);
void findTree(Node* ptrRoot, int iNum);
bool fullTree(Node* ptrRoot);
bool completeTree(Node*);
bool perfectTree(Node* ptrRoot);
void printSpace(int iNumber);
void printFeature(int iNumber);
int power(int iBase, int iExponent);
int numberDigits(int iNumber);
Border* mountBorder(Node* ptrRoot, int* iMaxDigits, int iHeight);
void printTree(Node* ptrRoot);

#endif