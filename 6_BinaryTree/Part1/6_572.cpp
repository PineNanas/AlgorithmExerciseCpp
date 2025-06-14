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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        if (!isSameTree(p->left, q->left))
        {
            return false;
        }
        if (!isSameTree(p->right, q->right))
        {
            return false;
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
        {
            return true;
        }
        if (!root && subRoot)
        {
            return false;
        }
        if (root->left && isSubtree(root->left, subRoot))
        {
            return true;
        }
        if (root->right && isSubtree(root->right, subRoot))
        {
            return true;
        }
        if (isSameTree(root, subRoot))
        {
            return true;
        }
        return false;
    }
};
