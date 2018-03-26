#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N; cin >> N;
	int *arr = new int[N];
	int max, tmp, upper;
	for (int i = 0; i<N; i++)
	{
		cin >> arr[i];
	}

	max = arr[0]; tmp = arr[1], upper = 63000;

	for (int i = 1; i<N; i++)
	{
		if (arr[i] > max && arr[i]<upper)
		{
			tmp = max;
			max = arr[i];
		}
		else if (arr[i] == max)
		{
			upper = max;
			max = tmp;
		}
		else if (arr[i]>tmp && arr[i]<upper)
		{
			tmp = arr[i];
		}
	}

	cout << max;
	return 0;
}
