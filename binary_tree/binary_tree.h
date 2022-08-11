//
// Created by whyan on 2022/7/27.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "tree_node.h"

using std::vector;
using std::string;
using std::to_string;
using std::stoi;
using std::stack;
using std::queue;
using std::unordered_map;

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

// 判断对称二叉树
bool RecursiveIsSymmetric(TreeNode *tree, TreeNode *other_tree);
bool IterateIsSymmetric(TreeNode *tree, TreeNode *other_tree);

// 路径和
bool RecursivePathSum(TreeNode *root, int &target);
bool RecursivePathSum(TreeNode *root, int target, int flag);
bool IteratePathSum(TreeNode *root, int &target);
bool LevelOrderPathSum(TreeNode *root, int &target);

// 通过前序遍历和中序遍历恢复二叉树
void CreateMap(vector<int> &inorder);
TreeNode *BuildTreeFromPreInOrder(vector<int> &preorder, vector<int> &inorder,
                                  int preorder_left, int preorder_right,
                                  int inorder_left, int inorder_right);

// 通过中序遍历和后序遍历恢复二叉树
TreeNode *BuildTreeFromInOrderPostOrder(vector<int> &inorder, vector<int> &postorder,
                                        int inorder_left, int inorder_right,
                                        int postorder_left, int postorder_right);

// 填充每个节点的下一个右侧节点
TreeNode *ConnectNodeNext(TreeNode *root);
void RecursiveConnectNodeNext(TreeNode *lhs, TreeNode *rhs);
TreeNode *OptConnectNodeNext(TreeNode *root);

// 找到两个节点的最近公共祖父节点
TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
TreeNode *HashLowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

// 二叉树的序列化和反序列化
void SerializeBinaryTree(TreeNode *root, string &res);
TreeNode* DeserializeBinaryTree(queue<string> &res);

#endif
