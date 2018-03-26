#include "func.h"

void main()
{
	char *P = "pham minh chien";
	char *T = "mrc pham minh chien ahihi chien ne chien pham minh chien chien";
	cout << P << endl << T << endl;
	DFA_Search(P,T);
	search(P, T);
	/*char * t = getSigma("abcabcabcbabcbabcacbacbafbcba");
	cout << t<<endl;*/
}