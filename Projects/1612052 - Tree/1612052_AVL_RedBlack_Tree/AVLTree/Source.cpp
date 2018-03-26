#include "AVL.h"

int main()
{
	Node* r = NULL;
	
	insertNode(r, 5);
	insertNode(r, 7);
	insertNode(r, 10);
	insertNode(r, 12);
	insertNode(r, 9);
	insertNode(r, 8);
	insertNode(r, 3);
	insertNode(r, 1);
	insertNode(r, 4);
	
	cout << "MID: ";
	printTreeMID(r);
	cout << endl;

	cout << "PRE: ";
	printTreePRE(r);
	cout << endl;
	cout << "POST: ";
	printTreePOS(r);
	cout << endl;

	removeNode(r, 5);
	removeNode(r, 1);
	removeNode(r, 3);
	removeNode(r, 4);
	removeNode(r, 12);
	
	cout << "MID (DEL):";
	printTreeMID(r)	;
	removeTree(r);
	
	return 0;
}