#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int x = k * threshold;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        int count = 0;
        if (sum >= x)
        {
            count++;
        }
        int i = 0;
        int j = k;
        while (j < arr.size())
        {
            sum -= arr[i];
            sum += arr[j];
            if (sum >= x)
            {
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};