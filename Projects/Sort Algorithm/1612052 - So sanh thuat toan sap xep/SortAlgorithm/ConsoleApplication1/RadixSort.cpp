#include "SortAlgorithm.h"
int Digit(int n, int k)
{
	for (int i = 1; i < k; i++)
		n = n / 10;
	return n % 10;
}
void ArrangeCollumn(int*m_arr, int m_size, int k)
{
	int *B = (int*)malloc(m_size*sizeof(int));
	int *C = (int*)malloc(10*sizeof(int));

	for (int i = 0; i < 10; i++)
		C[i] = 0;

	for (int i = 0; i < m_size; i++)
		C[Digit(m_arr[i],k)]++;

	for (int i = 1; i < 10; i++)
		C[i] += C[i-1];

	for (int i = m_size-1; i >= 0; i--)
	{
		int d = Digit(m_arr[i], k);
		int vt2 = C[d] - 1;
		B[vt2] = m_arr[i];
		C[d]--;
	}
	for (int i = 0; i < m_size; i++)
		m_arr[i] = B[i];
	free(B);
	free(C);
}
void RadixSort(int*m_arr, int m_size)
{
	int max = Max(m_arr, m_size);
	
	int max_digit = 1;
	while (max / 10 > 0)
	{
		max_digit++;
		max /= 10;
		//19273
	}
	//printf("- max digit: %d\n", max_digit);
	for (int k = 1; k <= max_digit;k++)
		ArrangeCollumn(m_arr, m_size, k);
}

void RadixSortUsingMatrix(int *m_arr, int m_size)
{
	int max = Max(m_arr, m_size);

	int max_digit = 1;
	while (max / 10 > 0)
	{
		max_digit++;
		max /= 10;
		//19273
	}

	int **L = (int**)malloc(10 * sizeof(int*));
	int i, j, k, t;
	//Ô đầu mỗi dòng lưu số lượng phần tử
	for (i = 0; i < 10; i++)
	{
		*(L + i) = (int*)malloc(m_size*sizeof(int*));
		*(*(L + i) + 0) = 0;
	}

	for (k = 1; k <= max_digit; k++)
	{
		//Phan loại
		for (i = 0; i < m_size; i++)
		{
			int dgt = Digit(m_arr[i], k);
			L[dgt][0]++;//tang so luong
			//*(L + dgt) = (int*)realloc(L+dgt,(L[dgt][0] +1)*sizeof(int));//cấp thêm vùng nhớ sau L[i][0]
			L[dgt][(L[dgt][0])] = m_arr[i];
		}
		//Gộp
		t = 0;
		for (int j = 0; j < 10;j++)
		if (L[j][0]>0)
		{
			//chay tu [1...L[j][0]
			for (i = 1; i <= L[j][0]; i++)
			{
				m_arr[t] = L[j][i];
				t++;
			}
			L[j][0] = 0;//reset
		}
		//Display(m_arr, m_size);
	}
}

void RadixSortUsingMatrixDynamicAllocated(int *m_arr, int m_size)
{
	int max = Max(m_arr, m_size);

	int max_digit = 1;
	while (max / 10 > 0)
	{
		max_digit++;
		max /= 10;
		//19273
	}

	int **L = (int**)malloc(10 * sizeof(int*));
	int i, j, k, t;
	//Ô đầu mỗi dòng lưu số lượng phần tử
	for (i = 0; i < 10; i++)
	{
		*(L + i) = (int*)malloc(sizeof(int*));
		*(*(L + i) + 0) = 0;
	}

	for (k = 1; k <= max_digit; k++)
	{
		//Phan loại
		for (i = 0; i < m_size; i++)
		{
			int dgt = Digit(m_arr[i], k);
			L[dgt][0]++;//tang so luong
			//*(L + dgt) = (int*)realloc(L+dgt,(L[dgt][0] +1)*sizeof(int));//cấp thêm vùng nhớ sau L[i][0]
			L[dgt] = (int*)realloc(L[dgt], (L[dgt][0] + 1) * sizeof(int));
			L[dgt][(L[dgt][0])] = m_arr[i];
		}
		//Gộp
		t = 0;
		for (int j = 0; j < 10; j++)
		if (L[j][0]>0)
		{
			//chay tu [1...L[j][0]
			for (i = 1; i <= L[j][0]; i++)
			{
				m_arr[t] = L[j][i];
				t++;
			}
			L[j] = (int*)realloc(L[j],1*sizeof(int));
			L[j][0] = 0;//reset
		}
		//Display(m_arr, m_size);
	}
}
