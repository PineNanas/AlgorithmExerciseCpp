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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }

    int dfs(TreeNode* root, int low, int high)
    {
        if (!root)
        {
            return 0;
        }
        int sum = 0;
        sum += dfs(root->left, low, high);
        if (root->val <= high && root->val >= low)
        {
            sum += root->val;
        }
        sum += dfs(root->right, low, high);
        return sum;
    }
};