// Balanced binary tree
// 9/2/2017
// Easy
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int balancedheight(TreeNode *root) {
    if (!root) return 0;

    int left = balancedheight(root->left);
    int right = balancedheight(root->right);

    if (left < 0 || right < 0 || abs(left-right) > 1) return -1;

    return max(left, right) + 1;
}

bool isbalanced(TreeNode *root) {
    return balancedheight(root) > 0;
}

int main()
{
    return 0;
}
