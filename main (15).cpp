/******************************************************************************

Árvore - estrutura de dados hierárquica

Definições básicas:
Root - Elemento que não possui ancestrais.
Child Node - Nó que possui um pai.
Parent - Pai de um nó.
Sibling - Nós de mesmo nível e mesmo pai. 
Ancestor Node - Um nó (não necessariamente um nó pai) que está na ascedência de um nó qualquer.
Leaf Node - Nó que não possui filhos.

Existem vários tipos de árvores:

Árvore binária - cada nó possui de 0 a 2 filhos.
Árvore de busca binária - Dado um nó com payload x, seus filhos à esquerda possuem carga menor
e a direita possuem carga maior ou igual que x.

*******************************************************************************/
#include <iostream>
using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

struct Node* newNode(int iData)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> iPayload = iData;
    newNode -> ptrLeft = nullptr;
    newNode -> ptrRight = nullptr;
    
    return newNode;
}

//Sequencializar usando pré-ordem(Meio, esquerda, direita)
void traversePreOrder(struct Node* ptrStartingNode)
{
    if(ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode -> iPayload;
        traversePreOrder(ptrStartingNode -> ptrLeft);
        traversePreOrder(ptrStartingNode -> ptrRight);
    }
}

//Sequencializar usando In-order(esquerda, meio, direita)
void traverseInOrder(struct Node* ptrStartingNode)
{
    if(ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode -> ptrLeft);
        cout << " " << ptrStartingNode -> iPayload;
        traverseInOrder(ptrStartingNode -> ptrRight);
    }
}

//Sequencializar usando In-order(esquerda, direita, meio)
void traversePostOrder(struct Node* ptrStartingNode)
{
    if(ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode -> ptrLeft);
        traversePostOrder(ptrStartingNode -> ptrRight);
        cout << " " << ptrStartingNode -> iPayload;
    }
}

//Procura nó em uma árvore de busca
struct Node* searchNode(struct Node* Node, int iData)
{
    if(Node == nullptr) return nullptr;
    else if(iData == Node -> iPayload) return Node;
    else if(iData < Node -> iPayload) return searchNode(Node -> ptrLeft, iData);
    else  return searchNode(Node -> ptrRight, iData);
    
}

//Inserir um nó na árvore
struct Node* insertNode(struct Node* Node, int iData)
{
    //Se a árvore for vazia
    if(Node == nullptr)
    {
        return newNode(iData);
    }
    
    //Se o dado for menor que o do nó atual - Usamos recursão no 
    //ponteiro à esquerda
    if(iData < Node -> iPayload)
    {
        Node -> ptrLeft = insertNode(Node -> ptrLeft, iData);
    }
    else
    {
        Node -> ptrRight = insertNode(Node -> ptrRight, iData);
    }
    
    return Node;
}

//Encontrar a folha de menor número
struct Node* LesserLeaf(struct Node* Node)
{
    struct Node* ptrCurrent = Node;
    
    while(ptrCurrent != nullptr && ptrCurrent -> ptrLeft != nullptr)
    {
        ptrCurrent = ptrCurrent -> ptrLeft;
    }
    return ptrCurrent;
}

//Deletar um nó da árvore
struct Node* deleteNode(struct Node* Node, int iData)
{
    //Caso seja nulo
    if(Node == nullptr)
    {
        return Node;
    }
    
    if(iData < Node -> iPayload)
    {
        Node -> ptrLeft = deleteNode(Node -> ptrLeft, iData);
    }
    else if(iData > Node -> iPayload)
    {
        Node -> ptrRight = deleteNode(Node -> ptrRight, iData);
    }
    else 
    {
        //Estou no nó que quero deletar
        struct Node* ptrTemp = nullptr;
        
        //Casos fáceis: 0/1 nó filho
        if(Node -> ptrLeft == nullptr)
        {
            ptrTemp = Node -> ptrRight;
            free(Node);
            
            return ptrTemp;
        }
        else if(Node -> ptrRight == nullptr)
        {
            ptrTemp = Node -> ptrLeft;
            free(Node);
            
            return ptrTemp;
        }
        else
        {
            //Buscando o candidato
            ptrTemp = LesserLeaf(Node -> ptrRight);
            
            //Fica para casa ajustar
            Node -> iPayload = ptrTemp -> iPayload;
            Node -> ptrRight = deleteNode(Node -> ptrRight, ptrTemp -> iPayload);
        }
        
    }
    
    return Node;
}

int main()
{
    //Árvore binária de busca feita à mão
    struct Node* root = newNode(42);
    root -> ptrLeft = newNode(7);
    root -> ptrRight = newNode(100);
    root -> ptrLeft -> ptrLeft = newNode(1);
    root -> ptrLeft -> ptrRight = newNode(13);
    
    /*
    Técnicas para atravessar a árvore:
    
    DFS (Busca em profundidade): Ir lendo de folha em folha.
    
    Sequencializar uma árvore - andar de elemento a elemento em uma árvore,
    como se fosse uma lista.Há algumas maneira de fazer isso:
    
    Pre-Order: Olhar o nó em que se está, depois olhar primeiro para a esquerda
    e depois para a direita.
    
    InOrder: Esquerda, meio, direita.
    
    PostOrder: Esquerda, direita, meio.
    */
    
    cout << "Atravesando a árvore - PreOrder: ";
    traversePreOrder(root);
    cout << endl;
    
    cout << "Atravesando a árvore - InOrder: ";
    traverseInOrder(root);
    cout << endl;
    
    cout << "Atravesando a árvore - PostOrder: ";
    traversePostOrder(root);
    cout << endl;
    
    //Casos de teste para o método de busca
    string resultado;
    
    resultado = (nullptr == searchNode(nullptr, 42))? "Ok":"Ops";
    cout << "Busca nullptr: " << resultado << endl;
    
    resultado = (root == searchNode(root, 42))? "Ok":"Ops";
    cout << "Busca 42: " << resultado << endl;
    
    resultado = (root -> ptrLeft == searchNode(root, 7))? "Ok":"Ops";
    cout << "Busca 7: " << resultado << endl;
    
    resultado = (root -> ptrLeft ->ptrLeft == searchNode(root, 1))? "Ok":"Ops";
    cout << "Busca 1: " << resultado << endl;
    
    resultado = (nullptr == searchNode(root, 10))? "Ok":"Ops";
    cout << "Busca 10: " << resultado << endl;
    
    //Inserindo nós em árvore binária de busca
    //Vazamento de memória!! Não faça isso em casa!!!
    root = nullptr;
    root = insertNode(root,42);
    root = insertNode(root,7);
    root = insertNode(root,100);
    root = insertNode(root,1);
    root = insertNode(root,13);
    
    //Deletando 
    deleteNode(root, 42);
    
    cout << "Atravesando a árvore - PreOrder: ";
    traversePreOrder(root);
    cout << endl;
    
    cout << "Atravesando a árvore - InOrder: ";
    traverseInOrder(root);
    cout << endl;
    
    cout << "Atravesando a árvore - PostOrder: ";
    traversePostOrder(root);
    cout << endl;
    
    return 0;
}









