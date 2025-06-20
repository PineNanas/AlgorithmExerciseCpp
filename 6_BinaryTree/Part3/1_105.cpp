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
    unordered_map<int, int> inorderHash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        for (int i = 0; i < size; i++)
        {
            inorderHash[inorder[i]] = i;
        }
        TreeNode* root = makeNode(preorder, inorder, 0, size - 1, 0, size - 1);
        return root;
    }

    TreeNode* makeNode(const vector<int>& preorder, const vector<int>& inorder, int inorderFront, int inorderBack, int preoderNow, int preoderBack) 
    {
        if (preoderNow > preoderBack)
        {
            return nullptr;
        }
        int nodeValue = preorder[preoderNow];
        int inorderIndex = inorderHash[nodeValue];
        int leftLen = inorderIndex -  inorderFront;
        TreeNode* node = new TreeNode(nodeValue);
        node->left = makeNode(preorder, inorder, inorderFront, inorderIndex - 1, preoderNow + 1, preoderNow + leftLen);
        node->right = makeNode(preorder, inorder, inorderIndex + 1, inorderBack, preoderNow + leftLen + 1, preoderBack);
        return node;
    }
};