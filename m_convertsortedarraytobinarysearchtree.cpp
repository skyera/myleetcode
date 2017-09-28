// Convert sorted array to binary search tree
// 9/27/2017
// Medium
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


template<typename RandomAccessIterator>
TreeNode* sortedarraytobst(RandomAccessIterator first, RandomAccessIterator last) {
    const auto length = distance(first, last);

    if (length <= 0) return nullptr;

    auto mid = first + length / 2;
    TreeNode *root = new TreeNode(*mid);
    root->left = sortedarraytobst(first, mid);
    root->right = sortedarraytobst(mid + 1, last);

    return root;
}

TreeNode* sortedarraytobst(vector<int> &num) {
    return sortedarraytobst(num.begin(), num.end());
}

int main()
{
    return 0;
}
