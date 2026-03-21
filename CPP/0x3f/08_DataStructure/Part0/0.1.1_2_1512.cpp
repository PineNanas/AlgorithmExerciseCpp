#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int x;
        int ans = 0;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            x = nums[i];
            for (int j = 0; j < i; j++)
            {
                if (nums[j] == x)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};