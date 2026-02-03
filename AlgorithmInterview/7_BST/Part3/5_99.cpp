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
    TreeNode* leftNode = nullptr;
    TreeNode* rightNode = nullptr;
    TreeNode* lastNode = nullptr;
    void recoverTree(TreeNode* root) {
        dfs(root);
        if (!rightNode)
        {
            dfs(root);
        }
        swap(leftNode->val, rightNode->val);
        return;
    }

    void dfs(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left);
        if (lastNode && root->val < lastNode->val)
        {
            if (!leftNode)
            {
                leftNode = lastNode;
            }
            else
            {
                rightNode = root;
            }
        }
        lastNode = root;
        dfs(root->right);
        return;
    }
};