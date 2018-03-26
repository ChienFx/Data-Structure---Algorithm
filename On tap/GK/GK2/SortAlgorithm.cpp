#include "SortAlgorithm.h"

void InsertionSort(List&l){
	Node*dummy = new Node;
	dummy->pNext = l.pHead;
	Node*i, *iprev, *p1, *p2;
	for (i = l.pHead->pNext; i; i = i->pNext){
		p1 = dummy;
		p2 = p1->pNext;
		while (p2 != i->pNext && CompareData(p2->info, i->info)<0){
			p1 = p2; p2 = p2->pNext;
		}

		if (p2 != i)
		{
			for (iprev = p1; iprev->pNext != i; iprev = iprev->pNext)
				;
			iprev->pNext = i->pNext;
			p1->pNext = i;
			i->pNext = p2;
			i = iprev;
		}
	}
	l.pHead = dummy->pNext;
	delete dummy;
}

void SelectionSort(List&l)
{
	Node *i = NULL, *j = NULL, *min = NULL;
	for (i = l.pHead; i->pNext; i = i->pNext){
		min = i;
		for (j = i->pNext; j; j = j->pNext){
			//if (CompareData(min->info, j->info) > 0)
			if (j->info.x <= min->info.x)
				min = j;
		}
		Swap(l, min, i);
		//swap(min->info, i->info);
	}
}

void Swap(List&l, Node*&a, Node *&b)
{ 
	Node*dummy = new Node;
	dummy->pNext = l.pHead;

	Node *a_prev = dummy, *b_prev = dummy, *tmp = NULL;
	for (a_prev; a_prev->pNext != a && a_prev; a_prev = a_prev->pNext)
		;
	for (b_prev; b_prev->pNext != b && b_prev; b_prev = b_prev->pNext)
		;
	if (!a_prev || !b_prev)
		return;//node *a and node *b is not exist in this list
	else if (a_prev == b)
	{
		b->pNext = a->pNext;
		a->pNext = b;
		b_prev->pNext = a;
	}
	else if (b_prev == a)
	{
		a->pNext = b->pNext;
		b->pNext = a;
		a_prev->pNext = b;
	}
	else
	{
		a_prev->pNext = b;
		b_prev->pNext = a;
		tmp= a->pNext;
		a->pNext = b->pNext;
		b->pNext = tmp;
	}
	
	//restore each pointer address (this func just swap data of node)
	tmp = a; //a_prev: temp
	a = b;
	b = tmp;

	l.pHead = dummy->pNext;
	delete dummy;
}
//Quick sort
Node *Partition(List&l){
	Node*dummy = new Node;
	dummy->pNext = l.pHead;
	Node* i = dummy;
	for (Node*j = l.pHead; j&&j != l.pTail; j = j->pNext){
		if (j->info.x <= l.pTail->info.x){
			i = i->pNext;
			Swap(l, i, j);
		}
	}
	i = i->pNext;
	Swap(l, i, l.pTail);
	//Head & delete dummy
	delete dummy; dummy = NULL;
	return i;
}
void QuickSort(List&l)
{
	if ((l.pHead != l.pTail))
	{
		Node*p = Partition(l);
		List l1, l2;
		InitList(l1); InitList(l2);
		Node*t = l.pHead;
		
		//split
		while(l.pHead && l.pHead != p)
		{
			t = l.pHead;
			l.pHead = t->pNext;
			t->pNext = NULL;
			AddTail(l1, t);
		}
		if (l.pHead)//p
		{
			l.pHead = p->pNext;// head->p->..->tail
			while (l.pHead)
			{
				t = l.pHead;
				l.pHead = t->pNext;
				t->pNext = NULL;
				AddTail(l2, t);
			}
		}

		QuickSort(l1);
		QuickSort(l2); 

		//join
		if (l1.pHead)
		{
			l.pHead = l1.pHead;
			l1.pTail->pNext = p;
		}
		else
			l.pHead = p;
		p->pNext = l2.pHead;
		if (l2.pHead)
			l.pTail = l2.pTail;
		else
			l.pTail = p;
	}
}


//Merge Sort 
void MergeSort(List&l)
{
	if (l.pHead == l.pTail) return;
	List l1, l2;
	InitList(l1); InitList(l2);
	DistributeList(l, l1, l2);
	if (l1.pHead && l2.pHead)
	{
		MergeSort(l1);
		MergeSort(l2);
	}
	Merge(l, l1, l2);
	
}
void Merge(List&l, List&l1, List&l2)
{
	Node *p;
	while (l1.pHead && l2.pHead)
	{
		if (l1.pHead->info.x <= l2.pHead->info.x){
			p = l1.pHead;
			l1.pHead = p->pNext;
		}
		else{
			p = l2.pHead;
			l2.pHead = p->pNext;
		}
		p->pNext = NULL;
		AddTail(l, p);
	}
	//noi phan con lai
	while (l1.pHead){
		p = l1.pHead; 
		l1.pHead = l1.pHead->pNext;
		p->pNext = NULL;
		AddTail(l, p);
	}
	while (l2.pHead){
		p = l2.pHead; l2.pHead = l2.pHead->pNext;
		p->pNext = NULL;
		AddTail(l, p);
	}
}
void DistributeList(List&l, List&l1, List&l2)
{
	Node *p;
	do//spit l into l1 & l2
	{
		p = l.pHead;
		l.pHead = p->pNext;
		p->pNext = NULL;
		AddTail(l1, p);
	} while ((l.pHead) &&(p->info.x <= l.pHead->info.x));
	if (l.pHead)
		DistributeList(l, l2, l1);
	else
		l.pTail = NULL;
}

void Input(List &l, const char* _path){
	fstream f_in;
	f_in.open(_path, ios::in);
	if (f_in.is_open()){
		int n, tmp;
		Data info;
		f_in >> n;
		for (int i = 0; i < n; i++){
			f_in >> tmp;
			info.x = tmp;
			AddTail(l, info);
		}
	}
	f_in.close();
}