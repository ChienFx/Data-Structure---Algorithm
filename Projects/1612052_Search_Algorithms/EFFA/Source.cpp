/* EFFICIENT CONSTRUCTION OF FINITE AUTOMATA
Algorithm:
1) Fill the first row.All entries in first row are always 0 except the entry for pat[0] character.For pat[0] character, we always need to go to state 1.
2) Initialize lps as 0. lps for the first index is always 0.
3) Do following for rows at index i = 1 to M. (M is the length of the pattern)
…..a) Copy the entries from the row at index equal to lps.
…..b) Update the entry for pat[i] character to i + 1.
…..c) Update lps “lps = TF[lps][pat[i]]” where TF is the 2D array which is being constructed.

Implementation
Following is C implementation for the above algorithm.
*/

#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256

/* This function builds the TF table which represents Finite Automata for a
given pattern  */
void computeTransFun(char *pat, int M, int**TF)
{
	int i, lps = 0, x;

	// Fill entries in first row
	for (x = 0; x < NO_OF_CHARS; x++)
		TF[0][x] = 0;
	TF[0][pat[0]] = 1;

	// Fill entries in other rows
	for (i = 1; i <= M; i++)
	{
		// Copy values from row at index lps
		for (x = 0; x < NO_OF_CHARS; x++)
			TF[i][x] = TF[lps][x];

		// Update the entry corresponding to this character
		TF[i][pat[i]] = i + 1;

		// Update lps for next row to be filled
		if (i < M)
			lps = TF[lps][pat[i]];
	}
}

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	//int TF[M + 1][NO_OF_CHARS];
	int**TF = new int*[M + 1];
	for (int i = 0; i <= M; i++)
		TF[i] = new int[NO_OF_CHARS];

	computeTransFun(pat, M, TF);

	// process text over FA.
	int i, j = 0;
	for (i = 0; i < N; i++)
	{
		j = TF[j][txt[i]];
		if (j == M)
		{
			printf("\n pattern found at index %d", i - M + 1);
		}
	}
	for (int i = 0; i <= M; i++)
		delete TF[i];
}

/* Driver program to test above function */
int main()
{
	char *txt = "GEEKS FOR GEEKS";
	char *pat = "GEEKS";
	search(pat, txt);
	getchar();
	return 0;
}