#include <iostream>
#include "tree_operations.h"

using namespace std;

//Função que retorna a altura da árvore (quantos níveis a árvore possui)
int heightTree(Node* ptrRoot)
{
    //Se chegar em uma folha retorna 0, significando que chegou ao final da árvore
    if(ptrRoot == nullptr)
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
    if(ptrRoot == nullptr)
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
        if(ptrRoot->iPayload == iNum)
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
    if(ptrRoot == nullptr)
    {
        return true;
    }
    
    //Se alguns dos filhos for nullptr, então irá conferir se ambos são, do contrário não será cheia
    if(ptrRoot->ptrLeft == nullptr || ptrRoot->ptrRight == nullptr)
    {
        if(ptrRoot->ptrLeft == nullptr && ptrRoot->ptrRight == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //Confere se ambos os lados do ptrRoot são cheios, se um não for, a árvore não será cheia
    return (fullTree(ptrRoot->ptrLeft) && fullTree(ptrRoot->ptrRight));
}

//Função que retorna true se árvore é a completa
bool completeTree(Node* ptrRoot)
{
    //Se chegou em um nó folha então retorna true
    if(ptrRoot == nullptr)
    {
        return true;
    }
    //Existem dois casos que precisam ocorrer para a árvore ser completa, se ocorrerem,
    //então testa se as subárvores são completas
    if((heightTree(ptrRoot->ptrLeft) == heightTree(ptrRoot->ptrRight)) || fullTree(ptrRoot->ptrLeft))
    {
        return (completeTree(ptrRoot->ptrLeft)&&completeTree(ptrRoot->ptrRight));
    }
    else if((heightTree(ptrRoot->ptrLeft) == heightTree(ptrRoot->ptrRight)+1) || fullTree(ptrRoot->ptrRight))
    {
        return (completeTree(ptrRoot->ptrLeft) && completeTree(ptrRoot->ptrRight));
    }

    //Se os casos não ocorrerem então ele nõ pode ser perfeita
    return false;
}

//Função que retorna true se a árvore passada é perfeita
bool perfectTree(Node* ptrRoot)
{
    //Se chegou em uma folha, então não houve nenhum problema e retorna true 
    if(ptrRoot == nullptr)
    {
        return true;
    }
    //Se a altura de ambos os galhos do ptrRoot forem iguais, então significa que possuem mesmo número de níveis
    if(heightTree(ptrRoot->ptrLeft) == heightTree(ptrRoot->ptrRight))
    {
        //Agora testa com os filhos do ptrRoot
        return (perfectTree(ptrRoot->ptrLeft) && perfectTree(ptrRoot->ptrRight));
    }
    //Se não possuírem as mesmas alturas, então não tem como ser perfeita
    else
    {
        return false;
    }
}


//FUNÇÕES UTILIZADAS APENAS PARA PRINTAR A ÁRVORE

//Função que printa iNumber espaços 
void printSpace(int iNumber)
{
    for(int i = 0; i < iNumber; i++)
    {
        cout << " ";
    }
    return;
}

//Função que printa iNumber hífens
void printFeature(int iNumber)
{
    for(int i = 0; i < iNumber; i++)
    {
        cout << "-";
    }
    return;
}

//Função que retorna iBase^iExponent
int power(int iBase, int iExponent)
{
    //Tratamos que se iNumber for negativo então retorna 0, devido o uso da função 
    if(iExponent < 0)
    {
        return 0;
    }
    int iPow = 1;
    for(int i = 0; i < iExponent; i++)
    {
        iPow *= iBase;
    }
    return iPow;
}

//Função que retorna o número de dígitos do iNumber
int numberDigits(int iNumber)
{
    int iDigits = 0;
    while(iNumber > 0)
    {
        iNumber /= 10;
        iDigits +=1;
    }
    return iDigits;
}

//Função que a partir do ptrRoot adiciona todos os elementos por BFS,
//também encontra qual é o máximo de dígitos que os elementos tem
Border* mountBorder(Node* ptrRoot, int* iMaxDigits, int iHeight)
{
    Border* ptrBorder = newBorder();
    //Adiciona o ptrRoot a Border
    insertBorder(ptrBorder, ptrRoot, 1);
    //Define o iterador
    BorderElement* ptrAux = ptrBorder->ptrTop;
    //Adiciona a quantidade de vezes que uma árvore perfeita com essa altura teria de elementos
    for(int i = 0; i<power(2,iHeight)-1; i++)
    { 
        if(ptrAux->ptrData!=nullptr)
        {
            insertBorder(ptrBorder, ptrAux->ptrData->ptrLeft, ptrAux->iLevel +1);
            //Se o filho não for nullptr, confere quantos dígitos ele possue e atualiza o iMaxDigits
            if(ptrAux->ptrData->ptrLeft!=nullptr)
            {    
                if(numberDigits(ptrAux->ptrData->ptrLeft->iPayload)>*iMaxDigits)
                {
                    *iMaxDigits = numberDigits(ptrAux->ptrData->ptrLeft->iPayload);
                }
            }
            insertBorder(ptrBorder, ptrAux->ptrData->ptrRight, ptrAux->iLevel +1);
            //Se o filho não for nullptr, confere quantos dígitos ele possue e atualiza o iMaxDigits
            if(ptrAux->ptrData->ptrRight!=nullptr)
            {
                if(numberDigits(ptrAux->ptrData->ptrRight->iPayload)>*iMaxDigits)
                {
                    *iMaxDigits = numberDigits(ptrAux->ptrData->ptrRight->iPayload);
                }
            }
        }
        //Se o nó for nullptr, considera que seus "filhos" também serão
        else{
            insertBorder(ptrBorder, nullptr, ptrAux->iLevel +1);
            insertBorder(ptrBorder, nullptr, ptrAux->iLevel +1);
        }
        ptrAux = ptrAux->ptrNext;
    }
    
    return ptrBorder;
}

//Função que printa a árvore
void printTree(Node* ptrRoot)
{
    int iHeight = heightTree(ptrRoot);
    //Inicializa a variável
    int iMaxDigits = numberDigits(ptrRoot->iPayload);
    Border* ptrBorder = mountBorder(ptrRoot, &iMaxDigits, iHeight);
    for(int iDepth = 1; iDepth <= iHeight; iDepth++)
    {
        if(iDepth != iHeight)
        {
            printSpace(power(2,iHeight-(iDepth) - 1)*iMaxDigits);

            //Itera os elementos da camada iDepth
            for(int j = 0; j < power(2,iDepth - 1); j++)
            {
                if(ptrBorder->ptrTop->ptrData!=nullptr)
                {
                    printFeature((power(2,iHeight - iDepth - 1) - 1) * iMaxDigits);
                    //Para quando o elemento possui menos dígitos que o iMaxDigits, preenche de hífen
                    printFeature((int)((iMaxDigits - numberDigits(ptrBorder->ptrTop->ptrData->iPayload) + 1) / 2));
                    cout << ptrBorder->ptrTop->ptrData->iPayload;
                    printFeature((int)((iMaxDigits - numberDigits(ptrBorder->ptrTop->ptrData->iPayload)) / 2));
                    
                    printFeature((power(2,iHeight - iDepth -1 ) - 1) * iMaxDigits);
                }

                else
                {
                    printSpace(iMaxDigits);
                }
                printSpace((power(2, iHeight - iDepth) + 1) * iMaxDigits);

                popBorder(ptrBorder);
            }         
        }

        //Para o caso em que estamos na última camada, não devemos adicionar hífens, então tratamos
        else 
        {
            for(int j = 0; j < power(2,iDepth - 1); j++)
            {

                if(ptrBorder->ptrTop->ptrData!=nullptr)
                {
                        printSpace((int)((iMaxDigits-numberDigits(ptrBorder->ptrTop->ptrData->iPayload))/2));
                        cout << ptrBorder->ptrTop->ptrData->iPayload;
                        printSpace((int)((iMaxDigits-numberDigits(ptrBorder->ptrTop->ptrData->iPayload))/2));
                }
                
                else
                {
                    printSpace(iMaxDigits);
                }
                printSpace(iMaxDigits);

                popBorder(ptrBorder);
            }
        }
        cout << endl;
    }
}