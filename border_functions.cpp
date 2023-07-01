#include "border_functions.h"

//Função que retorna uma fila vazia
Border* newBorder()
{
    Border* ptrBorder = (Border*)malloc(sizeof(Border));
    ptrBorder->ptrLast = nullptr;
    ptrBorder->ptrTop = nullptr;

    return ptrBorder;
}

//Função que insere novo elemento a fronteira
void insertBorder(Border* ptrBorder, Node* ptrAddress, int iNum)
{
    //Inicializa o novo elemento da fronteira
    BorderElement* newElement = (BorderElement*)malloc(sizeof(BorderElement));
    newElement->ptrData = ptrAddress;
    //Nível em que o elemento está na árvore
    newElement->iLevel = iNum;
    newElement->ptrNext = nullptr;
    //Se a fronteira está vazia, o novo elemento será o primeiro e o último da fronteira
    if(ptrBorder->ptrTop==nullptr)
    {
        ptrBorder->ptrTop = newElement;
    }
    //Do contrário, vamos adicioná-lo no final
    else
    {
        ptrBorder->ptrLast->ptrNext = newElement;
    }
    //Atualizamos o último elemento da fronteira
    ptrBorder->ptrLast = newElement;
    
    return;
}

//Função que retira o elemento do topo da fronteira, e se o elemento tiver filhos vai adicioná-los
void popBorder(Border* ptrBorder)
{
    //Primeiro confere se a fronteira não está vazia
    if(ptrBorder->ptrTop!=nullptr)
    {
        //Define o elemento que será retirado
        BorderElement* ptrPop = ptrBorder->ptrTop;

        //Atualiza o novo top da fronteira
        ptrBorder->ptrTop = ptrBorder->ptrTop->ptrNext;

        //Apaga o elemento retirado
        delete(ptrPop);
    }   
    //Se caso o elemento retirado era o último, então deixa a fronteira vazia 
    if(ptrBorder->ptrTop==nullptr)
    {
        ptrBorder->ptrLast = nullptr;
    }
    return;
}