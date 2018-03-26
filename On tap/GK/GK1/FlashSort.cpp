/***** FLASH.C ,FLOAT-, recursive subroutine version

Translation of Neubert's algorithm into C by Michael Sahota *****/


/* Subroutine Flash(a,n,m,ctr)

- Sorts array a with n elements by use of the index vector l of

dimension m (with m about 0.1 n).

- The routine runs fastest with a uniform distribution of elements.

- The vector l is declare dynamically using the calloc function.

- The variable ctr counts the number of times that flashsort is called.

- THRESHOLD is a very important constant.  It is the minimum number

of elements required in a subclass before recursion is used.     */


#include "SortAlgorithm.h"

const int THRESHOLD = 75;

const int CLASS_SIZE = 75;     /* minimum value for m */



void FlashSort(int *a, int n, int m, int &ctr)
{
	/* declare variables */

	long i, j, k, nmove, nx,mx, nmin,nmax;
	int *l, flash, hold;

	float c1, c2;
	
	/* allocate space for the l vector */

	l = new int[m];

	/***** CLASS FORMATION ****/

	//Find maxnial, minial
	nmin = nmax = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] < a[nmin]) nmin = i;
		else if (a[i] > a[nmax]) nmax = i;
	}
	

	if ((a[nmax] == a[nmin]) && (ctr == 0))
	{
		//printf("All the numbers are identical, the list is sorted\n");
		return;
	}

	c1 = (m - 1.0) / (a[nmax] - a[nmin]);
	c2 = a[nmin];


	l[0] = -1; /* since the base of the "a" (data) array is 0 */

	for (k = 1; k < m; k++) 
		l[k] = 0;

	for (i = 0; i < n; i++)
	{
		k = floor(c1*(a[i] - c2));
		l[k] += 1;
	}

	for (k = 1; k < m; k++) 
		l[k] += l[k - 1];
	
	hold = a[nmax];
	a[nmax] = a[0];
	a[0] = hold;

	/**** PERMUTATION *****/

	nmove = 0;
	j = 0;
	k = m - 1;

	while (nmove <  n)// thực hiện đúng n lần sẽ thoát
	{
		while (j  >  l[k])
		{
			j++;
			k = floor(c1*(a[j] - c2));
		}

		flash = a[j];  //leader

		while (j <= l[k])
		{
			k = floor(c1*(flash - c2));
			
			hold = a[l[k]];
			a[l[k]] = flash;
			flash = hold;

			l[k]--;

			nmove++;
		}
	}

	/**** Choice of RECURSION or STRAIGHT INSERTION *****/

	for (k = 0; k<(m - 1); k++)
	if ((nx = l[k + 1] - l[k]) > THRESHOLD)  /* then use recursion */
	{
		FlashSort(&a[l[k] + 1], nx, CLASS_SIZE, ctr);
		ctr++;
	}
	
	else  /* use insertion sort */

	for (i = l[k + 1] - 1; i > l[k]; i--)
	if (a[i] > a[i + 1])
	{
		hold = a[i];
		j = i;

		while (hold  >  a[j + 1])  
			a[j++] = a[j + 1];
		
		a[j] = hold;
	}
	delete[]l;/* need to free the memory we grabbed for the l vector */
}





void MyFlashSort(int *a, int n)
{
	int m = floor(0.43*n);

	int *L = new int[m];

	int min = a[0], max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)min = a[i];
		if (a[i] > max)max = a[i];
	}
	//Set L
	L[0] = -1;
	for (int k = 1; k < m; k++) L[k] = 0;

	for (int i = 0; i < n; i++)
	{
		int k = floor((m - 1.0)*(a[i] - min) / (max - min));
		L[k]++;
	}
	for (int i = 1; i < m; i++)
		L[i] += L[i - 1];
	
	//Permutation

	int count = 0, i = 0, k = m - 1, x;
	while (count < n)
	{
		while (i >L[k])//a[i] đã được xếp
		{
			i++;
			k = floor((m - 1.0)*(a[i] - min) / (max - min));//xét tiep phan tiep theo
		}

		x = a[i];

		while (i <= L[k])
		{
			k = floor((m - 1.0)*(x - min) / (max - min));//note! x == a[i]
			int tmp = a[L[k]];
			a[L[k]] = x;
			x = tmp;//xet tiep
			L[k]--;
			count++;
		}
	}

	//Sort m partition
	for (int k = 0; k < m - 1; k++)
	{
		for (i = L[k + 1] - 1; i >L[k]; i--)
		{
			if (a[i] > a[i + 1])
			{
				x = a[i];
				int j = i;
				while (x > a[j+1])
				{
					a[j++] = a[j + 1];
				}
				a[j] = x;
			}
		}
	}
	delete[]L;
}

void MyFlashSort2(int *a, int n)
{
	int m = floor(0.43*n);

	int *L = new int[m];

	int min = a[0], max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)min = a[i];
		if (a[i] > max)max = a[i];
	}

	//Set L
	//L[0] = 0;
	for (int k = 1; k <= m; k++) L[k] = 0;

	for (int i = 0; i < n; i++)
	{
		int k = floor((m - 1.0)*(a[i] - min) / (max - min));
		L[k]++;
	}
	for (int i = 1; i < m; i++)
		L[i] += L[i - 1];

	//Permutation

	int count = 0, i = 0, k = m, x;
	while (count < n)
	{
		while (i >L[k])//a[i] đã được xếp
		{
			i++;
			k = floor((m - 1.0)*(a[i] - min) / (max - min));//xét tiep phan tiep theo
		}

		x = a[i];

		while (i <= L[k])
		{
			k = floor((m - 1.0)*(x - min) / (max - min));//note! x == a[i]
			int tmp = a[L[k]];
			a[L[k]] = x;
			x = tmp;//xet tiep
			L[k]--;
			count++;
		}
	}

	//Sort m partition
	for (int k = 2; k <= m; k++)
	{
		for (i = L[k + 1] - 1; i >L[k]; i--)
		{
			if (a[i] > a[i + 1])
			{
				x = a[i];
				int j = i;
				while (x > a[j + 1])
				{
					a[j++] = a[j + 1];
				}
				a[j] = x;
			}
		}
	}
	delete[]L;
}