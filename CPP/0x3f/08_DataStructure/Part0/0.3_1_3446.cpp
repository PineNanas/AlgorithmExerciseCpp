#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int x = 0; x < n; x++)
        {
            vector<int> diagV;
            for (int i = x; i < n; i++)
            {
                int j = i - x;
                diagV.push_back(grid[i][j]);
            }
            ranges::sort(diagV, greater());
            for (int i = x; i < n; i++)
            {
                int j = i - x;
                grid[i][j] = diagV[j];
            }
        }
        for (int x = 1; x < n; x++)
        {
            vector<int> diagV;
            for (int j = x; j < n; j++)
            {
                int i = j - x;
                diagV.push_back(grid[i][j]);
            }
            ranges::sort(diagV);
            for (int j = x; j < n; j++)
            {
                int i = j - x;
                grid[i][j] = diagV[i];
            }
        }
        return grid;
    }
};