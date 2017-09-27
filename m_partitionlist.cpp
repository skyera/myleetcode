// Partition list
// 9/26/2017
// Medium
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* partition(ListNode *head, int x) {
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);

    auto left_cur = &left_dummy;
    auto right_cur = &right_dummy;

    for (ListNode *cur = head; cur; cur = cur->next) {
        if (cur->val < x) {
            left_cur->next = cur;
            left_cur = cur;
        } else {
            right_cur->next = cur;
            right_cur = cur;
        }
    }

    left_cur->next = right_dummy.next;
    right_cur->next = nullptr;
    return left_dummy.next;
}

int main()
{
    return 0;
}
