// Swap nodes in pair
// 8/31/2017
// Easy
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v): val(v), next(NULL) {}
};

ListNode* swappairs(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode dummy(-1);
    dummy.next = head;

    for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
         next; prev = cur, cur = cur->next, next = cur ? cur->next : NULL) {
        prev->next = next;
        cur->next = next->next;
        next->next = cur;
    }

    return dummy.next;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode *p = swappairs(n1);

    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
