#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int max1 = 0;
        for (int x: hashSet)
        {
            if (hashSet.find(x - 1) != hashSet.end())
            {
                continue;
            }
            int now = x + 1;
            while (hashSet.find(now) != hashSet.end())
            {
                now++;
            }
            max1 = max(max1, now - x);
        }
        return max1;
    }
};