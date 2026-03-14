#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n, 1);
        vector<int> back(n, 1);
        for (int i = 1; i < n; i++)
        {
            front[i] = front[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            back[i] = back[i + 1] * nums[i + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = front[i] * back[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int cur = 1;
        for (int i = 1; i < n; i++)
        {
            cur *= nums[i - 1];
            ans[i] *= cur;
        }
        cur = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            cur *= nums[i + 1];
            ans[i] *= cur;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int front = 1;
        int back = 1;
        for (int i = 1; i < n; i++)
        {
            front *= nums[i - 1];
            back *= nums[n - i];
            ans[i] *= front;
            ans[n - i - 1] *= back;
        }
        return ans;
    }
};