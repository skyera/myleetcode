// Linked list cycle II
// 09/26/2017
// Medium
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* detectcycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *slow2 = head;

            while (slow2 != slow) {
                slow2 = slow2->next;
                slow = slow->next;
            }
            return slow2;
        }
    }
    return nullptr;
}

int main()
{
    return 0;
}
