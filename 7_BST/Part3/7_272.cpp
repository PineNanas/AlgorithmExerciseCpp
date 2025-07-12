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
    queue<int> kClosest;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root, target, k);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(kClosest.front());
            kClosest.pop();
        }
        return ans;
    }

    void dfs(TreeNode* root, double target, int k)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, target, k);
        if (kClosest.size() < k)
        {
            kClosest.push(root->val);
        }
        else
        {
            if (abs(kClosest.front() - target) > abs(root->val - target))
            {
                kClosest.pop();
                kClosest.push(root->val);
            }
        }
        dfs(root->right, target, k);
        return;
    }
};