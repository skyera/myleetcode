// Sort list
// 9/28/2017
// Medium
#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* mergetwolists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    for (ListNode *p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
        int val1 = l1 == nullptr?INT_MAX:l1->val;
        int val2 = l2 == nullptr?INT_MAX:l2->val;
        if (val1 < val2) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
    }
    return dummy.next;
}

ListNode* sortlist(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow;
    slow = slow->next;
    fast->next = NULL;

    ListNode *l1 = sortlist(head);
    ListNode *l2 = sortlist(slow);
    return mergetwolists(l1, l2);
}

int main()
{
    return 0;
}
