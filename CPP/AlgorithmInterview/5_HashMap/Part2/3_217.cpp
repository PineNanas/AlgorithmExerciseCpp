#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> before;
        for (int i = 0; i < nums.size(); i++)
        {
            if (before.find(nums[i]) != before.end())
            {
                return true;
            }
            before.insert(nums[i]);
        }
        return false;
    }
};