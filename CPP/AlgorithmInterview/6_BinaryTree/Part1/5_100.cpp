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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        if (!isSameTree(p->left, q->left))
        {
            return false;
        }
        if (!isSameTree(p->right, q->right))
        {
            return false;
        }
        return true;
    }
};

class SolutionMorris
{
public:
    vector<int> MorrisTraversal(TreeNode *root)
    {
        vector<int> MorrisTraversal;
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
                    MorrisTraversal.push_back(p->val);
                    mostRight->right = p;
                    p = p->left;
                    continue;
                }
                else
                {
                    mostRight->right = nullptr;
                }
            }
            MorrisTraversal.push_back(p->val);
            p = p->right;
        }
        return MorrisTraversal;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> MorrisP = MorrisTraversal(p);
        vector<int> MorrisQ = MorrisTraversal(q);
        if (MorrisP.size() != MorrisQ.size())
        {
            return false;
        }
        for (int i = 0; i < MorrisP.size(); i++)
        {
            if (MorrisP[i] != MorrisQ[i])
            {
                return false;
            }
        }
        return true;
    }
};

class SolutionMorris2
{
public:
    bool isSameTree(TreeNode *root1, TreeNode *root2)
    {
        bool ans = true;
        TreeNode *p = root1;
        TreeNode *q = root2;
        TreeNode *mostRight = nullptr;
        int bufferNumber;
        while (p != nullptr || q != nullptr)
        {
            if (p != nullptr)
            {
                bufferNumber = p->val;
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
                    }
                    else
                    {
                        bufferNumber = p->val;
                        mostRight->right = nullptr;
                        p = p->right;
                    }
                }
                else
                {
                    bufferNumber = p->val;
                    p = p->right;
                }
            }
            else
            {
                ans = false;
            }
            if (q != nullptr)
            {
                if (bufferNumber != q->val)
                {
                    ans = false;
                }
                mostRight = q->left;
                if (mostRight != nullptr)
                {
                    while (mostRight->right != nullptr && mostRight->right != q)
                    {
                        mostRight = mostRight->right;
                    }
                    if (mostRight->right == nullptr)
                    {
                        mostRight->right = q;
                        q = q->left;
                    }
                    else
                    {
                        mostRight->right = nullptr;
                        q = q->right;
                    }
                }
                else
                {
                    q = q->right;
                } 
            }
            else
            {
                ans = false;
            }
        }
        return ans;
    }
};