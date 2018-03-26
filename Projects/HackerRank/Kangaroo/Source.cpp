#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int x1, x2, v1, v2;
	cin >> x1 >> v1>> x2 >> v2;
	int d1=x1, d2=x2;
	bool flag = 0;
	
	float k = (x2 - x2) / (v1 - v2);

	if (k == (int)k)
		flag = 1;
	
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
