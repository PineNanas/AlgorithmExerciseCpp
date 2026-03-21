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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
        {
            return nullptr;
        }
        int vecSize = nums.size();
        int mid = vecSize / 2;
        vector<int> leftVec(nums.begin(), nums.begin() + mid);
        vector<int> rightVec(nums.begin() + mid + 1, nums.end());
        TreeNode* left = sortedArrayToBST(leftVec);
        TreeNode* right = sortedArrayToBST(rightVec);
        TreeNode* root = new TreeNode(nums[mid], left, right);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildNode(nums, 0, nums.size() - 1);
    }
    TreeNode* buildNode(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* leftNode = buildNode(nums, left, mid - 1);
        TreeNode* rightNode = buildNode(nums, mid + 1, right);
        return new TreeNode(nums[mid], leftNode, rightNode);
    }
};