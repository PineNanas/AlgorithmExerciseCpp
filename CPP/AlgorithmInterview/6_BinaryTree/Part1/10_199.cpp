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
    int treeDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
    void dfs(TreeNode *root, vector<int>& ans, int nodeDepth)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, ans, nodeDepth + 1);
        dfs(root->right, ans, nodeDepth + 1);
        ans[nodeDepth] = root->val;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans(treeDepth(root));
        dfs(root, ans, 0);
        return ans;
    }
};