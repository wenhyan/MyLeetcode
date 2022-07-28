#include <iostream>
#include "test_interface.h"
#include "binary_tree/binary_tree.h"

using std::cout;
using std::endl;

int main() {
    TreeNode tree(1);
    TreeNode* root = &tree;
    TreeNode tree2(2);
    TreeNode tree3(3);
    TreeNode tree4(4);
    root->left = &tree2;
    root->right = &tree3;
    root->left->left = &tree4;

    vector<int> res;
    IteratePreOrderTraversal(root, res);
    for (auto &item : res)
        cout << item << " ";

    return 0;
}
