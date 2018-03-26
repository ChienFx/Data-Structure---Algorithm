#include "SortAlgorithm.h"
#include <string.h>

void Swap(int &a, int &b)
{
	int tmp = a; a = b; b = tmp;
}
int Max(int*m_arr, int m_size)
{
	int max = m_arr[0];
	for (long i = 1; i < m_size; i++)
	if (m_arr[i]>max)
		max = m_arr[i];
	return max;
}
void RandomizeArray(int*m_arr, int m_size)
{
	srand(time(NULL));
	for (int i = 0; i < m_size; i++)
		m_arr[i] = rand();// % 2000;
	/*
	FILE *f_in;
	char *path = new char[200];
	strcpy(path, "Input_");
	
	char num[30];
	itoa(m_size,num,10);
	strcat(num, ".txt");
	strcat(path, num);
		
	f_in = fopen(path, "w");
	if (f_in != NULL)
	{
		fprintf(f_in, "%d\n", m_size);
		for (int i = 0; i < m_size; i++)
			fprintf(f_in, "%d ", m_arr[i]);
	}
	fclose(f_in);*/
}
void Display(int*m_arr, int m_size)
{
	//printf("\n- Size: %d \n", m_size);
	printf("\n");
	for (int i = 0; i < m_size; i++)
		printf("%4d ", m_arr[i]);

	FILE *f;
	f = fopen("Output.txt", "w");
	if (f != NULL)
	{
		fprintf(f, "%d\n", m_size);
		for (int i = 0; i < m_size; i++)
			fprintf(f, "%d ", m_arr[i]);
	}
	fclose(f);
}


double runTime(int *m_arr, int m_size, void(*sortFunction)(int*, int))
{
	clock_t start = clock();
	sortFunction(m_arr, m_size);
	return (double)(clock() - start) / CLOCKS_PER_SEC;
}

void readInputFile(int *m_arr, int m_size)
{
	//delete[]m_arr;
	//m_arr = new int[m_size];

	char *path = new char[200];
	strcpy(path, "InputFile/Input_");

	char num[30];
	itoa(m_size, num, 10);
	strcat(num, ".txt");
	strcat(path, num);

	ifstream f_in;
	f_in.open(path, ios::in);
	int tmp; f_in >> tmp; 
	if (tmp != m_size) {
		cout << "Not match case!"; return;
	}
	for (long i = 0; i < m_size; i++)
		f_in >> m_arr[i];
	f_in.close();
}
//vidu: QuickSort(arr,0,N-1)
double runTime2(int *m_arr, int m_begin, int m_end, void(*sortFunction)(int*, int, int))
{
	clock_t start = clock();
	sortFunction(m_arr, m_begin,m_end);
	return (double)(clock() - start) / CLOCKS_PER_SEC;
}

//vidu: FlashSort(arr,N,M,&count)
double runTime3(int *m_arr, int m_size, int m_M,int &count, void(*sortFunction)(int*, int, int,int&))
{
	clock_t start = clock();
	sortFunction(m_arr, m_size, m_M,count);
	return (double)(clock() - start) / CLOCKS_PER_SEC;
}
