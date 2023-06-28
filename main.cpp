
#include <iostream>
#include <limits>
#include <chrono>
//Incluir bibliotecas próprias 
/*
#include "tree_functions.h"
#include "border_functions.h"
*/
using namespace std;

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
    cout << "2. Create a tree by input data." << endl;
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
            case 1:
                return;
            case 2:
                return;
            case 3:  
                return;
            case 4:
                return;
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
    cout << "Wellcome to Tree data struct explorer!" << endl << endl;
    
    bool bexecution = true;
    
    while(bexecution == true)
    {
        FirstOperation();
        bexecution = Exitfunction();
    }

    return 0;
}
