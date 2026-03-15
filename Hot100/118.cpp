#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
        {
            return {{1}};
        }
        vector<vector<int>> ans(1, vector<int>(1, 1));
        ans.reserve(numRows);
        for (int i = 1; i < numRows; i++)
        {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                cur[j] = ans.back()[j - 1] + ans.back()[j];
            }
            ans.push_back(move(cur));
        }
        return ans;
    }
};