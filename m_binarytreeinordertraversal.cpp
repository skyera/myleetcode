// Binary tree inorder traversal
// 9/27/2017
// Medium
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> inordertraversal(TreeNode *root) {
    vector<int> result;
    const TreeNode *p = root;
    stack<const TreeNode *> s;

    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            p = p->right;
        }
    }
    return result;
}

int main()
{
    return 0;
}
