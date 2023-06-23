#include <iostream>

struct Node
{
    int iPayload;
    Node *ptrRight;
    Node *ptrLeft;
};

struct Node* newNode;
void insertData(Node**, int);
void deleteData(Node**, int);
struct Node* findReplace(Node*);