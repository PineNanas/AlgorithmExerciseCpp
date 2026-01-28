#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> sumV;
    NumArray(vector<int>& nums) {
        sumV.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            sumV[i + 1] = sumV[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sumV[right + 1] - sumV[left];
    }
};