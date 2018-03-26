#ifndef _BST_H
#define _BST_H
#include <iostream>
#include <queue>
using namespace std;
/*
a. Hãy xây dựng cây nhị phân tìm kiếm với key nhập vào từ bàn phím.
b. Hãy viết hàm nhận vào Node gốc, xóa một Node có giá trị key cho trước khỏi
	cây. (Trả về “True” nếu xóa thành công, “False” nếu xóa không thành công).
c. Hãy viết hàm nhận vào Node gốc, tìm chiều cao của cây.
d. Hãy viết hàm nhận vào Node gốc, đếm số node không phải lá trên cây. 
*/
typedef struct BSTNode 
{
	int key;
	BSTNode* pLeft, *pRight;
}Node;

BSTNode* getNode(int k);

void insertNode(BSTNode*&root, int k);

bool removeNode(BSTNode*&root, int k);
void findStandFor(BSTNode*&root, BSTNode*&q);

int getHeight(BSTNode*root);

int countInternalNode(BSTNode*root);

void printTree(BSTNode* root);
//MorrisTraversal
void InOrder_MorrisTraversal(Node *root);
void PreOrder_MorrisTraversal(Node* root);
void PostOrder_MorrisTraversal(Node*root);
void printReveserRightHand(Node*head, Node*tail);


void removeAll(BSTNode*&root);

void levelOrder(Node * root);

void for_left(Node * root);
void for_right(Node * root);
void topView(Node * root);

//kiem tra BST
bool checkLeft(Node*root, int pdata);
bool checkRight(Node*root, int pdata);
bool checkBST(Node*root);

//đếm số node trong chỉ có 1 con
int countSingleInternal(Node*root);

//tính giá trị trung bình của cây
float meanTree(Node*root);

//tinh  tong
int sumTree(Node*root);

//dem so node
int countNode(Node*root);

//Đếm số Node nhỏ hơn 1 giá trị
int	countLess(Node* root, int x);


//tim node co gia tri gan voi 1 gia tri cho truoc
Node* find_nearest(Node*root, float k);
Node* find(Node* root, Node* cur, float k);
Node* median_nearest(Node*root);


//the (n+1)/2-th element when sorted
Node* findMedian(Node*root);
Node* findPosition(Node*root,Node*cur, int k);

#endif

