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
    int ans = 0;
    int depth(TreeNode* baseNode)
    {
        if (!baseNode)
        {
            return 0;
        }
        int depthLeft = depth(baseNode->left);
        int depthRight = depth(baseNode->right);
        ans = max(ans, depthLeft + depthRight);

        return max(depthLeft, depthRight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};