#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int left = 0;
        vector<int> cntT(58, 0);
        vector<int> cntS(58, 0);
        for (auto &&c : t)
        {
            cntT[c - 'A']++;
        }
        int minLeft = INT_MAX;
        int minLen = INT_MAX;
        
        for (int right = 0; right < n; right++)
        {
            int cir = s[right] - 'A';
            cntS[cir]++;
            if (cntS[cir] < cntT[cir])
            {
                continue;
            }
            int cil = s[left] - 'A';
            while (cntS[cil] > cntT[cil] && left < right)
            {
                cntS[cil]--;
                left++;
                cil = s[left] - 'A';
            }
            bool contained = true;
            for (int i = 0; i < 58; i++)
            {
                if (cntS[i] < cntT[i])
                {
                    contained = false;
                }
            }
            if (!contained)
            {
                continue;
            }
            int len = right - left + 1;
            if (len >= minLen)
            {
                continue;
            }
            minLeft = left;
            minLen = len;
        }
        
        if (minLeft == INT_MAX)
        {
            return "";
        }
        return s.substr(minLeft, minLen);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int left = 0;
        vector<int> cntT(58, 0);
        vector<int> cntS(58, 0);
        int less = 0;
        for (auto &&c : t)
        {
            if (cntT[c - 'A'] == 0)
            {
                less++;
            }
            cntT[c - 'A']++;
        }
        int minLeft = INT_MAX;
        int minLen = INT_MAX;
        
        for (int right = 0; right < n; right++)
        {
            int cir = s[right] - 'A';
            cntS[cir]++;
            if (cntS[cir] < cntT[cir])
            {
                continue;
            }
            if (cntS[cir] == cntT[cir])
            {
                less--;
            }
            int cil = s[left] - 'A';
            while (cntS[cil] > cntT[cil] && left < right)
            {
                cntS[cil]--;
                left++;
                cil = s[left] - 'A';
            }
            if (less > 0)
            {
                continue;
            }
            int len = right - left + 1;
            if (len >= minLen)
            {
                continue;
            }
            minLeft = left;
            minLen = len;
        }
        
        if (minLeft == INT_MAX)
        {
            return "";
        }
        return s.substr(minLeft, minLen);
    }
};