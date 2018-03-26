#include "SortAlgorithm.h"

void QuickSort(int *m_arr, int m_left, int m_right)
{
	if(m_left < m_right)
	{
		int p = Partition(m_arr, m_left, m_right);
		QuickSort(m_arr, m_left, p - 1);
		QuickSort(m_arr, p + 1, m_right);
	}
}

//Luon chon phan tu cuoi cung m_arr[n-1] lam phan tu chot
int  Partition(int *m_arr, int m_left, int m_right)
{
	int x = m_arr[m_right];
	int i = m_left - 1;
	
	for (int j = i + 1; j < m_right;j++)
	if (m_arr[j] <= x)
	{
		i++;
		Swap(m_arr[i], m_arr[j]);
	}
	Swap(m_arr[i + 1], m_arr[m_right]);
	return i + 1;
}
