#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashMap.count(nums[i]) == 0 || i - hashMap[nums[i]] > k)
            {
                hashMap[nums[i]] = i;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};