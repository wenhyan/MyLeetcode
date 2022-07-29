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

void RecursiveInOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    RecursiveInOrderTraversal(root->left, res);
    res.emplace_back(root->value);
    RecursiveInOrderTraversal(root->right, res);
}

void RecursivePostOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;

    RecursivePostOrderTraversal(root->left, res);
    RecursivePostOrderTraversal(root->right, res);
    res.emplace_back(root->value);
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

vector<int> IteratePreOrderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode*> tree_st;

    while (root != nullptr || !tree_st.empty())
    {
        while (root)
        {
            res.emplace_back(root->value);
            tree_st.emplace(root);
            root = root->left;
        }

        TreeNode *node = tree_st.top();
        tree_st.pop();
        root = node->right;
    }

    return res;
}

void IterateInOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    stack<TreeNode*> tree_st;
    TreeNode *point = root;
    while (!tree_st.empty() || point != nullptr)
    {
        while (point != nullptr) {
            tree_st.emplace(point);
            point = point->left;
        }

        TreeNode *node = tree_st.top();
        tree_st.pop();
        res.emplace_back(node->value);
        point = node->right;
    }
}

void IteratePostOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    stack<TreeNode*> tree_st;
    // 使用一个指针来回溯
    TreeNode *point = nullptr;

    while (root != nullptr || !tree_st.empty())
    {
        while (root)
        {
            tree_st.emplace(root);
            root = root->left;
        }

        TreeNode *node  = tree_st.top();
        tree_st.pop();

        if (node->right == nullptr || node->right == point)
        {
            res.emplace_back(node->value);
            point = node;
            root = nullptr;
        } else
        {
            tree_st.emplace(node);
            root = node->right;
        }
    }
}

void LevelOrderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    queue<TreeNode*> tree_que;

    tree_que.emplace(root);

    while (!tree_que.empty())
    {
        unsigned int len = tree_que.size();

        for (int i = 0; i < len; ++i)
        {
            TreeNode *node = tree_que.front();
            tree_que.pop();
            res.emplace_back(node->value);

            if (node->left) tree_que.emplace(node->left);
            if (node->right) tree_que.emplace(node->right);
        }
    }
}