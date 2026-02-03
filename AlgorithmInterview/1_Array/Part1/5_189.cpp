#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        reverse(nums, 0, size - k - 1);
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - 1);
    }
    void reverse(vector<int>& nums, int x, int y){
        while (x < y)
        {   
            swap(nums[x], nums[y]);
            x++;
            y--;
        }
    }
};