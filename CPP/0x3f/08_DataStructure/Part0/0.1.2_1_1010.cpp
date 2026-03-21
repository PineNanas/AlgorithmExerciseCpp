#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> countV(60, 0);
        int ans = 0;
        int tab;
        for (int i = 0; i < time.size(); i++)
        {
            tab = time[i] % 60;
            ans += countV[(60 - tab) % 60];
            countV[tab]++;
        }
        return ans;
    }
};