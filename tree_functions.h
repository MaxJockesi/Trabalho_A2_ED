#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include <string>
#include <iostream>
#include "node.h"

struct Node* newNode(int);
void insertData(Node**, int);
void deleteData(Node**, int);
struct Node* findReplace(Node*);
Node* convertToList(Node **);
Node *createTree();
Node* readTree(std::string strFileName);

#endif