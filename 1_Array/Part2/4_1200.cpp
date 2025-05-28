#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int base = 2147483647;
        int diff = 0;
        vector<vector<int>> ans(size);
        for (int i = 0; i < size - 1; i++)
        {
            diff = arr[i + 1] - arr[i];
            if (diff < base)
            {
                ans.clear();
                base = diff;
                vector<int> couple = {arr[i], arr[i + 1]};
                ans.push_back(couple);
            }
            else if (diff == base)
            {
                vector<int> couple = {arr[i], arr[i + 1]};
                ans.push_back(couple);
            }
        }
        return ans; 
    }
};