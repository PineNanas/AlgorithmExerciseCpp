#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneHeap(stones.begin(), stones.end());
        while (stoneHeap.size() > 1)
        {
            int stoneA = stoneHeap.top();
            stoneHeap.pop();
            int stoneB = stoneHeap.top();
            stoneHeap.pop();
            if (stoneA == stoneB)
            {
                continue;
            }
            stoneHeap.push(abs(stoneA - stoneB));
        }
        if (stoneHeap.empty())
        {
            return 0;
        }
        return stoneHeap.top();
    }
};