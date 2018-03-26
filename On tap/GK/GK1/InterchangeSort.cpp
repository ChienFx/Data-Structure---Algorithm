#include "SortAlgorithm.h"

void InterchangeSort(int *m_arr, int m_size)
{
	for (int i = 0; i < m_size - 1; i++)
	{
		for (int j = i+1; j < m_size; j++)
		{
			if (m_arr[i] > m_arr[j])
			{
				Swap(m_arr[i], m_arr[j]);
			}
		}
	}
}
