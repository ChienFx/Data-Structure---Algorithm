#include "AVL.h"


Node* getNode(int k)
{
	Node* p = new Node;
	if (p)
	{
		p->key = k;
		p->balance = 0;
		p->left = NULL;
		p->right = NULL;
	}
	else
		cout << "Not enough memory.";
	return p;
}

void rotateLL(Node*&r)
{
	Node* p1 = r->left;
		
	r->left = p1->right;
	p1->right = r;
	
	switch(p1->balance)
	{
		case LH: // p1 nghieng trai
			p1->balance = EH;
			r->balance 	= EH;
			break;
		case EH: // p1 cb
			p1->balance = RH;
			r->balance 	= LH;
			break;
	}
	r = p1;
}

void rotateRR(Node*&r)
{
	Node* p1 = r->right;
	
	r->right = p1->left;
	p1->left = r;
	switch(p1->balance)
	{
		case RH: //p1 nghien phai
			p1->balance = EH;
			r->balance = EH;
			break;
		case EH: //p1 cb
			r->balance = RH;
			p1->balance = LH;
			break;	
	}
	r = p1;
}

void rotateLR(Node*&r)
{
	Node* p1 = r->left;
	Node* p2 = p1->right;
	
	p1->right = p2->left;
	p2->left = p1;
	
	r->left = p2->right;
	p2->right = r;
	
	switch(p2->balance)
	{
		case EH: //p2 cb
			p1->balance = EH;
			r->balance = EH;	
			break;
		case LH:
			p1->balance = EH;
			r->balance = RH;	
			break;
		case RH:
			p1->balance = LH;
			r->balance = EH;	
			break;
	}
	p2->balance = EH; //char
	r = p2;
}

void rotateRL(Node*&r)
{
	Node* p1 = r->right;
	Node* p2 = p1->left;
	
	p1->left = p2->right;
	p2->right = p1;
	
	r->right = p2->left;
	p2->left = r;
	
	switch(p2->balance)
	{
		case EH: //p2 cb
			p1->balance = EH;
			r->balance = EH;	
			break;
		case LH:
			p1->balance = RH;
			r->balance = EH;	
			break;
		case RH:
			p1->balance = EH;
			r->balance = LH;	
			break;
	}
	p2->balance = EH; //char
	r = p2;
}
//return 1 - r không CB, 2 - r đã CB
int balanceLeft(Node*&r)
{
	Node* p1 = r->left;
	
	switch(p1->balance)
	{
		case LH: 
			rotateLL(r);
			return 2;
		case EH:
			rotateLL(r);
			return 1;
		case RH:
			rotateLR(r);
			return 2;
	}
	return 0;
}
//return 1 - r không CB, 2 - r đã CB
int balanceRight(Node*&r)
{
	Node* p1 = r->right;
	switch(p1->balance)
	{
		case EH: 
			rotateRR(r);
			return 1;
		case RH:
			rotateRR(r);
			return 2;
		case LH:
			rotateRL(r);
			return 2;
	}
	return 0;
}

//return: 0-đã có, 1 - cây CB, 2 - cây tăng chiều cao lên 1 đv 
int insertNode(Node*&r, int k)
{
	int res;
	if(r)
	{
		if(k == r->key) return 0;// da co
		if(k < r->key)
		{//chen vao ben trai node r
			
			res = insertNode(r->left, k);	
			
			// res < 2 -> cây đã đc hiệu chỉnh -> thoát, nếu == 2 (tăng chiều cao) -> hiệu chỉnh
			if(res < 2) 
				return res;
			
			switch(r->balance) //dieu chinh balance hoac rotate cay con
			{
				case EH:		//đang CB - chèn trái  => lệch trái
					r->balance = LH;		
					return 2;
					break;
				case LH:		//đang lệch trái - chèn trái => mất CB => CB trái => CB
					balanceLeft(r);
					return 1;
					break;
				case RH:		//đang lệch phải - chèn trái => CB
					r->balance = EH;
					return 1;
					break;	
			}
		}
		else
		{//chen vao ben phai node r
			res = insertNode(r->right, k);
			if(res < 2) return 1;
			switch(r->balance) //dieu chinh balance hoac rotate cay con
			{
				case EH:			//đang CB - chèn phải => lệch phải
					r->balance = RH; 	
					return 2;
					break;
				case LH:			//đang lệch trái -> chèn phải => CB
					r->balance = EH;		
					return 1;
					break;
				case RH:			//đang lêch phải - chèn phải => mất CB => cân bằng phải => CB
					balanceRight(r);	
					return 1;
					break;	
			}
		}
	}
	r = getNode(k);
	return 2;
}

int removeNode(Node*&r, int k)
{
	int res;
	if (r == NULL) return 0;
	else
	{
		if (r->key > k)
		{
			res = removeNode(r->left,k);	
			if(res < 2) return res;
			switch(r->balance)
			{
				case LH:  r->balance = EH; return 2;
				case EH:  r->balance = RH; return 1;
				case RH:  return balanceRight(r);
			}
		}
		else if (r->key < k)
		{
			res = removeNode(r->right,k);	
			if(res < 2) return res;
			switch(r->balance)
			{
				case LH:  return balanceLeft(r);
				case EH:  r->balance = LH; return 1;
				case RH:  r->balance = EH; return 2;
			}
		}
		else// r->key == k
		{
			Node * q = r; // xoas r
			if (q->left == NULL)
			{
				r = q->right;
				res = 2;
			}
			else if (q->right == NULL)
			{	
				r = q->left;
				res = 2;
			}
			else//co du 2 cay con
			{	
				res = findStandFor(r->left, q);//chon node phai nhat ben cay con trai lam node the mang
				if(res < 2) return res;
				switch(r->balance)
				{
					case LH:  r->balance = EH; return 2;
					case EH:  r->balance = RH; return 1;
					case RH:  return balanceRight(r);		
				}
			}
			delete q;
			q = NULL;
			return res;
		}
	}
}

int findStandFor(Node*&r, Node*&q)
{
	int res;
	if (r->right)
	{
		res = findStandFor(r->right, q);
		if (res < 2) return res;
		switch(r->balance)
		{
			case LH:  return balanceLeft(r);
			case EH:  r->balance = LH; return 1;
			case RH:  r->balance = EH; return 2;
		}
	}
	else
	{
		q->key = r->key;
		q = r;
		r = r->left;
		return 2;
	}
}



//-------------------Print method----------------------
//r - Left - Right
void printTreePRE(Node*&r)
{
	if (r)
	{
		cout << r->key << "  ";
		printTreeMID(r->left);
		printTreeMID(r->right);
	}
}

void printTreeMID(Node*&r)
{
	if (r)
	{
		printTreeMID(r->left);
		cout << r->key << "  ";
		printTreeMID(r->right);
	}
}

//Left - Right - r
void printTreePOS(Node*&r)
{
	if (r)
	{
		printTreeMID(r->left);
		printTreeMID(r->right);
		cout << r->key << "  ";
	}
}

void addNode(Node*&r, int k)
{
	if (r == NULL)
		r = getNode(k);
	else
	{
		if (r->key > k)
			addNode(r->left, k);
		else if (r->key < k)
			addNode(r->right, k);
		else
			cout << "Node " << k << "is exist." << endl;
	}
}

Node* findNode(Node*root, int k)
{
	if (root == NULL)
		return root;
	else
	{
		if (root->key > k)
			return findNode(root->left, k);
		else if (root->key < k)
			return findNode(root->right, k);
		else
			return root;
	}
}

// void removeNode(Node*&r, int k)
// {
	// if (r == NULL) return;
	// else
	// {
		// if (r->key > k)
			// removeNode(r->left, k);
		// else if (r->key < k)
			// removeNode(r->right, k);
		// else
		// {
			// Node * q = r; // xoas r
			// if (q->left == NULL)
				// r = q->right;
			// else if (q->right == NULL)
				// r = q->left;
			// else
				// findStandFor(r->left, q);//chon node phai nhat ben cay con trai lam node the mang
			// delete q;
			// q = NULL;
		// }
	// }
// }

// void findStandFor(Node*&r, Node*&q)
// {
	// if (r->right)
		// findStandFor(r->right, q);
	// else
	// {
		// q->key = r->key;
		// q = r;
		// r = r->left;
	// }
// }

void removeTree(Node*&root)
{
	if (root)
	{
		removeTree(root->left);
		removeTree(root->right);
		delete root;
		root = NULL;
	}
}