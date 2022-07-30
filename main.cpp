#include <iostream>
#include "third_lib/test_interface.h"
#include "binary_tree/binary_tree.h"

using std::cout;
using std::endl;

int main() {
    TreeNode tree(1);
    TreeNode* root = &tree;
    TreeNode tree2(2);
    TreeNode tree_right2(2);
    TreeNode tree3(3);
    TreeNode tree_right3(3);
    TreeNode tree4(4);
    TreeNode tree_right4(4);
    root->left = &tree2;
    root->right = &tree_right2;
    tree2.left = &tree3;
    tree2.right = &tree4;
    tree_right2.left = &tree_right4;
    tree_right2.right = &tree_right3;

    cout << IterateIsSymmetric(root, root) << endl;
    return 0;
}
