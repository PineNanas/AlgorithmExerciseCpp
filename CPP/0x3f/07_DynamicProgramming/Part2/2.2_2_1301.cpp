#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1000000007;
        vector<vector<long long>> score(n, vector<long long>(n, -1));
        vector<vector<long long>> path(n, vector<long long>(n, -1));
        score[n - 1][n - 1] = 0;
        path[n - 1][n - 1] = 1;
        score[0][0] = 0;

        auto dfs = [&] (this auto&& dfs, int x, int y) -> pair<long long, long long>
        {
            if (x >= n || y >= n)
            {
                return {0, 0};
            }
            if (board[x][y] == 'X')
            {
                return {0, 0};
            }
            if (path[x][y] != -1)
            {
                return {score[x][y], path[x][y]};
            }

            map<long long, long long> MaxHeap;
            pair<long long, long long> curP;
            curP = dfs(x + 1, y);
            MaxHeap[curP.first] += curP.second % mod;
            MaxHeap[curP.first] = MaxHeap[curP.first] % mod;
            curP = dfs(x, y + 1);
            MaxHeap[curP.first] += curP.second % mod;
            MaxHeap[curP.first] = MaxHeap[curP.first] % mod;
            curP = dfs(x + 1, y + 1);
            MaxHeap[curP.first] += curP.second % mod;
            MaxHeap[curP.first] = MaxHeap[curP.first] % mod;
            long long curScore = MaxHeap.rbegin()->first + (board[x][y] - '0');
            long long curPath = MaxHeap.rbegin()->second;
            score[x][y] = curScore;
            path[x][y] = curPath;
            return {curScore, curPath}; 
        };
        auto [score0, path0] = dfs(0, 0);
        if (path0 == 0)
        {
            return {0, 0};
        }
        
        return {(int)((score0 - 21) % mod), (int)(path0 % mod)};
    }
};