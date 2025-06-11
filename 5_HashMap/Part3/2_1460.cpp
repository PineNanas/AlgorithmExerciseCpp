#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hashMap1;
        vector<int> ans;
        for (int i = 0; i < target.size(); i++)
        {
            hashMap1[target[i]]++;
            hashMap1[arr[i]]--;
        }
        for (const auto& [_, value] : hashMap1) 
        {
            if (value != 0)
            {
                return false;
            }
        }
        return true;
    }
};