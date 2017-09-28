// Sum root to leaf numbers
// 9/27/2017
// Medium
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode *root, int sum) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr)
        return sum * 10 + root->val;

    return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
}

int sumnumbers(TreeNode *root) {
    return dfs(root, 0);
}

int main()
{
    return 0;
}
