#ifndef _AVL_H
#define _AVL_H

#include <iostream>
using namespace std;

struct Node
{
	int key;
	char balance;
	Node* left;
	Node* right;
};

#define LH 	-1	 //Cay lech trai
#define EH 	0	//Cay can bang	
#define RH 	1	//Cay lech phai

Node* getNode(int k);

int insertNode(Node*&r, int k);

int removeNode(Node*&r, int k);
int findStandFor(Node*&p, Node*&q);


void rotateLL(Node*&r);
void rotateRR(Node*&r);
void rotateLR(Node*&r);
void rotateRL(Node*&r);

//return 1 - r không CB, 2 - r đã CB
int balanceLeft(Node*&r);
//return 1 - r không CB, 2 - r đã CB
int balanceRight(Node*&r);



//Root - Left - Right
void printTreePRE(Node*&root);
//Left - Root - Right
void printTreeMID(Node*&root);
//Left - Right - Root
void printTreePOS(Node*&root);

void addNode(Node*&root, int k);

Node* findNode(Node*root, int k);

// void removeNode(Node*&r, int k);

// //find the node p which is stand for q
// void findStandFor(Node*&p, Node*&q);

void removeTree(Node*&root);
#endif