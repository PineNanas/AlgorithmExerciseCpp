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

class BSTIterator {
public:
    stack<TreeNode*> nodeStk;
    BSTIterator(TreeNode* root) {
        while (root)
        {
            nodeStk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* nowNode = nodeStk.top();
        int ans = nowNode->val;
        nodeStk.pop();
        nowNode = nowNode->right;
        while (nowNode)
        {
            nodeStk.push(nowNode);
            nowNode = nowNode->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !nodeStk.empty();
    }
};
