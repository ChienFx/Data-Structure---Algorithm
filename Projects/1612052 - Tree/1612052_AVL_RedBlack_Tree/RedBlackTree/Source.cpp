#include "RBTree.h"

int main()
{
	Node* nil = new Node;
	nil->color = BLACK;
	nil->parent = nil->left = nil->right;
	
	Node* root = nil;
	
	RBT_Insert(root, 50, nil);
	RBT_Insert(root, 20, nil);
	RBT_Insert(root, 10, nil);
	RBT_Insert(root, 40, nil);
	RBT_Insert(root, 30, nil);
	
	printTreeMID(root, nil);
	
	RBT_Remove(root, 30, nil);
	cout << endl;
	printTreeMID(root, nil);
	
	removeTree(root, nil);
	delete nil;
	return 0;
}
