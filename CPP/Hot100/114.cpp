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
    void flatten(TreeNode* root) {
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> pair<TreeNode*, TreeNode*>
        {
            if (!cur)
            {
                return {nullptr, nullptr};
            }
            auto [lefthead, lefttail] = dfs(cur->left);
            auto [righthead, righttail] = dfs(cur->right);
            if (!lefttail && !righttail)
            {
                return {cur, cur};
            }
            if (!lefttail)
            {
                cur->right = righthead;
                return {cur, righttail};
            }
            if (!righttail)
            {
                cur->right = lefthead;
                cur->left = nullptr;
                return {cur, lefttail};
            }
            lefttail->right = righthead;
            cur->right = lefthead;
            cur->left = nullptr;
            return {cur, righttail};
        };
        dfs(root);
        return;
    }
};