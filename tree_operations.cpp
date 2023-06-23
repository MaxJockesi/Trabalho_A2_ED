#include <iostream>
#include "tree_operations.h"

int heightTree(Node* ptrRoot)
{
    //Se chegar em uma folha retorna 0, significando que chegou ao final da árvore
    if(ptrRoot==nullptr){
        return 0;
    }
    //Senão aumenta mais 1 na contagem da altura, e soma a maior altura entre seus filhos
    else{
        return 1 + std::max(heightTree(ptrRoot->ptrLeft), heightTree(ptrRoot->ptrRight));
    }
}



