#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sumMat(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sumMat[i + 1][j + 1] = sumMat[i + 1][j] + sumMat[i][j + 1] - sumMat[i][j] + mat[i][j];
            }
        }
        auto calSum = [&] (int lefti, int leftj, int righti, int rightj) -> int
        {
            lefti = max(lefti, 0);
            leftj = max(leftj, 0);
            righti = min(righti, m - 1);
            rightj = min(rightj, n - 1);
            return sumMat[righti + 1][rightj + 1] - sumMat[righti + 1][leftj] - sumMat[lefti][rightj + 1] + sumMat[lefti][leftj];
        };
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = calSum(i - k, j - k, i + k, j + k);
            }
        }
        return ans;
    }
};