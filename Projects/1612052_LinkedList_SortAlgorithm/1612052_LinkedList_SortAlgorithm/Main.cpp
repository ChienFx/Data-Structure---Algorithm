#include "SortAlgorithm.h"

Node* InsertNth(Node *&head, int info, int position)
{
	// Complete this method only
	// Do not write main function. 
	Data x; x.x = info;
	Node*p = new Node; 
	p->info = x; 
	p->pNext = NULL;
	if (!head||position==0)
		head = p;
	else
	{
		Node*t = head;
		for (int i = 0; i < position - 1 && t->pNext != NULL; i++)
			t = t->pNext;
		Node*p2 = t->pNext;
		t->pNext = p;
		p->pNext = p2;
	}
	return head;
}

void main()
{
	Node*head = NULL;
	/*InsertNth(head, 3, 0);
	InsertNth(head, 5, 1); 
	InsertNth(head, 4, 2);
	InsertNth(head, 2, 3);
	InsertNth(head, 10, 1);
	*/
	List l;
	InitList(l);

	Input(l, "Input_10.txt");
	//PrintList(l, "\nList:\t");
	InsertionSort(l);
	PrintList(l, "\nInsertion sort:\t");
	RemoveAll(l);

	Input(l, "Input_5000.txt");
	//PrintList(l, "\nList:\t");
	SelectionSort(l);
	PrintList(l, "\nSelection sort:\t");
	RemoveAll(l);

	Input(l, "Input_10.txt");
	PrintList(l, "\nList:\t");
	MergeSort(l);
	PrintList(l, "\nMerge sort:\t");
	RemoveAll(l);

	Input(l, "Input_10.txt");
	PrintList(l, "\nList:\t");
	QuickSort(l);
	PrintList(l, "\nQuick sort:\t");
	RemoveAll(l);
}