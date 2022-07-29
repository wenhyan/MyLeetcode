//
// Created by whyan on 2022/7/27.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "tree_node.h"

using std::vector;
using std::string;
using std::stack;
using std::queue;

// 前序遍历
void RecursivePreorderTraversal(TreeNode *root, vector<int> &res);
void IteratePreorderTraversal(TreeNode *root, vector<int> &res);
vector<int> IteratePreorderTraversal(TreeNode *root);

// 中序遍历
void RecursiveInorderTraversal(TreeNode *root, vector<int> &res);
void IterateInorderTraversal(TreeNode *root, vector<int> &res);

// 后序遍历
void RecursivePostorderTraversal(TreeNode *root, vector<int> &res);
void IteratePostorderTraversal(TreeNode *root, vector<int> &res);

// 层序遍历
void LevelOrderTraversal(TreeNode *root, vector<int> &res);

#endif
