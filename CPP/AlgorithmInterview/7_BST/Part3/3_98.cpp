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
    int lastNum = 0;
    bool defined = false;
    bool ans = true;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left);
        if (defined == true && lastNum >= root->val)
        {
            ans = false;
        }
        lastNum = root->val;
        defined = true;
        dfs(root->right);
        return;
    }
};