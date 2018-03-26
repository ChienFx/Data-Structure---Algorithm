#ifndef _NODE_H
#define _NODE_H
#include <wchar.h>
#include <stdio.h>

class Node
{
	wchar_t		c;
	bool		used;
	unsigned long		freq;
	Node*		left;
	Node*		right;
public:
	Node(wchar_t c);
	Node(wchar_t ch, unsigned long fr);
	virtual ~Node();
	friend class StaticHuffman;
	void printTree()
	{
			if(left!=NULL)
				left->printTree();
			wprintf(L"%d  ", freq);
			if (right!=NULL)
				right->printTree();
	}
};

#endif