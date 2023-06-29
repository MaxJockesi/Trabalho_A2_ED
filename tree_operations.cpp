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
        return 1 + sizeTree(ptrRoot->ptrLeft) + sizeTree(ptrRoot->ptrRight);
    }
}

//Função que printa os endereços que possuem o número procurado
void findTree(Node* ptrRoot, int iNum)
{
    if(ptrRoot!=nullptr)
    {
        //Se o ptrRoot tiver o mesmo número que procuramos, printa ele
        if(ptrRoot->iPayload==iNum)
        {
            cout << ptrRoot << endl;
        }
        //Encontra em qual lado o número pode estar, se for menor estará do lado esquerdo
        if(iNum < ptrRoot->iPayload)
        {
            findTree(ptrRoot->ptrLeft, iNum);
        }
        //Do contrário, no lado direito
        else
        {
            findTree(ptrRoot->ptrRight, iNum);
        }
    }
    return;
}

//Função que retorna true se árvore passada é cheia
bool fullTree(Node* ptrRoot)
{
    if(ptrRoot==nullptr){
        return true;
    }
    //Se alguns dos filhos for nullptr, então irá conferir se ambos são, do contrário não será cheia
    if(ptrRoot->ptrLeft==nullptr || ptrRoot->ptrRight==nullptr){
        if(ptrRoot->ptrLeft==nullptr && ptrRoot->ptrRight==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    //Confere se ambos os lados do ptrRoot são cheios, se um não for, a árvore não será cheia
    return (fullTree(ptrRoot->ptrLeft) && fullTree(ptrRoot->ptrRight));
}

bool completeTree(Node* ptrRoot)
{
    //false/false=false true/true=true true/false=false 
    if(ptrRoot==nullptr){
        return true;
    }
    if(!((heightTree(ptrRoot->ptrLeft)==heightTree(ptrRoot->ptrRight)) || (heightTree(ptrRoot->ptrLeft)==heightTree(ptrRoot->ptrRight)+1))
    ||!((fullTree(ptrRoot->ptrLeft)&&fullTree(ptrRoot->ptrRight)) || (fullTree(ptrRoot->ptrLeft)&&!fullTree(ptrRoot->ptrRight)))){
        return false;
    }

    return (completeTree(ptrRoot->ptrLeft)&&completeTree(ptrRoot->ptrRight));
}

//Função que retorna true se a árvore passada é perfeita
bool perfectTree(Node* ptrRoot)
{
    //Se chegou em uma folha, então não houve nenhum probema e retorna true 
    if(ptrRoot == nullptr){
        return true;
    }
    //Se a altura de ambos os galhos do ptrRoot forem iguais, então significa que possuem mesmo número de níveis
    if(heightTree(ptrRoot->ptrLeft)==heightTree(ptrRoot->ptrRight)){
        //Agora testa com os filhos do ptrRoot
        return (perfectTree(ptrRoot->ptrLeft) && perfectTree(ptrRoot->ptrRight));
    }
    //Se não possuírem as mesmas alturas, então não tem como ser perfeita
    else{
        return false;
    }
}

void printTree(Node* ptrRoot)
{
    int iDepth = 1;
    int iSize = sizeTree(ptrRoot);
    Border* ptrBorder = newBorder();
    insertBorder(ptrBorder, ptrRoot, 1);
    BorderElement* ptrCurrent;
    for(int i = 0; i<iSize; i++){
        ptrCurrent = ptrBorder->ptrTop; 
        if(iDepth<ptrCurrent->iLevel){
            iDepth += 1;
            cout << endl;
        }
        cout << ptrCurrent->ptrData->iPayload << " ";
        popBorder(ptrBorder);
    }
    cout << endl;

}