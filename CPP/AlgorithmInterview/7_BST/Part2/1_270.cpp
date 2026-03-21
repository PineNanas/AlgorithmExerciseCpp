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
    int closestValue(TreeNode* root, double target) {
        double delta = 1000000000;
        int ans = 1000000000;
        while (root)
        {
            double deltaNow = abs(target - root->val);
            if (deltaNow == delta && ans > root->val)
            {
                delta = deltaNow;
                ans = root->val;
            }
            if (deltaNow < delta)
            {
                delta = deltaNow;
                ans = root->val;
            }
            if (root->val > target)
            {
                if (!root->left)
                {
                    return ans;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (!root->right)
                {
                    return ans;
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