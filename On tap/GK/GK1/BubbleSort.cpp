#include "SortAlgorithm.h"


//void swap(int &a, int &b){ int tmp = a; a = b; b = tmp; }
void BubbleSort(int*m_arr, int m_size)
{
	for (int i = 0; i < m_size;i++)
	for (int j = m_size - 1; j > i;j--)
	if (m_arr[j] < m_arr[j - 1])
		Swap(m_arr[j], m_arr[j-1]);
}