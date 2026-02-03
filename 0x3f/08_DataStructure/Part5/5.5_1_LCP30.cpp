#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 0LL) < 0)
        {
            return -1;
        }
        priority_queue< int,
                        vector<int>,
                        greater<int>> minHeap;
        long long limit = 0;
        long long hp = 1;
        int change = 0;
        for (auto &&num : nums)
        {
            if (num < 0)
            {
                minHeap.push(num);
            }
            hp += num;
            if (hp <= limit)
            {
                limit += minHeap.top();
                minHeap.pop();
                change++;
            }
        }
        return change;
    }
};