#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "tree_functions.h"

#include <iostream>

using namespace std;

void swapNodes(Node**, Node*, Node*);
void bubbleSort(Node**);
void selectionSort(Node**);
void putBeforeList(Node**, Node*, Node*);
void insertionSort(Node**);
int sizeOfList(Node*);
Node* nodeCrawler(Node*, int, string);
void shellSort(Node**);

#endif