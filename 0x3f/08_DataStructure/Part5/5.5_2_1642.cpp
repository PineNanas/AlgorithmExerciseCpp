#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int lastHeight = INT_MAX;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] <= lastHeight)
            {
                lastHeight = heights[i];
                continue;
            }
            int diff = heights[i] - lastHeight;
            maxHeap.push(diff);
            bricks -= diff;
            while (ladders > 0 && bricks < 0)
            {
                bricks += maxHeap.top();
                maxHeap.pop();
                ladders--;
            }
            if (bricks < 0)
            {
                return i - 1;
            }
            lastHeight = heights[i];
        }
        return heights.size() - 1;
    }
};