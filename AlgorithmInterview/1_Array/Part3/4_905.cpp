#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0, k;
        int len = nums.size();
        while (j < len && nums[i] % 2 == 0)
        {
            i++;
            j++;
        }
        while (j < len)
        {
            if (nums[j] % 2 == 0)
            {
                k = nums[i];
                nums[i] = nums[j];
                nums[j] = k;
                i++;
            }
            j++;
        }
        return nums;
    }
};