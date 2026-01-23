#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1;
        int nowLen = 1;
        int nowCount = 0;
        int left = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                if (nowCount == 0)
                {
                    nowCount++;
                }
                else
                {
                    do
                    {
                        left++;
                        nowLen--;
                    } while (s[left - 1] != s[left]);
                }
            }
            nowLen++;
            ans = max(ans, nowLen);
        }
        return ans;
    }
};