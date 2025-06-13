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

class Solution1
{
public:
    vector<int> preTraversal;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            preTraversal.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return preTraversal;
    }
};

class SolutionMorris
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preTraversal;
        TreeNode* p = root;
        TreeNode* mostRight = nullptr;
        while (p != nullptr)
        {
            mostRight = p->left;
            if (mostRight != nullptr)
            {
                while (mostRight->right != nullptr && mostRight->right != p)
                {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr)
                {
                    preTraversal.push_back(p->val);
                    mostRight->right = p;
                    p = p->left;
                    continue;
                }
                else
                {
                    mostRight->right = nullptr;
                }
            }
            else
            {
                preTraversal.push_back(p->val);
            }
            p = p->right;
        }
        return preTraversal;
    }
};