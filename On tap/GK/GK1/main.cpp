#include "SortAlgorithm.h"
/*
1. Interchange Sort

2. Insertion Sort

3. Quick Sort

4. Heap Sort

5. Radix Sort

6. Flash Sort*/
void main()
{
	int n = 50000000;
	int *a=new int[n];// = { 123, 80, 250, 19, 180, 31, 6 };
	//n = sizeof(a) / sizeof(a[0]);

	RandomizeArray(a, n);
	//Display(a, n);
	//RadixSortUsingBinary(a, n);
	MyFlashSort(a, n);
	Display(a, n);

	//cout << Get_Binary_Length(1611)<<" -- "<<Get_Binary_Digit(1611,4);
	//
	//int *arr; int N; double rtime;
	//ofstream f_out;
	//f_out.open("Output/FlashSort1.txt",ios::app);
	//if (f_out.fail()) return;
	////f_out << "FlastSort Sort runing time" << endl;

	//for (long i = 5000; i <= 2000000; i += 5000)
	//{
	//	N = i;
	//	arr = new int[N];
	//	readInputFile(arr, N);
	//	//RandomizeArray(arr, N);
	//	int part = 75, count = 0;
	//	//rtime = runTime(arr,N,InsertionSort);
	//	//rtime = runTime2(arr,0,N-1,QuickSort);
	//	rtime = runTime3(arr, N, part,count,FlashSort);
	//	f_out << setw(6)<<i << " - " << rtime << endl;
	//	cout << setw(6) << i << " - " << rtime << endl;

	//	delete[]arr;
	//}
	//TEst-Alg
	///SelectionSort(arr, N);
	//BubbleSort(arr, N);
	//InsertionSort(arr, N);
	//BinaryInsertionSort(arr, N);
	//HeapSort(arr, N);
	//QuickSort(arr, 0, N - 1);
	//MergeSort(arr, 0, N - 1);
	//CountingSort(arr, N);
	//RadixSort(arr, N);
	//RadixSortUsingMatrixDynamicAllocated(arr,N);
	//Display(arr, N);
	//delete[]arr;
	
}