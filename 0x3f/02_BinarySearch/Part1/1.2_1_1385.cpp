#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        int sortIndex;
        for (int i = 0; i < arr1.size(); i++)
        {
            sortIndex = lowerBound(arr2, arr1[i] - d);
            if (sortIndex == arr2.size() || arr2[sortIndex] > arr1[i] + d)
            {
                ans++;
            }
        }
        return ans;
    }

    int lowerBound(vector<int> nums, int target)
    {
        int left = -1;
        int right = nums.size();
        int mid;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return right;
    }
};

class Solution2 {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        bool existed;
        for (int i = 0; i < arr1.size(); i++)
        {
            existed = false;
            for (int j = 0; j < arr2.size(); j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                {
                    existed = true;
                    break;
                }
            }
            if (!existed)
            {
                ans++;
            }
        }
        return ans;
    }
};