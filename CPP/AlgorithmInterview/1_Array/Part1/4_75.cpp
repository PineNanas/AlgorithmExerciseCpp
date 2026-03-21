#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsize = nums.size();
        for (int i = 0, x = -1, y = -1; i < numsize; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[++x], nums[i]);
                ++y;
                if (x != y)
                {
                    swap(nums[y], nums[i]);
                }
            }
            else if (nums[i] == 1)
            {
                swap(nums[++y], nums[i]);
            }
        }
    }
};