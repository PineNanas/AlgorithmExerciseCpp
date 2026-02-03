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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            ans.push_back(nodeQueue.back()->val);
            for (int i = 0; i < size; i++)
            {
                if (nodeQueue.front()->left != nullptr)
                {
                    nodeQueue.push(nodeQueue.front()->left);
                }
                if (nodeQueue.front()->right != nullptr)
                {
                    nodeQueue.push(nodeQueue.front()->right);
                }
                nodeQueue.pop();
            }
        }
        return ans;
    }
};