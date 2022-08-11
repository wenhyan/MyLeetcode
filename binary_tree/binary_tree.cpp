//
// Created by whyan on 2022/7/27.
//
#include "binary_tree.h"

void RecursivePreorderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    res.emplace_back(root->value);

    RecursivePreorderTraversal(root->left, res);
    RecursivePreorderTraversal(root->right, res);
}

void RecursiveInorderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;
    RecursiveInorderTraversal(root->left, res);
    res.emplace_back(root->value);
    RecursiveInorderTraversal(root->right, res);
}

void RecursivePostorderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) return ;

    RecursivePostorderTraversal(root->left, res);
    RecursivePostorderTraversal(root->right, res);
    res.emplace_back(root->value);
}

void IteratePreorderTraversal(TreeNode *root, vector<int> &res)
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

vector<int> IteratePreorderTraversal(TreeNode *root)
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

void IterateInorderTraversal(TreeNode *root, vector<int> &res)
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

void IteratePostorderTraversal(TreeNode *root, vector<int> &res)
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

bool RecursiveIsSymmetric(TreeNode *tree, TreeNode *other_tree)
{
    if (tree == nullptr && other_tree == nullptr) return true;
    if (tree == nullptr || other_tree == nullptr) return false;
    if (tree->value != other_tree->value) return false;

    bool res = RecursiveIsSymmetric(tree->left, other_tree->right) && 
               RecursiveIsSymmetric(tree->right, other_tree->left);
    return res;
}

bool IterateIsSymmetric(TreeNode *tree, TreeNode *other_tree)
{
    if (tree == nullptr && other_tree == nullptr) return true;

    queue<TreeNode*> que1, que2;
    que1.emplace(tree), que2.emplace(other_tree);

    while (!que1.empty() || !que2.empty())
    {
        TreeNode *node1 = que1.front();
        TreeNode *node2 = que2.front();
        que1.pop();
        que2.pop();

        if (node1 == nullptr && node2 == nullptr) continue;
        if (node1 == nullptr || node2 == nullptr) return false;
        if (node1->value != node2->value) return false;

        que1.emplace(node1->left), que2.emplace(node2->right);
        que1.emplace(node1->right), que2.emplace(node2->left);
    }

    return true;
}

bool RecursivePathSum(TreeNode *root, int &target)
{
    if (root == nullptr) return false;
    target -= root->value;
    if (!root->left && !root->right && target == 0) return true;

    if (root->left)
    {
        if (RecursivePathSum(root->left, target)) return true;
        target += root->left->value; // 回溯，每次检查完左子树后，检查右子树前要减去左子树的路径和
    }

    if (root->right)
    {
        if (RecursivePathSum(root->right, target)) return true;
        target += root->right->value;
    }
    return false;
}

bool RecursivePathSum(TreeNode *root, int target, int flag)
{
    if (root == nullptr) return false;
    target -= root->value;

    if (root->left == nullptr && root->right == nullptr && target == 0) return true;

    return RecursivePathSum(root->left, target, 1) || RecursivePathSum(root->right, target, 1);
}

bool IteratePathSum(TreeNode *root, int &target)
{
    if (root == nullptr) return false;
    stack<TreeNode*> tree_st;
    stack<int> sum_st;
    tree_st.emplace(root);
    sum_st.emplace(root->value);

    while (!tree_st.empty())
    {
        auto node = tree_st.top();
        auto sum = sum_st.top();
        tree_st.pop();
        sum_st.pop();

        if (!node->left && !node->right && sum == target) return true;
        if (node->left)
        {
            tree_st.emplace(node->left);
            sum_st.emplace(sum + node->left->value);
        }
        if (node->right)
        {
            tree_st.emplace(node->right);
            sum_st.emplace(sum + node->right->value);
        }
    }
    return false;
}

bool LevelOrderPathSum(TreeNode *root, int &target)
{
    if (root == nullptr) return false;
    queue<TreeNode*> tree_que;
    queue<int> sum_que;
    tree_que.emplace(root);
    sum_que.emplace(root->value);

    while (!tree_que.empty())
    {
        auto node = tree_que.front();
        auto sum = sum_que.front();
        tree_que.pop();
        sum_que.pop();

        if (!node->left && !node->right && sum == target) return true;

        if (node->left)
        {
            tree_que.emplace(node->left);
            sum_que.emplace(sum + node->left->value);
        }

        if (node->right)
        {
            tree_que.emplace(node->right);
            sum_que.emplace(sum + node->right->value);
        }
    }
    return false;
}

unordered_map<int, int> val_to_index;
void CreateMap(vector<int> &inorder)
{
    for (int i = 0; i < inorder.size(); ++i)
    {
        val_to_index[inorder[i]] = i;
    }
}

TreeNode *BuildTreeFromPreInOrder(vector<int> &preorder, vector<int> &inorder,
                                  int preorder_left, int preorder_right,
                                  int inorder_left, int inorder_right)
{
    if (preorder_left > preorder_right) return nullptr;

    auto root = new TreeNode(preorder[preorder_left]);

    int root_index = val_to_index[preorder[preorder_left]];
    int subtree_len = root_index - inorder_left;
    root->left = BuildTreeFromPreInOrder(preorder, inorder,
                                         preorder_left+1, preorder_left + subtree_len,
                                         inorder_left, root_index);
    root->right = BuildTreeFromPreInOrder(preorder, inorder,
                                          preorder_left + subtree_len + 1, preorder_right,
                                          root_index+1, inorder_right);

    return root;
}


TreeNode *BuildTreeFromInOrderPostOrder(vector<int> &inorder, vector<int> &postorder,
                                        int inorder_left, int inorder_right,
                                        int postorder_left, int postorder_right)
{
    if (postorder_left > postorder_right) return nullptr;
    auto root = new TreeNode(postorder[postorder_right]);
    int root_index = val_to_index[postorder[postorder_right]];
    int subtree_len = root_index - inorder_left;

    root->left = BuildTreeFromInOrderPostOrder(inorder, postorder,
                                               inorder_left, root_index-1,
                                               postorder_left, postorder_left+subtree_len-1);
    root->right = BuildTreeFromInOrderPostOrder(inorder, postorder,
                                                root_index, inorder_right,
                                                postorder_left+subtree_len, postorder_right-1);
    return root;
}

TreeNode *ConnectNodeNext(TreeNode *root)
{
    if (root == nullptr) return root;

    queue<TreeNode*> node_que;
    node_que.emplace(root);

    while (!node_que.empty())
    {
        int len = node_que.size();
        for (int i = 0; i < len; ++i)
        {
            auto node = node_que.front();
            node_que.pop();

            if (i < len-1)
            {
                node->next = node_que.front();
            }

            if (node->left) node_que.emplace(node->left);
            if (node->right) node_que.emplace(node->right);
        }
    }

    return root;
}

TreeNode *OptConnectNodeNext(TreeNode *root)
{
    if (!root) return root;
    auto current = root;

    while (current)
    {
        auto head = current;
        while (head && head->left) {
            head->left->next = head->right;

            if (head->next) {
                head->right->next = head->next->left;
            }

            head = head->next;
        }

        current = current->left;
    }

    return root;
}

void RecursiveConnectNodeNext(TreeNode *lhs, TreeNode *rhs)
{
    if (!lhs || !rhs) return ;
    lhs->next = rhs;
    RecursiveConnectNodeNext(lhs->left, rhs->right);
    RecursiveConnectNodeNext(lhs->right, rhs->left);
    RecursiveConnectNodeNext(rhs->left, rhs->right);
}

TreeNode *LowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q) return root;

    auto left_tree = LowestCommonAncestor(root->left, p, q);
    auto right_tree = LowestCommonAncestor(root->right, p, q);

    // 如果左子树和右子树都在，就是公共父节点
    if (left_tree && right_tree) return root;
    // 如果左子树在，右子树不在，返回左子树
    if (left_tree && !right_tree) return left_tree;
    if (!left_tree && right_tree) return right_tree;

    return nullptr;
}

unordered_map<int, TreeNode*> val_to_node;
unordered_map<int, bool> visited;

void dfs(TreeNode *root)
{
    if (root->left)
    {
        val_to_node[root->left->value] = root;
        dfs(root->left);
    }

    if (root->right)
    {
        val_to_node[root->right->value] = root;
        dfs(root->right);
    }
}

TreeNode *HashLowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    val_to_node[root->value] = nullptr;

    dfs(root);
    while (p)
    {
        visited[p->value] = true;
        p = val_to_node[p->value];
    }

    while (q)
    {
        if (visited[q->value]) return q;
        q = val_to_node[q->value];
    }

    return nullptr;
}
