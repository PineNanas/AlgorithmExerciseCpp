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
    int maxDepth(TreeNode* root) {
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> int
        {
            if (!cur)
            {
                return 0;
            }
            return max(dfs(cur->left), dfs(cur->right)) + 1;
        };
        return dfs(root);
    }
};