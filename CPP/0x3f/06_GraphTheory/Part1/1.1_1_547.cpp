#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        auto dfs = [&] (this auto&& dfs, int cur) -> void
        {
            if (visited[cur])
            {
                return;
            }
            visited[cur] = true;
            for (int i = 0; i < n; i++)
            {
                if (isConnected[cur][i])
                {
                    dfs(i);
                }
            }
            return;
        };
        int province = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                province++;
                dfs(i);
            }
        }
        return province;
    }
};