#include "SortAlgorithm.h"

void InsertionSort(int *m_arr, int m_size)
{
	for (int i = 1; i < m_size; i++)
	{
		int x = m_arr[i];
		int pos = i - 1;
		while (pos >= 0 && m_arr[pos] > x)
		{
			m_arr[pos+1] = m_arr[pos];
			pos--;
		}
		m_arr[pos+1] = x;
	}
}

void BinaryInsertionSort(int *m_arr, int m_size)
{
	int l, r, m, x;
	for (int i = 1; i < m_size; i++)
	{
		x = m_arr[i];
		l = 0; r = i-1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (m_arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		for (int j = i - 1; j >= l; j--)
			m_arr[j+1] = m_arr[j];
		m_arr[l] = x;
	}
}