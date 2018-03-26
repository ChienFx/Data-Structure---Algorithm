#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node* pNext;
};

struct List
{
	Node* Head;
	Node* Tail;
};

void addTail(List&l, int k);
void removeAffter(List&l, Node*p);
void main()
{
	List l;
	int k, n, x;
	l.Head = l.Tail = NULL;
	cout << "Input K:";
	cin >> k;
	cout << "Input anmount:";
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		addTail(l, i);
	
	Node*p1,*p2;
	do
	{
		p1 = l.Head;
		p2 = p1->pNext;

		for (int i = 0; i < k - 1; i++)
		{
			p1 = p2; p2 = p2->pNext;
		}

		cout << p2->key <<"  ";
		p2 = p2->pNext;

		removeAffter(l, p1);//remove p2

		l.Head = p2;
		l.Tail = p1;

	} while (l.Head !=l.Tail);
	cout << endl << "- Alive: " << l.Head->key;
}


void addTail(List&l, int k)
{
	Node*p = new Node;
	p->key = k;
	p->pNext = NULL;

	if (l.Head == NULL)
	{
		l.Head = l.Tail = p;
		l.Tail->pNext = l.Head;
	}
	else
	{
		l.Tail->pNext = p;
		p->pNext = l.Head;
		l.Tail = p;
	}

}
void removeAffter(List&l, Node*q)
{
	Node*p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p == q)
			l.Head = l.Tail = NULL;
		else
		{
			q->pNext = p->pNext;
			if (p == l.Tail)
				l.Tail = q;
		}
		delete p;
	}
}