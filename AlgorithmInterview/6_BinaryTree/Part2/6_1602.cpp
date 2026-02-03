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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        int ans = 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
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
                if (nodeQueue.front() == u)
                {
                    nodeQueue.pop();
                    if (i != size - 1)
                    {
                        return nodeQueue.front();
                    }
                    else
                    {
                        return nullptr;
                    }
                }
                nodeQueue.pop();
            }
        }
        return nullptr;
    }
};