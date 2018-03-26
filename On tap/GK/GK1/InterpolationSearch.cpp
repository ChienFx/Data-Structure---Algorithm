#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void ExchangeSort(int*arr, int size);
int	 InterpolationSearch(int*arr, int size, int key);

void main()
{
	
	const int size = 100;
	int a[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
	ExchangeSort(a, size);
	int key = 10;
	int index = InterpolationSearch(a, size, key);
	
	printf("%d", index);
	if (index != -1)
		printf("\n%d", a[index]);
}

void ExchangeSort(int*arr, int size)
{
	for (int i = 0; i < size - 1;i++)
	for (int j = i + 1; j < size;j++)
	if (arr[i] > arr[j])
	{
		int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
	}
}
int	 InterpolationSearch(int*arr, int size, int key)
{
	int l = 0;
	int r = size - 1;
	int x = -1;
	while (l < r)
	{
		x = l + ((r - l)*(key - arr[l])) / (arr[r] - arr[l]);
		if (arr[x] == key)
			return x;
		if (arr[x]<key)
		{
			l = x + 1;
		}
		else
		{
			r = x - 1;
		}
	}
	return -1;
}