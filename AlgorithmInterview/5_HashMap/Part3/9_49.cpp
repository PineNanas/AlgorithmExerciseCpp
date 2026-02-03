#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> counts(26);
            for (const auto& c : strs[i])
            {
                counts[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++)
            {
                key.push_back('a' + i);
                key.append(to_string(counts[i]));
            }
            if (hashMap.count(key) == 0)
            {
                hashMap.insert({key, {strs[i]}});
            }
            else
            {
                hashMap[key].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for (const auto& v : hashMap)
        {
            ans.push_back(v.second);
        }
        return ans;
    }
};