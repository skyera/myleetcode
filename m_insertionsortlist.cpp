// Insertion sort list
// 9/27/2017
// Medium
#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


ListNode* findinsertpos(ListNode *head, int x) {
    ListNode *pre = nullptr;
    for (ListNode *cur = head; cur != nullptr && cur->val <= x; pre = cur, cur = cur->next)
        ;
    return pre;
}

ListNode* insertionsortlist(ListNode *head) {
    ListNode dummy(INT_MIN);

    for (ListNode *cur = head; cur != nullptr; ) {
        auto pos = findinsertpos(&dummy, cur->val);
        ListNode *tmp = cur->next;
        cur->next = pos->next;
        pos->next = cur;
        cur = tmp;
    }
    return dummy.next;
}

int main()
{

}
