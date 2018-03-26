#include "BST.h"

int main()
{
	BSTNode*root = NULL;
	insertNode(root, 10);
	insertNode(root, 5);
	insertNode(root, 13);
	insertNode(root, 1);
	insertNode(root, 8);
	insertNode(root, 6);
	insertNode(root, 9);
	insertNode(root, 12);
	insertNode(root, 16);
	insertNode(root, 14);

	/*
	insertNode(root, 47);
	insertNode(root, 18);
	insertNode(root, 40);
	insertNode(root, 83);
	insertNode(root, 48);
	insertNode(root, 68);
	insertNode(root, 93);
	insertNode(root, 95);
	*/
/*
	insertNode(root, 11);
	insertNode(root, 5);
	insertNode(root, 18);
	insertNode(root, 3);
	insertNode(root, 8);
	insertNode(root, 9);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 15);
	insertNode(root, 14);
	insertNode(root, 20);
	insertNode(root, 19);
	insertNode(root, 30);
	*/
	
	printTree(root); cout << endl;
	InOrder_MorrisTraversal(root); cout << endl;
	PreOrder_MorrisTraversal(root); cout << endl;
	PostOrder_MorrisTraversal(root); cout << endl;
	//printReveserRightHand(root, root->pRight->pRight);
	cout << endl;
	cout << "- Trung vi: " << findMedian(root)->key << endl;
	cout << endl;
	cout << "- So node trong: " << countInternalNode(root) << endl;
	cout << "- So node trong 1 con : " << countSingleInternal(root) << endl;
	cout << "- So node			   : " << countNode(root) << endl;

	cout << "- Tong				   : " << sumTree(root) << endl;
	
	cout << "- Gia tri trung binh  : " << meanTree(root) << endl;
	cout << "- Gia tri gan trung binh nhat: "<< find_nearest(root, meanTree(root))->key<<endl;
	

	//cout << checkBST(root);
	
	//topView(root);
	//cout << endl;

	//levelOrder(root);

	/*int key=1;
	while (key > 0)
	{
		cout << "- nhap gia tri key (nhap so am de key thuc):";
		cin >> key;
		if (key < 0)
			break;
		insertNode(root, key);
	}

	printTree(root);
	cout << endl;
	cout << "- CHieu cao    : " << getHeight(root) << endl;
	cout << "- So node trong: " << countInternalNode(root) << endl;

	while (root)
		removeNode(root,root->key);
	cout << endl;
	
	printTree(root);
	removeAll(root);
	*/
	return 0;
}