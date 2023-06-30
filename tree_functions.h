#ifndef TREE_FUNCTIONS_H
#define TREE_FUNCTIONS_H

#include <iostream>

struct Node
{
    int iPayload;
    Node *ptrRight;
    Node *ptrLeft;
};

struct Node* newNode(int);
void insertData(Node**, int);
void deleteData(Node**, int);
struct Node* findReplace(Node*);
void convertToList(Node **);
Node *createTree();
Node* readTree(char* strFileName);

#endif