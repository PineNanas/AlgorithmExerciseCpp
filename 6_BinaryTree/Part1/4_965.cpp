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

class SolutionMorris {
public:
    bool isUnivalTree(TreeNode* root) {
        int valueNow = root->val;
        TreeNode* p = root;
        TreeNode* lastRight = nullptr;
        bool ans = true;
        while (p != nullptr)
        {
            lastRight = p->left;
            if (lastRight != nullptr)
            {
                while (lastRight->right != nullptr && lastRight->right != p)
                {
                    lastRight = lastRight->right;
                }
                if (lastRight->right == nullptr)
                {
                    lastRight->right = p;
                    p = p->left;
                    continue;
                }
                else
                {
                    lastRight->right = nullptr;
                }
            }
            if (p->val != valueNow)
            {
                ans = false;
            }
            p = p->right;
        }
        return ans;
    }
};

class SolutionDFS {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        int checkNum = root->val;
        if (root->left != nullptr)
        {
            if (root->left->val != checkNum || !isUnivalTree(root->left))
            {
                return false;
            }
        }
        if (root->right != nullptr)
        {
            if (root->right->val != checkNum || !isUnivalTree(root->right))
            {
                return false;
            }
        }
        return true;
    }
};