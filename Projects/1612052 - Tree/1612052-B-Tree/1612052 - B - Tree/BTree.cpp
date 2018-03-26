#include "BTree.h"


BTree::BTree(int _t)
{
	t = _t;
	root = NULL;
}


BTree::~BTree()
{
	delete root;
}

// function to traverse the tree
void BTree::traverse()
{
	if (root != NULL) root->traverse();
}

// function to search a key in this tree
BTreeNode* BTree::search(int k, int &index)
{
	return (root == NULL) ? NULL : root->search(k, index);
}

void BTree::insert(int k)
{
	if (root == NULL)
	{
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
		
	}
	else
	{
		BTreeNode* r = root;
		if (r->n == 2 * t - 1)
		{
			BTreeNode* s = new BTreeNode(t, false);
			root = s;
			s->n = 0;
			s->C[0] = r;
			s->splitChild(0);
			s->insertNonNull(k);
		}
		else
			r->insertNonNull(k);
	}
}

void BTree::remove(int k)
{
	if (!root)
	{
		cout << "The tree is empty\n";
		return;
	}

	// Call the remove function for root
	root->remove(k);

	// If the root node has 0 keys, make its first child as the new root
	//  if it has a child, otherwise set root as NULL
	if (root->n == 0)
	{
		BTreeNode *tmp = root;
		if (root->leaf)
			root = NULL;
		else
			root = root->C[0];

		// Free the old root
		delete tmp;
	}
	return;
}