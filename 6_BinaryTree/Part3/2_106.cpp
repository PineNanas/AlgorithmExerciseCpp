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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            inorderHash[inorder[i]] = i;
        }
        TreeNode* root = makeNode(postorder, inorder, 0, size - 1, size - 1, 0);
        return root;
    }

    TreeNode* makeNode(const vector<int>& postorder, const vector<int>& inorder, int inorderFront, int inorderBack, int postorderNow, int postorderFront) 
    {
        if (postorderNow < postorderFront)
        {
            return nullptr;
        }
        int nodeValue = postorder[postorderNow];
        int inorderIndex = inorderHash[nodeValue];
        TreeNode* node = new TreeNode(nodeValue);
        int rightLen = inorderBack - inorderIndex;
        node->left = makeNode(postorder, inorder, inorderFront, inorderIndex - 1, postorderNow - rightLen - 1, postorderFront);
        node->right = makeNode(postorder, inorder, inorderIndex + 1, inorderBack, postorderNow - 1, postorderNow - rightLen);
        return node;
    }
};