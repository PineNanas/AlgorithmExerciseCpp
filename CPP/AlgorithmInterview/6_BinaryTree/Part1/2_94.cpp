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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inTraversal;
        TreeNode *p = root;
        TreeNode *mostRight = nullptr;
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
                    mostRight->right = p;
                    p = p->left;
                    continue;
                }
                else
                {
                    mostRight->right = nullptr;
                }
            }
            inTraversal.push_back(p->val);
            p = p->right;
        }
        return inTraversal;
    }
};