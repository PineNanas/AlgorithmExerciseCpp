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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valueToNode;
        unordered_set<int> notRoot;
        for (const auto& description: descriptions)
        {
            notRoot.insert(description[1]);
            if (!valueToNode.contains(description[0]))
            {
                TreeNode* newNode = new TreeNode(description[0]);
                valueToNode.insert({description[0], newNode});
            }
            if (!valueToNode.contains(description[1]))
            {
                TreeNode* newChild = new TreeNode(description[1]);
                valueToNode.insert({description[1], newChild});
            }
            if (description[2] == 1)
            {
                valueToNode[description[0]]->left = valueToNode[description[1]];
            }
            else
            {
                valueToNode[description[0]]->right = valueToNode[description[1]];
            }
        }
        TreeNode* root = nullptr;
        for (const auto& valueNodePair: valueToNode)
        {
            if (!notRoot.contains(valueNodePair.first))
            {
                root = valueNodePair.second;
                return root;
            }
        }
        return nullptr;
    }
};