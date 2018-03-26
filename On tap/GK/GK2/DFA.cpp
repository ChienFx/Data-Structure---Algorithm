#include "func.h"

void ComputeTable(int **&dfa, char*P, char*Sigma);
int  DFA_Search(char*P, char*T);
char *getSigma(char*T);
int  getIndexSigma(char* Sigma, char a);
bool isPosfix(char*P, int k, int q, char a); // Kiem tra Pk la hau to cua Pq+a

void main()
{
	char *P = "pham minh chien";
	char *T = "mrc pham minh chien ahihi chien ne chien chien chien";
	cout << P << endl << T << endl;
	DFA_Search(P,T);
}


int DFA_Search(char*P, char*T)
{
	char*Sigma = getSigma(T);
	int m = strlen(P);
	int n = strlen(Sigma);
	int **dfa = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		dfa[i] = new int[n];
		for (int j = 0; j < n; j++)
			dfa[i][j] = 0;
	}

	ComputeTable(dfa, P, Sigma);
	int q = 0;
	//Tìm trong van bản T
	for (int i = 0; i < strlen(T); i++)
	{
		int j = getIndexSigma(Sigma, T[i]);
		q = dfa[q][j];
		if (q == m)
			cout << (i-m+1) << endl;
	}

	/*In bang automaton
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n; j++)
			cout << dfa[i][j] << "  ";
		cout << endl;
	}
	*/
	return 0;
}
void ComputeTable(int **&dfa, char*P, char*Sigma)
{
	int m = strlen(P);
	for (int q = 0; q <= m;q++)
	for (int i = 0; i < strlen(Sigma); i++)
	{
		int k = (m + 1 < q + 2) ? m + 1 : q + 2;
		do
		{
			k--;
		} while (!isPosfix(P,k,q,Sigma[i]));
		dfa[q][i] = k;
	}
}

char* getSigma(char*T)
{
	char*Sigma = NULL;
	int k = 0;
	bool flag = true;
	for (int i = 0; i < strlen(T); i++)
	{
		flag = true;
		for (int j = 0; j < k; j++)
		{
			if (Sigma[j] == T[i])
			{
				flag = false; break;
			}
		}
		if (flag)
		{
			Sigma = (char*)realloc(Sigma, (k + 1)*sizeof(char));
			Sigma[k++] = T[i];
		}
	}
	Sigma[k] = 0;
	return Sigma;
}

int getIndexSigma(char* Sigma, char a)
{
	for (int i = 0; i < strlen(Sigma);i++)
	if (Sigma[i] == a)
		return i;
	return -1;
}

bool isPosfix(char*P, int k, int q, char a)
{//kiem tra Pk hau to cua Pq+a
	if (k == 0)
		return true;
	int i, j;

	bool kq = P[k-1] == a; //kí tự cuối trùng

	if (kq)
	{
		for (i = k - 2, j = q-1; i >= 0 && j >= 0; i--, j--)
		{
			if (P[i] != P[j])//P[i] thuộc Pk, P[j] thuộc Pq+a
			{
				kq = false; break;
			}
		}
	}
	return kq;
}