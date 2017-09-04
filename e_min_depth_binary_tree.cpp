// Minimum depth of binary tree
// 9/3/2017
// Easy
#include <iostream>
#include <cassert>
#include <climits>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int mindepth(TreeNode *root, bool hasbrother) {
    if (!root) hasbrother? INT_MAX: 0;
    
    return 1 + min(mindepth(root->left, root->right != NULL), 
                   mindepth(root->right, root->left != NULL));
}

// XXX
int mindepth2(TreeNode *root) {
    if (root == nullptr)
        return 0;

    int result = INT_MAX;

    stack<pair<TreeNode*, int> > s;
    s.push(make_pair(root, 1));

    while (!s.empty()) {
        auto node = s.top().first;
        auto depth = s.top().second;
        s.pop();

        if (node->left == nullptr && node->right == nullptr)
            result = min(result, depth);

        if (node->left != nullptr && result > depth)
            s.push(make_pair(node->left, depth + 1));

        if (node->right != nullptr && result > depth)
            s.push(make_pair(node->right, depth + 1));
    }

    return result;
}


int main()
{
    return 0;
}
