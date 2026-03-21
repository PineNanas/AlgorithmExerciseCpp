#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curRound;
        int n = s.size();

        auto check = [&] (string s1) -> bool
        {
            int left = 0;
            int right = s1.size() - 1;
            while (left < right)
            {
                if (s1[left] != s1[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        auto dfs = [&] (this auto&& dfs, int left) -> void
        {
            if (left >= n)
            {
                ans.push_back(curRound);
                return;
            }
            for (int right = left; right < n; right++)
            {
                string curStr(s.begin() + left, s.begin() + right + 1);
                if (check(curStr))
                {
                    curRound.push_back(curStr);
                    dfs(right + 1);
                    curRound.pop_back();
                }
            }
            return;
        };

        dfs(0);
        return ans;
    }
};