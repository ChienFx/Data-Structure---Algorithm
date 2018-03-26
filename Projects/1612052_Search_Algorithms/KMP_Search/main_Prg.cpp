#include "func.h"

void main()
{
	char *P = "pham minh chien";
	char *T = "f mrc pham minh chien ahihi chien ne pham minh chien";
	cout << P << endl << T << endl;
	KMP_Search(P,T);
	/*char * t = getSigma("abcabcabcbabcbabcacbacbafbcba");
	cout << t<<endl;*/
}