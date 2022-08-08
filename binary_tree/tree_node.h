//
// Created by 燕文豪 on 2022/7/26.
//

#ifndef LEETCODE_TREE_NODE_H
#define LEETCODE_TREE_NODE_H
class TreeNode
{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;
        TreeNode *next;
        TreeNode () : value(0), left(nullptr), right(nullptr), next(nullptr) {}
        TreeNode (int x) : value(x), left(nullptr), right(nullptr), next(nullptr) {}
        TreeNode (int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right), next(nullptr) {}
};
#endif //LEETCODE_TREE_NODE_H
