#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffMat(n + 2, vector<int>(n + 2));
        for (auto &&query : queries)
        {
            diffMat[query[0] + 1][query[1] + 1]++;
            diffMat[query[2] + 2][query[3] + 2]++;
            diffMat[query[0] + 1][query[3] + 2]--;
            diffMat[query[2] + 2][query[1] + 1]--;
        }
        vector<vector<int>> originalMat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diffMat[i + 1][j + 1] = diffMat[i][j + 1]
                                    +   diffMat[i + 1][j]
                                    +   diffMat[i + 1][j + 1]
                                    -   diffMat[i][j];
                originalMat[i][j] = diffMat[i + 1][j + 1];
            }
        }
        return originalMat;
    }
};