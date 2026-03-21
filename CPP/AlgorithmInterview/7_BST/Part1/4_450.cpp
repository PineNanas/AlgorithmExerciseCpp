#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
        {
            return nullptr;
        }
        auto [parent, target] = findNode(root, key);
        if (!target)
        {
            return root;
        }
        if (!target->left && !target->right)
        {
            if (!parent)
            {
                return nullptr;
            }
            if (target == parent->left)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else if (!target->left)
        {
            if (!parent)
            {
                return target->right;
            }
            if (target == parent->left)
            {
                parent->left = target->right;
            }
            else
            {
                parent->right = target->right;
            }
        }
        else if (!target->right)
        {
            if (!parent)
            {
                return target->left;
            }
            if (target == parent->left)
            {
                parent->left = target->left;
            }
            else
            {
                parent->right = target->left;
            }
        }
        else
        {
            TreeNode* mostRight = target->left;
            parent = target;
            while (mostRight->right)
            {
                parent = mostRight;
                mostRight = mostRight->right;
            }
            target->val = mostRight->val;
            if (mostRight == parent->left)
            {
                parent->left = mostRight->left;
            }
            else
            {
                parent->right = mostRight->left;
            }
        }
        return root;
    }

    pair<TreeNode*, TreeNode*> findNode(TreeNode* root, int key)
    {
        pair<TreeNode*, TreeNode*> parentAndTarget = {nullptr, nullptr};
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        while (current)
        {
            if (current->val == key)
            {
                parentAndTarget.first = parent;
                parentAndTarget.second = current;
                return parentAndTarget;
            }
            else if (current->val < key)
            {
                parent = current;
                current = current->right;
            }
            else
            {
                parent = current;
                current = current->left;
            }
        }
        return parentAndTarget;
    }
};