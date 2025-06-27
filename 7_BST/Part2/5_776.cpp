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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> ans = {nullptr, nullptr};
        if (!root)
        {
            return ans;
        }
        if (root->val > target)
        {
            vector<TreeNode*> leftVector = splitBST(root->left, target);
            root->left = leftVector[1];
            ans[0] = leftVector[0];
            ans[1] = root;
        }
        else
        {
            vector<TreeNode*> rightVector = splitBST(root->right, target);
            root->right = rightVector[0];
            ans[0] = root;
            ans[1] = rightVector[1];
        }
        return ans;
    }
};