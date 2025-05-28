#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int size = arr.size();
        int threshold = size / 4 + 1;
        int count = 0;
        int now = arr[0];
        int nowIndex = 0;
        while (count < threshold)
        {
            if (arr[nowIndex] == now)
            {
                count++;
            }
            else
            {
                now = arr[nowIndex];
                count = 1;
            }
            nowIndex++;
        }
        return now;
    }
};