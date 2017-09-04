// Maximum depth of binary tree
// 9/3/2017
// Easy
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int maxdepth(TreeNode *root) {
    if (root == nullptr) return 0;

    return max(maxdepth(root->left), maxdepth(root->right)) + 1;
}

int main()
{
    return 0;
}
