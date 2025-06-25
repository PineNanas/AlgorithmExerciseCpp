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
    TreeNode* target{nullptr};
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return target;
    }
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || target)
        {
            return {false, false};
        }
        auto leftPair = dfs(root->left, p, q);
        auto rightPair = dfs(root->right, p, q);
        if (target)
        {
            return {false, false};
        }
        pair<bool, bool> selfPair = {root->val == p->val, root->val == q->val};
        pair<bool, bool> ansPair = {leftPair.first || rightPair.first || selfPair.first,
                                    leftPair.second || rightPair.second || selfPair.second};
        if (ansPair.first && ansPair.second)
        {
            target = root;
        }
        return ansPair;
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* big = nullptr;
        TreeNode* small = nullptr;
        if (p->val > q->val)
        {
            big = p;
            small = q;
        }
        else
        {
            big = q;
            small = p;
        }
        while (true)
        {
            if (root->val >= small->val && root->val <= big->val)
            {
                return root;
            }
            else if (root->val < big->val)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return root;
    }
};