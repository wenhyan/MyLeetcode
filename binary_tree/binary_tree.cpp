//
// Created by whyan on 2022/7/27.
//
#include "binary_tree.h"

void RecursivePreOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    res.emplace_back(root->value);

    RecursivePreOrderTraversal(root->left, res);
    RecursivePreOrderTraversal(root->right, res);
}

void IteratePreOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    stack<TreeNode*> tree_st;
    tree_st.emplace(root);

    while (!tree_st.empty())
    {
        TreeNode *node = tree_st.top();
        tree_st.pop();
        res.emplace_back(node->value);

        if (node->right) tree_st.emplace(node->right);
        if (node->left) tree_st.emplace(node->left);
    }
}