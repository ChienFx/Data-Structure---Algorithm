#include "Node.h"


Node::Node(wchar_t c )
{
	this->c = c;
	this->freq = 1;
	this->used = false;
	this->right = this->left = NULL;
}


Node::~Node()
{
	wprintf(L"\n- delete node");
	delete left;
	delete right;
}

