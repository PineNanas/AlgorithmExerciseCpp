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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            vector<int> level(size);
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
                level[i] = nodeQueue.front()->val;
                nodeQueue.pop();
            }
            if (size <= 1) continue;
            vector<int> levelCopy(level);
            sort(levelCopy.begin(), levelCopy.end());
            unordered_map<int, queue<int>> valuePositions;
            for (int idx = 0; idx < size; idx++) {
                valuePositions[levelCopy[idx]].push(idx);
            }
            vector<int> mapping(size);
            for (int i = 0; i < size; i++) {
                mapping[i] = valuePositions[level[i]].front();
                valuePositions[level[i]].pop();
            }
            vector<bool> visited(size, false);
            int cycles = 0;
            for (int i = 0; i < size; i++) {
                if (visited[i]) continue;
                cycles++;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = mapping[j];
                }
            }
            ans += (size - cycles);
        }
        return ans;
    }
};