#ifndef _BTREE_H
#define _BTREE_H
#include "BTreeNode.h"

class BTree
{
private:
	BTreeNode*	root;	//con trỏ trỏ đến node gốc
	int			t;		//bậc của cây
public:
	BTree(int _t);
	~BTree();
	//Insert 



	// Duyệt cây (in ra màn hình)
	void traverse();
	//Tìm khóa k trong BtreeNode
	//+ Nếu không có trả về NULL, index = -1
	//+ Nếu có trả về địa chỉ BtreeNode *y và index được cập nhật, khi đó y->key[index] == k
	BTreeNode* search(int k, int &index);

	/*INSERT*/
	void insert(int k);
	/*REMOVE*/
	void remove(int k);
};

#endif