#include <bits/stdc++.h>
using namespace std;

bool bigger(pair<int, int> pair1, pair<int, int> pair2)
{
    if (pair1.second > pair2.second)
    {
        return true;
    }
    return false;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hashMap1;
        for (int i = 0; i < nums.size(); i++)
        {
            hashMap1[nums[i]]++;
        }
        vector<pair<int, int>> frequency(hashMap1.begin(), hashMap1.end());
        sort(frequency.begin(), frequency.end(), bigger);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(frequency[i].first);
        }
        return ans;
    }
};