#ifndef _SORTALGORITHM_H
#define _SORTALGORITHM_H
#include "SinglyLinkedList.h"
#include <fstream>

void Input(List&l, const char* _path);
void Swap(List&l, Node*&p, Node *&q);

//Insertion sort
void InsertionSort(List&l);

//Selection sort
void SelectionSort(List&l);

//Quick sort
Node *Partition(List&l);
void QuickSort(List&l);

//Merge Sort 
void MergeSort(List&l);
void Merge(List&l, List&l1, List&l2);
void DistributeList(List&l, List&l1, List&l2);
#endif