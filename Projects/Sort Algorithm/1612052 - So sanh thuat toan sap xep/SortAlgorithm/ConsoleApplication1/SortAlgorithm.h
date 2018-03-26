#ifndef _SORTALGORITHM_H
#define _SORTALGORITHM_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Create a interger array m_size elements randomly
void RandomizeArray(int*m_arr, int m_size);
//Print m_arr array on the screen
void Display(int*m_arr, int size);
//Swap a and b
void Swap(int &a, int &b);
//Find the maximum element
int Max(int*m_arr, int m_size);
//Interchange sort
void InterchangeSort(int *m_arr, int m_size);

//Bubble sort: Accsending
void BubbleSort(int*m_arr, int m_size);

//Insertion sort: Accsending
void InsertionSort(int *m_arr, int m_size);
void BinaryInsertionSort(int *m_arr, int m_size);

//Selection sort: Accsending
void SelectionSort(int *m_arr, int m_size);

//Heap sort: Accsending
void Heapified(int* m_arr, int m_left, int m_right);
void BuildHeap(int *m_arr, int m_size);
void HeapSort(int *m_arr, int m_size);

//Quick sort: Accsending
void QuickSort(int *m_arr, int m_left, int m_right);
int  Partition(int *m_arr, int m_left, int m_right);

//Merge sort: Accsending
void Merge(int *m_arr, int left, int mid, int right);
void MergeSort(int *m_arr, int left, int right);


//Counting Sort: 
void CountingSort(int*m_arr, int m_size);
int Max(int*m_arr, int m_size);

//Radix Sort:
//Get the digit of postion k  from right to left of n (1, 2, ..)
int  Digit(int n,int k);
void ArrangeCollumn(int*m_arr, int m_size, int exp);
void RadixSort(int*m_arr, int m_size);

void RadixSortUsingMatrix(int *m_arr, int m_size);
void RadixSortUsingMatrixDynamicAllocated(int *m_arr, int m_size);


//FlashSort
void FlashSort(int *m_arr, int m_size, int m_partition, int &count);

//do thoi gian chay
void readInputFile(int *arr, int m_size);
double runTime(int *m_arr, int m_size, void(*sortFunction)(int*, int) );
double runTime2(int *m_arr, int m_begin, int m_end, void(*sortFunction)(int*, int,int));
double runTime3(int *m_arr, int m_size, int m_M, int &count, void(*sortFunction)(int*, int, int, int&));
#endif