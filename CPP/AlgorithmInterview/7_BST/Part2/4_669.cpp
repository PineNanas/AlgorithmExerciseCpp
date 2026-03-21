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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
        {
            return nullptr;
        }
        TreeNode* leftNode = trimBST(root->left, low, high);
        TreeNode* rightNode = trimBST(root->right, low, high);
        if (root->val < low)
        {
            return rightNode;
        }
        else if (root->val > high)
        {
            return leftNode;
        }
        else
        {
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }
    }
};