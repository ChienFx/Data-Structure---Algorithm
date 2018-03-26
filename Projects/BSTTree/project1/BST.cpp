#include "BST.h"

BSTNode* getNode(int k)
{
	BSTNode*p = new BSTNode;
	p->key = k;
	p->pLeft = p->pRight = NULL;
	return p;
}

void insertNode(BSTNode*&root, int k)
{
	if (root == NULL)
		root = getNode(k);
	else
	{
		BSTNode*dummy = getNode(-1);
		dummy->pRight = root;
		
		BSTNode*p1 = dummy;
		BSTNode*p2 = p1->pRight;
		int d = 1;//d: -1 left, 0 mid, 1 right 
		while (p2 != NULL && d!=0)
		{
			p1 = p2;
			if (p2->key <k)
			{
				d = 1;
				p2 = p2->pRight;
			}
			else if (p2->key > k)
			{
				d = -1;
				p2 = p2->pLeft;
			}
			else
				d = 0;
		}
		if (d == 0)
			return;
		BSTNode* p = getNode(k);
		if (d == -1)
			p1->pLeft = p;
		else
			p1->pRight = p;
		delete dummy;
	}
}


bool removeNode(BSTNode*&r, int k)
{
	if (r == NULL) return false;
	else
	{
		if (r->key > k)
		{
			return removeNode(r->pLeft, k);
		}
		else if (r->key < k)
		{
			return removeNode(r->pRight, k);
		}
		else// r->key == k
		{
			BSTNode * q = r; // xoas r
			if (q->pLeft == NULL)
			{
				r = q->pRight;
			}
			else if (q->pRight == NULL)
			{
				r = q->pLeft;
			}
			else//co du 2 cay con
			{
				findStandFor(r->pLeft, q);//chon Node phai nhat ben cay con trai lam Node the mang
			}
			delete q;
			q = NULL;
			return true;
		}
	}
}

void findStandFor(BSTNode*&r, BSTNode*&q)
{
	if (r->pRight)
	{
		findStandFor(r->pRight, q);
	}
	else
	{
		q->key = r->key;
		q = r;
		r = r->pLeft;
	}
}

//Tính theo Node
int getHeight(BSTNode*root)
{
	if (root == NULL)
		return 0;
	else
	{
		int hLeft = 1 + getHeight(root->pLeft);
		int hRight = 1 + getHeight(root->pRight);
		
		if (hLeft > hRight)
			return hLeft;
		else
			return hRight;
	}
}
////Tính theo cạnh
//int height(Node* root) {
//	// Write your code here.
//	if (root == NULL)
//		return -1;
//	if (!root->pLeft && !root->pRight)
//		return 0;
//	else
//	{
//		int h1 = 1 + height(root->pLeft);
//		int h2 = 1 + height(root->pRight);
//		if (h1>h2)
//			return h1;
//		return h2;
//	}
//}

int countInternalNode(BSTNode*root)
{
	if (root == NULL)
		return 0;
	else
	{
		if (!root->pLeft && !root->pRight)
			return 0;
		else
		{
			return 1 + countInternalNode(root->pLeft) + countInternalNode(root->pRight);
		}
	}
}

void printTree(BSTNode* root)
{
	if (root)
	{
		printTree(root->pLeft);
		cout << root->key << " ";
		printTree(root->pRight);
	}
}

void removeAll(BSTNode*&root)
{
	if (root)
	{
		//cout << endl << "-remove:" << root->key;
		removeAll(root->pLeft);
		removeAll(root->pRight);
		delete root;
	}
}

void levelOrder(Node * root) {
	queue<Node *> q;
	Node *temp = root;
	if (root != NULL)
	{
		q.push(root);
	}
	while (!q.empty())
	{
		cout << temp->key << " ";
		if (temp->pLeft)
			q.push(temp->pLeft);
		if (temp->pRight)
			q.push(temp->pRight);

		q.pop();
		temp = q.front();
	}
}

//top view
void for_left(Node *root)
{
	if (root->pLeft != NULL)
		for_left(root->pLeft);
	cout << root->key << " ";
}


void for_right(Node * root)
{
	cout << root->key << " ";
	if (root->pRight != NULL)
		for_right(root->pRight);
}

void topView(Node * root)
{
	if (root->pLeft != NULL)
		for_left(root->pLeft);
	cout << root->key << " ";
	if (root->pRight != NULL)
		for_right(root->pRight);

}


//--kiem tra cay nhi phan tim kiem
bool checkLeft(Node*root, int pkey) 
{
	if (root == NULL) 
		return true;
	if (root->key >= pkey) 
		return false;
	return 
		checkLeft(root->pLeft, root->key) &&
		checkLeft(root->pLeft, pkey) &&
		checkLeft(root->pRight, pkey) &&
		checkRight(root->pRight, root->key);
}
bool checkRight(Node*root, int pkey)
{
	if (root == NULL)
		return true;
	if (root->key <= pkey)
		return false;
	return
		checkRight(root->pRight, root->key) &&
		checkRight(root->pRight, pkey) &&
		checkRight(root->pLeft, pkey) &&
		checkLeft(root->pLeft, root->key);
}

bool checkBST(Node *root) {
	return 
		checkLeft(root->pLeft, root->key) &&
		checkRight(root->pRight, root->key);
}

//Lowest common ancescor
Node *lca(Node *root, int v1, int v2)
{
	if (root->key < v1 && root->key < v2){
		return lca(root->pRight, v1, v2);
	}
	//Bigger than both
	if (root->key > v1 && root->key > v2){
		return lca(root->pLeft, v1, v2);
	}

	//Else solution already found
	return root;
}

//đếm số node trong chỉ có 1 node lá
int countSingleInternal(Node*root)
{
	if (!root)
		return 0;
	if (!root->pLeft && !root->pRight)//leaf
		return 0;
	
	if (root->pLeft&&root->pRight)//internal node with 2 subtrees
		return countSingleInternal(root->pLeft) + 
		countSingleInternal(root->pRight);
	else//1 leaf
	{
		return 1;
	}
}

//tính giá trị trung bình của cây
float meanTree(Node*root)
{
	return (float)sumTree(root) / countNode(root);
}

int sumTree(Node*root)
{
	if (!root)
		return 0;
	if (!root->pLeft && !root->pRight)//leaf
		return root->key;

	int kq = root->key;
	if (root->pLeft)
		kq = (kq + sumTree(root->pLeft));
	if (root->pRight)
		kq = (kq + sumTree(root->pRight));
	return kq;
}

//dem so node
int countNode(Node*root)
{
	if (!root)return 0;
	if (!root->pLeft && !root->pRight) return 1;
	return 1 + countNode(root->pLeft) + countNode(root->pRight);
}


//tim node co gia tri gan voi 1 gia tri cho truoc
Node* find_nearest(Node*root, float k)
{
	if (!root)return NULL;
	Node*cur = root;
	return find(root, cur, k);
}
Node* find(Node* root, Node* cur, float k)
{
	if (root)
	{
		if (abs(root->key - k) < abs(cur->key - k))
			cur = root;
		if (root->pLeft)
			cur = find(root->pLeft, cur, k);
		if (root->pRight)
			cur = find(root->pRight, cur, k);
	}
	return cur;
}

Node* median_nearest(Node*root)
{
	return find_nearest(root, meanTree(root));
}

/*
1. Initialize current as root 
2. While current is not NULL
   If current does not have left child
      a) Print current’s key
      b) Go to the right, i.e., current = current->pRight
   Else
      a) Make current as right child of the rightmost 
         node in current's left subtree (current = cur's predecessor)
      b) Go to this left child, i.e., current = current->pLeft*/
void InOrder_MorrisTraversal(Node *root){	
	if (root == NULL) return;
	Node *current, *pre;

	current = root;
	while (current != NULL)
	{
		if (current->pLeft == NULL)
		{
			printf("%d ", current->key);
			current = current->pRight;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->pLeft;
			while (pre->pRight != NULL && pre->pRight != current)
				pre = pre->pRight;

			/* Make current as right child of its inorder predecessor */
			if (pre->pRight == NULL)
			{
				pre->pRight = current;
				current = current->pLeft;
			}

			/* Revert the changes made in if part to restore the original
			tree i.e., fix the right child of predecssor */
			else
			{
				pre->pRight = NULL;
				printf("%d ", current->key);
				current = current->pRight;
			} /* End of if condition pre->pRight == NULL */
		} /* End of if condition current->pLeft == NULL*/
	} /* End of while */
}

/*
1.	If left child is NULL:
		Print the current node data. 
		Move to right child.
	Else
		Make the right child of the inorder predecessor point to the current node. Two cases arise:
			a) The right child of the inorder predecessor already points to the current node. 
				Set right child to NULL. 
				Move to right child of current node.
			b) The right child is NULL. Set it to current node. 
				Print current node’s data and move to left child of current node.
2.	Iterate until current node is not NULL.*/

void PreOrder_MorrisTraversal(Node* root)
{
	if (!root)return;
	Node* current = root, *pre;
	while (current)
	{
		// If left child is NULL, print the current node key. Move to
		// right child.
		if (current->pLeft == NULL)
		{
			printf("%d ", current->key);
			current = current->pRight;
		}
		else
		{
			// Find inorder predecessor
			pre = current->pLeft;
			while (pre->pRight && pre->pRight != current)
				pre = pre->pRight;

			// If the right child of inorder predecessor already points to this node
			if (pre->pRight == current)
			{
				pre->pRight = NULL;
				current = current->pRight;
			}

			// If right child doesn't point to this node, then print this
			// node and make right child point to this node
			else
			{
				printf("%d ", current->key);
				pre->pRight = current;
				current = current->pLeft;
			}
		}
	}
}
/*POSTORDER_MORRISTRAVERSAL 
initialize current as root
while current is not NULL: 
    if current does not have left child:
        Go to the right, i.e., current = current->pRight
    else:
       a. Find the predecessor of current node
       b. if predecessor's right child is NULL:
           1) make current the right child of its predecessor
           2) Go to this left child, i.e., current = current->pLeft
        else:
           1) if predecessor's right child is current node, set predecessor's right child to NULL
           2) print out all nodes on path from current's left to current's predecessor reversely.
           3) set current node to its right child*/
void PostOrder_MorrisTraversal(Node*root)
{
	if (root == NULL) return;

	Node* pre = NULL;
	Node* dummy = getNode(-1);
	dummy->pLeft = root;
	root = dummy;
	while (root != NULL){
		if (root->pLeft == NULL){
			root = root->pRight;
		}
		else{
			/* find predecessor */
			pre = root->pLeft;
			while (pre->pRight != NULL && pre->pRight != root)
				pre = pre->pRight;

			/* if predecessor's right == NULL, set current node as its right child */
			if (pre->pRight == NULL){
				pre->pRight = root;
				root = root->pLeft;
			}
			else{
				/* recover tree, when return to parent node the second time */
				pre->pRight = NULL;

				printReveserRightHand(root->pLeft, pre);
				
				root = root->pRight;
			}
		}
	}
}

//In ngược thứ tự từ head->tail (in tail->head) theo nhánh Right
void printReveserRightHand(Node*head, Node*tail){
	Node*p = head;
	while (head != tail){
		while (p && p->pRight != tail)
			p = p->pRight;

		cout << tail->key << " ";
		tail = p;
		p = head;
	}
	cout << head->key << " ";
}


//the (n+1)/2-th element when sorted
Node* findMedian(Node*root)
{
	if (!root) return NULL;
	int n = countNode(root);
	int id = trunc((n) / 2);
	return findPosition(root, root,id);
}

//Tìm Node ở vị tri thứ k sau khi sap xep
Node* findPosition(Node*root, Node*cur, int k)
{
	if (!cur)
		return NULL;
	int num = countLess(root, cur->key);
	if (num == k)
		return cur;
	else
	{
		Node*res1 = findPosition(root, cur->pLeft, k);
		Node*res2 = findPosition(root, cur->pRight, k);
	
		if (res1)
			return res1;
		return res2;
	}
}

//Đếm số node nhỏ hơn 1 giá trị cho trước
int	countLess(Node* root, int x){	if (root == NULL)		return 0;	if (root->key == x)		return countLess(root->pLeft, x);	else	{		if (root->key > x)			return countLess(root->pLeft, x);		else			return 1 + countLess(root->pLeft, x)			+ countLess(root->pRight, x);	}}