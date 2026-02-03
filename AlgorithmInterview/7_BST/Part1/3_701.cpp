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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if (root == nullptr)
        {
            return newnode;
        }
        TreeNode* parent = nullptr;
        TreeNode* child = root;
        while (child)
        {
            parent = child;
            if (parent->val < val)
            {
                child = parent->right;
            }
            else
            {
                child = parent->left;
            }
        }
        if (parent->val < val)
        {
            parent->right = newnode;
        }
        else
        {
            parent->left = newnode;
        }
        return root;
    }
};