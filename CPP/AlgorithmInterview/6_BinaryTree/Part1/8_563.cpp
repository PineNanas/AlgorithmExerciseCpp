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
    int sumTilt = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return sumTilt;
    }
    int dfs(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        sumTilt += abs(leftSum - rightSum);
        return rightSum + leftSum + root->val;
    }
};