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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> curPath;
        vector<string> ans;
        auto buildString = [&] () -> void
        {
            string s = "";
            for (auto &&num : curPath)
            {
                s.append(to_string(num) + "->");
            }
            s.erase(s.size() - 2, 2);
            ans.push_back(s);
        };
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> bool
        {
            if (!cur)
            {
                return false;
            }
            curPath.push_back(cur->val);
            bool l = dfs(cur->left);
            bool r = dfs(cur->right);
            if (!l && !r)
            {
                buildString();
            }
            curPath.pop_back();
            return true;
        };
        dfs(root);
        return ans;
    }
};