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
    TreeNode* ans = nullptr;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return ans;
    }
    void dfs(TreeNode* root, TreeNode* p)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, p);
        if (root->val > p->val && !ans)
        {
            ans = root;
        }
        dfs(root->right, p);
        return;
    }
};

class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        if (p->right)
        {
            ans = p->right;
            while (ans->left)
            {
                ans = ans->left;
            }
        }
        else
        {
            while (root != p)
            {
                if (root->val > p->val)
                {
                    ans = root;
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return ans;
    }
};