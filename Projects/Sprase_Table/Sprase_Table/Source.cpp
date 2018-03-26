#include "SpraseTable.h"

int main(){
	Node*head = createSpraseTable();
	insertNode(head, 3, 0, 0);
	insertNode(head, 4, 0, 1);
	insertNode(head, 5, 1, 2);
	insertNode(head, 4, 2, 3);
	insertNode(head, 6, 3, 1);
	insertNode(head, 7, 4, 2);
	/*insertNode(head, 4, 0, 1);
	insertNode(head, 4, 0, 1);
	insertNode(head, 4, 0, 1);
	insertNode(head, 4, 0, 1);
	insertNode(head, 4, 0, 1);
	*/

	printTable(head);
	Node*p = getPosition(head, 1, 21);
	if (p)
		cout << p->val << endl;
	else
		cout << "- Not exist!"<<endl;
	return 0;
}