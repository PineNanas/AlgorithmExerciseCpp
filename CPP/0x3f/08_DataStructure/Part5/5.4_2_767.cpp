#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> letterCount(26);
        for (auto &&c : s)
        {
            letterCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (letterCount[i] == 0)
            {
                continue;
            }
            maxHeap.push({letterCount[i], i});
        }
        string ans = "";
        pair<int, int> out = maxHeap.top();
        maxHeap.pop();
        pair<int, int> mid;
        while (!maxHeap.empty())
        {
            ans.push_back('a' + out.second);
            out.first--;
            if (maxHeap.empty() && out.first != 0)
            {
                break;
            }
            mid = maxHeap.top();
            maxHeap.pop();
            if (out.first > 0)
            {
                maxHeap.push(out);
            }
            out = mid;
        }
        if (out.first > 1)
        {
            return "";
        }
        if (out.first == 1)
        {
            ans.push_back('a' + out.second);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    solution.reorganizeString("aab");
    return 0;
}