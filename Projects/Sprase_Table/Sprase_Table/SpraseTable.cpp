#include "SpraseTable.h"

Node* getNode(int value, int x, int y){
	Node*p = new Node;
	p->val = value;
	p->x = x;	
	p->y = y;
	p->right = p->down = NULL;
	return p;
}

Node* createSpraseTable(){
	return getNode(-1, -1, -1);
}

void insertNode(Node*&head, int val, int x, int y){
	if (!head)
		head = createSpraseTable();
	Node*p = getNode(val, x, y);
	insert(head, p);
}

void insert(Node*&head, Node*p){
	
	Node*pr1 = head, *pr2 = pr1->right;
	//Tìm vị trí cột sẽ chưa p
	while (pr2 && pr2->y <= p->y){
		pr1 = pr2; pr2 = pr2->right;
	}
	
	//Chưa có con trỏ quản lí cột chứa p
	if (pr1->y != p->y){
		Node*newCol = getNode(-1, -1, p->y);
		pr1->right = newCol;
		newCol->right = pr2;
		pr1 = newCol;
	}

	//Tìm vị trí chính xác của p (theo cột)
	pr2 = pr1->down;
	while (pr2 && pr2->x <= p->x){
		pr1 = pr2; pr2 = pr2->down;
	}

	//làm tương tự cho dòng
	Node*pd1 = head, *pd2 = pd1->down;
	while (pd2 && pd2->x <= p->x){
		pd1 = pd2; pd2 = pd2->down;
	}
	if (pd1->x != p->x){
		Node*newRow = getNode(-1, p->x, -1);
		pd1->down = newRow;
		newRow->down = pd2;
		pd1 = newRow;
	}
	pd2 = pd1->right;
	while (pd2 && pd2->y <= p->y){
		pd1 = pd2; pd2 = pd2->right;
	}
	//lieen keet 
	pr1->down = p; p->down = pr2;
	pd1->right = p; p->right = pd2;
}

Node* getPosition(Node*head, int x, int y)
{
	Node*pr, *pd;
	for (pr = head; pr != NULL && pr->x != x; pr = pr->down)
		;
	if (pr == NULL) return NULL;
	for (pd = pr; pd != NULL && pd->y != y; pd = pd->right)
		;
	if (pd == NULL)return NULL;
	return pd;
}

void printTable(Node*head)
{
	if (!head)
		cout << "-empty table";
	else
	{
		if (!head->down || !head->right)
			cout << "-empty table";
		else
		{
			Node*pd, *pr;
			for (pd = head->down; pd != NULL; pd = pd->down){
				for (pr = pd->right; pr != NULL; pr = pr->right)
					cout << "(" << pr->x << ", " << pr->y << ") = " << pr->val << endl;
			}
		}
	}
}