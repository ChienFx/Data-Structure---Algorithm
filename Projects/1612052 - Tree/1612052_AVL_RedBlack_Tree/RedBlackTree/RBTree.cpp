#include "RBTree.h"

Node* getNode(int key, bool color, Node* nil)
{
	Node* p = new Node;
	p->key = key;
	p->color = color;
	p->parent = p->left = p->right = nil;
	return p;
}

void rotateLeft(Node* &root, Node* x, Node* nil)
{
	Node* y = x->right;
	x->right = y->left;
	
	if(y->left != nil)
		y->left->parent = x;
	
	y->parent = x->parent;
	
	if(x->parent == nil)
		root = y;
	else
	{
		if(x == x->parent->left)
			x->parent->left = y;
		else// x== x->parent->right;
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void rotateRight(Node* &root, Node* x, Node* nil)
{
	Node* y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if(x->parent == nil)
		root = y;
	else
	{
		if(x==x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}


/*INSERT NODE*/
void RBT_Insert(Node* &root, int key, Node* nil)
{
	Node* x = getNode(key, RED, nil);
	if(BST_Insert(root, x, nil))
		Insertion_Fixup(root, x, nil);
	else
		delete x;//đã tồn tại x trong root
}

bool BST_Insert(Node* &root, Node* x, Node* nil)
{
	Node* y = nil;
	Node* z = root;
	while(z!=nil)
	{
		y = z;
		if(z->key > x->key)
			z = z->left;
		else if(z->key < x->key)
			z = z->right;
		else
			return 0;
	}
	x->parent = y;
	if(y == nil)
		root = x;
	else
	{
		if(x->key < y->key)
			y->left = x;
		else
			y->right = x;
	}
	
	return 1;
}

void Insertion_Fixup(Node* &root, Node* x, Node* nil)
{
	while(x->parent->color == RED)
	{
		if(x->parent == x->parent->parent->left)
			InsertAdjustLeft(root, x, nil);
		else
			InsertAdjustRight(root, x, nil);
	}
	root->color = BLACK;
}

void InsertAdjustLeft(Node* &root, Node *&x, Node* nil)
{
	Node* u = x->parent->right;//uncle
	if(u->color == RED)//case 2: p, u RED
	{
		x->parent->color = BLACK;
		u->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;// lan truyen len tren de tiep tuc hieu chinh
	}
	else // u BLACK
	{
		if(x == x->parent->right) //chau noi internal, case 4
		{
			x = x->parent;
			rotateLeft(root, x, nil);
		}
		//case 3
		x->parent->parent->color = RED;
		x->parent->color = BLACK;
		rotateRight(root, x->parent->parent, nil);
	}
}

void InsertAdjustRight(Node* &root, Node *&x, Node* nil)
{
	Node* u = x->parent->left;//uncle
	if(u->color == RED)//case 2: p, u RED
	{
		x->parent->color = BLACK;
		u->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;// lan truyen len tren de tiep tuc hieu chinh
	}
	else // u BLACK
	{
		if(x == x->parent->left) //chau noi internal, case 4
		{
			x = x->parent;
			rotateRight(root, x, nil);
		}
		//case 3
		x->parent->parent->color = RED;
		x->parent->color = BLACK;
		rotateLeft(root, x->parent->parent, nil);
	}
}

void printTreePRE(Node*&r, Node* nil)
{
	if (r != nil)
	{
		cout << r->key << "  ";
		printTreePRE(r->left, nil);
		printTreePRE(r->right,nil);
	}
}

void printTreeMID(Node*&r, Node* nil)
{
	if (r != nil)
	{
		printTreeMID(r->left, nil);
		cout << r->key << "  ";
		printTreeMID(r->right,nil);
	}
}

void printTreePOST(Node*&r, Node* nil)
{
	if (r != nil)
	{
		printTreePOST(r->left, nil);
		printTreePOST(r->right,nil);
		cout << r->key << "  ";
	}
}

void removeTree(Node*&root, Node* nil)
{
	if (root != nil)
	{
		removeTree(root->left, nil);
		removeTree(root->right, nil);
		delete root;
		root = NULL;
	}
}

Node* searchTree(Node*&root, int k, Node* nil)
{
	if(root == nil)
		return nil;
	else
	{
		if(root->key == k)
			return root;
		else
			if(root->key < k)
				return searchTree(root->right, k, nil);
			else
				return searchTree(root->left, k, nil);
	}
}

Node* TreeSuccessor(Node* root, Node*x, Node*nil)
{ 
	Node* p = x->right;
	while(p->left!=nil)
		p = p->left;
	return p;
}


/*ROMOVE NODE*/
void RBT_Remove(Node* &root, int k, Node* nil)
{
	Node* x = nil;
	Node* z = searchTree(root, k, nil);
	Node* y = nil;
	if(z == nil) return;
	
	if(z->left == nil || z->right == nil)
		y = z;
	else
		y = TreeSuccessor(root, z, nil);
	
	if(y->left == nil)
		x = y->right;
	else
		x = y->left;
	
	x->parent = y->parent;
	
	if(y->parent == nil)
		root = x;
	else if( y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if(y!=z)
		z->key = y->key;
	
	if(y->color == BLACK)
		Remove_Fixup(root,x,nil);
	delete y;
	
	
}

void Remove_Fixup(Node*& root, Node* x, Node* nil)
{
	while(x->color == BLACK && x!=root)
		if(x == x->parent->left)
			RemoveAdjustLeft(root, x, nil);
		else
			RemoveAdjustRight(root, x, nil);
	x->color = BLACK;
}

void RemoveAdjustLeft(Node*& root, Node*& x, Node* nil)
{
	Node* w = x->parent->right;
	if(w->color == RED)
	{
		w->color = BLACK;
		x->parent->color = RED;
		rotateLeft(root, x->parent, nil);
		w = x->parent->right; // xét tiếp trường hợp 2,4
	}
	if(w->right->color == BLACK && w->left->color == BLACK)
	{
		w->color = RED;
		x = x->parent; // tăng dấu hiệu đen lên 1 bậc
	}
	else
	{
		if(w->right->color == BLACK) //TH 4a
		{
			w->left->color = BLACK;
			w->color = RED;
			rotateRight(root, w, nil);
			w = x->parent->right; // chuyeenr sang 4b
		}
		//th 4b
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->right->color = BLACK;
		rotateLeft(root, x->parent, nil);
		x = root;
	}
}
void RemoveAdjustRight(Node*& root, Node*& x, Node* nil)
{
	Node* w = x->parent->left;
	if(w->color == RED)
	{
		w->color = BLACK;
		x->parent->color = RED;
		rotateRight(root, x->parent, nil);
		w = x->parent->left; // xét tiếp trường hợp 2,4
	}
	if(w->left->color == BLACK && w->right->color == BLACK)
	{
		w->color = RED;
		x = x->parent; // tăng dấu hiệu đen lên 1 bậc
	}
	else
	{
		if(w->left->color == BLACK) //TH 4a
		{
			w->right->color = BLACK;
			w->color = RED;
			rotateLeft(root, w, nil);
			w = x->parent->left; // chuyeenr sang 4b
		}
		//th 4b
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->left->color = BLACK;
		rotateRight(root, x->parent, nil);
		x = root;
	}
}