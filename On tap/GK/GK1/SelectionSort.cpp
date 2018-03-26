#include "SortAlgorithm.h"

void SelectionSort(int *m_arr, int m_size)
{
	for(int i = 0;i < m_size - 1;i++)
	{
		int min = i+1;
		for(int j = min; j < m_size; j++)
		{
			if(m_arr[j] < m_arr[min])
				min = j;
			if(m_arr[i] > m_arr[min])
			{
				Swap(m_arr[i], m_arr[j]);
			}
		}
	}
}
