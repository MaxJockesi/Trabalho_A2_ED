#define SDL_MAIN_HANDLED

#include <iostream>
#include "tree_functions.h"
#include <SDL2/SDL.h>

using namespace std;

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
    
    bool bFinished = false;
    Node *ptrCurrent;

    // Criamos um Node proibido
    Node *ptrForbidden = nullptr;

    while (bFinished == false)
    {
        bFinished = true;
        ptrCurrent = *ptrRoot;

        // ptrCurrent irá até imediatamente antes do proibido
        while (ptrCurrent->ptrRight != ptrForbidden)
        {
            if (ptrCurrent->iPayload > ptrCurrent->ptrRight->iPayload)
            {
                swapNodes(ptrRoot, ptrCurrent, ptrCurrent->ptrRight);
                bFinished = false;
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

// Função que coloca o ptrNode2 antes do ptrNode1
void putBeforeList(Node** ptrAddrHead, Node* ptrNode1, Node* ptrNode2){
	if(ptrNode1!=ptrNode2){
		Node* ptrNode1prev = ptrNode1->ptrLeft;
		Node* ptrNode2prev = ptrNode2->ptrLeft;
		Node* ptrNode2next = ptrNode2->ptrRight;
		
		// Se o ptrNode1 for o primeiro da lista, então deve mudar o head
		if(ptrNode1 == *ptrAddrHead){
		    *ptrAddrHead = ptrNode2;
		}
		else{
			// Do contrário muda o próximo do antecessor do ptrNode1
		    ptrNode1prev->ptrRight = ptrNode2;
		}
		if(ptrNode2next != nullptr){
			// Se o ptrNode não for o último, então muda o antecessor do seu próximo
			 ptrNode2next->ptrLeft = ptrNode2prev;
		}
		
		// Faz as trocas necessárias
		ptrNode2prev->ptrRight = ptrNode2next;
		ptrNode2->ptrLeft = ptrNode1prev;
		ptrNode2->ptrRight = ptrNode1;
		ptrNode1->ptrLeft = ptrNode2;
	}
	return;
}

// Função que ordena a lista usando o algoritmo inserction sort
void insertionSort(Node** ptrAddrHead){
	Node* ptrCurrent = *ptrAddrHead;
	Node* ptrIter;
	Node* ptrAux;
	bool bChanged;
	
	while(ptrCurrent!=nullptr){
		// Inicializa os nós auxiliares
		ptrAux = ptrCurrent->ptrRight;
		bChanged = false;
		ptrIter = ptrCurrent;
		while(ptrIter->ptrLeft!=nullptr){
			// Confere se o ptrCurrent é maior que o antecessor do ptrIter
			if(ptrIter->ptrLeft->iPayload<ptrCurrent->iPayload){
				// Se for coloca ele entre os dois
				putBeforeList(ptrAddrHead, ptrIter, ptrCurrent);
				bChanged = true;
				break;
			}		
			ptrIter = ptrIter->ptrLeft;
		}
		if(!bChanged){
			// Se não houve troca, então o ptrCurrent é o menor, e vai para o começo da lista
			putBeforeList(ptrAddrHead, *ptrAddrHead, ptrCurrent);
		}
		// Passo da iteração
		ptrCurrent = ptrAux;
	}
	return;
}

int sizeOfList(Node* ptrRoot)
{
    Node* ptrTmp = ptrRoot;
    int i = 0;
    while (ptrTmp != nullptr)
    {
        i++;
        ptrTmp = ptrTmp->ptrRight;
    }
    return i;
}

// função pega o Node ptrRoot, vai k vezes na direção, retorna o node alcançado
Node* nodeCrawler(Node* ptrRoot, int iSteps, string strDirection) {
    int i = 0;
    Node* ptrTmp = ptrRoot;
    if (strDirection == "left") {
        while (iSteps > i) {
            ptrTmp = ptrTmp->ptrLeft;
            i++;
        }
    }
    if (strDirection == "right") {
        while (iSteps > i) {
            ptrTmp = ptrTmp->ptrRight;
            i++;
        }
    }
    return ptrTmp;
}

void shellSort(Node** ptrRoot) 
{
    int iSize = sizeOfList((*ptrRoot));
    int iGap = (iSize - iSize % 2)/2; // gap inicial
    while (iGap >= 1) 
    {
        Node* ptrTmp_i = nodeCrawler(*ptrRoot, iGap, "right");
        // ptrTmp_i é o (iGap)-ésimo termo da DLL
        for (int i = iGap; i < iSize; i++) 
        {
            Node* ptrTmp_j = ptrTmp_i;
            // ptrTmp_j irá acompanhar j:
            int j = i;
            Node* ptrNext_i = ptrTmp_i->ptrRight;
            while (j >= iGap) 
            {
                Node* ptrCurrent = nodeCrawler(ptrTmp_j, iGap, "left");

                // ptrCurrent volta iGap posições
                if (ptrCurrent->iPayload > ptrTmp_j->iPayload) 
                {
                    swapNodes(ptrRoot, ptrCurrent, ptrTmp_j);
                    j = j - iGap;
                }
                else break;
            }
            ptrTmp_i = ptrNext_i;
        }
        iGap = (iGap - iGap % 2)/2; // Nova iGap é piso(iGap/2)
    }
}

int maxOfList(Node* ptrRoot)
{
    Node* ptrTmp = ptrRoot;
    int iMax = ptrRoot->iPayload;
    while (ptrTmp != nullptr)
    {
        if (ptrTmp->iPayload > iMax)
        {
            iMax = ptrTmp->iPayload;
        }
        ptrTmp = ptrTmp->ptrRight;
    }
    return iMax;
}

void drawState(Node* ptrRoot, SDL_Renderer* ptrRenderer)
{
    int iIndex = 0;
    Node* ptrTmp = ptrRoot;
    while (ptrTmp != nullptr)
    {
        SDL_SetRenderDrawColor(ptrRenderer, 0, 0, 0, 225);
        SDL_RenderDrawLine(ptrRenderer, iIndex, 720-ptrTmp->iPayload, iIndex, 0);
        iIndex += 1;
        ptrTmp = ptrTmp->ptrRight;
    }
}