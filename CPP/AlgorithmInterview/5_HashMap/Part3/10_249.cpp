#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;
        for (const auto& s: strings)
        {
            string changeS;
            for (const auto& c: s)
            {
                changeS.push_back((c - s[0] + 26) % 26);
            }
            if (hashMap.count(changeS) == 0)
            {
                hashMap.insert({changeS, {s}});
            }
            else
            {
                hashMap[changeS].push_back(s);
            }
        }
        vector<vector<string>> ans;
        for (const auto& x: hashMap)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};