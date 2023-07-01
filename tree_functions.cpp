#include <iostream>
#include <fstream>
#include <string>
#include "tree_functions.h"

using namespace std;

struct Node* newNode(int iNewData)
{
    // Cria novo node
    Node *ptrProx = new Node; 
    ptrProx->iPayload = iNewData; 
    ptrProx->ptrRight = nullptr;
    ptrProx->ptrLeft = nullptr;
    return ptrProx;
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
    
    // Caso em que o head tem que ser apagado (só ocorre quando a raiz da árvore vai ser apagada)
    if((*ptrRoot)->iPayload == iDelete)
    {
        Node *ptrTmp = findReplace(*ptrRoot);
        free(*ptrRoot);
        *ptrRoot = ptrTmp;  
        return;
    }

    // Caso em que o filho a direita do head vai ser apagado
    if((*ptrRoot)->ptrRight != nullptr)
        if((*ptrRoot)->ptrRight->iPayload == iDelete)
        {
            Node *ptrTmp = findReplace((*ptrRoot)->ptrRight);
            free((*ptrRoot)->ptrRight);
            (*ptrRoot)->ptrRight = ptrTmp;
            return;
        }

    // Caso em que o filho a esquerda do head vai ser apagado
    if((*ptrRoot)->ptrLeft != nullptr)
        if((*ptrRoot)->ptrLeft->iPayload == iDelete)   
        {
            Node *ptrTmp = findReplace((*ptrRoot)->ptrLeft);
            free((*ptrRoot)->ptrLeft);
            (*ptrRoot)->ptrLeft = ptrTmp;
            return;
        }   

    // Nenhum caso anterior ocorreu: se move na arvore na direção certa
    if(iDelete >= (*ptrRoot)->iPayload)
        deleteData(&(*ptrRoot)->ptrRight, iDelete);
    else
        deleteData(&(*ptrRoot)->ptrLeft, iDelete);

    return;
}

// Encontra o substituto correto para o node deletado e ajeita os ponteiros 
Node* findReplace(Node* ptrRoot)
{
    // Casos em que o node tem 0 filhos ou só filho à esquerda
    if(ptrRoot->ptrRight == nullptr) 
        return ptrRoot->ptrLeft;

    // Tem um filho à direita que nao tem filho à esquerda
    if(ptrRoot->ptrRight->ptrLeft == nullptr)
    {
        ptrRoot->ptrRight->ptrLeft = ptrRoot->ptrLeft;
        return ptrRoot->ptrRight;
    }
    
    // Tem um filho à direita que tem filho à esquerda
    Node *ptrIter = ptrRoot;
    ptrIter = ptrIter->ptrRight;
    while(ptrIter->ptrLeft->ptrLeft != nullptr) // vai seguindo até o penultimo do "galho" à esquerda
        ptrIter = ptrIter->ptrLeft;

    // Ajuste dos filhos 
    Node *ptrCopy = ptrIter->ptrLeft->ptrRight;
    ptrIter->ptrLeft->ptrLeft = ptrRoot->ptrLeft;
    ptrIter->ptrLeft->ptrRight = ptrRoot->ptrRight;
    ptrRoot = ptrIter->ptrLeft; // substituto para o node deletado
    ptrIter->ptrLeft = ptrCopy;
    return ptrRoot;
}

// Conversão para uma doubly linked list  
Node* convertToList(Node **ptrRoot) 
{
    // Casos em que o root é vazio ou tem 0 filho
    if ((*ptrRoot) == nullptr || (((*ptrRoot)->ptrLeft == nullptr) && ((*ptrRoot)->ptrRight == nullptr)))
        return *ptrRoot;
    
    Node* ptrTmpLeft = (*ptrRoot);
    Node* ptrTmpRight = (*ptrRoot)->ptrRight;
    
    // Caso em que root tem filho à esquerda
    if ((*ptrRoot)->ptrLeft != nullptr) 
    {
        // Converter a sub-árvore da esquerda em lista
        convertToList(&((*ptrRoot)->ptrLeft));

        (*ptrRoot)->ptrRight = (*ptrRoot)->ptrLeft;
        ((*ptrRoot)->ptrLeft)->ptrLeft = *ptrRoot;

        // Geramos uma sub-lista que começa no root
        // e inclui toda a sub-árvore da esquerda.
        // Agora, iremos chegar ao último da sub-lista gerada
        while (ptrTmpLeft->ptrRight != nullptr)
        {
            ptrTmpLeft = ptrTmpLeft->ptrRight;
        }
    }

    if (ptrTmpRight == nullptr)
        return *ptrRoot;

    else
    {
        // Converter a sub-árvore da direita em lista
        convertToList(&(ptrTmpRight));

        (*ptrRoot)->ptrLeft = nullptr;

        // Continuar a sub-lista
        ptrTmpLeft->ptrRight = ptrTmpRight;
        ptrTmpRight->ptrLeft = ptrTmpLeft;
    }
    return *ptrRoot;
}

Node *createTree()
{
    Node *ptrRoot = nullptr;
    char chStop = 'Y'; // para encerrar o pedido de variáveis
    int iNewData;
    do 
    {
        cout << "Type an integer" << endl;
        cin >> iNewData;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> iNewData;
        }
        insertData(&ptrRoot, iNewData); // insere o dado na arvore
        cout << "End with the process? (Y/Any)" << endl; 
        cin >> chStop;
    } 
    while(chStop != 'Y' && chStop != 'y'); // enquanto o usuario não digitar Y quando pedido, continua pedindo dados
    return ptrRoot;
}

Node* readTree(std::string strFileName)
{   
    // Checa se o arquivo foi aberto 
    // Se não foi, printa uma mensagem de erro e retorna
    fstream file;
    file.open(strFileName);
    if(!file.is_open())
    {
        cout << "ERROR: Unable to open the archive." << endl;
        return nullptr;
    }
    // Lê os dados do arquivo considerando inteiros separados por espaços ou linhas
    int iData;
    Node *ptrRoot = nullptr; // cria a árvore
    ifstream infile(strFileName);
    while(infile >> iData)
        insertData(&ptrRoot, iData); // insere na árvore

    // Fecha o arquivo e retorna a árvore construida
    file.close();
    return ptrRoot;
}