#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x == info2.x)
		return 0;
	else if (info1.x < info2.x)
		return -1;
	else
		return 1;
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	l.pHead = l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	return (l.pHead == NULL);
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	cout << str;
	if (!IsEmptyList(l))
	{
		Node *p = l.pHead;
		while (p)
		{
			cout << p->info<<" ";
			p = p->pNext;
		}
	}
	else
		cout << "- Empty List.";
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	Node*p = new Node;
	if (!p)
		cout << "- Not enough memory.";
	return p;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	Node* p = l.pHead;
	while (p && CompareData(p->info,info)!=0)
	{
		p = p->pNext;
	}
	return p;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	Node*p = l.pHead;
	while (p && index>=0)
	{
		p = p->pNext;
		index--;
	}
	return p;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	int i = 0;
	Node*p = l.pHead;
	while (p && p != pNode)
	{
		i++;
		p = p->pNext;
	}
	if (p == NULL)
		i = -1;
	return i;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	Node*p = l.pHead;
	if (p == pNode || pNode == NULL)
		return NULL;
	while (p && p->pNext != pNode)
	{
		p = p->pNext;
	}
	return p;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	
	if (IsEmptyList(l))
	{
		l.pHead = l.pTail = pNewNode;
		pNewNode->pNext = NULL;
	}
	else
	{
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	Node*p = new Node;
	if (p)
	{
		p->info = info;
		if (IsEmptyList(l))
		{
			l.pHead = l.pTail = p;
			p->pNext = NULL;
		}
		else
		{
			p->pNext = l.pHead;
			l.pHead = p;
		}
	}
	return p;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	if (l.pHead==NULL)
	{
		l.pHead = pNewNode;
		l.pTail = pNewNode;
		pNewNode->pNext = NULL;
	}
	else
	{
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
		pNewNode->pNext = NULL;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{

	Node * p = new Node;
	if (p)
	{
		p->info = info;
		p->pNext = NULL;
		if (IsEmptyList(l))
		{
			l.pHead = l.pTail = p;
		}
		else
		{
			l.pTail->pNext = p;
			l.pTail = p;
		}
	}
	return p;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	pNewNode->pNext = q->pNext;
	q->pNext = pNewNode;
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info)
{
	Node * p = new Node;
	if (p)
	{
		p->info = info;
		p->pNext = q->pNext;
		q->pNext = p;
	}
	return p;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	Data info = q->info;
	pNewNode->pNext = q->pNext;
	q->pNext = pNewNode;
	q->info = pNewNode->info;
	pNewNode->info = info;
	/*viet gon
	Data info = pNewNode->info;
	*pNewNode = *q;
	q->next = pNextNode;
	q->info = info;
	*/
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	Node *p = new Node;
	if (p)
	{
		p->info = info;
		p->pNext = NULL;
		AddBefore(l, q, p);
	/*	*p = *q;
		q->pNext = p;
		q->info = info;
	*/}
	return p;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode)
{

}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	//dummy head
	Node *dummy = new Node;
	dummy->pNext = l.pHead;
	l.pHead = dummy;
	Node * p1 = dummy;
	Node * p2 = p1->pNext;
	while (p2&&CompareData(p2->info,info)<0)//p2->info < info
	{
		p1 = p2; p2 = p2->pNext;
	}
	Node* p = new Node;
	p->info = info;
	p1->pNext = p;
	p->pNext = p2;
	RemoveHead(l);
	return p;
}

// 20. Hàm hủy một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveHead(List& l)
{
	Node*p = l.pHead;
	if (p)
	{
		if (l.pHead == l.pTail)
		{
			l.pHead = l.pTail = NULL;
			l.pHead->pNext = l.pTail->pNext = NULL;
		}
		else
		{
			l.pHead = l.pHead->pNext;
			p->pNext = NULL;
		}
	}
	return p;
}

// 21. Hàm hủy một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveTail(List& l)
{
	Node * p=NULL;
	if (IsEmptyList(l))
		return p;
	p = l.pTail;
	if (l.pHead == l.pTail)
	{
		l.pHead = l.pTail = NULL;
		l.pHead->pNext = l.pTail->pNext = NULL;
	}
	else
	{
		p->pNext = NULL;
		l.pTail = GetPreviousNodePointer(l, l.pTail);
		l.pTail->pNext = NULL;
	}
	return p;
}

// 22. Hàm hủy một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveAfter(List& l, Node* q)
{
	if (q == NULL || q == l.pTail)
		return NULL;

	Node * p = q->pNext;
	q->pNext = p->pNext;
	p->pNext = NULL;
	return p;
}

// 23. Hàm hủy một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveNode(List& l, Data info)
{
	Node * p = l.pHead;
	while (p && CompareData(p->info, info)!=0)
	{
		p = p->pNext;
	}
	if (p == NULL)
		return p;
	if (p == l.pHead)
	{
		l.pHead = p->pNext;
		p->pNext = NULL;
	}
	else
		p = RemoveAfter(l, GetPreviousNodePointer(l, p));
	return p;
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void RemoveAll(List& l)
{
	Node *p = NULL;
	while (l.pHead)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
		p = NULL;
	}
}

