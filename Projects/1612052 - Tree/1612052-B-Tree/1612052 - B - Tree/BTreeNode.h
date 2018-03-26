#ifndef _BTREENODE_H
#define _BTREENODE_H
#include <iostream>
using namespace std;

class BTreeNode
{
private:
	int*		keys;		//mảng các khóa
	int			t;			//bậc của b cây
	BTreeNode**	C;			//dãy các cây con
	int			n;			//số lượng khóa hiện tại
	bool		leaf;		//is Leaf?
public:
	BTreeNode(int _t, bool _leaf);
	~BTreeNode();
	//BTree là lớp bạn để sử dụng thành phần private
	friend class BTree;

	//Duyệt cây
	void traverse();

	//Tìm khóa k trong BtreeNode
	//+ Nếu không có trả về NULL, index = -1
	//+ Nếu có trả về địa chỉ BtreeNode *y và index được cập nhật, khi đó y->key[index] == k
	BTreeNode* search(int k, int &index);

	int getKey(int index)
	{
		if (index >= n || index < 0)
			return INT_MIN;
		return keys[index];
	}
	
	/*INSERT AREA*/
	//Tách cây con tại i
	void splitChild(int i);
	//Chèn vào Node chưa đầy (n<2t-1)
	void insertNonNull(int k);

	/*REMOVE NODE AREA*/
	// Trả về vị trí i:  key[i] >= k
	int findKey(int k);

	// A wrapper function to remove the key k in subtree rooted with
	// this node.
	void remove(int k);
	
	// Xóa keys[idx] tại node hiện tại
	void removeFromLeaf(int idx);

	// Xóa phần tử ở cây con thứ idx
	void removeFromNonLeaf(int idx);

	// Trả về phần tử pred lớn nhất sao cho: pred < key[idx]
	int getPredessor(int idx);

	// Trả về phần tử succ nhỏ nhất sao cho: pred > key[idx]
	int getSuccessor(int idx);

	// Hàm điền điền khóa của 2 cây con tại nhánh idx
	void fill(int idx);

	// A function to borrow a key from the C[idx-1]-th node and place
	// it in C[idx]th node
	void borrowFromPrev(int idx);

	// A function to borrow a key from the C[idx+1]-th node and place it
	// in C[idx]th node
	void borrowFromNext(int idx);

	// A function to merge idx-th child of the node with (idx+1)th child of
	// the node
	void merge(int idx);
};

#endif