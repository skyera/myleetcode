// remove duplicates from sorted list
// 8/31/2017
// Easy
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* removedups(ListNode *head) {
    if (head == NULL) return NULL;

    for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
        } else 
            prev = cur;
    }

    return head;
}

void recur(ListNode *prev, ListNode *cur) {
    if (!cur) return;

    if (prev->val == cur->val) {
        prev->next = cur->next;
        delete cur;
        recur(prev, prev->next);
    } else {
        recur(cur, cur->next);
    }
}

// recursive
ListNode *removedup2(ListNode *head) {
    if (!head) return NULL;

    ListNode dummy(head->val + 1);
    dummy.next = head;

    recur(&dummy, head);

    return dummy.next;
}

int main()
{
    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(1);
        ListNode *n3 = new ListNode(2);
        n1->next = n2;
        n2->next = n3;

        ListNode *head = removedups(n1);

        for (ListNode *n = head; n; n = n->next)
            cout << n->val << " ";

        cout << endl;
    }

    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(1);
        ListNode *n3 = new ListNode(2);
        n1->next = n2;
        n2->next = n3;

        ListNode *head = removedup2(n1);

        for (ListNode *n = head; n; n = n->next)
            cout << n->val << " ";

        cout << endl;
    }
    return 0;
}
