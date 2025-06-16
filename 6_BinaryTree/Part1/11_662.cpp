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
    unsigned long long treeDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
    void dfs(TreeNode* root, vector<pair<unsigned long long, unsigned long long>>& leftToRight, unsigned long long nodeDepth, unsigned long long deltaWidth)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, leftToRight, nodeDepth + 1, deltaWidth * 2);
        dfs(root->right, leftToRight, nodeDepth + 1, deltaWidth * 2 + 1);
        if (leftToRight[nodeDepth].first == -1 || deltaWidth < leftToRight[nodeDepth].first)
        {
            leftToRight[nodeDepth].first = deltaWidth;
        }
        if (leftToRight[nodeDepth].second == -1 || deltaWidth > leftToRight[nodeDepth].second)
        {
            leftToRight[nodeDepth].second = deltaWidth;
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<pair< unsigned long long, unsigned long long>> leftToRight(treeDepth(root), {-1, -1});
        dfs(root, leftToRight, 0, 0);
        unsigned long long ans = 1;
        for (int i = 0; i < leftToRight.size(); i++)
        {
            ans = max(ans, leftToRight[i].second - leftToRight[i].first + 1);
        }
        return ans;
    }
};