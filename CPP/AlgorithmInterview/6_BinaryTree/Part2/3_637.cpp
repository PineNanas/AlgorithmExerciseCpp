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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> nodeQueue;
        if (!root)
        {
            return ans;
        }
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            long long sum = 0;
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                sum += nodeQueue.front()->val;
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
            ans.push_back((double)sum / size);
        }
        return ans;
    }
};