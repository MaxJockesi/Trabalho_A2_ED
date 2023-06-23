#include <iostream>
#include "tree_operations.h"

using namespace std;

//Função que retorna a altura da árvore (quantos níveis a árvore possui)
int heightTree(Node* ptrRoot)
{
    //Se chegar em uma folha retorna 0, significando que chegou ao final da árvore
    if(ptrRoot==nullptr)
    {
        return 0;
    }
    //Senão aumenta mais 1 na contagem da altura, e soma a maior altura entre seus filhos
    else
    {
        return 1 + std::max(heightTree(ptrRoot->ptrLeft), heightTree(ptrRoot->ptrRight));
    }
}

//Função que retorna o tamnho da árvore (quantos elementos a árvore possui)
int sizeTree(Node* ptrRoot)
{
    //Se chegou em uma folha, acaba a recorrência e retorna 0, significando que não há mais elementos
    if(ptrRoot==nullptr)
    {
        return 0;
    }
    //Senão soma 1 ao tamanho mais o tamanho do galho a esquerda mais o tamnho do galho a direita
    else
    {
        return 1 + sizeTree(ptrRoot) + sizeTree(ptrRoot);
    }
}

void findTree(Node* ptrRoot, int iNum)
{
    if(ptrRoot!=nullptr)
    {
        if(ptrRoot->iPayload==iNum)
        {
            cout << ptrRoot << endl;
        }
        if(ptrRoot->iPayload > iNum)
        {
            findTree(ptrRoot->ptrLeft, iNum);
        }
        else
        {
            findTree(ptrRoot->ptrRight, iNum);
        }
    }
    return;
}