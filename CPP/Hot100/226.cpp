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
    TreeNode* invertTree(TreeNode* root) {
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> TreeNode*
        {
            if (!cur)
            {
                return nullptr;
            }
            TreeNode* tmp = cur->left;
            cur->left = dfs(cur->right);
            cur->right = dfs(tmp);
            return cur;
        };
        return dfs(root);
    }
};