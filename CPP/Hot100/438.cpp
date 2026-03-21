#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n)
        {
            return {};
        }
        vector<int> originCount(26);
        vector<int> curCount(26);
        vector<int> ans;
        for (auto &&c : p)
        {
            originCount[c - 'a']++;
        }
        for (int i = 0; i < m; i++)
        {
            curCount[s[i] - 'a']++;
        }
        
        auto check = [&] () -> bool
        {
            for (int i = 0; i < 26; i++)
            {
                if (originCount[i] != curCount[i])
                {
                    return false;
                }
            }
            return true;
        };

        for (int i = m; i < n; i++)
        {
            if (check())
            {
                ans.push_back(i - m);
            }
            curCount[s[i - m] - 'a']--;
            curCount[s[i] - 'a']++;
        }
        if (check())
        {
            ans.push_back(n - m);
        }
        return ans;
    }
};