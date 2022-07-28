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

#endif
