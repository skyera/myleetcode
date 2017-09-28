// Validate binary search tree
// 9/27/2017
// Medium
#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isvalidbst(TreeNode *root, int lower, int upper) {
    if (root == nullptr) return true;

    return root->val > lower && root->val < upper
           && isvalidbst(root->left, lower, root->val)
           && isvalidbst(root->right, root->val, upper);
}

bool isvalidbst(TreeNode *root) {
    return isvalidbst(root, INT_MIN, INT_MAX);
}

int main()
{
    return 0;
}
