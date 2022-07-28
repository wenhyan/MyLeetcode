//
// Created by whyan on 2022/7/27.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <string>
#include <stack>
#include "tree_node.h"

using std::vector;
using std::string;
using std::stack;

// 前序遍历
void RecursivePreOrderTraversal(TreeNode *root, vector<int> &res);
void IteratePreOrderTraversal(TreeNode *root, vector<int> &res);

// 中序遍历
void RecursiveInOrderTraversal(TreeNode *root, vector<int> &res);
void IterateInOrderTraversal(TreeNode *root, vector<int> &res);

// 后序遍历
void RecursivePostOrderTraversal(TreeNode *root, vector<int> &res);
void IteratePostOrderTraversal(TreeNode *root, vector<int> &res);

#endif
