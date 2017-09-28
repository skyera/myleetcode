// Flatten binary tree to linked list
// 9/27/2017
// Medium
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// 1
void flatten(TreeNode *root) {
    if (root == nullptr) return;

    flatten(root->left);
    flatten(root->right);

    if (nullptr == root->left) return;

    TreeNode *p = root->left;
    while (p->right) 
        p = p->right;
    p->right = root->right;
    root->right = root->left;
    root->left = nullptr;
}

// 2
TreeNode *flatten(TreeNode *root, TreeNode *tail) {
    if (NULL == root) return tail;

    root->right = flatten(root->left, flatten(root->right, tail));
    root->left = NULL;
    return root;
}

void flatten2(TreeNode *root) {
    flatten(root, NULL);
}


// iterative
 void flatten3(TreeNode *root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        auto p = s.top();
        s.pop();

        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);

        p->left = nullptr;
        if (!s.empty())
            p->right = s.top();
    }
 }

int main()
{
    return 0;
}
