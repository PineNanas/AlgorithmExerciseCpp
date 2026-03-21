#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> existed;
        int ans = 0;
        int now = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (!existed[c])
            {
                existed[c]++;
                now++;
                ans = max(now, ans);
            }
            else
            {
                while (s[left] != c)
                {
                    existed[s[left]]--;
                    now--;
                    left++;
                }
                left++;
            }
        }
        return ans;
    }
};