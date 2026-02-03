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
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> smallStk;
        int minNum = -1;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] < minNum)
            {
                return false;
            }
            while (!smallStk.empty() && smallStk.top() < preorder[i])
            {
                minNum = smallStk.top();
                smallStk.pop();
            }
            smallStk.push(preorder[i]);
        }
        return true;
    }
};