#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            graph[i].push_back(i + 1);
        }
        auto bfs = [&] () -> int
        {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(0);
            int len = -1;
            while (q.size())
            {
                len++;
                int si = q.size();
                for (int i = 0; i < si; i++)
                {
                    if (q.front() == n - 1)
                    {
                        return len;
                    }
                    if (visited[q.front()])
                    {
                        q.pop();
                        continue;
                    }
                    for (int j = 0; j < graph[q.front()].size(); j++)
                    {
                        q.push(graph[q.front()][j]);
                    }
                    visited[q.front()] = true;
                    q.pop();
                }
            }
            return -1;
        };
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            graph[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(bfs());
        }
        return ans;
    }
};