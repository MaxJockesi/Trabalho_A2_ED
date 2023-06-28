#include <iostream>
#include "tree_functions.h"

struct Node* newNode(int iNewData)
{
    // Cria novo node
    Node *ptrProx = new Node; 
    ptrProx->iPayload = iNewData; 
    ptrProx->ptrRight = nullptr;
    ptrProx->ptrLeft = nullptr;
}

void insertData(Node** ptrRoot, int iNewData)
{
    // Árvore vazia
    if (*ptrRoot == nullptr) 
    {
        Node *ptrProx = newNode(iNewData);
        *ptrRoot = ptrProx;
        return;
    }
    // Coloca o elemento na posição correta 
    if(iNewData >= (*ptrRoot)->iPayload)
        insertData(&(*ptrRoot)->ptrRight, iNewData);
    else
        insertData(&(*ptrRoot)->ptrLeft, iNewData);
    return;
}

void deleteData(Node **ptrRoot, int iDelete)
{
    if(*ptrRoot == nullptr)
        return;
    
    // Caso em que o head tem que ser apagado
    if((*ptrRoot)->iPayload == iDelete)
    {
        Node *ptrTmp = findReplace(*ptrRoot);
        free(*ptrRoot);
        *ptrRoot = ptrTmp;  
        return;
    }

    if((*ptrRoot)->ptrRight != nullptr)
        if((*ptrRoot)->ptrRight->iPayload == iDelete)
        {
            Node *ptrTmp = findReplace((*ptrRoot)->ptrRight);
            free((*ptrRoot)->ptrRight);
            (*ptrRoot)->ptrRight= ptrTmp;
            return;
        }

    if((*ptrRoot)->ptrLeft != nullptr)
        if((*ptrRoot)->ptrLeft->iPayload == iDelete)   
        {
            Node *ptrTmp = findReplace((*ptrRoot)->ptrLeft);
            free((*ptrRoot)->ptrLeft);
            (*ptrRoot)->ptrLeft = ptrTmp;
            return;
        }   

    if(iDelete >= (*ptrRoot)->iPayload)
        deleteData(&(*ptrRoot)->ptrRight, iDelete);
    else
        deleteData(&(*ptrRoot)->ptrRight, iDelete);

    return;
}

Node* findReplace(Node* ptrRoot)
{
    Node *ptrIter = ptrRoot;
    // Casos em que o node tem 0 ou 1 filhos
    if(ptrRoot->ptrLeft == nullptr)
        return ptrRoot->ptrRight;

    if(ptrRoot->ptrLeft->ptrRight == nullptr)
    {
        ptrRoot->ptrLeft->ptrRight = ptrRoot->ptrRight;
        return ptrRoot->ptrLeft;
    }
    
    // Caso em que tem dois filhos
    ptrIter = ptrIter->ptrLeft;
    while(ptrIter->ptrRight->ptrRight != nullptr)
        ptrIter = ptrIter->ptrRight;

    // Ajuste dos filhos 
    Node *ptrCopy = ptrIter->ptrRight->ptrLeft;
    ptrIter->ptrRight->ptrRight = ptrRoot->ptrRight;
    ptrIter->ptrRight->ptrLeft = ptrRoot->ptrLeft;
    ptrRoot = ptrIter->ptrRight;
    ptrIter->ptrRight = ptrCopy;
    return ptrRoot;
}

// Conversão para uma linked list  
void convertToList(Node **ptrRoot) 
{
    // Casos em que o root é vazio ou tem 0 filho
    if ((*ptrRoot) == nullptr || (((*ptrRoot)->ptrLeft == nullptr) && ((*ptrRoot)->ptrRight == nullptr)))
        return;
    
    Node* ptrTmpLeft = (*ptrRoot);
    Node* ptrTmpRight = (*ptrRoot)->ptrRight;
    
    // Caso em que root tem filho à esquerda
    if ((*ptrRoot)->ptrLeft != nullptr) 
    {
        // Converter a sub-árvore da esquerda em lista
        convertToList(&((*ptrRoot)->ptrLeft));

        (*ptrRoot)->ptrRight = (*ptrRoot)->ptrLeft;

        // Geramos uma sub-lista que começa no root
        // e inclui toda a sub-árvore da esquerda.
        // Agora, iremos chegar ao último da sub-lista gerada
        while (ptrTmpLeft->ptrRight != nullptr)
        {
            ptrTmpLeft = ptrTmpLeft->ptrRight;
        }
    }

    if (ptrTmpRight == nullptr)
        return;
    else
    {
        // Converter a sub-árvore da direita em lista
        convertToList(&(ptrTmpRight));

        (*ptrRoot)->ptrLeft = nullptr;

        // Continuar a sub-lista
        ptrTmpLeft->ptrRight = ptrTmpRight;
    }
}