#include<bits/stdc++.h>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> curPath;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> bool
        {
            if (!cur)
            {
                return true;
            }
            sum += cur->val;
            curPath.push_back(cur->val);
            bool l = dfs(cur->left);
            bool r = dfs(cur->right);
            if (sum == targetSum && l && r)
            {
                ans.push_back(curPath);
            }
            curPath.pop_back();
            sum -= cur->val;
            return false;
        };
        dfs(root);
        return ans;
    }
};