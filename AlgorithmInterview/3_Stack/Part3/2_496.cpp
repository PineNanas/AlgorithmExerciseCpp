#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_map<int, int> hashMap;
        stack<int> stk;
        for (int i = 0; i < size2; i++)
        {
            while (!stk.empty() && stk.top() < nums2[i])
            {
                hashMap[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        vector<int> ans (size1);
        for (int i = 0; i < size1; i++)
        {
            ans[i] = hashMap.find(nums1[i]) == hashMap.end()? -1 : hashMap[nums1[i]];
        }
        return ans;
    }
};