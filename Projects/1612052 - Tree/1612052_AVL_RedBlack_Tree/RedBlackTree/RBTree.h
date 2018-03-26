#ifndef _RBTREE_H
#define _RBTREE_H

#include <iostream>
using namespace std;

const bool BLACK = true;
const bool RED	 = false;

struct Node
{
	int 	key;
	bool 	color;
	Node* 	parent;
	Node*	left;
	Node* 	right;
};


//Duyệt trước: Gốc - Trái - Phải
void printTreePRE(Node*&r, Node* nil);
//Duyệt giữa : Trái - Gốc - Phải
void printTreeMID(Node*&r, Node* nil);
//Duyệt sau	 : Trái - Phải - Gốc
void printTreePOST(Node*&r, Node* nil);

//Hủy toàn bộ cây
void removeTree(Node*&root, Node* nil);

Node* getNode(int key, bool color, Node* nil);

void rotateLeft(Node* &root, Node* x, Node* nil);
void rotateRight(Node* &root, Node* x, Node* nil);

/*INSERT NODE*/

/*Chèn một key vào cây root*/
void RBT_Insert(Node* &root, int key, Node* nil);
/*Chèn Node x vào cây Root (không đệ qui) Trả về TRUE-thành công, FALSE-thất bại (đã tồn tại)*/
bool BST_Insert(Node* &root, Node* x, Node* nil);
/*Cân bằng lại cây sau khi chèn*/
void Insertion_Fixup(Node*& root, Node* x, Node* nil);
/*Điều chỉnh bên trái*/
void InsertAdjustLeft(Node*& root, Node*&x, Node*nil);
/*Điều chỉnh bên phải*/
void InsertAdjustRight(Node*& root, Node*&x, Node*nil);



/*ROMOVE NODE*/
void RBT_Remove(Node* &root, int k, Node* nil);

void Remove_Fixup(Node*&root, Node* x, Node* nil);

void RemoveAdjustLeft(Node*& root, Node*& x, Node* nil);
void RemoveAdjustRight(Node*& root, Node*& x, Node* nil);


/*Tìm node chứa key = k, trả về nil nếu không tìm thấy*/
Node* searchTree(Node*&root, int k, Node* nil);

/*Successor: phần tử trái nhất trên cây con phải (khác nil)*/
Node* TreeSuccessor(Node* root, Node*x, Node*nil);

#endif