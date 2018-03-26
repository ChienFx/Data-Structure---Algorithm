#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	int *arr = new int[n];
	int *kq = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		kq[i] = arr[i];
		if (kq[i] >= 38)
		{
			if (5 - kq[i] % 5 < 3)
				kq[i] += 5 - kq[i] % 5;

			if (kq[i] > 100)
				kq[i] = 100;
		}
	}

	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << kq[i] << endl;


	return 0;
}
