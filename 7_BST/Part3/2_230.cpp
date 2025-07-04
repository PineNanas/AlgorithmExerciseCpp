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
    int kthSmall = -1;
    int count = -1;
    int kthSmallest(TreeNode* root, int k) {
        count = k - 1;
        dfs(root, k);
        return kthSmall;
    }
    void dfs(TreeNode* root, int k)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, k);
        if (count == 0)
        {
            kthSmall = root->val;
        }
        count--;
        dfs(root->right, k);
        return;
    }
};