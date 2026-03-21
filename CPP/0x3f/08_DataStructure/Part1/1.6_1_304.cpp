#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sumM;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        sumM.resize(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sumM[i + 1][j + 1] = sumM[i][j + 1] + sumM[i + 1][j] - sumM[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumM[row2 + 1][col2 + 1] - sumM[row2 + 1][col1] - sumM[row1][col2 + 1] + sumM[row1][col1];
    }
};