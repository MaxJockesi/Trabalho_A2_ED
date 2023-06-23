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