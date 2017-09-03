// Binary tree level order traversal
// 9/2/2017
// Easy
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode *root, size_t level, vector<vector<int> > &result) {
    if (!root) return;

    if (level > result.size())
        result.push_back(vector<int>());
    
    result[level-1].push_back(root->val);
    traverse(root->left, level + 1, result);
    traverse(root->right, level + 1, result);
}

vector<vector<int> > levelorder(TreeNode *root) {
    vector<vector<int> > result;
    
    traverse(root, 1, result);
    return result;
}

//
vector<vector<int> > levelorder2(TreeNode *root) {
    vector<vector<int> > result;
    if (!root) return result;

    queue<TreeNode*> current, next;
    current.push(root);

    while (!current.empty()) {
        vector<int> level;
        while (!current.empty()) {
            TreeNode *node = current.front();
            current.pop();
            level.push_back(node->val);

            if (node->left) next.push(node->left);
            if (node->right) next.push(node->right);
        }

        result.push_back(level);
        swap(current, next);
    }

    return result;
}

int main()
{
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n20 = new TreeNode(20);
    TreeNode *n15 = new TreeNode(15);
    TreeNode *n7 = new TreeNode(7);

    n3->left = n9;
    n3->right = n20;
    n20->left = n15;
    n20->right = n7;

    vector<vector<int> > result = levelorder(n3);
    vector<vector<int> > out;
    
    vector<int> v;

    v.push_back(3);
    out.push_back(v);
    
    v.clear();
    v.push_back(9);
    v.push_back(20);
    out.push_back(v);

    v.clear();
    v.push_back(15);
    v.push_back(7);
    out.push_back(v);

    assert(result == out);

    //
    result = levelorder2(n3);
    assert(result == out);

    return 0;
}
