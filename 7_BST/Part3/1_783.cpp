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
    int lastNum = -1;
    int minDiff = 1000000;
    int minDiffInBST(TreeNode* root) {
        dfsInOrder(root);
        return minDiff;
    }
    void dfsInOrder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        dfsInOrder(root->left);
        if (lastNum == -1)
        {
            lastNum = root->val;
        }
        else
        {
            int diff = root->val - lastNum;
            minDiff = min(minDiff, diff);
            lastNum = root->val;
        }
        dfsInOrder(root->right);
        return;
    }
};