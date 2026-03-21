#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool big = true;
        int z;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if ((nums[i] <= nums[i + 1]) != big)
            {
                z = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = z;
            }
            big = !big;
        }
        return;
    }
};