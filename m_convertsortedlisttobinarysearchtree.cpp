// Convert sorted list to binary search tree
// 9/27/2017
// Medium
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// 1

int listlength(ListNode *node) {
    int n = 0;
    while (node) {
        ++n;
        node = node->next;
    }
    return n;
}

ListNode* nth_node(ListNode *node, int n) {
    while (--n)
        node = node->next;
    return node;
}


TreeNode* sortedlisttobst(ListNode *head, int len) {
    if (len == 0) return nullptr;
    if (len == 1) return new TreeNode(head->val);

    TreeNode *root = new TreeNode(nth_node(head, len/2+1)->val);
    root->left = sortedlisttobst(head, len/2);
    root->right = sortedlisttobst(nth_node(head, len/2+2), (len-1)/2);
    return root;
}

TreeNode* sortedlisttobst(ListNode *head) {
    return sortedlisttobst(head, listlength(head));
}

int main()
{
    return 0;
}
