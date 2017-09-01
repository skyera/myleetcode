// Linked list cycle
// 8/31/2017
// Easy
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v): val(v), next(NULL) {}
};

bool hascycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main()
{
    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(2);
        ListNode *n3 = new ListNode(3);
        ListNode *n4 = new ListNode(4);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;

        bool ok = hascycle(n1);
        assert(!ok);
    }
    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(2);
        ListNode *n3 = new ListNode(3);
        ListNode *n4 = new ListNode(4);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n1;

        bool ok = hascycle(n1);
        assert(ok);

    }
    return 0;
}
