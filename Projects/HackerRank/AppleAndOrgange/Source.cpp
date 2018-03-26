#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	
	int s, t, a, b, num_app, num_org, count_app = 0, count_org = 0;

	cin >> s >> t;
	cin >> a >> b;
	cin >> num_app >> num_org;

	int *app = new int[num_app];
	int *org = new int[num_org];

	for (int i = 0; i < num_app; i++)
		cin >> app[i];

	for (int i = 0; i < num_org; i++)
		cin >> org[i];

	for (int i = 0; i < num_app; i++)
	{
		if (a + app[i] >=s && a+app[i]<=t )
			count_app++;
	}
	
	for (int i = 0; i < num_org; i++)
	{
		if (b + org[i] >= s && b + org[i] <= t)
			count_org++;
	}
	cout << count_app << endl;
	cout << count_org;
	return 0;
}
