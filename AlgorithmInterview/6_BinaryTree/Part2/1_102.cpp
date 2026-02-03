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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode*> pointerQueue;
        pointerQueue.push(root);
        while (!pointerQueue.empty())
        {
            vector<int> ansPerLevel;
            int size = pointerQueue.size();
            for (int i = 0; i < size; i++)
            {
                ansPerLevel.push_back(pointerQueue.front()->val);
                if (pointerQueue.front()->left != nullptr)
                {
                    pointerQueue.push(pointerQueue.front()->left);
                }
                if (pointerQueue.front()->right != nullptr)
                {
                    pointerQueue.push(pointerQueue.front()->right);
                }
                pointerQueue.pop();
            }
            ans.push_back(ansPerLevel);
        }
        return ans;
    }
};