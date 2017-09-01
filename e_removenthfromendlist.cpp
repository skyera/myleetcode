// Remove nth node from end of list
// 8/31/2017
// Easy
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v): val(v), next(NULL) {}
};


ListNode* removenthendlist(ListNode *head, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;

    for (int i = 0; i < n; i++)
        q = q->next;

    while (q->next) {
        p = p->next;
        q = q->next;
    }

    ListNode *tmp = p->next;
    p->next = p->next->next;
    delete tmp;

    return dummy.next;
}


int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode *head = removenthendlist(n1, 2);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
