#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int len = arr.size();
        if (len < 3)
        {
            return arr;
        }
        bool edited = true;
        while (edited)
        {
            edited = false;
            vector<int> check(arr.begin(), arr.end());
            for (int i = 1; i < len - 1; i++)
            {
                if (arr[i] > check[i - 1] && arr[i] > check[i + 1])
                {
                    arr[i]--;
                    edited = true;
                }
                if (arr[i] < check[i - 1] && arr[i] < check[i + 1])
                {
                    arr[i]++;
                    edited = true;
                }
            }
        }
        return arr;
    }
};