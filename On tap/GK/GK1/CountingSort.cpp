#include "SortAlgorithm.h"


void CountingSort(int*m_arr, int m_size)
{
	int *B = new int[m_size];
	int k = Max(m_arr, m_size)+1;
	int *C = new int[k];
	for (int i = 0; i < k; i++)
		C[i] = 0;
	//dem tan suat cua mang m_arr vao C
	for (int i = 0; i < m_size; i++)
		C[m_arr[i]]++;
	for (int i = 1; i < k; i++)
		C[i] += C[i - 1];
	for (int j = m_size - 1; j >= 0; j--)
	{
		B[C[m_arr[j]]-1] = m_arr[j];
		C[m_arr[j]]--;
	}
	for (int i = 0; i < m_size; i++)
		m_arr[i] = B[i];
	delete[]B;
	delete[]C;
}
