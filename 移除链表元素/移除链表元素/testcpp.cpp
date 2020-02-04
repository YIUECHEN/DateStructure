#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* removeElements(ListNode* head, int val) {
	ListNode* res = new ListNode(0);
	res->next = head;
	ListNode* temp = res;
	while (temp->next!=NULL){
		if (temp->next->val == val){
			temp->next = temp->next->next;
		}
		else{
			temp = temp->next;
		}
	}
	return res->next;
}
int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	ListNode* res=removeElements(&a,2);
	while (res != NULL){
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
	return 0;
}