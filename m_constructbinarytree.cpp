// Construct binary tree from preorder and inorder traversal
// 9/27/2017
// medium
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

template<typename InputIterator>
TreeNode* buildtree(InputIterator pre_first, InputIterator pre_last,
                    InputIterator in_first, InputIterator in_last) {
    if (pre_first == pre_last) return nullptr;
    if (in_first == in_last) return nullptr;

    auto root = new TreeNode(*pre_first);

    auto inrootpos = find(in_first, in_last, *pre_first);
    auto leftsize = distance(in_first, inrootpos);

    root->left = buildtree(next(pre_first), next(pre_first, leftsize + 1), in_first, next(in_first, leftsize));
    root->right = buildtree(next(pre_first, leftsize+1), pre_last, next(inrootpos), in_last);

    return root;
}

TreeNode* buildtree1(vector<int> &preorder, vector<int> &inorder) {
    return buildtree(begin(preorder), end(preorder), begin(inorder), end(inorder));
}

int main()
{
    return 0;
}
