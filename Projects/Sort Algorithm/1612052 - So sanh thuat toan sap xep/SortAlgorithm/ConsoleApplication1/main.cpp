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
	int *arr; int N; double rtime=0.0;
	ofstream f_out;
	//f_out.open("Output/InterchangSort.txt",ios::app);
	//f_out.open("Output/InsertionSort.txt", ios::app);
	//f_out.open("Output/HeapSort.txt", ios::app);
	//f_out.open("Output/QuickSort.txt", ios::app);
	//f_out.open("Output/RadixSort.txt", ios::app);
	f_out.open("Output/FlashSort.txt", ios::app);

	if (f_out.fail()) return;

	for (long i = 5000; i <= 2000000; i += 5000)
	{
		N = i;
		arr = new int[N];
		readInputFile(arr, N);
		//RandomizeArray(arr, N);
		int part = 75, count = 0;
		//rtime = runTime(arr, N, InterchangeSort);
		//rtime = runTime(arr, N, InsertionSort);
		//rtime = runTime(arr, N, HeapSort);
		//rtime = runTime2(arr, 0, N-1, QuickSort);
		
		rtime = runTime3(arr, N, part,count,FlashSort);
		
		f_out << setw(6)<<i << " - " << rtime << endl;
		cout << setw(6) << i << " - " << rtime << endl;

		delete[]arr;
	}
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