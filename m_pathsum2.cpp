// Path sum II
// 9/27/2017
// Medium
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void pathsum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int> > &result) {
    if (root == nullptr) return;

    cur.push_back(root->val);

    if (root->left == nullptr & root->right == nullptr) {
        if (gap == root->val)
            result.push_back(cur);
    }

    pathsum(root->left, gap - root->val, cur, result);
    pathsum(root->right, gap - root->val, cur, result);

    cur.pop_back();
}

vector<vector<int> > pathsum(TreeNode *root, int sum) {
    vector<vector<int> > result;
    vector<int> cur;

    pathsum(root, sum, cur, result);
    return result;
}

int main()
{
    return 0;
}

