#include <iostream>
#include "tree_functions.h"

// Função que troca nós de uma lista de inteiros - Supondo nó 2 após nó 1
void swapNodes(Node** ptrRoot, Node* ptrNode1, Node* ptrNode2)
{
    if (ptrNode1 == ptrNode2) 
        return;

    // Armazenando nós importantes
    struct Node* ptrPrev1 = ptrNode1->ptrLeft;
    struct Node* ptrNext1 = ptrNode1->ptrRight;
    struct Node* ptrPrev2 = ptrNode2->ptrLeft;
    struct Node* ptrNext2 = ptrNode2->ptrRight;
    
    // Nó 1 inicia a lista
    if(ptrNode1 == (*ptrRoot))
    {
        // Nó 2 termina a lista
        if(ptrNext2 == nullptr)
        {
            // Nó 2 é vizinho do nó 1 - a lista possui 2 nós
            if(ptrNext1 == ptrNode2)
            {
                ptrNode2->ptrRight = ptrNode1;
                ptrNode1->ptrLeft = ptrNode2;
                ptrNode1->ptrRight = nullptr;
            }
            // Caso contrário
            else
            {
                ptrNode1->ptrRight = nullptr;
                ptrNode1->ptrLeft = ptrPrev2;
                
                ptrNext1->ptrLeft = ptrNode2;
                ptrPrev2->ptrRight = ptrNode1;
                
                ptrNode2->ptrRight = ptrNext1;
            }
        }
        // Nó 2 no meio da lista
        else
        {
            ptrNext2->ptrLeft = ptrNode1;
            ptrNode1->ptrRight = ptrNext2;
            
            // Nó 2 vizinho do nó 1 - primeiro e segundo elementos
            if(ptrNext1 == ptrNode2)
            {
                ptrNode2->ptrRight = ptrNode1;
                ptrNode1->ptrLeft = ptrNode2;
            }
            // Nó 2 é um nó do meio da lista e não é vizinho do nó 1
            else
            {
                ptrPrev2->ptrRight = ptrNode1;
                ptrNode1->ptrLeft = ptrPrev2;
                
                ptrNext1->ptrLeft = ptrNode2;
                ptrNode2->ptrRight = ptrNext1; 
            }
        }
        
        ptrNode2->ptrLeft = nullptr;
        (*ptrRoot) = ptrNode2;
        return;
    }
    // Nó 1 está no meio da lista - Mas não no fim
    else
    {
        // Se nó 2 estiver no fim da lista
        if(ptrNext2 == nullptr)
        {
            ptrNode1->ptrRight = nullptr;
            // Se forem vizinhos - penúltimo e último
            if(ptrNext1 == ptrNode2)
            {
                ptrNode1->ptrLeft = ptrNode2;
                
                ptrNode2->ptrRight = ptrNode1;
                ptrNode2->ptrLeft = ptrPrev1;
                ptrPrev1->ptrRight = ptrNode2;
            }
            else
            {
                ptrNode1->ptrLeft = ptrPrev2;
                ptrPrev2->ptrRight = ptrNode1;
                
                ptrNode2->ptrLeft = ptrPrev1;
                ptrNode2->ptrRight = ptrNext1;
                
                ptrPrev1->ptrRight = ptrNode2;
                ptrNext1->ptrLeft = ptrNode2;
            }
        }
        // Caso contrário - Nós do meio da lista
        else
        {
            // Se forem vizinhos
            if(ptrNext1 == ptrNode2)
            {
                ptrNode1->ptrRight = ptrNext2;
                ptrNext2->ptrLeft = ptrNode1;
                
                ptrNode1->ptrLeft = ptrNode2;
                ptrNode2->ptrRight = ptrNode1;
                
                ptrPrev1->ptrRight = ptrNode2;
                ptrNode2->ptrLeft = ptrPrev1;
            }
            // Caso geral - Nós do meio da lista não-vizinhos
            else
            {
                ptrNode1->ptrRight = ptrNext2;
                ptrNext2->ptrLeft = ptrNode1;
                
                ptrNode2->ptrRight = ptrNext1;
                ptrNext1->ptrLeft = ptrNode2;
                
                ptrNode1->ptrLeft = ptrPrev2;
                ptrPrev2->ptrRight = ptrNode1;
                
                ptrNode2->ptrLeft = ptrPrev1;
                ptrPrev1->ptrRight = ptrNode2;
            }
        }
    }
}

void bubbleSort(Node** ptrRoot) 
{
    if (((*ptrRoot) ==  nullptr) || ((*ptrRoot)->ptrRight ==  nullptr))
        return;
    
    bool finished = false;
    Node *ptrCurrent;

    // Criamos um Node proibido
    Node *ptrForbidden = nullptr;

    while (finished == false)
    {
        finished = true;
        ptrCurrent = *ptrRoot;

        // ptrCurrent irá até imediatamente antes do proibido
        while (ptrCurrent->ptrRight != ptrForbidden)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrRight->iPayload)
            {
                swapNodes(ptrRoot, ptrCurrent, ptrCurrent->ptrRight);
                finished = false;
            }
            else
            {
            ptrCurrent = ptrCurrent->ptrRight;
            }
        }
        // O proibido irá passar do nullptr até o segundo da lista
        ptrForbidden = ptrCurrent;
    }
}

void selectionSort(Node** ptrRoot) 
{
    if (((*ptrRoot) ==  nullptr) || ((*ptrRoot)->ptrRight ==  nullptr))
        return;
    
    // Node que irá localizar o loop 1
    Node* ptrCurrent = *ptrRoot;
    while (ptrCurrent->ptrRight != nullptr)
    {
        // primeiro, mínimo e localizador do loop 2 da sub-lista
        Node* ptrFirst = ptrCurrent;
        Node* ptrMin = ptrFirst;
        Node* ptrTmp = ptrFirst;
        while (ptrTmp != nullptr)
        {
            if (ptrTmp->iPayload < ptrMin->iPayload)
            {
                ptrMin = ptrTmp;
            }
            ptrTmp = ptrTmp->ptrRight;
        }
        swapNodes(ptrRoot, ptrFirst, ptrMin);
        ptrCurrent = ptrMin->ptrRight;
    }
}

// função pega o Node ref, vai k vezes na direção, retorna o node alcançado
Node* nodeCrawler(Node* ref, int k, std::string direction) {
    int i = 0;
    Node* ptrTmp = ref;
    if (direction == "left") {
        while (k > i) {
            ptrTmp = ptrTmp->ptrLeft;
            i++;
        }
    }
    if (direction == "right") {
        while (k > i) {
            ptrTmp = ptrTmp->ptrRight;
            i++;
        }
    }
    return ptrTmp;
}