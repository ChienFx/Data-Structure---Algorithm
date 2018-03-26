#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
using namespace std;

void ComputeTable(int **&dfa, char*P, char*Sigma);
int  DFA_Search(char*P, char*T);
char *getSigma(char*T);
int  getIndexSigma(char* Sigma, char a);
bool isPosfix(char*P, int k, int q, char a); // Kiem tra Pk la hau to cua Pq+a

//Geek's solution
/* Prints all occurrences of pat in txt */
#define NO_OF_CHARS 256
void search(char *pat, char *txt);
void computeTF(char *pat, int M, int** TF);
int getNextState(char *pat, int M, int state, int x);

#endif