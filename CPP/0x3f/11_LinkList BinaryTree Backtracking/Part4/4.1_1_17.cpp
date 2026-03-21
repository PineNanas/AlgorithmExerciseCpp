#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        string s = "";
        unordered_map<char, string> mapping =
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        auto dfs = [&] (this auto&& dfs, int now) -> void
        {
            if (now >= n)
            {
                ans.push_back(s);
                return;
            }
            char c = digits[now];
            for (int i = 0; i < mapping[c].size(); i++)
            {
                s.push_back(mapping[c][i]);
                dfs(now + 1);
                s.pop_back();
            }
            return;
        };
        
        dfs(0);
        return ans;
    }
};