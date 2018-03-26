#include "func.h"

int KMP_Search(char*P, char*T);
void ComputeArray(char*P, int *&pi);


void main()
{
	char *P = "pham minh chien";
	char *T = "mrc pham minh chien ahihi chien ne pham minh chien";
	cout << P << endl << T << endl;
	KMP_Search(P,T);
	/*char * t = getSigma("abcabcabcbabcbabcacbacbafbcba");
	cout << t<<endl;*/
}

int KMP_Search(char*P, char*T)
{
	int m = strlen(P);
	int *pi = NULL;
	ComputeArray(P, pi);
	int q = 0;
	for (int i = 0; i < strlen(T); i++)
	{
		while (q>0 && P[q] != T[i])
			q = pi[q];
		if (P[q] == T[i])
			q++;
		if (q == m)
		{
			cout << i - m + 1 << endl;
			q = pi[q];
		}
	}
	return 0;
}
void ComputeArray(char*P, int *&pi)
{
	int m = strlen(P);
	pi = new int[m + 1];
	pi[0] = -1; //bor khong dung`
	pi[1] = 0;
	int k = 0;
	for (int q = 2; q <= m; q++)
	{
		while (k>0 && P[k]!=P[q-1])
		{
			k = pi[k];// k giam
		}
		if (P[k] == P[q - 1]) k++;
		pi[q] = k;
	}
}