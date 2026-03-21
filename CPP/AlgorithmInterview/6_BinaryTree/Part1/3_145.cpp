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

TreeNode* reverse(TreeNode* cur)
{
    TreeNode* pre = nullptr,* next = nullptr;
    while (cur != nullptr)
    {
        next = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

class Solution {
public:
    vector<int> postOrderVector;
    void pushRightEdgeInversely(TreeNode* head)
    {
        head = reverse(head);
        TreeNode* cur = head;
        while (cur != nullptr)
        {
            postOrderVector.push_back(cur->val);
            cur = cur->right;
        }
        reverse(head);
    }

    vector<int> postorderTraversal(TreeNode* root) {
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
                    pushRightEdgeInversely(p->left);
                }
            }
            p = p->right;
        }
        pushRightEdgeInversely(root);
        return postOrderVector;
    }
};