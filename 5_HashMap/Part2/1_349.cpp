#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        unordered_set<int> ansSet;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (hashSet.find(nums2[i]) != hashSet.end())
            {
                ansSet.insert(nums2[i]);
            }
        }
        vector<int> ans(ansSet.begin(), ansSet.end());
        return ans;
        
    }
};