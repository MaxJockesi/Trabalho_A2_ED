#include <iostream>
#include <limits>
#include <chrono>

//Incluir bibliotecas próprias 

#include "tree_operations.h"
#include "sorting_algorithms.h"
#include "tree_functions.h"

using namespace std;
using namespace chrono;

//Variáveis globais(Slots de árvores)
struct Node* ptrTree1 = nullptr;
struct Node* ptrTree2 = nullptr;
struct Node* ptrTree3 = nullptr;
struct Node* ptrTree4 = nullptr;
struct Node* ptrTree5 = nullptr;

//Teste - apagar depois 
void principal()
{
    for(int i = 0; i < 5; i++)
    {
        insertData(&ptrTree1, i);
    }

    printTree(ptrTree1);
}

/*
As funções time execution são usadas para cálculo da execução das funções.
É passado um ponteiro da função, a fim de tornar o código menos verboso.
*/

//Cálculo de tempo para funções de ponteiro duplo(Sorts)
void TimeExecutionSorts(Node* ptrRoot, void (*function)(Node**))
{
    auto timeStart = high_resolution_clock::now();
    
    function(&ptrRoot);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    return;
}

//Para funções de ponteiro simples
void TimeExecution(Node* ptrRoot, void (*function)(Node*))
{
    auto timeStart = high_resolution_clock::now();
    
    function(ptrRoot);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    return;
}

//Função que calcula tempo para inteiros - função int
int TimeExecution(Node* ptrRoot, int (*function)(Node*))
{
    auto timeStart = high_resolution_clock::now();
    int iNumber = function(ptrRoot);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    cout << endl;
    return iNumber;
}

//Função que calcula tempo para inteiros - função void
void TimeExecution(Node** ptrRoot, int iNumber, void (*function)(Node**, int))
{
    auto timeStart = high_resolution_clock::now();
    function(ptrRoot, iNumber);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    cout << endl;
    return;
}

//Cálculo de tempo para função void com inteiro e ponteiro simples
void TimeExecution(Node* ptrRoot, int iNumber, void (*function)(Node*, int))
{
    auto timeStart = high_resolution_clock::now();
    function(ptrRoot, iNumber);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    cout << endl;
    return;
}


//Função que calcula tempo para inteiros - função bool
bool TimeExecution(Node* ptrRoot, bool (*function)(Node*))
{
    auto timeStart = high_resolution_clock::now();
    bool bverify = function(ptrRoot);
                
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    cout << endl;
    return bverify;
}


//Tratamento de exceção na inserção de inteiros
int CinInsertion()
{
    int iNumber;
    cin >> iNumber;
    
    if(cin.fail())
    {
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cin >> iNumber;
        }
    }
    
    return iNumber;
}


//Conseguindo um ponteiro na tela - até 5 árvores na memória
struct Node** ChooseRoot()
{
    
    cout << "Choose a integer your tree from 1 to 5." << endl << endl;
    
    for(int i = 1; i <= 5; i++)
    {
        cout << i <<". Tree " << i << endl;
    }
    
    cout << endl;
    
    while(true)
    {
        int iChosenNumber = CinInsertion();
        
        switch(iChosenNumber)
        {
            case 1:
                return &ptrTree1;
            case 2:
                return &ptrTree2;
            case 3:
                return &ptrTree3;
            case 4:
                return &ptrTree4;
            case 5:
                return &ptrTree5;
            default:
                cout << "Invalid option. Choose an integer from 1 to 5." << endl
                << endl;
        }
    }
    
    //Evitar warning 
    return nullptr;
}

//Função de continuar/sair do programa
bool Exitfunction()
{
    cout << endl;
    while(true) 
    {
        cout << "Do you want to continue? Y/N: ";
        char chexit;
        cin >> chexit;

        switch(chexit)
        {
        case 'Y':
        case 'y':
            cout << endl;
            return true;
        case 'N':
        case 'n':
            cout << "Exiting the program." << endl;
            return false;
        default:
            cout << "Invalid character. Try again." << endl << endl;
        }
    } 
}

//Opções para criação/alteração de árvore.
void TreeCreation()
{
    cout << endl;
    cout << "Tree's creation and change: Type the number of the "
    "function of your choose." << endl;
    
    cout << "1. Create a tree from a text-archive" << endl;
    cout << "2. Create a tree by inputing data." << endl;
    cout << "3. Insert an element into a tree." << endl;
    cout << "4. Remove an element from a tree." << endl;
    cout << endl;
    
    while(true)
    {
        int ioption = CinInsertion();
        
        switch(ioption)
        {
            //Criar árvore por arquivo-texto
            case 1:
            {    
                struct Node** ptrInterface = ChooseRoot();
                char* NameFile;
                cout << "Input the adress of your file: " << endl;
                cin >> NameFile;
                
                auto timeStart = high_resolution_clock::now();
                *ptrInterface = readTree(NameFile);
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<seconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " seconds" << endl;
                return;
            }    
            //Criar árvore pela interface
            case 2:
            {
                struct Node** ptrInterface = ChooseRoot();
                auto timeStart = high_resolution_clock::now();
                
                *ptrInterface = createTree();
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<seconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " seconds" << endl;
                return;
            }    
            // Insere um novo elemento na árvore
            case 3:
            {
                struct Node** ptrInterface = ChooseRoot();
                
                cout << "Type a number to be a new element for the " 
                "choosen tree: ";
                int iNewelement = CinInsertion();
                
                TimeExecution(ptrInterface, iNewelement, &insertData);
                return;
            }    
            // Deleta um elemento da árvore    
            case 4:
            {
                struct Node** ptrInterface = ChooseRoot();
                int idelelement;
                
                cout << "Type a number to be deleted for the "
                "choosen tree one time: ";
                cin >> idelelement;
                
                TimeExecution(ptrInterface, idelelement, &deleteData);
                return;
            }    
            default:
            {
                cout << "Invalid option. Choose an integer from 1 to 4." << endl
                << endl;
            }    
        }
    }
}

//Opções para informações sobre uma árvore.
void TreeInformation()
{
    cout << endl;
    cout << "Tree's information: Type the number of the "
    "function of your choose." << endl;
    
    cout << "1. Get the tree's height." << endl;
    cout << "2. Get the tree's size." << endl;
    cout << "3. Get a an element's adress from a tree." << endl;
    cout << "4. Verify if a tree is complete." << endl;
    cout << "5. Verify if a tree is perfect." << endl;
    cout << "6. Display tree by BFS(Breadth-First Search)." << endl;
    cout << endl;
    
    while(true)
    {
        int ioption = CinInsertion();
        
        //Escolhendo o ponteiro e realizando as funções de informção da árovre
        switch(ioption)
        {
            //Altura da árvore
            case 1:
            {
                struct Node** ptrInterface = ChooseRoot();
                int iheight = TimeExecution(*ptrInterface, &heightTree);
                
                cout << "Tree's height: " << iheight << endl;
                return;
                
            }
            //Tamanho da árvore
            case 2:
            {
                struct Node** ptrInterface = ChooseRoot();
                int itreesize = TimeExecution(*ptrInterface, &sizeTree);
                cout << "Tree's size: " << itreesize << endl;
                return;
            }
            //Endereços de um número inteiro em uma árvore
            case 3:  
            {
                struct Node** ptrInterface = ChooseRoot();
                
                cout << "Type a integer number you want to find in the choosen " 
                "tree: "<< endl;
                
                //Verificação do número
                int iSearchNum = CinInsertion();
                
                //Resultado
                cout << "Adresses with the number at the tree: " << endl;
                TimeExecution(*ptrInterface, iSearchNum, &findTree);
                cout << endl;
                return;
            }
            //Verifica se árvore é completa
            case 4:
            {
                struct Node** ptrInterface = ChooseRoot();
                bool biscomplete = TimeExecution(*ptrInterface, &completeTree);
                if(biscomplete == true)
                {
                    cout << "The tree is complete." << endl;
                }
                else
                {
                    cout << "The tree isn't complete." << endl;
                }
                return;
            }
            //Verifica se árvore é perfeita
            case 5:
            {
                struct Node** ptrInterface = ChooseRoot();
                bool bisperfect = TimeExecution(*ptrInterface, &perfectTree);
                if(bisperfect == true)
                {
                    cout << "The tree is perfect." << endl;
                }
                else
                {
                    cout << "The tree isn't perfect." << endl;
                }
                return;
            }
            // Imprime a árvore por BFS
            case 6:
            {
                struct Node** ptrInterface = ChooseRoot();
                cout << "Printing tree by BFS: " << endl << endl;
                TimeExecution(*ptrInterface, &printTree);
                return;
            }
            default:
            {
                cout << "Invalid option. Choose an integer from 1 to 6." << endl
                << endl;
            }    
        }
    }
}

//Opções para informações sobre ordenação de elementos.
void TreeOrder()
{
    cout << endl;
    cout << "Tree's element sorting: Type the number of the "
    "function of your choose." << endl;
    cout << "The sorts will convert the tree in a list to do the sort." << endl;
    
    cout << "1. Sort by Bubble Sort." << endl;
    cout << "2. Sort by Selection Sort." << endl;
    cout << "3. Sort by Insertion Sort." << endl;
    cout << "4. Sort by Shell Sort." << endl;
    cout << "5. Sort visualization(Bubble)." << endl;
    cout << "6. Sort visualization(Selection). " << endl;
    cout << "7. Sort visualization(Insertion). " << endl;
    cout << "8. Sort visualization(Shell). " << endl;
    cout << endl;
    
    while(true)
    {
        int ioption = CinInsertion();
        
        switch(ioption)
        {
            //Bubble Sort
            case 1:
            {
                struct Node** ptrInterface = ChooseRoot();
                TimeExecutionSorts(*ptrInterface, &bubbleSort);
                cout << "Ordened tree. See it now." << endl;
                return;
            }    
            //Selection Sort    
            case 2:
            {
                struct Node** ptrInterface = ChooseRoot();
                TimeExecutionSorts(*ptrInterface, &selectionSort);
                cout << "Ordened tree. See it now." << endl;
                return;
            }    
            //Insertion Sort    
            case 3:
            {
                struct Node** ptrInterface = ChooseRoot();
                TimeExecutionSorts(*ptrInterface, &insertionSort);
                cout << "Ordened tree. See it now." << endl;
                return;
            }    
            //Shell Sort    
            case 4:
            {
                struct Node** ptrInterface = ChooseRoot();
                TimeExecutionSorts(*ptrInterface, &shellSort);
                cout << "Ordened tree. See it now." << endl;
                return;
            }    
            case 5:
            {
                struct Node** ptrInterface = ChooseRoot();
                
                
                return;
            }    
            case 6:
            {
                struct Node** ptrInterface = ChooseRoot(); 
                
                
                return;
            }    
            case 7:
            {
                struct Node** ptrInterface = ChooseRoot();
                return;
            }    
            case 8:
            {
                struct Node** ptrInterface = ChooseRoot();
                return;
            }    
            default:
            {
                cout << "Invalid option. Choose an integer from 1 to 8." << endl
                << endl;
            }    
        }
    }
}

//Função de menu das operações
void FirstOperation()
{
    cout << "Which of the options below do you want to work with it?"
    "Type the integer of the function." << endl << endl;
    
    cout << "1. Tree's creation and change" << endl;
    cout << "2. Tree's information" << endl;
    cout << "3. Tree's elements sorting" << endl;
    cout << endl;
    
    while(true)
    {
        //Loop para escolha de opções
        int ientrance = CinInsertion();
       
        //Opções primárias 
        switch(ientrance)
        {
            case 1:
                TreeCreation();
                return;
            case 2:
                TreeInformation();
                return;
            case 3:
                TreeOrder();
                return;
            default:
                cout << "Invalid type. Choose a integer from 1 to 3. " << endl;
        }
    }
}

/*
Driver Code
*/
int main()
{
    //Teste
    principal();
    
    //Entrada inicial do sistema 
    cout << "Welcome to Tree data struct explorer!" << endl << endl;
    
    bool bexecution = true;
    
    while(bexecution == true)
    {
        FirstOperation();
        bexecution = Exitfunction();
    }
    
    //Liberar memória
    free(ptrTree1);
    free(ptrTree2);
    free(ptrTree3);
    free(ptrTree4);
    free(ptrTree5);
    
    return 0;
}
