#include "SortAlgorithm.h"

void MergeSort(int *m_arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(m_arr, left, mid);
		MergeSort(m_arr, mid + 1, right);
		Merge(m_arr, left, mid, right);
	}
}

void Merge(int *m_arr, int left, int mid, int right)
{
	if (left < right){
		int n = right - left + 1;
		int *tmp = new int[n];
		int i = left, j = mid + 1, k = 0;

		for (k = 0; k < n; k++){
			if (m_arr[i] < m_arr[j]){
				tmp[k] = m_arr[i];
				i++;
			}
			else{
				tmp[k] = m_arr[j];
				j++;
			}
			if (i > mid){
				while (j <= right){
					k++;
					tmp[k] = m_arr[j];
					j++;
				}
				break;
			}
			if (j > right){
				while (i <= mid){
					k++;
					tmp[k] = m_arr[i];
					i++;
				}
				break;
			}
		}
		
		for (i = 0; i < n;i++)
			m_arr[i + left] = tmp[i];

		delete[]tmp;
	}
}