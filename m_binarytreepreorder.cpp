// Binary tree preorder traversal
// 9/27/2017
// Medium
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> preordertraversal(TreeNode *root) {
    vector<int> result;
    const TreeNode *p;
    stack<const TreeNode *> s;

    p = root;
    if (p != nullptr) s.push(p);

    while (!s.empty()) {
        p = s.top();
        s.pop();
        result.push_back(p->val);

        if (p->right != nullptr) s.push(p->right);
        if (p->left != nullptr) s.push(p->left);
    }
    return result;
}

int main()
{
    return 0;
}
