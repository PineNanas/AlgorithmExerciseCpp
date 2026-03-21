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

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        bool odd = true;
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            queue<TreeNode*> buffer;
            vector<int> valueBuffer(size);
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
                if (!odd)
                {
                    valueBuffer[size - i - 1] = nodeQueue.front()->val;
                    buffer.push(nodeQueue.front());
                }
                nodeQueue.pop();
            }
            if (!odd)
            {
                for (int i = 0; i < size; i++)
                {
                    buffer.front()->val = valueBuffer[i];
                    buffer.pop();
                }
            }
            odd = !odd;
        }
        return root;
    }
};