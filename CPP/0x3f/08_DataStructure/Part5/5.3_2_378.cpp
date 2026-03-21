#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< int,
                        vector<int>,
                        greater<int>> minHeap;
        for (auto &&vec : matrix)
        {
            for (auto &&num : vec)
            {
                minHeap.push(num);
            }
        }
        for (int i = 0; i < k - 1; i++)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};