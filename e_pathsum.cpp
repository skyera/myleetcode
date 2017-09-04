// Path sum tree
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

int haspathsum(TreeNode *root, int sum) {
    if (root == nullptr) return false;

    if (root->left == nullptr && root->right == nullptr)
        return sum == root->val;

    return haspathsum(root->left, sum - root->val) || haspathsum(root->right, sum - root->val);
}

int main()
{
    return 0;
}
