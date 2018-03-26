#include "SortAlgorithm.h"

void Heapified(int* m_arr, int m_left, int m_right)
{
	int x, i, j;
	i = m_left;
	j = m_left * 2 + 1; //[i, j] vs [i, j+1] is relate
	x = m_arr[i];
	while (j <= m_right)
	{
		if (j<m_right)//has a[j+1]
		if (m_arr[j] < m_arr[j + 1])
			j++; // arr[j] is bigger than a[j+1]
		if (m_arr[j] < x)
			return;//ok
		else
		{
			Swap(m_arr[i], m_arr[j]);
			i = j;
			j = i * 2+1;
			x = m_arr[i];
		}
	}
}
void BuildHeap(int *m_arr, int m_size)
{
	int left = (m_size-2) / 2;
	while (left >= 0)
	{
		Heapified(m_arr, left, m_size - 1);
		left--; 
	}
}
void HeapSort(int *m_arr, int m_size)
{
	BuildHeap(m_arr, m_size);
	int r = m_size - 1;
	while (r>0)
	{
		Swap(m_arr[0], m_arr[r]);
		r--;
		Heapified(m_arr, 0, r);
	}

}