#include <iostream>
using namespace std;

struct Node{
	int val;//value
	int x;//row
	int y;//col
	Node* right;
	Node* down;
};

Node* getNode(int value, int x, int y);
Node* createSpraseTable();
void insertNode(Node*&head, int val, int x, int y);
void insert(Node*&head, Node*p);
Node* getPosition(Node*head, int x, int y);
void printTable(Node*head);