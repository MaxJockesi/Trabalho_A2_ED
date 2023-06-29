#include <iostream>
#include <limits>
#include <chrono>
//Incluir bibliotecas próprias 
/*
#include "tree_functions.h"
#include "border_functions.h"
*/
using namespace std;
using namespace chrono;

//Tratamento de exceção na inserção de dados
void FailInsertion()
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    return;
}

//Função para determinar tempo de execução (em milisegundos) de uma operação
void TimeExecution()
{
    /*auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
    cout << "Time of execution: " << timeDuration.count()
    << " milliseconds" << endl;
    return;*/
}

//Conseguindo um ponteiro na tela - até 5 árvores na memória
struct Node* ChooseRoot()
{
    
    cout << "Choose a integer your tree from 1 to 5." << endl << endl;
    
    for(int i = 1; i <= 5; i++)
    {
        cout << i <<". Tree " << i << endl;
    }
    
    cout << endl;
    
    while(true)
    {
        int iChosenNumber;
        cin >> iChosenNumber;
        
        FailInsertion();
        
        switch(iChosenNumber)
        {
            case 1:
                return ptrTree1;
            case 2:
                return ptrTree2;
            case 3:
                return ptrTree3;
            case 4:
                return ptrTree4;
            case 5:
                return ptrTree5;
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
        int ioption;
        cin >> ioption;
        
        FailInsertion();
        
        switch(ioption)
        {
            //Criar árvore por arquivo-texto
            case 1:
            {    
                auto timeStart = high_resolution_clock::now();
                
            
                return;
            }    
            //Criar árvore pela interface
            case 2:
            {
                struct Node* ptrInterface = ChooseRoot();
                auto timeStart = high_resolution_clock::now();
                
                return;
            }    
            // Insere um novo elemento na árvore
            case 3:
            {
                struct Node* ptrInterface = ChooseRoot();
                int iNewelement;
                
                cout << "Type a number to be a new element for the " 
                "choosen tree: ";
                cin >> iNewelement;
                
                auto timeStart = high_resolution_clock::now();
                insertData(&ptrInterface, iNewelement);
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                
                return;
            }    
            // Deleta um elemento da árvore    
            case 4:
            {
                struct Node* ptrInterface = ChooseRoot();
                int idelelement;
                
                cout << "Type a number to be deleted for the "
                "choosen tree one time: ";
                cin >> idelelement;
                
                auto timeStart = high_resolution_clock::now();
                deleteData(&ptrInterface, idelelement);
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
            }    
            default:
                cout << "Invalid option. Choose an integer from 1 to 4." << endl
                << endl;
        }
    }
}

//Opções para informações sobre uma árvore.
void TreeInformation()
{
    cout << endl;
    cout << "Tree's information: Type the number of the "
    "function of your choose." << endl;
    
    cout << "1. Get the tree's height" << endl;
    cout << "2. Get the tree's size." << endl;
    cout << "3. Get a an element's adress from a tree." << endl;
    cout << "4. Verify if a tree is complete" << endl;
    cout << "5. Verify if a tree is perfect" << endl;
    cout << "6. Display tree by BFS(Breadth-First Search)" << endl;
    cout << endl;
    
    while(true)
    {
        int ioption;
        cin >> ioption;
        
        FailInsertion();
        
        switch(ioption)
        {
            case 1:
            {
                struct Node* ptrInterface = ChooseRoot();
                
                auto timeStart = high_resolution_clock::now();
                
                int iheight = heightTree(ptrInterface);
                cout << "Tree's height: " << iheight << endl;
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
                
            }
            //Tamanho da árvore
            case 2:
            {
                struct Node* ptrInterface = ChooseRoot();
                
                auto timeStart = high_resolution_clock::now();
                int itreesize = sizeTree(ptrInterface);
                
                cout << "Tree's size: " << itreesize << endl;
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
            }    
            case 3:  
            {
                int iSearchNum;
                struct Node* ptrInterface = ChooseRoot();
                
                cout << "Type a integer number you want to find in the choosen " 
                "tree: "
                << endl;
                
                //Verificação do número
                cin >> iSearchNum;
                while(cin.fail())
                {
                    cout << "Invalid insertion(Has to be a integer number)." << endl;
                    FailInsertion();
                }
                
                //Resultado
                cout << "Adresses with the number at the tree: " << endl;
                auto timeStart = high_resolution_clock::now();
                findTree(ptrInterface, iSearchNum);
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                cout << endl;
                return;
            }    
            case 4:
            {
                struct Node* ptrInterface = ChooseRoot();
                auto timeStart = high_resolution_clock::now();
                if(completeTree(ptrInterface))
                {
                    cout << "The tree is complete." << endl;
                }
                else
                {
                    cout << "The tree isn't complete." << endl;
                }
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
            case 5:
            {
                struct Node* ptrInterface = ChooseRoot();
                auto timeStart = high_resolution_clock::now();
                if(perfectTree(ptrInterface))
                {
                    cout << "The tree is perfect." << endl;
                }
                else
                {
                    cout << "The tree isn't perfect." << endl;
                }
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
            }    
            case 6:
            {
                auto timeStart = high_resolution_clock::now();
                struct Node* ptrInterface = ChooseRoot();
                cout << "Printing tree by BFS: " << endl << endl;
                printTree(ptrInterface);
                
                auto timeStop = high_resolution_clock::now();
                auto timeDuration = duration_cast<milliseconds>(timeStop - timeStart);
                
                cout << "Time of execution: " << timeDuration.count()
                << " milliseconds" << endl;
                return;
            }   
            default:
                cout << "Invalid option. Choose an integer from 1 to 6." << endl
                << endl;
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
    
    cout << "1. Sort by Bubble Sort" << endl;
    cout << "2. Sort by Selection Sort" << endl;
    cout << "3. Sort by Insertion Sort" << endl;
    cout << "4. Sort by Shell Sort" << endl;
    cout << "5. Sort visualization(Bubble)" << endl;
    cout << "6. Sort visualization(Selection) " << endl;
    cout << "7. Sort visualization(Insertion) " << endl;
    cout << "8. Sort visualization(Shell) " << endl;
    cout << endl;
    
    while(true)
    {
        int ioption;
        cin >> ioption;
        
        FailInsertion();
        
        switch(ioption)
        {
            case 1:
                return;
            case 2:
                return;
            case 3:  
                return;
            case 4:
                return;
            case 5:
                return;
            case 6:
                return;
            case 7:
                return;
            case 8:
                return;
            default:
                cout << "Invalid option. Choose an integer from 1 to 8." << endl
                << endl;
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
        int ientrance;
        cin >> ientrance;
        
        //Tratamento de Exçeção - Algo sem ser inteiro
        FailInsertion();
       
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
Execução do sistema 
*/
int main()
{
    //Entrada inicial do sistema 
    cout << "Welcome to Tree data struct explorer!" << endl << endl;
    
    bool bexecution = true;
    
    while(bexecution == true)
    {
        FirstOperation();
        bexecution = Exitfunction();
    }

    return 0;
}