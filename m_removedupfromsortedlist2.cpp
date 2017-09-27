// Remove duplicates from sorted list II
// 9/26/2017
// Medium
#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* deleteduplicates(ListNode *head) {
    if (!head || !head->next) return head;

    ListNode *p = head->next;
    if (head->val == p->val) {
        while (p && head->val == p->val) {
            ListNode *tmp = p;
            p = p->next;
            delete tmp;
        }
        delete head;
        return deleteduplicates(p);
    } else {
        head->next = deleteduplicates(head->next);
        return head;
    }
}

//
ListNode* deleteduplicates2(ListNode *head) {
    if (head == nullptr) return head;

    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode *prev = &dummy, *cur = head;
    while (cur != nullptr) {
        bool duplicated = false;
        while (cur->next != nullptr && cur->val == cur->next->val) {
            duplicated = true;
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
        }

        if (duplicated) {
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
            continue;
        }

        prev->next = cur;
        prev = prev->next;
        cur = cur->next;
    }
    prev->next = cur;
    return dummy.next;
}

int main()
{
    return 0;
}
