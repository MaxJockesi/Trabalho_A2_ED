#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include "node.h"

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
int maxOfList(Node*);
void drawState(Node*, SDL_Renderer*);
void bubbleSortAnimation(Node**);
void selectionSortAnimation(Node**);
void insertionSortAnimation(Node**);
void shellSortAnimation(Node**);

#endif