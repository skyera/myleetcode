// reorder list
// 9/27/2017
// Medium
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode *prev = head;
    for (ListNode *curr = head->next, *next = curr->next; curr;
         prev = curr, curr = next, next = next?next->next:nullptr) {
        curr->next = prev;
    }
    head->next = nullptr;
    return prev;
}

void roorderlist(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return;

    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);

    // merge 2 lists
    ListNode *curr = head;
    while (curr->next) {
        ListNode *tmp = curr->next;
        curr->next = slow;
        slow = slow->next;
        curr->next->next = tmp;
        curr = tmp;
    }
    curr->next = slow;

    prev->next = nullptr;
}

int main()
{
    return 0;
}
