// same tree
// 9/2/2017
// Easy
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool issametree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;

    if (!p || !q) return false;

    return p->val == q->val &&
           issametree(p->left, q->left) &&
           issametree(p->right, q->right);
}

bool issametree2(TreeNode *p, TreeNode *q) {
    stack<TreeNode*> stk;

    stk.push(p);
    stk.push(q);

    while (!stk.empty()) {
        p = stk.top();
        stk.pop();
        q = stk.top();
        stk.pop();

        if (!p && !q) continue;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        stk.push(p->left);
        stk.push(q->left);
        stk.push(p->right);
        stk.push(q->right);
    }

    return true;
}

int main()
{
    return 0;
}
